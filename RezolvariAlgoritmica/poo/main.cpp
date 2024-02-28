#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class masina
        {
        protected:
            char nume[20];
        public:


            masina(){
                strcpy(nume,"None");
            };
            masina(char *nume){
                cout<<"Masina "<<nume<<" este inregistrata"<<endl<<endl;
                strcpy(masina::nume,nume);
            }

            void setname(char *nume){
                strcpy(masina::nume,nume);
            }

            void printname(){
                cout<<"Numele masinii este:"<<nume<<endl;
            }

            ~masina(){
                cout<<"masina pe nume "<<nume<<" este distrusa"<<endl;
            }
        };

class angajat:public masina{

    char nume_angajat[20];
    char prenume[20];
    unsigned int varsta;

public:



    angajat(char *nume_angajat,char *prenume,unsigned int varsta,char *nume):masina(nume){

        strcpy(angajat::nume_angajat,nume_angajat);
        strcpy(angajat::prenume,prenume);
        angajat::varsta=varsta;
        strcpy(masina::nume,nume);
        cout<<"Angajatul "<<angajat::nume_angajat<<' '<<angajat::prenume<<' '<<angajat::varsta<<" este inregistrat"<<endl<<endl;
    }

    friend void print(angajat a);
    friend void hello(void);

    ~angajat(){

        cout<<"Angajatul "<<angajat::nume_angajat<<' '<<angajat::prenume<<' '<<angajat::varsta<<" nu mai este"<<endl<<endl;

    }



};

void hello(masina *a){
    cout<<"hello"<<endl;
    a->printname();

}

void print(angajat a){
    cout<<"Angajatul "<<a.nume_angajat<<' '<<a.prenume<<' '<<a.varsta<<endl<<endl;
}


int main() {
    angajat *a1=new angajat("Andrei","Arapu",19,"TESLA");
    cout<<endl<<endl<<endl;
    hello((masina*)a1);
    cout<<endl<<endl<<endl;





    return 0;
}
