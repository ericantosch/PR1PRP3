/*
Programmieren 1 - Praktikum 3
Aufgabe 3.1
Autoren: Florian Tietjen und Eric Antosch
Beschreibung: Dieses Programm approximiert den Wert einer Wurzel einer reellen Zahl durch eine Folge.
Die Genauigkeit und die reelle Zahl müssen vom Nutzer eingeben werden.
*/
//Includes
#include<stdio.h>

double square(double radical, int i) { // Call-By-Value
	int n = 0; // Deklaration der Variablen für das Abbrechen der Schleife und des Ergebnisses
	double x_n = 1; 
	do {
		x_n = 0.5 * (x_n + (radical / x_n)); // Formel aus der Aufgabe
		n++;


	} while (n < i); // Abbruchbedingung

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