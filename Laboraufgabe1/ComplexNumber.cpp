#include "ComplexNumber.h"

	//relevante Update-Funktion nach jeder Änderung. Nach Bedarf anpassen
	void ComplexNumber::update() {
			m_length = sqrt(pow(m_x, 2) + pow(m_y, 2));
			m_phi = getPhi();
	}

	//constructor
	ComplexNumber::ComplexNumber(double x=1, double y=1) {
			m_x = x;
			m_y = y;
			m_length;
			m_phi;
			ComplexNumber::update();
	}

	ComplexNumber::ComplexNumber() {
	}

	ComplexNumber::~ComplexNumber() {
	}

	//getter and setter
	void ComplexNumber::set(double x, double y) {
			m_x = x;
			m_y = y;
			ComplexNumber::update();
	}
	void ComplexNumber::setX(double x) {
			m_x = x;
			ComplexNumber::update();
	}
	void ComplexNumber::setY(double y) {
			m_y = y;
			ComplexNumber::update();
	}

	double ComplexNumber::getX() {
			return m_x;
	}
	double ComplexNumber::getY() {
			return m_y;
	}
	double ComplexNumber::getLength() {
			return m_length;
	}
	double ComplexNumber::getPhi() {
			m_phi = std::atan2(m_y, m_x) / (pi);
			m_phi = (float)(fmod(2+m_phi, 2));
		return m_phi;
	}

	std::string ComplexNumber::toString() {
		std::ostringstream output;
		output << m_x << ::std::showpos << m_y << "i";
		return output.str();
	}
	std::string ComplexNumber::toPolarString() {
		std::ostringstream output;
		output << m_length << "*(cos(" << m_phi << "pi) + i*sin(" << m_phi << "pi)";
		return output.str();
	}

	std::string ComplexNumber::toEulerString() {
		std::ostringstream output;
		output << m_length << "*e^(i*" << m_phi << "pi)";
		return output.str();
	}

	//rechnen mit ComplexNumber
	ComplexNumber ComplexNumber::add(ComplexNumber z1, ComplexNumber z2) {
			double x = z1.getX() + z2.getX();
			double y = z1.getY() + z2.getY();
			ComplexNumber z3(x, y);
		return z3;
	}
