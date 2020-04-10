/*
Programmieren 1 - Praktikum 3
Aufgabe 3.2 - Zusatzaufgabe
Autoren: Florian Tietjen und Eric Antosch
Beschreibung: Dieses Programm simuliert die Verbreitung des Covid19-Viruses anhand einiger Annahme und eines
expotentiellen Modells.
*/

//Includes
#include<math.h>
#include<stdio.h>

//Funktion gibt die Liste der Infizierten mit einer Verdopplung von drei Tagen und einer Verdopplung von zwei Wochen aus
int printList() {
    //Alle drei Tage
    double result = 100000;
    int n = 0;
    double tworesult = 0;
    
    printf("Tag     Infizierte\n");
    do
    {
        result *= cbrt(2); //Expotententielles Wachstum ohne e-Funktion
        n++;
        if (n == 17) {
            tworesult = result;

        }
        printf("%2.0d      %2.0lf\n", n, result);
    } while (result < 600000000);
    printf("Die Menge an Infizierten in den letzten drei Wochen: %.0lf\n", result - tworesult); // Berechnet die Differenz der Infizierten von letzten Tag zu 21 Tagen davor
    //Alle zwei Wochen
    double bresult = 100000;
    int m = 0;
    double twobresult = 0;
   

    printf("Version der Bundesregierung:\n");
    printf("Tag     Infizierte\n");
    do
    {
        bresult *= exp(log(pow(2, pow(14, -1)))); //Expotentielles Wachstum mit e-Funktion
        //bresult *= pow(2, pow(14, -1));
        if (m == 155) {
            twobresult = bresult;
        }
        m++;
        printf("%2.0d%15.0lf\n", m, bresult);
    } while (bresult < 600000000);
    printf("Die Menge der Infizierten in den letzten drei Wochen: %.0lf", bresult - twobresult); // Berechnet die Differenz der Infizierten von letzten Tag zu 21 Tagen davor


    return 0;
}


int main(void) {
    printList();
    getch();
    return 0;
}