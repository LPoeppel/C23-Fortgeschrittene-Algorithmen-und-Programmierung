#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

class Taxi {
private:
	/*std::string m_name;	//eingefuegt, da ein Bezeichner sting gefordert war. Ersetzt durch m_ID unter Verwendung von s_ID. In cpp auskommentiert, aber nicht geloescht*/
	double m_currentTankful, m_mileage, m_economy;
	const double m_maxTankful, m_kmCost, m_consumption;
	const int m_ID;
	static int s_ID, s_Counter;
public:
	//void initialize(double, double, double);
	bool bookTrip(double, bool);
	int fillUp(double);
	//std::string toString() const; ersetzt durch getState()
	std::string getState() const;

	//Taxi();
	Taxi(double, double, double);
	Taxi(const Taxi*);
	Taxi(const Taxi&);
	/*Taxi(double, double, double, std::string); // uerbfluessig da ID statt m_name*/
	Taxi();
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
	/*
	void setName(std::string);
	std::string getName() const;
	*/
	int getCounter() const;
};
