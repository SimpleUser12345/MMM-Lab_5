#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
	return (1-cos(x)) / pow(x, 1.5);
}

void simpson(double a, double b, double h)
{
	cout << "Simpson integral" << endl;
	
	double I = 0;
	for(int i = 0; i*h < b-a; i++)
	{
		double x1 = a + i*h;
		double x2 = a + (i+1)*h;
		I += (x2-x1)/6.0 * (f(x1) + 4.0*f(0.5*(x1+x2)) + f(x2));
	}

	cout << "I = " << I << endl;
}


const double M_PI=3.1415926535897932;

double EPS = 0.001;

int main()
{
	/*      
	    Int[0;oo]{(1-cos(x))/(x^1.5)}dx ~= 
			Int[0;b]{(1-cos(x))/(x^1.5)}dx 
			+
			Int[b;oo]{(1-cos(x))/(x^1.5)}dx
		
		1-cos(x) <= 2,  
	    Int[b;oo]{(1-cos(x))/(x^1.5)}dx <= 2*Int[b;oo]{1/(x^1.5)}dx
		
		Int[b;oo]{(1-cos(x))/(x^1.5)}dx = 2/(b^0.5) < EPS
	    
	    b > (2/EPS)^2 = 4 / EPS^2.
	    
	*/
	double a = 1e-6;
	double b = 4 / (EPS*EPS);
	cout << "Calculating with accuracy " << EPS << endl;
	cout << "a = "<< a << ", b = " << b << endl;
	cout << "Please wait..." << endl;
	
	simpson(a, b, 0.1);
}
