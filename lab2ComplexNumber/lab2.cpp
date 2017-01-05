/* Created by:
 *	Reydavid Palomares, Joseph Phan
 *	Lab 2: 9:15AM
 */

#include<iostream>
using namespace std;

class Complex {
	private:
		double a; // real
		double b; // imaginary
	public:
	Complex(){ // default constructor
		a=0;
		b=0;
	}
	Complex(double x, double y){	
		a=x;
		b=y;
	}	
	double Re() { return a;	}	//returns real number
	double Im() { return b; }	//returns imaginary number
	void setRe(double x){a=x;}	//set real number
	void setIm(double x){b=x;}	//set imaginary number
	Complex operator+ (const Complex& rhs) {
		Complex c(0,0);
		c.a = this->a + rhs.a;
		c.b = this->b + rhs.b;
		return c;
	}
	Complex operator* (const Complex& rhs){
		Complex c;
		c.a = (this->a * rhs.a - this->b * rhs.b);
		c.b = (this->a * rhs.b + this->b * rhs.a);
		return c;
	}
	friend ostream &operator<< (ostream &output, const Complex& rhs){
		output<< rhs.a<< " + " << rhs.b<<"i";
		return output;
	}
	friend istream  &operator>> (istream &input, Complex& rhs){
		input >> rhs.a >> rhs.b;
		return input;
	}
};

int main(){
	Complex c1;
	cout<<"insert real then imaginary \n";
	cin>>c1;	
	cout<< "\nCompex Number" << c1.Re() << " + " << c1.Im() << "i\n";
	cout<<c1<< "\n";
	Complex c2(1.0,2.0);
	c1 = c1 + c2;
	cout<<c1<<"\n";
	c1.setRe(5);
	c1.setIm(7);
	cout<<c1<<"\n";
	c1 = c1 * c2;
	cout<<c1<<"\n";	
	
	return 0;
}
