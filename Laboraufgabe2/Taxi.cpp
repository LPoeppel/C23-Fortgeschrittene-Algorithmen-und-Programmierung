#include "Taxi.h"
	
	int Taxi::s_ID = 0;
	/*
	void Taxi::initialize(double consumption, double kmCost, double maxTankful){
		m_consumption = consumption / 100;
		m_kmCost = kmCost;
		m_maxTankful = maxTankful;

		m_mileage = 0;
		m_currentTankful = maxTankful;
		m_economy = 0;
	}
	*/

	bool Taxi::bookTrip(double distance, bool guests) {
		if ((m_consumption * distance) <= m_currentTankful) {
			if (guests) {
				m_currentTankful -= (m_consumption * distance);
				m_mileage += distance;
				m_economy += (distance * m_kmCost);
			}
			else if (!guests) {
				m_currentTankful -= (m_consumption * distance);
				m_mileage += distance;
			}
			return true;
		}
		else {
			std::cout << "Nicht genug Tankinhalt." << std::endl << std::endl;
			return false; 
		}
	}
	int Taxi::fillUp(double fuelCost) {
		if (m_economy <= 0) { return 0; }
		else if(m_currentTankful < m_maxTankful) {
			double fillCost = (m_maxTankful - m_currentTankful) * fuelCost;
			if (fillCost <= m_economy) {
				m_economy -= fillCost;
				m_currentTankful = m_maxTankful;
				return 1;
			}
			else {
				m_economy = 0;
				m_currentTankful += m_economy * fuelCost;
				return 2;
			}
		}
		else { return 1; }
	}
	std::string Taxi::toString() const {
		std::ostringstream output;
		output << "Taxi " << m_ID << ":" << "\n >Kilometerstand: " << m_mileage <<" km\n >Tankinhalt: " << m_currentTankful << " liter\n >Bilanz: " << ::std::showpos << m_economy << " euro";
		return output.str();
	}


	Taxi::Taxi(double consumption, double kmCost, double maxTankful): m_consumption(consumption / 100), m_kmCost(kmCost), m_maxTankful(maxTankful), m_ID(s_ID + 1)
	{
		m_mileage = 0;
		m_currentTankful = maxTankful;
		m_economy = 0;
		s_ID++;
	}

	Taxi::~Taxi()
	{
	}


	void Taxi::setCurrentTankful(double d) {
		m_currentTankful = d;
	}
	double Taxi::getCurrentTankful() const {
		return m_currentTankful;
	}

	void Taxi::setMileage(double d) {
		m_mileage = d;
	}
	double Taxi::getMileage() const {
		return m_mileage;
	}
	double Taxi::getEconomy() const {
		return m_economy;
	}
	double Taxi::getMaxTankful() const {
		return m_maxTankful;
	}
	double Taxi::getConsumption() const {
		return m_consumption;
	}
	double Taxi::getKmCost() const {
		return m_kmCost;
	}
	int Taxi::getSID() const {
		return s_ID;
	}
	int Taxi::getMID() const {
		return m_ID;
	}