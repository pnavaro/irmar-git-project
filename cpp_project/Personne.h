// Class automatically generated by Dev-C++ New Class wizard

#ifndef PERSONNE_H
#define PERSONNE_H
#include "Adresse.h"
// No description
class Personne
{
    private:
        Adresse adresse;
        char nom[50];
        static int nbInstance; 
    public:
        // class constructor
        Personne(char* unNom, char* uneRue, int unCodePostal, char* uneVille);
        // class default constructor
        Personne();
        // copy constructor
        Personne(Personne& other);
        Personne& operator=(Personne& other);
        void setNom(char* unNom);
        char* getNom();
        Adresse getAdresse();
        void setAdresse(Adresse uneAdresse);
        static int getNbInstance();
        void saisir();
        void afficher();
        // class destructor
        ~Personne();
		
		
};

#endif // PERSONNE_H