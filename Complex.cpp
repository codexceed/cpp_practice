#include<iostream>
#include<string>
using namespace std;

class Complex{
	private:
		int real, imag;
	public:
		Complex(){real = 0; imag = 0;}
		Complex(int a, int b){ real = a; imag = b;}
		

		

		friend ostream &operator<<(ostream &output, const Complex &c){
			output<<c.real<<"+i"<<c.imag;
			return output;
		}
		
		
		friend Complex operator+(const Complex &c1, const Complex &c2){
			return Complex(c1.real + c2.real,c1.imag + c2.imag);
		}
};

