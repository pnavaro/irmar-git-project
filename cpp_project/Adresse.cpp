#include <string.h>
#include "Adresse.h"
#include <iostream>

using namespace std;

char* Adresse::getRue() 
{
    return rue;
}

void Adresse::setRue(const char* uneRue)
{
    strcpy(rue,uneRue);
}

int Adresse::getCodePostal()
{
    return codePostal;
}

void Adresse::setCodePostal(int unCodePostal)
{
    codePostal = unCodePostal;
}

char* Adresse::getVille() 
{
    return ville;
}

void Adresse::setVille(const char* uneVille)
{
    strcpy(ville,uneVille);
}

//constructeurs

Adresse::Adresse(const char* uneRue, int unCodePostal, const char* uneVille)
{
    strcpy(rue,uneRue);
    codePostal = unCodePostal;
    strcpy(ville, uneVille);
}

Adresse::Adresse()
{
    strcpy(rue,"");
    codePostal = 0000;
    strcpy(ville, "");
}

Adresse::Adresse(Adresse &other)
{
    setRue(other.getRue());
    setCodePostal(other.getCodePostal());
    setVille(other.getVille());
}

Adresse& Adresse::operator =(Adresse &other)
{
    if (&other == this) return (*this);
    setRue(other.getRue());
    setCodePostal(other.getCodePostal());
    setVille(other.getVille());
    return (*this);
}

void Adresse::saisir()
{
    cout << "rue?" << endl;
    cin.getline(rue,50);
    cout << "code postal?" << endl;
    cin >> codePostal;
    cin.ignore();
    cout << "ville?" << endl;
    cin.getline(ville,50);
}

void Adresse::afficher()
{
    cout << " rue : " << rue << endl;
    cout << " Code postal : " << codePostal << endl;
    cout << " Ville : " << ville << endl ;
}

