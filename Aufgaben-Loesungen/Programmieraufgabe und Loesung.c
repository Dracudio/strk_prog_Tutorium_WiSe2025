// Programmieraufgabe:
// Zu entwickeln ist eine Funktion "angriff", die den Angriff eines Studimons auf ein anderes darstellt.
//
// Dabei sollen die HP des anzugreifenden Studimons per Referenz übergeben werden.
// Weitere benötigte Werte sollen als Parameter per Wert übergeben werden.
// Der Schaden wird berechnet durch: Stärke - Verteidigung
// 
// Das Studimon soll die Chance haben in der Funktion einen kritischen Treffer zu landen.
// Die Variabel Kirtchance ist ein integer und gibt die Wahrscheinlichkeit in Prozent an (z.B. 20 = 20%).
// Mit dem Code "rand() % 100 + 1" kann eine Zufallszahl zwischen 0 und 99 generiert werden.
// Falls das Studimon einen kritischen Treffer landet, soll der Schaden verdoppelt werden.
// 
// Es soll ebenfalls darauf geachtet werden, dass die HP nicht unter 0 fallen können und es keinen negativen Schaden gibt.

#include <stdio.h>
#include <stdlib.h>   // für rand, srand
#include <time.h>     // für time

// Lösung der Programmieraufgabe
void angriff(int* hp, int staerke, int verteidigung, int kritschance) {

	int schaden = staerke - verteidigung;

	if (schaden < 0) {
		schaden = 0;
	}

	if ((rand() % 100) < kritschance) {
		schaden *= 2;
		printf("Kritischer Treffer!\n"); //optional für die Programmieraufgabe
	}

	*hp -= schaden;
	if (*hp < 0) {
		*hp = 0;
	}
}

// Zum testen der Funktion angriff
int main() {
	int HPa = 100;
	angriff(&HPa, 50, 10, 0); 
	printf("Verbleibende HP ohne Krit: %d\n", HPa);
	int HPb = 100;
	angriff(&HPb, 50, 10, 100);
	printf("Verbleibende HP mit Krit: %d\n", HPb);
	return 0;
}