/*
Programmieren 1 - Praktikum 3
Aufgabe 3.2a-c
Autoren: Florian Tietjen und Eric Antosch
Beschreibung: Dieses Programm berechnet über die Expotentialreihe den Wert der Zahl e bis die Funktion nach 10 Summanden abbricht.
Der Unterschied zwischen dem Ergebnis und der Zahl e aus der math.h-Funktion exp(x) wird dann dazu noch ausgegeben.
*/
//Includes
#include<stdio.h>
#include<math.h>


//Diese Funktion berechnet den Wert der Zahl e über die Expotentialreihe
double eulNum(double euler) {
	double result = 1;
	double fac = 1;
	double euler_x = 1;
	double resultEuler = 1;
	for (int i = 1; i < 10; i++)
	{	
			fac *= i; // Berechnet die entsprechende Zahl für k! aus der Formel
			euler_x *= euler; // euler_x entspricht der Zahl x^k
			resultEuler = euler_x/fac; // Fügt die Berechnung über einen Bruch zusammen
		
		result += resultEuler; // Addiert das Ergebnis auf
	}
	return result;
}
//Berechnet die Differenz in Prozent
double diff(double euler) {

	double difference = exp(euler) - eulNum(euler);
	return (difference / exp(euler)) * 100;
}

int main(void) {

	double euler;
	do {//Schleife um mehrere Zahl e^x mit x = euler zu berechnen
		printf("Geben Sie bitte eine Zahl ein, von der der Expotentialwert bestimmt werden soll!\n");
		scanf_s("%lf", &euler);
		if (euler != 0) {
			// Aufrufe der Funktionen von oben
			printf("%lf\n", eulNum(euler));
			printf("Der Unterschied zwischen der richtigen und der errechneten Zahl betr%cgt %lf%%\n", 132, diff(euler));
			printf("Um das Programm zu beenden, geben Sie bitte eine %d ein.\n", 0);
		}
		else
		{
			break;// Bricht die Schleife im Fall von x = 0 ab.
		}
	} while (1 == 1); //= While(true)
	getch();
	return 0;
}