#pragma once
#include <iostream>
#include <sstream>
#include "ComplexNumber.h"

class UI {
private:
public:
	static void printCartesian(ComplexNumber);
	static void printPolar(ComplexNumber);
	static void printEuler(ComplexNumber);
	static ComplexNumber getComplex();
	static void setComplex(ComplexNumber);
	static void setComplexX(ComplexNumber);
	static void setComplexY(ComplexNumber);
	static ComplexNumber addComplex();
};