#include<stdio.h>
#include<math.h>
#include "euler.h"




double eulNum(double euler, int* i) {
	double result = 1;
	double fac = 1;
	double euler_x = 1;
	double resultEuler = 1;
	do
	{
		fac *= *i;
		euler_x *= euler;
		resultEuler = euler_x / fac;


		if (isnan(resultEuler) != 0) {
			break;
		}
		*i = *i + 1;
		result += resultEuler;
	} while (diff(euler, result) > 0);
	return result;
}
double diff(double euler, double result) {
	return exp(euler) - result;
}

int main(void) {

	double euler;
	int i = 1;
	do {
		printf("Geben Sie bitte eine Zahl ein, von der der Expotentialwert bestimmt werden soll!\n");
		scanf_s("%lf", &euler);
		if (euler != 0) {
			printf("%lf\n", eulNum(euler, &i));
			printf("Die Anzahl der Summanden betr%cgt %d\n", 132, i);
			printf("Um das Programm zu beenden, geben Sie bitte eine %d ein.\n", 0);
			i = 1;
		}
		else
		{
			break;
		}
		
	} while (1 == 1);
	return 0;
}