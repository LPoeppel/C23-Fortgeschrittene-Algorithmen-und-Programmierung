#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#define pi atan(1)*4

class ComplexNumber {
	private:
		double m_x, m_y, m_length;
		double m_phi; //phi (in radian)
		void update();
	public:
		//constructor
		ComplexNumber(double, double);
		ComplexNumber();
		~ComplexNumber();
		
		//getter and setter
		void set(double, double);
		void setX(double);
		void setY(double);
		double getX();
		double getY();
		double getLength();
		double getPhi();

		//weitere Funktionen
		std::string toString();
		std::string toPolarString();
		std::string toEulerString();
		static ComplexNumber add(ComplexNumber, ComplexNumber);
};
