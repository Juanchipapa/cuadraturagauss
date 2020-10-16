#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Proyecto 2, al ejecutar se puede verificar todos los resultados.
printf ("Hola perris\n");

double cuadGauss( double a, double b, double (*fun)(double) );
double CuadraturaGaussN3( double a, double b, double (*fun)(double) );
double simpson(double (*fun)(double), double a, double b );
double f(double x);
double g(double x);
double z(double x);
double GaussAdaptativo (double (*fun)(double), double a, double b, double tol, int nivel, double Area );
double SimpsonAdaptable(double (*fun)(double), double a, double b, double tol, int nivel, double Area );


int main() {
	
	double h, j, k;
	printf ("Ejemplo 2, pag 173 Burden vol 10\n Comparaciones evaluando integral de la funcion f = pow(x,6) - pow(x,2)*sin(2*x)\n En intervalo [1,3]\n Sol Real = = 317.3442466\n");
	
	h = cuadGauss(1,3, f);
	printf ("Cuadratura Gauss n=2 \n Aprox_Integral = %f \n", h);
	
	j = CuadraturaGaussN3(1,3, f);
	printf ("Cuadratura Gauss n=3\n Aprox_Integral = %f \n", j);
	
	k = simpson(f,1,3);
	printf ("Simpson\n Aprox_Integral = %f \n", j);
	
	printf ("-------------------------------------------------------- ");
	printf ("\nPrueba Para pregunta 3 de metodos Adaptables\nIlustracion Cuadratura adaptable Pag 167_168 Burden vol 10\n\n");
	printf("Funcion utilizada g = (100/pow(x,2)) * sin(10/x), en [1, 3], Tolerancia 1*e-5 \nSolucion Real = -1.426014\n ");
	
	h = SimpsonAdaptable(g, 1, 3, 0.00001, 1, 0 );
	printf ("\nSimpson, Cuadratura Adaptable Area = %f \n", h);
	
	h = GaussAdaptativo (g, 1, 3, 0.00001, 1, 0 );
	printf ("\nGauss, Cuadratura Adaptable Area = %f \n", h);
	
	printf ("--------------------------------------------------------\n");
	printf ("Pregunta 4, funcion (100/x) * sin(10/x), en [0.5, 3]\nSol analitica =  -29.809\n ");
	
	k = SimpsonAdaptable(g, 0.5, 3, 0.00001, 1, 0 );
	printf ("\nSimpson, Cuadratura Adaptable, tol = 1*e-5 \nResultado = %f \n", k);
	
}


double SimpsonAdaptable(double (*fun)(double), double a, double b, double tol, int nivel, double Area ){
	
	double c , fd , fe , S1, S2, Area1, Area2, absoluto;
	
	c	=	(a + b) /2;
	
	S1	=	simpson(fun, a, b);
	S2	=	simpson(fun, a, c) + simpson(fun, c, b);
	absoluto = S2 - S1;
	
	
	if (fabs(absoluto) <= tol || nivel >=8 ){
		nivel--;
		Area =  Area + S2; 
		return Area;
	}else{
		nivel++;
		Area1 = SimpsonAdaptable(fun, c, b, tol, nivel, Area);
		Area2 = SimpsonAdaptable(fun, a, c, tol, nivel, Area);
		nivel--;
		return Area + Area1 + Area2;
	}
	
}

double GaussAdaptativo (double (*fun)(double), double a, double b, double tol, int nivel, double Area){
	
	double  Area1, Area2, c, S1, S2, absoluto; 
	
	c	= (a + b) / 2;
	S1	= CuadraturaGaussN3(a, b, fun);
	S2	= CuadraturaGaussN3(a, c, fun) + CuadraturaGaussN3(c, b, fun);
	
	absoluto = S2 - S1;		
	
	if (  fabs(absoluto) <= tol || nivel >= 6){
		
		Area = Area + S2 ;
		nivel --;
		return Area;
	}
	else{
		nivel++;
		Area1 = GaussAdaptativo(fun , c, b, tol, nivel, Area);
		Area2 = GaussAdaptativo(fun , a, c, tol, nivel, Area);
		nivel--;
		Area = Area + Area1 + Area2;
		
		return Area;
	}
	
	
}


double f(double x){
   return pow(x,6) - pow(x,2)*sin(2*x);
}

double g(double x){
   return (100/pow(x,2)) * sin(10/x);
}

double z(double x){
   return (100/x) * sin(10/x);
}



