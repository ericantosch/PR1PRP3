/*
Programmieren 1 - Praktikum 3
Aufgabe 3.2d
Autoren: Florian Tietjen und Eric Antosch
Beschreibung: Dieses Programm berechnet über die Expotentialreihe den Wert der Zahl e bis sich das Ergebnis nicht weiter
von dem Ergebnis der math.h-Funktion exp(x); unterscheidet dahingehend, dass der Ergebnis nicht weiter ausgerechent werden kann.
*/

#include<stdio.h>
#include<math.h>
#include "euler.h"



//Diese Funktion berechnet den Wert der Zahl e über die Expotentialreihe
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


		if (isnan(resultEuler) != 0) {// Entscheidet ob die nächste Zahl, die auf result addiert werden soll schon außerhalb des Scopes von double ist
			break;
		}
		*i = *i + 1;
		result += resultEuler;
	} while (diff(euler, result) > 0); // Bricht auch ab, wenn das Ergebnis von euler und result 0 ist.
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
			printf("%lf\n", eulNum(euler, &i)); // Ruft die Funktion mit euler als x in e^x auf und mit der Referenz zu i um die Menge an Summanten 
			printf("Die Anzahl der Summanden betr%cgt %d\n", 132, i);
			printf("Um das Programm zu beenden, geben Sie bitte eine %d ein.\n", 0);
			i = 1;
		}
		else
		{
			break;
		}
		
	} while (1 == 1);
	getch();
	return 0;
}