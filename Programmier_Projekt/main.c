/*
Spielprinzip von Studimon 3000:
2 Spieler mit Studimons kämpfen gegeneinander.

Menü:
- Spiel starten
- Einstellungen
	* Art der Studimons für jeden Spieler (Analysis, Programmier, Schlüsselquali)
	* Anzahl der Studimons pro Spieler
- Beenden

Studimon:
- HP
- MP
- Schaden
- Verteidigung
- Agilität
- Kritschance

*/

#include <stdio.h>

struct Studimon {
	int hp;
	int mp;
	int schaden;
	int verteidigung;
	int agilitaet;
	float kritschance;
};

void zeigeMenue() {

	printf("Willkommen in Studimon 3000\n");
	printf("****************************\n");
	printf("[0] Spiel starten\n");
	printf("[1] Menue\n");
	printf("[2] Beenden\n");
	printf("-> ");
}

int main() {

	int AnzahlStudimons = 3;

	int auswahl;

	do {
		zeigeMenue();

		scanf_s("%d", &auswahl);
		printf("\n");

		switch (auswahl) {
		case 0:
			printf("Spiel wird gestartet...\n");
			break;
		case 1:
			printf("Was möchtest du ändern?\n");
			printf("[0] Studimons im Team ändern\n");
			printf("[1] Anzahl der Studimons ändern\n");
			printf("[2] Zurück zum Hauptmenü\n");
			printf("-> "), scanf_s("%d", &auswahl);

			switch (auswahl) {
			case 0:
				printf("Studimons im Team ändern...\n");
				break;
			case 1:
				do {

				printf("Gib die Anzahl der Studimons pro Spieler ein (1-6): ");
				scanf_s("%d", &AnzahlStudimons);

				if (AnzahlStudimons < 1 || AnzahlStudimons > 6) {
					printf("Ungültige Anzahl! Bitte gib eine Zahl zwischen 1 und 6 ein.\n");
				}

				} while (AnzahlStudimons < 1 || AnzahlStudimons > 6);

				break;
			}
		}
	} while (auswahl != 2);
	return 0;
}