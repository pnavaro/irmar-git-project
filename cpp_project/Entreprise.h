/*
 * Entreprise.h
 *
 *  Created on: 24 mars 2010
 *      Author: Administrateur
 */

#ifndef ENTREPRISE_H_
#define ENTREPRISE_H_
#include "employe.h"

class Entreprise {
private:
	char nom[50];
	Employe* tabPtrEmp[5];
        int nbEmploye;
public:
	Entreprise();
	Entreprise(const char* unNom);
        Entreprise(Entreprise& other);
        Entreprise& operator=(Entreprise& other);
        ~Entreprise();
        int getNbEmploye();
        char* getNom();
        void setNom(const char* nom);
        void afficher();
        void addEmp(Employe* e);

};

#endif /* ENTREPRISE_H_ */
