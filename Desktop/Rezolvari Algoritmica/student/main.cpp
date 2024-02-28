#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
class Student
{
    char nume[20], pren[20];
    int grupa, cod_postal;
public:
    Student(char[20],char[20],int,int);//Constructor
    ~Student();//Destructor
    void citire_date();
    void afisare_date();
};
//constructor
Student::Student(char nume[20],char pren[20],int grupa,int cod_postal)
{
    strcpy(this->nume,nume);
    strcpy(this->pren,pren);
    this->grupa=grupa;
    this->cod_postal=cod_postal;

    cout<<"Studentul a fost creea si initializat cu succes\n\n";
}
// funcție pentru citirea informațiilor

//funcție pentru afișarea datelor
void Student::afisare_date()
{
    cout << "Nume :" << nume << endl;
    cout << "Prenume:" << pren << endl;
    cout << "Grupa:" << grupa << endl;
    cout << "Cod postal :" << cod_postal;
}
//destructor
Student :: ~Student()
{
    cout << "\nDestructor: Eliberare memorie! ";
}
int main()
{
//crearea unui obiect de tip Student
Student s("Arapu","Andrei",1,2025);

//afișarea informațiilor
s.afisare_date();

s.~Student( );
}