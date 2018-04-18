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
        void    setRue( const char* uneRue);
        int     getCodePostal();
        void    setCodePostal(int unCodePostal);
        char*   getVille() ;
        void    setVille( const char* uneVille);
        
        // constructeurs
        
        Adresse();
        Adresse( const char* uneRue, int unCodePostal, const char* uneVille);
        Adresse& operator=(Adresse& other);
        Adresse(Adresse& other);

        // méthodes
        
        void saisir();
        void afficher() ;
    
};
#endif
