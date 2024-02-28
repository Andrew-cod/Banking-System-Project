#include <iostream>
#include <cstring>
using namespace std;
#define NR 2
class profesor {
    string nume, departament, grad_didactic;
    unsigned int vechime;
public:
    profesor();

    string nume_profesor(){
        return nume;
    }

    profesor(string, string, string, unsigned int);

    ~profesor();

    void citire_profesor();

    void afis_profesor();
};

profesor::~profesor(){
    nume = "";
    departament = "";
    grad_didactic = "";
    vechime = 0;
    cout<<"Profesorul a fost sters cu succes\n";
}

profesor::profesor() {
    nume = "";
    departament = "";
    grad_didactic = "";
    vechime = 0;

    citire_profesor();
}



profesor::profesor(string nume,string departament,string grad_didactic,unsigned int vechime) {
    this->nume = nume;
    this->departament = departament;
    this->grad_didactic = grad_didactic;
    this->vechime = vechime;
    cout << "Profesorul " << this->nume << " salvat cu succes\n\n";
}


void profesor::citire_profesor() {
    cout << "Date profesor:\n";
    cout << "Nume:";
    cin >> nume;
    cout << "Departament:";
    cin >> departament;
    cout << "Grad_didactic:";
    cin >> grad_didactic;
    cout << "Vechime: ";
    cin >> vechime;
    cout << "Profesorul " << nume << " salvat cu succes\n\n";
}

void profesor::afis_profesor() {
    cout << "Date profesor:\n" << "Nume: " << nume << "\nDepartament: " << departament << "\nGrad didactic: "
         << grad_didactic
         << "\nVechime: " << vechime << "\n\n";
}



int main() {

    profesor **profesori= new profesor*[NR];

    for(int i=0;i<NR;i++) profesori[i]=new profesor[NR];

    for(int i=0;i<NR;i++){
        for(int j=0;j<NR;j++)
            profesori[i][j].afis_profesor();
    }


    cout<<"Cautare dupa nume pentru stergere:\n";
    string n;
    cin>>n;

    for(int i=0;i<NR;i++){
        for(int j=0;j<NR;j++)
            if(profesori[i][j].nume_profesor()==n){
                profesori[i][j].~profesor();
                break;
            }
    }

    delete profesori;

    for(int i=0;i<NR;i++){
        for(int j=0;j<NR;j++)
            profesori[i][j].afis_profesor();
    }
    return 0;
}
