#include "UI.h"


		void UI::printCartesian(ComplexNumber z1){
				std::cout << "z=" << z1.toString() << std::endl;
		}
		void UI::printPolar(ComplexNumber z1) {
			std::cout << "z=" << z1.toPolarString() << std::endl;
		}
		void UI::printEuler(ComplexNumber z1) {
			std::cout << "z=" << z1.toEulerString() << std::endl;
		}

		 ComplexNumber UI::getComplex() {
			double x, y;
			std::cout << "Eingabe einer neuen komplexen Zahl." << std::endl;
				std::cout << "Bitte Realteil der komplexen Zahl eingeben." << std::endl; 
				std::cin >> x;
				std::cout << "Bitte Imaginaerteil der komplexen Zahl eingeben." << std::endl;
				std::cin >> y;
				ComplexNumber z1(x, y);
				printCartesian(z1);
			return z1;
		}

		 void UI::setComplex(ComplexNumber z1) {
			 double x, y;
			 std::cout << "Aendern von Re(z) und Im(z) von " << z1.toString() << std::endl;
			 std::cout << "Bitte neuen Realteil der komplexen Zahl eingeben." << std::endl;
			 std::cin >> x;
			 std::cout << "Bitte neuen Imaginaerteil der komplexen Zahl eingeben." << std::endl;
			 std::cin >> y;
			 z1.set(x, y);
			 printCartesian(z1);
		 }
		 void UI::setComplexX(ComplexNumber z1) {
			 double x;
			 std::cout << "Aendern von Re(z) von " << z1.toString() << std::endl;
			 std::cout << "Bitte neuen Realteil der komplexen Zahl eingeben." << std::endl;
			 std::cin >> x;
			 z1.setX(x);
			 printCartesian(z1);
		 }
		 void UI::setComplexY(ComplexNumber z1) {
			 double y;
			 std::cout << "Aendern von Im(z) von " << z1.toString() << std::endl;
			 std::cout << "Bitte neuen Imaginaerteil der komplexen Zahl eingeben." << std::endl;
			 std::cin >> y;
			 z1.setY(y);
			 printCartesian(z1);
		 }

		 ComplexNumber UI::addComplex() {
			 std::cout << "Addition zweier komplexen Zahlen." << std::endl;
			 ComplexNumber z1 = getComplex();
			 ComplexNumber z2 = getComplex();
			 ComplexNumber z3 = ComplexNumber::add(z1, z2);
			 std::cout << "Rechnung: " << z1.toString() << " + " << z2.toString() << " = " << z3.toString() << std::endl;
			 return z3;
		 }
