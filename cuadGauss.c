#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Cuadratura de Guauss N=2 . Respecto a la funcion y = pow(x,6) - pow(x,2)*sin(2*x) en [1, 3] 
// Ejemplo 2 pag 185 Burden
// Pregunta 2 Proyecto, se procede a implementar la Cuadratura Gaussiana para aproximar la integral
// del ejemplo del libro. Se puede observar que los resultados son exitosos

//Algoritmo: 1. Se aplica transformación en la integral, para que su dominio esté en [-1, 1]
//			 2. Se evalua la fórmula de integración general.

double t1 = 1/sqrt(3), t2 = -1/sqrt(3), x1, x2;

double cuadGauss( double a, double b, double (*fun)(double) ){
	
	x1 = 0.5* ( (b-a)*t1 + a + b );
	x2 = 0.5* ( (b-a)*t2 + a + b );
	
	return (*fun)(x1) + (*fun)(x2) ;	
	
}


