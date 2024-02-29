// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <fstream>

#include <stdlib.h>

#include <conio.h>

#include <vector>

using namespace std;

class Persoana;
class Cont_Bancar;
class Card_Bancar;

string generare_IBAN(string nume, string prenume, unsigned short int an) {
	string IBAN = "RO";
	int sum = 0;
	for (char c : nume) {
		sum = sum + (int)c;
	}
	IBAN[2] = (char)sum % 10 + 48;
	sum = 0;
	for (char c : prenume) {
		sum = sum + (int)c;
	}

	IBAN[3] = (char)sum % 10 + 48;
	for (int i = 4; i <= 10; i++) {
		IBAN[i] = (char)sum % 24 + 65;
	}
	for (int i = 11; i < 24; i++) {
		IBAN[i] = (char)sum % 10 + 48;
	}
	return IBAN;

}

bool validare_IBAN(string IBAN) {
	return (IBAN.length() == 24) && isalpha(IBAN[0]) && isalpha(IBAN[1]) && isdigit(IBAN[2]) && isdigit(IBAN[3]);
}

class Card_Bancar {
private: Cont_Bancar * cont;
		 unsigned long long int nr_card;
		 string titular;
		 unsigned short int cvv;
		 unsigned short int pin;
public: Card_Bancar(Cont_Bancar * c, unsigned long long int nr_card = 0, string titular = "BANCA", unsigned short int cvv = 0, unsigned int pin = 0) {
	cont = c;
	this->nr_card = nr_card;
	this->titular = titular;
	this->cvv = cvv;
	this->pin = pin;

}
		Card_Bancar(unsigned long long int nr_card = 0, string titular = "BANCA", unsigned short int cvv = 0, unsigned short int pin = 0) {
			this->nr_card = nr_card;
			this->titular = titular;
			this->cvv = cvv;
			this->pin = pin;
		}

		void set_pin(int pin) {
			this->pin = pin;
		}
		void set_cvv(int cvv) {
			this->cvv = cvv;
		}
		void set_nr_card(int nr_card) {
			this->nr_card = nr_card;
		}
		bool check_nr_card(unsigned long long int incercare_nr_card) {
			return incercare_nr_card == nr_card;
		}

		bool check_cvv(unsigned short int incercare_cvv) {
			return cvv == incercare_cvv;
		}
		void logare(vector < Persoana > & persoane);
		friend ostream & operator << (ostream & out,
			const Card_Bancar & c);
		friend istream & operator >> (istream & in, Card_Bancar & c);
};

ostream & operator << (ostream & out,
	const Card_Bancar & c) {
	out << c.nr_card << ' ' << c.titular << ' ' << c.cvv << ' ' << c.pin << ' ' << endl;
	return out;
}

istream & operator >> (istream & in, Card_Bancar & c) {
	in >> c.nr_card >> c.titular >> c.cvv >> c.pin;
	return in;
}

class Cont_Bancar {
private: Persoana * destinatar;
		 string IBAN;
		 string parola;
		 int sold;
		 Card_Bancar card;
public: Cont_Bancar(Persoana * deti, string IBAN = "", string parola = "", int sold = 0, Card_Bancar card = Card_Bancar()) {
	destinatar = deti;
	this->IBAN = IBAN;
	this->parola = parola;
	this->sold = sold;
	this->card = card;
}
		Cont_Bancar(string IBAN = "", string parola = "", int sold = 0) {
			destinatar = nullptr;
			this->IBAN = IBAN;
			this->parola = parola;
			this->sold = sold;
			this->card = card;
		}

		void set_card(Card_Bancar card) {
			this->card = card;
		}
		void set_IBAN(string IBAN) {
			this->IBAN = IBAN;
		}
		void set_parola(string parola) {
			this->parola = parola;
		}
		void set_sold(int sold) {
			this->sold = sold;
		}

		string & get_parola() {
			return parola;
		}
		string & get_IBAN() {
			return IBAN;
		}
		int & get_sold() {
			return sold;
		}
		Card_Bancar & get_card() {
			return card;
		}
		bool check_parola(string incercare_parola) {
			if (incercare_parola.length() == parola.length()) {
				if (incercare_parola == parola)
					return 1;
			}
			return 0;
		}
		void logare(vector < Persoana > & persoane);
		friend ostream & operator << (ostream & out,
			const Cont_Bancar & c);
		friend istream & operator >> (istream & in, Cont_Bancar & c);

};

ostream & operator << (ostream & out,
	const Cont_Bancar & c) {
	out << c.IBAN << ' ' << c.parola << ' ' << c.sold << ' ' << c.card << ' ';

	return out;
}

istream & operator >> (istream & in, Cont_Bancar & c) {
	in >> c.IBAN >> c.parola >> c.sold >> c.card;
	return in;
}

class Persoana {
private: string nume;
		 string login;
		 string prenume;
		 unsigned short int an_nastere;
		 Cont_Bancar cont;
public:

	Persoana(string login = "", string nume = "", string prenume = "", unsigned short int an_nastere = 1900, Cont_Bancar cont = Cont_Bancar()) {
		this->nume = nume;
		this->prenume = prenume;
		this->an_nastere = an_nastere;
		this->cont = cont;
		this->login = login;
	}

	void set_cont(Cont_Bancar cont) {
		this->cont = cont;
	}
	void set_nume(string nume) {
		this->nume = nume;
	}
	void set_prenume(string prenume) {
		this->prenume = prenume;
	}
	void set_an_nastere(unsigned short int an_nastere) {
		this->an_nastere = an_nastere;
	}

	string & get_login() {
		return this->login;
	}
	string & get_nume() {
		return this->nume;
	}
	string & get_prenume() {
		return this->prenume;
	}
	unsigned short int & get_an_nastere() {
		return this->an_nastere;
	}
	Cont_Bancar & get_cont() {
		return this->cont;
	}

	Persoana & operator = (Persoana & p) {
		this->login = p.login;
		this->nume = p.nume;
		this->prenume = p.prenume;
		this->an_nastere = p.an_nastere;
		this->cont = p.cont;
		return *this;
	}
	void logare(vector < Persoana > & persoane);
	friend ostream & operator << (ostream & out,
		const Persoana & c);
	friend istream & operator >> (istream & in, Persoana & c);
};

ostream & operator << (ostream & out,const Persoana & p) {
	out << p.login << ' ' << p.nume << ' ' << p.prenume << ' ' << p.an_nastere << ' ' << p.cont << ' ';
	return out;
}

istream & operator >> (istream & in, Persoana & p) {
	in >> p.login >> p.nume >> p.prenume >> p.an_nastere >> p.cont;
	return in;
}

Persoana inregistreaza_persoana() {
	string prenume, nume, parola, parola1, login;
	unsigned short int anul_nasterii;
	system("CLS");
	cout << "Pentru va inregistra la aceasta Banca trebuie sa introduceti urmatoarele date:\n";

	cout << "Prenume:" << endl;
	cin >> prenume;

	cout << "Nume" << endl;
	cin >> nume;

	cout << "Login" << endl;
	cin >> login;

	cout << "Anul Nasterii:" << endl;
	cin >> anul_nasterii;
	system("CLS");

	Persoana p(login, nume, prenume, anul_nasterii);
	cout << "Persoana a fost inregistrata cu succes" << endl;
	getch();
	system("CLS");
	cout << "Urmatorul pas este crearea contului:" << endl;
	cout << "Introduceti o parola:" << endl;
	cin >> parola;
	cout << "Confirmati parola:" << endl;
	cin >> parola1;
	while (parola != parola1) {
		cout << endl << "Parole diferie, mai incercati o data" << endl;
		cout << "Introduceti o parola:" << endl;
		cin >> parola;
		cout << "Confirmati parola:" << endl;
		cin >> parola1;
	}
	system("CLS");
	Cont_Bancar cont(generare_IBAN(nume, prenume, anul_nasterii), parola, 0);

	cout << "Cont Inregistrat cu Succes";
	p.set_cont(cont);
	return p;

}

void logare(vector < Persoana > & persoane) {
	string login, parola;
	cout << "Introduceti Login: ";
	cin >> login;
	cout << "Introduceti Parola: ";
	cin >> parola;

	for (Persoana & p : persoane) {
		if (p.get_login() == login) {
			if (p.get_cont().check_parola(parola)) {
				// User logged in successfully
				system("CLS");
				cout << "Ati intrat in cont " << p.get_nume() << ' ' << p.get_prenume() << endl;
				cout << "Soldurile actuale:" << endl;
				cout << "1. " << p.get_cont().get_IBAN() << ' ' << p.get_cont().get_sold() << endl;

				int option;
				cout << "Doriti sa faceti operatii pe acest cont (1 - da, 0 - nu): ";
				cin >> option;

				if (option == 1) {
					system("CLS");
					int operation, amount;
					cout << "1. Retragere numerar" << endl;
					cout << "2. Alimentare cont" << endl;
					cout << "3. Doneaza toti banii bancii" << endl;
					cout << "0. Revina la ecranul principal" << endl;
					cin >> operation;

					switch (operation) {
					case 1:
						cout << "Introduceti suma pentru retragere: ";
						cin >> amount;
						if (amount <= p.get_cont().get_sold()) {
							p.get_cont().set_sold(p.get_cont().get_sold() - amount);
							cout << "Suma retrasa cu succes." << endl;
						}
						else {
							cout << "Sold insuficient pentru retragere." << endl;
						}
						break;
					case 2:
						cout << "Introduceti suma pentru alimentare: ";
						cin >> amount;
						p.get_cont().set_sold(p.get_cont().get_sold() + amount);
						cout << "Cont alimentat cu succes." << endl;
						break;
					case 3:
						p.get_cont().set_sold(0);
						cout << "Toate fondurile au fost donate bancii." << endl;
						break;
					case 0:
						break;
					default:
						cout << "Optiune invalida." << endl;
						break;
					}
				}
			}
			else {
				cout << "Parola incorecta." << endl;
			}
			return; // Exit the function after processing the user's account
		}
	}

	cout << "Utilizatorul nu exista sau parola este incorecta." << endl;
}

void init(vector < Persoana > & pers) {
	ifstream fin("database");
	Persoana p;
	int nr;
	fin >> nr;
	for (int i = 0; i < nr; i++) {
		fin >> p;
		pers.push_back(p);
	}
	fin.close();

}

void dez_init(vector < Persoana > & pers) {
	ofstream fout("database");
	fout << pers.size() << endl;
	for (Persoana p : pers) {
		fout << p;
		fout << endl;
	}
	fout.close();
}

void tranzactie(vector < Persoana > & persoane) {
	string login, parola, login_destinatar;
	int sum = -1;
	cout << "Introduceti Login: ";
	cin >> login;
	cout << "Introduceti Parola: ";
	cin >> parola;

	for (Persoana & p : persoane) {
		if (p.get_login() == login) {
			if (p.get_cont().check_parola(parola)) {

				cout << "Introduceti loginul destinatarului: ";
				cin >> login_destinatar;
				while (sum <= 0) {
					cout << "Introduceti suma pe care doriti sa o transferati:";
					cin >> sum;
				}
				for (Persoana & destinatar : persoane) {
					if (destinatar.get_login() == login_destinatar) {
						p.get_cont().set_sold(p.get_cont().get_sold() - sum);
						destinatar.get_cont().set_sold(destinatar.get_cont().get_sold() + sum);
						cout << "Suma a fost transferata cu succes";
						getch();
						break;
					}
				}

			}
		}
	}

}
void emite_card(vector < Persoana > & persoane) {
	string login, parola;
	cout << "Introduceti Login: ";
	cin >> login;
	cout << "Introduceti Parola: ";
	cin >> parola;

	for (Persoana & p : persoane) {
		if (p.get_login() == login) {
			if (p.get_cont().check_parola(parola)) {
				int nr_card, cvv, pin;
				cout << "Introduceti numarul dorit pentru nrCardului" << endl;
				cin >> nr_card;
				p.get_cont().get_card().set_nr_card(nr_card);
				cout << "Introduceti PINUL dorit" << endl;
				cin >> pin;
				p.get_cont().get_card().set_pin(pin);
				cout << "Introduceti CVV dorit" << endl;
				cin >> cvv;
				p.get_cont().get_card().set_cvv(cvv);
				cout << "Cardul a fost adaugat cu succes";
			}
		}
	}
}

int main() {
	vector < Persoana > persoane;
	init(persoane);
	bool flag = 1;
	while (flag) {
		char optiune = '\0';
		system("CLS");
		cout << "1.Inregistrati Cont nou la banca\n";
		cout << "2.Intrati in Contul Bancar\n";
		cout << "3.Evectuati o Tranzactie\n";
		cout << "4.Emiteti un card sau schimbatil pe cel vechi\n";
		cout << "0. Iesire" << endl;
		cin >> optiune;
		switch (optiune) {
		case '1': {
			Persoana p = inregistreaza_persoana();
			persoane.push_back(p);
		}

				  break;
		case '2': {
			logare(persoane);
		}
				  break;
		case '3': {
			tranzactie(persoane);

		}
				  break;
		case '4': {
			emite_card(persoane);
		}
				  break;
		case '0': {
			flag = 0;
			break;
		}

		}
	}
	dez_init(persoane);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
