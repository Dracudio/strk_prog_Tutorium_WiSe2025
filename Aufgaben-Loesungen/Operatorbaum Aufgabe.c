#include <stdio.h>

int main() {

	// Aufagbe 1: Zeichnen Sie den dazugehörigen Operatorbaum.
	// Tipp: && Priorität: 5, || Priorität: 4, > Priorität: 10
	// Aufgabe 2: Zeigen Sie wie der Wert von d ermittelt wird und geben Sie diesen an

	int a = 0, b = 1, c = 1, d;
	d = (a && b-- || ++c > b) ? b : 0;

	printf("Ergebnis: %d\n", d);
	printf("a: %d\nb: %d\nc: %d\n", a, b, c);
	return 0;
}