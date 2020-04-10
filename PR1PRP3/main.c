/*
Programmieren 1 - Praktikum 3
Aufgabe 3.1
Autoren: Florian Tietjen und Eric Antosch
Beschreibung: Dieses Programm approximiert den Wert einer Wurzel einer reellen Zahl durch eine Folge.
Die Genauigkeit und die reelle Zahl müssen vom Nutzer eingeben werden.
*/
//Includes
#include<stdio.h>

double floatPointCalc(int i) {
	double result = 1;
	for (int t = 0; t < i; t++) {
		result *= 0.1;
	}
	return result;
}

double square(double radical, int i) { // Call-By-Value
	double previousN = 0;	// Deklaration der Variablen für das Abbrechen der Schleife und des Ergebnisses
	double x_n = 1; 
	double diff = floatPointCalc(i);
	int n = 0;
	while (1 == 1) {
		previousN = x_n;
		x_n = 0.5 * (x_n + (radical / x_n)); // Formel aus der Aufgabe
		if (n >= i && (x_n - previousN) < diff) { //Abbruchbedingung
			break;
		}
		n++;
	}
	return x_n;
}



int main(void) {

	double rad; // Deklaration der Variablen für den Input durch den User
	int i;
	printf("Bitte Zahl eingeben, deren Wurzel berechnet werden soll!\n");
	scanf_s("%lf", &rad);
	printf("Bitte Anzahl der g%cltigen Stellen hinter dem Komma eingeben!\n", 129);
	scanf_s("%d", &i);
	printf("%.*lf", i, square(rad, i)); //Aufruf der Funktion square. %.*lf bestimmt durch die Variable i die Menge an Nachkommastellen und damit die Genauigkeit  
	getch();
	return 0;

}