/*
Spielprinzip von Studimon 3000:
2 Spieler mit Studimons kämpfen gegeneinander.

Menü:
- Spiel starten
	* Kampfausgabe
	* Kampfaktionen + Studimon wechseln
	* Studimon wechseln falls KO durch Kampfaktion
	* Spieler wechseln
- Spielkonfigurationen
	* Art der Studimons für jeden Spieler auswählen
	* Anzahl der Studimons pro Spieler festlegen
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
#include <stdlib.h>   // rand, srand
#include <time.h>     // time

typedef enum Typ
{

} Typ;

typedef struct Aktion {
	char name[30];
	int staerke;	// 45
	int Aktionstyp; // 0: angriff, 1: sp.angriff, 2: Buff/Debuff
	int genauigkeit;// 90
} Aktion;

typedef struct Studimon {
	char name[30];
	int hp;				// 100
	int verteidigung;	// 10
	int spverteidigung;	// 10
	int agilitaet;		// 20
	int kritschance;	// 10
	Typ typ;
	Aktion aktionen[4];
} Studimon;

void angriff(int* hp, int staerke, int verteidigung, int kritschance) {

	int schaden = staerke - verteidigung;

	if (schaden < 0) {
		schaden = 0;
	}

	if ((rand() % 100) < kritschance) {
		schaden *= 2;
		printf("Kritischer Treffer!\n");
	}

	*hp -= schaden;
	if (*hp < 0) {
		*hp = 0;
	}
}

void zeigeMenue() {

	printf("Willkommen in Studimon 3000\n");
	printf("****************************\n");
	printf("[0] Spiel starten\n");
	printf("[1] Spielkonfigurationen\n");
	printf("[2] Beenden\n");
	printf("-> ");
}

int main() {

	srand(time(NULL));   // Seed setzen (SEHR wichtig!)
	int AnzahlStudimons = 3;

	int auswahl;				// Variable für Auswahloptionen

	do {
		zeigeMenue();

		scanf_s("%d", &auswahl);
		printf("\n");

		switch (auswahl) {
		case 0:
			// Das Spiel
			printf("Spiel wird gestartet...\n");
			break;
		case 1:
			// Spielkonfigurationen
			printf("Was möchtest du ändern?\n");
			printf("[0] Studimons im Team ändern\n");
			printf("[1] Anzahl der Studimons ändern\n");
			printf("[2] Zurück zum Hauptmenü\n");
			printf("-> "), scanf_s("%d", &auswahl);

			switch (auswahl) {
			case 0:
				printf("Studimons im Team ändern...\n");
				// Programmieraufgabe:
				// Zu entwickeln ist eine Funktion erstelle_<StudimonName> die ein vollständiges Studimon erstellt, initialisiert und zurückgibt.
				// Hier könnte ihr krativ sein und euch eigene Studimons ausdenken sowie ihre Werte und Aktionen.
				// Es muss mindestens eine Aktion geben, die das Studimon im Kampf einsetzen kann.
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