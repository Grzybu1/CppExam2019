#include <iostream>
using namespace std;
struct Abstrakcyjna {
	Abstrakcyjna()
	{	pisz();	}
	virtual void pisz() = 0;
	virtual void piszInaczej() = 0;
};

void Abstrakcyjna::pisz()
{	cout << "jednak sie da wywolac funkcje czysto wirtualna" << endl;	}
void Abstrakcyjna::piszInaczej()
{	cout << "Nawet na dwa rozne sposoby" << endl;	}

struct Pochodna:Abstrakcyjna
{
	void pisz()
	{
		cout << "Nic nie robie ale trzeba przeslonic funkcje czysto wirtualna zeby stworzyc obiekt";
	}
	void piszInaczej() {}
};

int main() 
{
	Pochodna a;
	a.Abstrakcyjna::piszInaczej();
}
/*Wynik:
*	jednak sie da wywolac funkcje czysto wirtualna
*	Nawet na dwa rozne sposoby
*/