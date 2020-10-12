#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Cuadratura de Gauss N=3 

double r1 =	0.7745966692, r2 = 0.0		  , r3 = -0.7745966692;
double c1 = 0.5555555556, c2 = 0.888888886, c3 =  0.5555555556;
double x1, x2, x3;


double CuadraturaGaussN3( double a, double b, double (*fun)(double) ){
	
	x1 = 0.5* ( (b-a)*r1 + a + b );
	x2 = 0.5* ( (b-a)*r2 + a + b );
	x3 = 0.5* ( (b-a)*r3 + a + b );
	
	return c1*(*fun)(x1) + c2*(*fun)(x2) + c3*(*fun)(x3) ;	
	
}


