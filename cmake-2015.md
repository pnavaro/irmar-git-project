% CMake
% Moteur de production multiplateforme
% Pierre Navaro IRMAR

# Moteur de production

## Wikipedia
Un moteur de production est un logiciel dont la fonction principale
consiste à automatiser (ordonnancer et piloter) l’ensemble des
actions (préprocessing, compilation, éditions des liens, etc.)
contribuant, à partir de données sources, à la production d’un
ensemble logiciel opérationnel.

- GNU Make
- Autotools (GNU build system)
- Outils python (setuptools, SCons, waf)
- Outils Java (Maven, Ant)


# Les outils CMake

1. **CMake**: Makefile (make, make install, make clean), KDevelop3 Eclipse CDT, Visual Studio, Code::Blocks, Xcode.
2. **CTest+CDash**: Gestion des test unitaires Diagnostics via un portail web.
3. **CPack**: Création de paquet deb, rpm, pkg,
tar.gz

# Kitware quality software process

Le fichier important : *CMakeLists.txt*


```python
cpp_project/
|-- Adresse.cpp
|-- Adresse.h
|-- CMakeLists.txt
|-- Entreprise.cpp
|-- Entreprise.h
|-- Personne.cpp
|-- Personne.h
|-- commercial.cpp
|-- commercial.h
|-- employe.cpp
|-- employe.h
|-- main.cpp
```

# CMakeLists.txt


```python
project(cpp_project CXX)
cmake_minimum_required(VERSION 3.0)

file(GLOB hpp_files ${PROJECT_SOURCE_DIR} "*.h")
file(GLOB cpp_files ${PROJECT_SOURCE_DIR} "*.cpp")
include_directories(${PROJECT_SOURCE_DIR})
foreach(cpp_file ${cpp_files})
   if (NOT ${cpp_file} MATCHES "main.c")
      list(APPEND  lib_sources ${cpp_file})
   endif (NOT ${cpp_file} MATCHES "main.c")
endforeach(cpp_file)
```

# CMakeLists.txt

Compilation de la bibliothèque "classes" :


```python
add_library(classes STATIC ${cpp_files})
```

Compilation du programme exécutable


```python
add_executable( project.exe main.cpp)
```

Édition de liens


```python
target_link_libraries( project.exe classes)
```

# Génération de Makefile


```bash
%%bash
$ mkdir build
$ cd build/
$ cmake ../cpp_project
```

Création d'un fichier CMakeCache.txt qui contient toutes les variables
propres à l’utilisateur et son environnement.

# Compilation


```bash
%%bash
make
```

# Le fichier CMakeCache.txt

- Fichier modifiable
- Modifier les variables
- Utilisez `ccmake` ou la commande `make edit_cache`


# Message de configuration


```python
MESSAGE([STATUS|WARNING|AUTHOR_WARNING|FATAL_ERROR|SEND_ERRO
"message to display" ...)
```

# Quelques variables utiles

- top level directory of your build tree
${CMAKE_BINARY_DIR} : 
- the top level source directory
${CMAKE_SOURCE_DIR}
- place where CMake should put all executable files
${EXECUTABLE_OUTPUT_PATH}
- where cmake look at when you use FIND_PACKAGE() or INCLUDE()
${CMAKE_MODULE_PATH}
- Show compilation with flags
${CMAKE_VERBOSE_MAKEFILE} )
- the compiler used for C files
${CMAKE_C_COMPILER}

CMake useful variables :
http://www.cmake.org/Wiki/CMake_Useful_Variables

# Doxygen


```python
find_package(Doxygen)
if(DOXYGEN_FOUND)
   add_custom_target( doc
      ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
      COMMENT "Generating API documentation with Doxygen"
      VERBATIM)
else(DOXYGEN_FOUND)
   message(STATUS "DOXYGEN NOT FOUND")
endif(DOXYGEN_FOUND)
```

`find_package` exécute un fichier fourni avec le programme CMake

# Créer son propre fichier de configuration

Dans le CMakeLists.txt principal.


```python
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
find_package(FFTW)
```

Dans le fichier cmake/FindFFTW.cmake


```python
set(TRIAL_PATHS $ENV{FFTW_HOME} /usr /usr/local )
find_path(FFTW_INCLUDE_DIRS NAMES fftw3.h
          HINTS ${TRIAL_PATHS} PATH_SUFFIXES include
          DOC "path to fftw3.h")
find_libray(FFTW_LIBRARY NAMES fftw3
             HINTS ${TRIAL_PATHS} PATH_SUFFIXES lib lib64)
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FFTW DEFAULT_MSG
FFTW_INCLUDE_DIRS FFTW_LIBRARIES)
```

=> Si fftw est installée, la variable FFTW_FOUND est "TRUE"

# Compilation conditionnelle et preprocessing


```python
include(FindThreads)
if (CMAKE_HAVE_PTHREAD_H)
   message(STATUS "Using parallel pthread threads code")
   set(CMAKE_REQUIRED_LIBRARIES "${CMAKE_THREAD_LIBS_INIT}")
   link_libraries(${CMAKE_THREAD_LIBS_INIT})
   add_definitions(-DHAVE_PTHREAD)
endif(CMAKE_HAVE_PTHREAD_H)
```

# CTest


```python
enable_testing()
add_test(NAME project.exe COMMAND compute-pi-test-program)
set_tests_properties(project.exe PROPERTIES PASS_REGULAR_EXPRESSION "PASSED")
```


```python
ctest
```

http://cmake.org/Wiki/CMake/Testing_With_CTest

Pierre Navaro (IRMA Strasbourg)

# Macro


```python
MACRO(ADD_MPI_TEST TEST_NAME EXEC_NAME PROCS ARGS)
ADD_TEST(NAME ${TEST_NAME}
COMMAND ${MPIEXEC}
${MPIEXEC_NUMPROC_FLAG} ${PROCS} ${MPIEXEC_PREFLAGS}
${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${EXEC_NAME}
${MPIEXEC_POSTFLAGS} ${ARGS})
ENDMACRO(ADD_MPI_TEST)
ADD_MPI_TEST(compute-pi-mpi mpi-test-program 4 " ")
```

# Manipulation de chaines et expressions régulières
## Linux


```python
SET(cpuinfo_file "/proc/cpuinfo")
IF(EXISTS "${cpuinfo_file}")
FILE(STRINGS "${cpuinfo_file}" procs
REGEX "^processor.: [0-9]+$")
LIST(LENGTH procs PROCESSOR_COUNT)
ENDIF()
IF(APPLE)
FIND_PROGRAM(cmd_sys_pro "system_profiler")
IF(cmd_sys_pro)
EXECUTE_PROCESS(COMMAND ${cmd_sys_pro}
OUTPUT_VARIABLE info)
STRING(REGEX
REPLACE "^.*Total Number of Cores: ([0-9]+).*$" "\\1"
PROCESSOR_COUNT "${info}")
ENDIF()
```

# Exécution de commande système
## Affiche le compilateur Fortran


```python
MESSAGE(STATUS "Fortran :${CMAKE_Fortran_COMPILER}")
IF (${CMAKE_Fortran_COMPILER} MATCHES "ifort")
EXEC_PROGRAM(${CMAKE_Fortran_COMPILER}
ARGS "-v" OUTPUT_VARIABLE source_path)
STRING(REGEX MATCH "1[0-9]\\.[0-9]\\.[0-9]"
COMPILER_VERSION ${source_path})
ELSE()
EXEC_PROGRAM(${CMAKE_Fortran_COMPILER}
ARGS "--version" OUTPUT_VARIABLE source_path)
STRING(REGEX MATCH "4\\.[0-9]\\.[0-9]"
COMPILER_VERSION ${source_path})
ENDIF()
```

# Affiche le numero de version du compilateur


```python
MESSAGE(STATUS "Fortran version:${COMPILER_VERSION}")
Pierre Navaro (IRMA Strasbourg)
```

# CPack


```python
SET(CPACK_BINARY_DEB "ON")
SET(CPACK PACKAGE VENDOR "IRMAR")
SET(CPACK_PACKAGE_NAME "mon_package")
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "0")
SET(CPACK PACKAGE VERSION PATCH "0")
SET(CPACK_PACKAGING_INSTALL_PREFIX "/usr")
SET(CPACK_PACKAGE_CONTACT "pierre.navaro@math.cnrs.fr")
SET(CPACK_GENERATOR "DEB")
SET(CPACK DEBIAN PACKAGE DEPENDS "libhdf5-openmpi-dev")
SET(CPACK_PACKAGE_ARCHITECTURE "amd64")
INCLUDE (CPack)
```

http://cmake.org/Wiki/CMake:Packaging_With_CPack

# CPack


```bash
%%bash
[build]$ cpack
CPack: Create package using TGZ
CPack: Install projects
CPack: - Run preinstall target for: compute_pi
CPack: - Install project: compute_pi
CPack: Create package
CPack: - package: compute-pi-1.0-Darwin.tar.gz generated.
```

# CTest+CDash


```python
SET(CTEST_PROJECT_NAME "COMPUTE_PI")
SET(CTEST_NIGHTLY_START_TIME "20:00:00 EST")
SET(CTEST_DROP_METHOD "http")
SET(CTEST_DROP_SITE "cdash.inria.fr")
SET(CTEST_DROP_LOCATION "/CDash/submit.php?project=Compute_P
SET(CTEST_DROP_SITE_CDASH TRUE)
INCLUDE(CTest)
```

Pierre Navaro (IRMA Strasbourg)

# Les cibles pour les soumissions CDash


```bash
%%bash
build $ make help
Continuous
ContinuousBuild
...
Experimental
ExperimentalBuild
...
Nightly
...
```

# CDash dashboard
Démo avec le dashboard http://cdash.inria.fr

# Conclusion

+ Réputé rapide et stable.
+ Outil de plus en plus utilisé.
+ Langage concis pour les tâches les plus courantes.
+ La compilation n’est pas faite dans le répertoire des sources.
+ Compatibles avec Code : :Blocks, Xcode, Eclipse,....
- Langage limité.
- Peut boucler infiniment (mauvaise syntaxe).
- Autorise la compilation "in place", avec les sources.

=> CMake est une bonne alternative aux autotools car plus
accessible pour l’utilisateur final.

# Ressources

- CMake : Cross Platform Make http://www.cmake.org
- Introduction à CMake par Loic Gouarin http://calcul.math.cnrs.fr/Documents/Ecoles/LEM2I/Mod2/tp_cmake.pdf
- CMake Wiki http://www.cmake.org/Wiki/CMake
- Ken Martin et Bill Hoffman.  Mastering CMake.  Kitware 2010
