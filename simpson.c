#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Evalua la integral con la Regla de Simpson

double c;

double simpson(double (*fun)(double), double a, double b ){
	
	c = (a + b) /2;
	
	return ((b - a)/6)*  ((*fun)(a) + 4*(*fun)(c) + (*fun)(b));
	
	
}
