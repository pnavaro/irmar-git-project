/*
 * Entreprise.cpp
 *
 *  Created on: 24 mars 2010
 *      Author: Administrateur
 */

#include "Entreprise.h"
#include "string.h"
#include <iostream>
#include "employe.h"

using namespace std;



Entreprise::Entreprise() {
	setNom("");
	nbEmploye = 0;
}

Entreprise::Entreprise(const char *unNom)
{
	setNom(unNom);
	nbEmploye = 0;
}

Entreprise::Entreprise(Entreprise& other)
{
setNom(other.getNom());
nbEmploye = other.nbEmploye;
for(int i=0;i<nbEmploye; i++)
     tabPtrEmp[i]=other.tabPtrEmp[i]->getClone();
}

Entreprise& Entreprise::operator=(Entreprise& other)
{
    if (&other == this) return (*this);

    for(int i=0;i<nbEmploye; i++) delete tabPtrEmp[i];

    setNom(other.getNom());
    nbEmploye = other.nbEmploye;
    for(int i=0;i<nbEmploye; i++) tabPtrEmp[i]=other.tabPtrEmp[i]->getClone();

    return (*this);
}

Entreprise::~Entreprise() {
    for(int i=0;i<nbEmploye; i++)
     delete tabPtrEmp[i];
}

void Entreprise::setNom(const char* unNom)
{
        strcpy(nom,unNom);
}

char* Entreprise::getNom()
{
	return nom;
}


void Entreprise::addEmp(Employe* employe)
{
    tabPtrEmp[nbEmploye] = employe;
	nbEmploye++;

}


int Entreprise::getNbEmploye()
{
	return nbEmploye;
}

void Entreprise::afficher()
{
	 cout << " nom de l'entreprise : " << getNom() << endl;
         for(int i=0;i<getNbEmploye();i++)
                 tabPtrEmp[i]->afficher();
}


