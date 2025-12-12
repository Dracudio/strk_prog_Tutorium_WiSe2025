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
#include <stdlib.h>   // für randomizer
#include <time.h>     // seed für randomizer

// Struktur eines Studimons
typedef enum Typ
{
	normal,
} Typ;

typedef struct Aktion {
	char name[30];
	int staerke;	// 45
	int Aktionstyp; // 0: angriff, 1: sp.angriff, 2: Buff/Debuff
	int genauigkeit;// 90
	int isNull;
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
	int isNull;
} Studimon;

// Hilfsfunktionen
int zahlEingabe() {
	int eingabe;
	int ergebnis;

	do {
		printf("-> ");
		ergebnis = scanf_s("%d", &eingabe);
		if (ergebnis != 1) {
			printf("Ungueltige Eingabe! Bitte gib eine Zahl ein.\n");
			while (getchar() != '\n')
				continue;
		}
	} while (ergebnis != 1);

	return eingabe;
}
void StudimonAusgabe(Studimon s) {
	printf("Name: %s\n", s.name);
	printf("HP: %d\n", s.hp);
	printf("Verteidigung: %d\n", s.verteidigung);
	printf("SP-Verteidigung: %d\n", s.spverteidigung);
	printf("Agilitaet: %d\n", s.agilitaet);
	printf("Kritschance: %d%%\n", s.kritschance);
	printf("Aktionen:\n");
	for (int i = 0; i < 4; i++) {
		if (!s.aktionen[i].isNull) {
			printf("  [%d] %s (Staerke: %d, Genauigkeit: %d%%)\n", i, s.aktionen[i].name, s.aktionen[i].staerke, s.aktionen[i].genauigkeit);
		}
	}
}
void zeigeMenue() {

	printf("Willkommen in Studimon 3000\n");
	printf("****************************\n");
	printf("[0] Spiel starten\n");
	printf("[1] Spielkonfigurationen\n");
	printf("[2] Beenden\n");
}

// Funktionen
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
struct Studimon erstelle_Prototyp() {
	Studimon prototyp;
	// Initialisierung der Werte
	strcpy_s(prototyp.name, sizeof(prototyp.name), "Prototyp");
	prototyp.hp = 100;
	prototyp.verteidigung = 10;
	prototyp.spverteidigung = 10;
	prototyp.agilitaet = 20;
	prototyp.kritschance = 10;
	prototyp.typ = normal;
	// Initialisierung der Aktionen
	strcpy_s(prototyp.aktionen[0].name, sizeof(prototyp.aktionen[0].name), "Tackle");
	prototyp.aktionen[0].staerke = 45;
	prototyp.aktionen[0].Aktionstyp = 0;
	prototyp.aktionen[0].genauigkeit = 90;
	prototyp.aktionen[0].isNull = 0;
	// Markiere verbleibende Aktionen als leer
	for (int i = 1; i < 4; i++) {
		prototyp.aktionen[i].isNull = 1;
	}
	prototyp.isNull = 0;
	return prototyp;
}

// Hauptprogramm
int main() {

	// Initialisierungen
	srand(time(NULL));			// Seed setzen für randomizer
	int auswahl;				// Variable für Auswahloptionen
	int AnzahlStudimons = 3;
	Studimon spieler1[6];
	Studimon spieler2[6];

	for (int i = 0; i < 6; i++) {
		// Initialisierung der Studimons
		spieler1[i].isNull = 1;
		for (int j = 0; j < 4; j++) {
			spieler1[i].aktionen[j].isNull = 1;
			spieler2[i].aktionen[j].isNull = 1;
		}
	}

	do {
		zeigeMenue();

		auswahl = zahlEingabe();
		printf("\n");

		switch (auswahl) {
		case 0:
			// Das Spiel
			printf("Spiel wird gestartet...\n");
			break;
		case 1:
			// Spielkonfigurationen
			printf("Was moechtest du aendern?\n");
			printf("[0] Studimons im Team aendern\n");
			printf("[1] Anzahl der Studimons aendern\n");
			printf("[2] Zurück zum Hauptmenü\n");
			auswahl = zahlEingabe();

			switch (auswahl) {
			case 0:
				printf("Studimons im Team aendern...\n");
				spieler1[0] = erstelle_Prototyp();
				StudimonAusgabe(spieler1[0]);
				break;
			case 1:
				do {

				printf("Gib die Anzahl der Studimons pro Spieler ein (1-6): ");
				AnzahlStudimons = zahlEingabe();
				if (AnzahlStudimons < 1 || AnzahlStudimons > 6) {
					printf("Ungueltige Anzahl! Bitte gib eine Zahl zwischen 1 und 6 ein.\n");
				}

				} while (AnzahlStudimons < 1 || AnzahlStudimons > 6);

				break;
			}
		}
	} while (auswahl != 2);
	return 0;
}