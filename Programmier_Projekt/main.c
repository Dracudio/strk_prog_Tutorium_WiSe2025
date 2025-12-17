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
	int AP;			// 10
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
// Programmieraufgabe:
//
// Es ist die Hilfsfunktion "zahlEingabeZwischen" zu implementieren, wo ein Benutzer so oft zu einer Zahleneingabe aufgefordert wird, 
// bis er eine Zahl innerhalb eines vorgegebenen Bereichs eingibt.
//
// Der min und max Wert soll als Parameter übergeben werden.
// Ebenso soll ein Prameter Übergeben werden dem den Benutzer vor Eingabe mitteilt, wofür die Zahl eingeben wird.
//
// Bei einer ungültigen Eingabe soll eine Fehlermeldung ausgegeben werden und der Benutzer erneut zur Eingabe aufgefordert werden.
//
// Hinweis: andere Hilfsfunktionen aus dem Programm dürfen verwendet werden.
//

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
			printf("  [%d] %s (Angriffstyp: %d, Staerke: %d, Genauigkeit: %d%%)\n", i, s.aktionen[i].name, s.aktionen[i].Aktionstyp, s.aktionen[i].staerke, s.aktionen[i].genauigkeit);
		}
		else {
			printf("  [%d] -- leer --\n", i);
		}
	}
}
void zeigeStudimons() {
	printf("Verfuegbare Studimons:\n");
	printf("[0] Prototyp\n");
}
int getStudimonAnzahl() {
	return 1; // Derzeit nur 1 Studimon implementiert
}
void zeigeMenue() {

	printf("Willkommen in Studimon 3000\n");
	printf("****************************\n");
	printf("[0] Spiel starten\n");
	printf("[1] Spielkonfigurationen\n");
	printf("[2] Beenden\n");
}

// Studimon-Erstellungen
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
	prototyp.aktionen[0].AP = 10;
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

// Funktionen
void angriff(int* hp, int staerke, int verteidigung, int kritschance) {

	// Hier muss noch die Genauigkeitsprüfung eingebaut werden

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
			printf("[0] Anzahl der Studimons aendern\n");
			printf("[1] Studimons im Team aendern\n");
			printf("[2] Studimons anschauen\n");
			printf("[3] Zurueck zum Hauptmenue\n");
			auswahl = zahlEingabe();

			// Programmieraufgabe:
			// 
			// Implementiere die Menüoptionen für die Spielkonfigurationen.
			// Verwende zur Realisierung die Hilfsfunktionen die bereits im Programm vorhanden sind, sowie Variabeln die im Hauptprogramm bereits definiert sind.
			// 
			// Aktuelle Hilfsfunktionen: 
			// - zahlEingabe() gibt eine Zahleneingabe des Benutzers zurück
			// - zahlEingabeZwischen(nachricht, min, max) gibt eine Zahleneingabe des Benutzers zurück, die zwischen min und max liegt mit einer auffordernde Nachricht
			// - StudimonAusgabe(Studimon) gibt die Werte eines Studimons aus
			// - zeigeStudimons() zeigt alle Studimons in einer Liste an, die es gibt
			// - getStudimonAnzahl() gibt die Anzahl der aktuell implementierten Studimons zurück
			// - erstelle_Prototyp() erstellt und gibt das Studimon "Prototyp" zurück
			// 
			// Aktuelle Variablen im Hauptprogramm:
			// - AnzahlStudimons: Anzahl der Studimons pro Spieler die im Kampf verwendet werden (max. 6)
			// - spieler1[6], spieler2[6]: Arrays, die die Studimons der beiden Spieler speichert
			// 
			// Hinweis: Es gibt derzeit nur ein Studimon, den "Prototyp".
			//

		}
	} while (auswahl != 2);
	return 0;
}