
#include "pch.h"
#include "Header.h"

using namespace std;

class Domeniu
{
public:
	string dom;

public:
	void set_dom(string d)
	{
		dom = d;

	};

	string get_dom() {
		return dom;
	};

	void domenii() {
		//	int sir[10000];
		ifstream f("carti.txt");
		const char delim = ',';
		string d;
	//	if (f.is_open())
			getline(f, d, delim);
			cout << d;
	};

};

	int main()
	{
		ifstream f("carti.txt");
		//ofstream g("carti.txt");
		alegere();
		meniu();



		f.close();
		return 0;
	}
