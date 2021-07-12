#include <iostream>
#include <string>
#include "UI.h"
#include "Taxi.h"

int main() {
		
		UI ui = UI();
		double fuelCost = 1.55;

		Taxi m1 = Taxi(7.2, 0.7, 75);
		ui.printTaxi(&m1);

		Taxi m2 = Taxi(12.5, 0.95, 90);
		ui.printTaxi(&m2);
		/*
		m1.bookTrip(100, true);
		m2.bookTrip(100, true);
		ui.printTaxi(m1);
		ui.printTaxi(m2);
		
		m1.bookTrip(10, false);
		m2.bookTrip(15, false);
		ui.printTaxi(m1);
		ui.printTaxi(m2);
		
		m1.fillUp(fuelCost);
		m2.fillUp(fuelCost);
		ui.printTaxi(m1);
		ui.printTaxi(m2);
		*/

		while(true) {
			switch (ui.auswahlTaxi()) {
				case 1: ui.auswahlAktion(&m1);
					break;
				case 2: ui.auswahlAktion(&m2);
					break;
				case 0: return false;
					break;
				default: std::cout << "Falsche eingabe" << std::endl;
					return true;
			}
			
		}
		ui.printTaxi(&m1);
		ui.printTaxi(&m2);
	return 0;
}
