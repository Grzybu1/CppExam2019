#include <iostream>

using std::cout; 
using std::endl;

struct X
{
	int i1;
	int i2;
};
struct Y //agregat
{
	char c;
	X x;
	int i[2];
	float f;
protected:
	static double d; //Mozna bo statyczna
private:
	void g() {}	//Mozna bo to metoda (metody dzialaja jak zmienne statyczne wiec wszystko pasi)
};

class Z//Nie agregat
{
public:
	char c;
	X x;
	int i[2];
protected:
	static double d; //Mozna bo statyczna
private:
	float f; //niestatyczna zmienna prywatna
	void g() {}
};

double Y::d = 5;
double Z::d = 6;
int main()
{
	Y y = { 'a', {10, 20}, {20, 30} };
	//Z z = { 'a', {10, 20}, {20, 30} }; //Error, bo to nie agregat. Wykomentowanie floata naprawi problem

	cout << "c: " << y.c << "\tx.i1: " << y.x.i1 << "\tx.i2: " << y.x.i2
		<< "\ti[0]: " << y.i[0] << "\ti[1]: " << y.i[1] << "\tf: " << y.f;
}
/*
*	c: a    x.i1: 10        x.i2: 20        i[0]: 20        i[1]: 30        f: 0
*	f nie zostalo zainicjalizowane listą inicjalizacyjną
*/