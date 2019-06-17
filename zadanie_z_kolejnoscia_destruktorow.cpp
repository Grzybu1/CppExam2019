#include <iostream>
#include <typeinfo>


struct A 
{ 
	~A() 
	{ 
		std::cout << "-A\n"; 
	} 
};


template<typename T> struct B : A
{
	T v = T();//c++11 Przeniesc wywolanie konstruktora T do konstruktora struktury albo usunac = T() zupelnie
	B() {}
	B(const B& b) : v(b.v)//c++11 przeniesc liste inicjalizacyjna do ciala konstruktora
	{
		std::cout << "Copy " << typeid(B<T>).name() << "()\n";
	}

	~B() { std::cout << "-" << typeid(B<T>).name() << "()\n"; }

};
/*
Klasa przy konstruowaniu obiektu domyslnym konstruktorem wywola:
kontstruktor A
konstruktor T
ciało funkcji w konstruktora

B<A>
konstruktor A
konstruktor A
ciało konstruktora

B<B<A>>
konstruktor A
konstruktor B<A> //Konstruktor B<A> to dwa konstruktory A. Razem 3 + cialo konstruktora B<A>
cialo konstruktora B<B<A>>
*/


int main()
{
	typedef B<A> B_A;
	using TypeName = B<B_A>;//c++11 zmienic na: typedef B<B_A>;
	
	TypeName a = TypeName{ TypeName() }; //To jest to samo co TypeName a = TypeName() // A to jest to samo co Type
										//c++11 trzeba zmienic na TypeName a; albo TypeName a = TypeName(); 
	TypeName b = a ; //To tworzy obiekt b konstruktorem kopiujacym
	//Destruktory a i b w przeciwnym kierunku do konstruktorów wyżej

}

/*wynik?
cpy B<A>
cpy B<b<A>>
destruktor B<B<A>>
destruktor B<A>
3x destruktor A
destruktor B<B<A>>
destruktor B<A>
3x destruktor A

 */