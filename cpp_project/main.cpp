#include <iostream>
#include "Adresse.h"
#include "Personne.h"
#include "employe.h"
#include "commercial.h"
#include "Entreprise.h"


using namespace std;

int main(int argc, char *argv[])
{
    Entreprise* ent1 = new Entreprise("CNRS");
    Employe* e;
    e = new Employe("Pierre","Descartes",67084,"Strasbourg",2100.0f);
    ent1->addEmp(e);
    e = new Commercial("Navaro","Wantzenau",67000,"Strasbourg",2100.0f,120,0.33);
    ent1->addEmp(e);


    cout <<"source"<< endl;
     ent1->afficher();
/*
    Entreprise ent2(*ent1);
    delete ent1;
    ent2.afficher();
    */

    cout << endl;
    cout <<"dest"<< endl;
    Entreprise ent3;
//    ent3=*ent1;
    ent3.afficher();


//    Adresse a1("Descartes",67084,"Strasbourg");
//    Adresse a2(a1);
////    a2.afficher();
//    Adresse a3;
//    a3= a1;
//    a3.afficher();
//    cout << endl;
//    Personne p1("Pierre","Descartes",67084,"Strasbourg");
//    Personne p2(p1);
//    Personne p3;
//    p3=p1;
////    p2.afficher();
//    p3.afficher();
//    cout << endl;
//    Employe e1("Pierre","Descartes",67084,"Strasbourg",2100.0f);
//    Employe e2(e1);
//    Employe e3;
//    e3 = e1;
//    e3.afficher();
////    e2.afficher();
//    cout << endl;
//    Commercial c1("Pierre","Descartes",67084,"Strasbourg",2100.0f,1000,0.33);
//    Commercial c2(c1);
//    Commercial c3;
//    c3 = c1;
//    c3.afficher();
////    c2.afficher();

    return 1;
}
