#include "pch.h"
#include "Header.h"
using namespace std;

int random_val() {
	int x;
	srand((int)time(0));
	x = rand() % 1000 + 1;
	return x;

}
void afisare() {
	string line;
	//	int sir[10000];
	ifstream f("carti.txt");

	if (f.is_open())
	{
		while (getline(f, line))

		{

			cout << line << '\n';
		
		}
		f.close();
	}
	else
		cout << "f gresit";

}


void nr_domenii() {
	int n,val;
	ifstream fin("carti.txt");
	fin >> n;
	cout << "In fisier exista " << n << " domenii.";
	cout << "Doriti sa creati domeniu nou? ";
	cout << "Alegeti: \n 1 pentru DA \n 2 pentru NU"<< endl;
	cin >> val;
	if (val == 1)
	{
		string domeniu;
		cout << "Introduceti numele noului domeniu(fara spatii):";
		fstream f("carti2.txt", ios::in | ios::out |ios::trunc);
		fstream g("carti.txt", ios::in | ios::out);

			cin >> domeniu;
			/*getline(cin, domeniu);
			istringstream iss(domeniu);
			vector<string> words;
			string word;
			while (iss >> word)
			{
				words.push_back(word);
			}
				for (auto word : words) {

					g << word << ' ';
				}
			*/

			//g << str << endl;
			n++;
			string line;
			string str;
			str = to_string(n);

			int i = 0;
			if (g.is_open())
			{
				while (getline(g, line))

				{
					if (i == 0) {
						line.replace(0, 1, str);
					}
					f << line << endl;
					cout << line << '\n';
					i++;
				}
				
			}
			f << domeniu << endl;
			g.clear();
			g.seekg(0, ios::beg);
			f.clear();
			f.seekg(0, ios::beg);

			string line2;
		
			
			if (f.is_open())
			{
				while (getline(f, line2))

				{

					g << line2 << endl;

				}
				f.close();
			}

			cout << "Domenii: " << n <<endl;
		

			//afisare();
			g.close();
			f.close();
			remove("carti2.txt");
			alegere();
			meniu();

		}
		else if (val == 2 )
		{
			alegere();
			meniu();
		}
		else
		{
			cout << "Valoare gresita, incercati din nou.";
			nr_domenii();
		}
	

}

bool verificare_domeniu(string dome) {
	fstream f("carti.txt", ios::in | ios::out);

	string line;
	size_t pos;
	int ok = 0;

	if (f.is_open())
	{
		while (getline(f, line))

		{

			if (pos = line.find(dome) != string::npos)
			{
				cout << "Domeniu gasit!" << endl << dome;
				cout << endl;
				//	cout << line << endl;;
				ok = 1;
				break;

			}

		}
		f.close();
	}

	if (ok == 0)
	{
		cout << "Domeniu inexistent!" << endl;
		cout << "Domeniul: " << dome << " nu a fost gasit " << endl;
		cout << "Incercati din nou! /n";
		return 0;
		exit(1);
		
	}
	else
	{
		return 1;

	}

}

string domeniu() {
	string dome;
	cout << "Alegeti domeniul cartii: " << endl;
	cin >> dome;

	if (verificare_domeniu(dome)) {
		return dome;

	}
	else {
		cout << "Reincercati";
		exit(1);
	}
}

	/*
	else
	{

	
		f.clear();
		f.seekg(0, ios::beg);

		if (f.is_open())
		{
			while (getline(f, line))

			{
				g << line;
				if (pos = line.find(dom, 1) != string::npos)
				{
					g << carte;
				}

			}

		}
		else
		{
			cout << "FISIER ERROR!";
		}
		
		g.clear();
		g.seekg(0, ios::beg);
		f.clear();
		f.seekg(0, ios::beg);

		if (g.is_open())
		{
			while (getline(g, line2))

			{

				f << line2 << endl;

			}
		}
		g.close();
		f.close();
		remove("carti2.txt");

	}*/


void adaugare_carte(string str, string autor, string titlu, int cota, int anul_aparitiei, int nr_editie, int imprumut) {

	fstream g("carti.txt", ios::in | ios::out);
	fstream f("carti2.txt",	ios::in|ios::out);

	string line;
	string carte;
	string line2;
	size_t found;



	carte = "carte" + to_string(random_val()) + " \t" + autor + " \t" + titlu + " \t" + to_string(cota) + " \t" + to_string(anul_aparitiei) + " \t" + to_string(nr_editie) + " \t" + to_string(imprumut) + " \n";
	cout << carte;
	if (g.is_open()) {
		while (getline(g, line))
		{
			f << line << endl;

			if (found = line.find(str) != string::npos)
			{
				cout << "FOUND"<<endl;
				f << carte ;
			}
			
		}
		
	}
	else
	{
		cout << "FISIER ERROR"<<endl;
	}

	f.clear();
	g.clear();
	f.seekg(0, ios::beg);
	g.seekg(0, ios::beg);

	if (f.is_open()) {
		while (getline(f, line))
		{
			g << line << endl;

		}
		g.close();
	}
	f.close();
	remove("carti2.txt");
	cout << "Carte adaugata cu succes!" << endl;


}


void get_data() {
	string str = domeniu();
	string aut;
	string tit;
	int cota;
	int an;
	int nr;
	int impr;

	cout  << "Detalii carte:"<<endl;

	cout << "Autor:"; 	cin >> aut;
	cout << "Titlu:";	cin >> tit;
	cout << "Cota:";		cin >> cota;
	cout << "Anul aparitie:"; cin >> an;
	cout << "Numar editie:"; cin >> nr;
	cout << "Cartea este imprumutata? 0 = NU / Data pana la care este imprumutata:";	cin >> impr;
	

	adaugare_carte(str, aut, tit, cota, an, nr, impr);

}

void cautare() {
	fstream g("carti.txt", ios::in);
	string line;
	size_t pos;
	string cuvant;
	int n;
	int ok = 0;
//	string cota1;

	int cota;
	cout << "1 .Cautare carte dupa titlu" << endl;
	cout << "2. Cautare carte dupa autor" << endl;
	cout << "3. Cautare carte dupa cota" << endl;
	
	cin >> n;
	switch (n)
	{
	case 1: 
	{
		cout << "Introduceti autorul: "; cin >> cuvant;
		break;
	}
	case 2: 
	{
		cout << "Introduceti titlul: ";
		cin >> cuvant;
		break;
	}
	case 3: 
	{
		cout << "Introduceti cota: ";
		cin >> cota;
		cuvant = to_string(cota);
		//cota1 = cuvant;
		break;
	}
	default: {
		cout << "Valoare gresita";
		break; 
	}

	}

	if (g.is_open())
	{
		while (getline(g, line))
		{
			if (pos = line.find(cuvant) != string::npos) {
				cout << "Carte/Carti gasita!" << endl;
			//	cout << pos;
				cout << line << endl;
				ok = 1;
			}

		}

	}
	g.close();

	if (ok == 0) {
		cout << "Cartea nu exista!" << endl;
	}

}

void stergere() {
	fstream g("carti2.txt", ios::in | ios::out);
	fstream f("carti.txt", ios::in | ios::out);
	string line;
	int cota,x;
	string str;
	const string del = " \t  \n";
	size_t pos;
	string found;
	cout << "Stergerea se face dupa cota, folositi functia de cautare pentru a afla cota unei carti." << endl;
	cout << "Cunoasteti cota? \n 1. DA \n 2. NU" << endl;
		cin >> x;
		if (x==1)
		{
			cout << "Introduceti cota cartii: " << endl;
			cin >> cota;

		}
		else if(x==2)
		{
			cautare();
			cout << "Introduceti cota cartii: " << endl;
			cin >> cota;

		}
		else
		{
			cout << "Valoare gresita!";
			exit(1);
		}

	
	str = to_string(cota);
	f.clear();
	f.seekg(0, ios::beg);
	if (f.is_open())
	{
		while (getline(f, line))

		{

			if (pos= line.find(str) != string::npos)
			{
				cout << "GASIT" << endl;
				found = line;
			}
			if (found != line) {
				g << line<<endl;
			}
		}
		//cout << line << '\n';

	}
	else
	{
	cout << "f gresit";
	}
	

	f.clear();
	g.clear();
	f.seekg(0, ios::beg);
	g.seekg(0, ios::beg);

	if (g.is_open()) {

		while (getline(g, line))
		{
			f << line << endl;

		}
		f.close();
	}
	f.close();


	remove("carti2.txt");


}

void meniu() {
	int selectie;
	cin >> selectie;

	if (selectie == 1)
	{

		afisare();

		cout << "Fisierul a fost incarcat cu succes! \n";
		cout << "Alegeti urmatoarea varianta: \n";

	alegere();
	meniu();
	}
	if (selectie == 2)
	{
		
		nr_domenii();

	}
	if (selectie == 3)
	{
		get_data();
		//adaugare_carte();
		alegere();
		meniu();
	}
	if (selectie == 4)
	{
		cautare();
		alegere();
		meniu();
	}
	if (selectie == 5)
	{
		stergere();
		alegere();
		meniu();
	}
	if (selectie == 6)
	{
	cout << "Hello 6";
	alegere();
	meniu();

	}
	if (selectie == 7)
	{
		cout << "Hello 7";
		alegere();
		meniu();
	}
	if (selectie == 8)
	{
		cout << "Fisier salvat cu succes";
		alegere();
		meniu();

	}
	if (selectie == 9)
	{
		cout << "La revedere";
		
		
		EXIT_SUCCESS;
	}

}