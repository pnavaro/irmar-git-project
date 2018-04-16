// Class automatically generated by Dev-C++ New Class wizard
#include <iostream>
#include "employe.h" // class's header file

using namespace std;

// class constructor
Employe::Employe(char* nom, char* rue, int codePostal, char* ville, float unSalaireMensuel)
:Personne(nom, rue, codePostal, ville)
{
     SetsalaireMensuel(unSalaireMensuel);
}

Employe::Employe()
:Personne()
{
	SetsalaireMensuel(0.0);
}

Employe::Employe(Employe &other)
:Personne(other)
{
     SetsalaireMensuel(other.GetsalaireMensuel());
}

Employe& Employe::operator=(Employe& other)
{
     if (&other == this) return (*this);
     Personne::operator =(other);
     SetsalaireMensuel(other.GetsalaireMensuel());
     return (*this);
}
// class destructor
// class destructor
Employe::~Employe()
{

}

// returns the value of salaireMensuel
float Employe::GetsalaireMensuel()
{
	return salaireMensuel;
}


// sets the value of salaireMensuel
void Employe::SetsalaireMensuel(float x)
{
	salaireMensuel = x;
}

// No description
void Employe::saisir()
{
	Personne::saisir();
    cout << "salaire mensuel?" << endl;
	cin >> salaireMensuel;
	cin.ignore();
}

// No description
void Employe::afficher()
{
	Personne::afficher();
	cout << "salaire mensuel = " << GetsalaireMensuel() << endl;
}
