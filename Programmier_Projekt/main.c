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

typedef struct Aktion {
	char name[30];
	int staerke;
	int Aktionstyp; // 0 = angriff, 1 = sp.angriff, 2 = Buff, 3 = Debuff
	int genauigkeit;
} Aktion;

typedef struct Studimon {
	char name[30];
	int hp;
	int verteidigung;
	int spverteidigung;
	int agilitaet;
	int kritschance;
} Studimon;

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
			// Programmieraufgabe:
			// Zu entwickeln ist eine Funktion "angriff", die den Angriff eines Studimons auf ein anderes dastellt.
			//
			// Dabei sollen die HP des anzugreifenden Studimons per Referenz übergeben werden.
			// Weitere benötigte Werte sollen als Parameter per Wert übergeben werden.
			// Der Schaden wird berechnet aus: Stärke - Verteidigung
			// 
			// Das Studimon soll die Chance haben in der Funktion einen kritischen Treffer zu landen.
			// Die Variabel Kirtchance ist ein integer und gibt die Wahrscheinlichkeit in Prozent an (z.B. 20 = 20%).
			// Mit dem Code "rand() % 100 + 1" kann eine Zufallszahl zwischen 0 und 99 generiert werden.
			// Falls das Studimon einen kritischen Treffer landet, soll der Schaden verdoppelt werden.
			// 
			// Es soll ebenfalls darauf geachtet werden, dass die HP nicht unter 0 fallen können und es keinen negativen Schaden gibt.
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
				// Zu entwickeln ist eine Funktion Erstelle_<StudimonName> die ein vollständiges Studimon erstellt, initialisiert und zurückgibt.
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
