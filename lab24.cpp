#include<iostream>
#include<cmath>
#define _USE_MATH_DEFINE
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}
ComplexNumber operator+(double n,const ComplexNumber &c){
	return ComplexNumber(n+c.real,c.imag);
}


ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}
ComplexNumber operator-(double n,const ComplexNumber &c){
	return ComplexNumber(n-c.real,0-c.imag);
}


ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),(imag*c.real+real*c.imag));					
	//ac-bd+(bc+ad)i
}
ComplexNumber operator*(double n,const ComplexNumber &c){
	return ComplexNumber((n*c.real)-(0*c.imag),(0*c.real+n*c.imag));
}


ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber(((real*c.real)+(imag*c.imag))/(pow(c.imag,2)+pow(c.real,2)),((c.real*imag)-(real*c.imag))/(pow(c.imag,2)+pow(c.real,2)));
	//(ac+bd)/pow(c,2)+pow(d,2) + (bc-ad)/pow(c,2)+pow(d,2)
}
ComplexNumber operator/(double n,const ComplexNumber &c){
	return ComplexNumber(((n*c.real)+(0*c.imag))/(pow(c.imag,2)+pow(c.real,2)),((c.real*0)-(n*c.imag))/(pow(c.imag,2)+pow(c.real,2)));
}

bool ComplexNumber::operator==(const ComplexNumber &j){
	return j.real==this->real && j.imag==this->imag;
}
bool operator==(double k,const ComplexNumber &j){
	return k==j.real && j.imag==0;
}

double ComplexNumber::abs(){
	return sqrt(pow(real,2)+pow(imag,2));
}

double ComplexNumber::angle(){
	return atan2(imag,real)*(180/M_PI);
}


ostream&operator<<(ostream &os, const ComplexNumber &c){
	if(c.real==0 && c.imag==0){
	return os<<0;
	}else if(c.real==0){
	return os<<c.imag<<"i";
	}else if(c.imag<0){
	return os<<c.real<<c.imag<<"i";
	}else if(c.imag==0){
	return os<<c.real;
	}else if(0<c.imag){
	return os<<c.real<<"+"<<c.imag<<"i";
	}else if(c.real<0){
	return os<<c.real;
	}else{
	return os<<c.real<<"+"<<c.imag<<"i";
	}
}




int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}



