#include <iostream>
#include <string>
using namespace std;

class carte{

    string titlu, nume_autori, editura;
    unsigned int an;
public:
    carte(){
        titlu="";
        nume_autori="";
        editura="";
        an=0;
        citire_carte();
    }


    carte(string,string,string,unsigned int);

    ~carte(){
        cout<<"Cartea: "<<titlu<<" a fost distrusa\n";
    }

    void citire_carte();
    inline void afis_carte();

};
    carte::carte(string titlu,string nume_autori,string editura,unsigned int an){
        this->titlu=titlu;
        this->nume_autori=nume_autori;
        this->editura=editura;
        this->an=an;
    }

    inline void carte::afis_carte(){
        cout<<"\n\nTitlul cartii: "<<titlu<<"\nNumele autorului: "<<nume_autori<<"\nEditura: "<<editura<<"\nAnul publicarii: "<<an<<"\n\n";
    }

    void carte::citire_carte(){
        cout<<"Citire carte:\n";
        cout<<"Titilu: ";cin>>titlu;
        cout<<"Nume autor: ";cin>>nume_autori;
        cout<<"Editura: ";cin>>editura;
        cout<<"An: ";cin>>an;
    }



int main()
{
        carte poveste("Poveste","Ion Creanga","Litera",2005);
        poveste.afis_carte();
        carte roman;
        roman.afis_carte();


    return 0;
}
