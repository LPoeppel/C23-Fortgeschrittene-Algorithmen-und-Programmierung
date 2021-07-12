#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
class Taxi {
private:
	double m_currentTankful, m_mileage, m_economy;
	const double m_maxTankful, m_kmCost, m_consumption;
	Taxi *ptrTaxi;
	const int m_ID;
	static int s_ID;
public:
	/*void initialize(double, double, double);*/
	bool bookTrip(double, bool);
	int fillUp(double);
	std::string toString() const;

	//Taxi();
	Taxi(double, double, double);
	~Taxi();

	void setCurrentTankful(double);
	double getCurrentTankful() const;
	void setMileage(double);
	double getMileage() const;
	double getEconomy() const;
	double getMaxTankful() const;
	double getConsumption() const;
	double getKmCost() const;
	int getSID() const;
	int getMID() const;
};
