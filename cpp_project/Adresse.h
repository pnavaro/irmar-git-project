#ifndef ADRESSE_H
#define ADRESSE_H

class Adresse
{
    private:
         char rue[50];
         int  codePostal;
         char ville[50]; 
    public:
        // accesseurs
        char*   getRue() ;
        void    setRue( char* uneRue);
        int     getCodePostal();
        void    setCodePostal(int unCodePostal);
        char*   getVille() ;
        void    setVille( char* uneVille);
        
        // constructeurs
        
        Adresse();
        Adresse( char* uneRue, int unCodePostal, char* uneVille);
        Adresse& operator=(Adresse& other);
        Adresse(Adresse& other);

        // méthodes
        
        void saisir();
        void afficher() ;
	
    
};
#endif
