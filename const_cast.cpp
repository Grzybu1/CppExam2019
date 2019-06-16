#include <iostream>

using std::cout; 
using std::endl;
int main()
{
	int a = 5;
	const int b = 10;
	int * ptr = &a;
	const int* ptr_c = &b;
	ptr = const_cast<int*>(ptr_c);
	*ptr = 13;
	cout << b << endl; //10 chociaz nie jest zdefiniowane w standardzie - wynik zalezy od kompilatora
	cout << *ptr; //13
	return 0;
}