#include "ComplexNumber.h"
#include "UI.h"

int main() {
	ComplexNumber z1(1, 1), z2(-1, 1), z3(-1,-1), z4(1,-1);
	UI::printEuler(z1);
	UI::printPolar(z2);
	UI::printEuler(z3);
	UI::printEuler(z4);
	ComplexNumber z5(0, 5);
	UI::printEuler(z5);

	
	ComplexNumber z6 = UI::getComplex();
	UI::printPolar(z6);
	UI::printEuler(z6);

	z6.setX(37);
	UI::printCartesian(z6);
	UI::printEuler(z6);
	ComplexNumber z7 = UI::addComplex();
	UI::printEuler(z7);

	UI::setComplex(z5);
	UI::printCartesian(z5);

	return 0;
}
