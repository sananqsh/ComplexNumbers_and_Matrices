#include <iostream>
#include <string>

using namespace std;

class Complex
{
public:
	Complex() {real = 0; imag = 0;}
	Complex(double _real, double _imag);
	Complex add(const Complex& c2) const;
	Complex difference(const Complex& c2) const;
	double multiply(const Complex& c2) const;
	void print1();
	void print2();
private:
	double real;
	double imag;
};

Complex::Complex(double _real, double _imag) {real = _real;imag = _imag;}

Complex Complex::add(const Complex& c2) const {return Complex(real + c2.real, imag + c2.imag);}

Complex Complex::difference(const Complex& c2) const {return Complex(real - c2.real, imag - c2.imag);}

double Complex::multiply(const Complex& c2) const
{
	double t = real * c2.real + imag * c2.imag;
	return t;
}

void Complex::print1()
{
	cout << real;
	if(imag < 0)
		cout << imag << 'i';
	else
		cout << '+' << imag << 'i';

	cout << endl;
}

void Complex::print2() { cout << '(' << real << ',' << imag << ')'; }

void help();

Complex build_complex();

int main()
{
	cout << "***Complex Numbers Simple Calculator***" << endl;
    int choice;
    Complex a;
	Complex b;

	help();

    while(true)
    {
        cin >> choice;
        switch(choice)
        {
        case 1:
    		a = build_complex();
    		b = build_complex();

    		cout << "a";
    		a.print2();
    		cout << " + ";
    		cout << "b";
    		b.print2();
    		cout << " = ";

            a.add(b).print2();
            cout << endl;
            break;
        case 2:
        	a = build_complex();
        	b = build_complex();

        	cout << "a";
    		a.print2();
    		cout << " - ";
    		cout << "b";
    		b.print2();
    		cout << " = ";

            a.difference(b).print2();
            cout << endl;
            break;
        case 3:
        	a = build_complex();
        	b = build_complex();

			cout << "a";
    		a.print2();
    		cout << " * ";
    		cout << "b";
    		b.print2();
    		cout << " = ";

            cout << a.multiply(b) << endl;
            break;
        case 4:
            help();
            break;
        case 5:
            return 0;
        default:
            cout << "Incorrect choice\n";
            break;
        }
    }

    return 0;
}

void help()
{
	cout << "Options:\n";
    cout<<"\t1-->Add\n";
    cout<<"\t2-->Difference\n";
    cout<<"\t3-->Multiply\n";
    cout<<"\t4-->Help\n";
    cout<<"\t5-->Quit\n";
    cout<<"Enter your choice: ";
}

Complex build_complex()
{
	int r, i;
	cout << "Enter Complex number\n";
	
	cout << "Re: ";
	cin >> r;
	cout << "Im: ";
	cin >> i;

	return Complex(r, i);
}
