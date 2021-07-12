#pragma once
#include "UI.h"


	UI::UI() {
	}
	UI::~UI(){
	}

	void UI::printTaxi(Taxi *t) {
		std::cout << "----------------------" << std::endl;
		std::cout << t->toString() << std::endl;
		std::cout << "----------------------" << std::endl;
		std::cout << std::endl;
	}

	int UI::auswahlTaxi() {
		int auswahl;
		std::cout << "****************************" << std::endl << "Bitte waehlen Sie ein Taxi: "
			<< std::endl << "  [1] Taxi 1"
			<< std::endl << "  [2] Taxi 2"
			<< std::endl << "[0] Quit" << std::endl;
		std::cout << "Taxi: "; 
		std::cin >> auswahl;
		if(auswahl != 1 && auswahl != 2 && auswahl != 0){
			std::fflush;
			std::cout << "Fehler. Bitte erneut Taxi auswaehlen." << std::endl;
			auswahlTaxi();
		}
		else {
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			return auswahl;
		}
	}

	int UI::auswahlAktion(Taxi *t) {
		int auswahl;
		std::cout << "Sie haben Taxi " << t->getMID() << " gewaehlt." << std::endl;
		std::cout << "Bitte waehlen Sie eine Aktion: "
			<< std::endl << "  [1] Buche Fahrt mit Gaesten."
			<< std::endl << "  [2] Buche Fahrt ohne Gaeste."
			<< std::endl << "  [3] Auftanken."
			<< std::endl << "  [4] Taxi-Status ausgeben."
			<< std::endl << "[0] zueruck" << std::endl;
		std::cout << "Aktion: ";
		std::cin >> auswahl;
		if (auswahl != 1 && auswahl != 2 && auswahl != 3 && auswahl != 4 && auswahl != 0) {
			std::cout << "Fehler. Bitte erneut Aktion auswaehlen." << std::endl;
			auswahlAktion(t);
		}
		else {
			switch (auswahl) {
			case 1:		std::cout << "Bitte waehlen Sie die Distanz: "; std::cin >> auswahl; t->bookTrip(auswahl, true);
				break;
			case 2:		std::cout << "Bitte waehlen Sie die Distanz: "; std::cin >> auswahl; t->bookTrip(auswahl, false);
				break;
			case 3:		std::cout << "Bitte geben Sie den Spritpreis pro Liter an: "; std::cin >> auswahl; t->fillUp(auswahl / 100);
				break;
			case 4:		printTaxi(t);
				break;
			case 0:		return 0;
				break;
			default:	std::cout << "Fehler. Erneut Aktion waehlen." << std::endl;
				auswahlAktion(t);
			}
		}
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
