#include "Taxi.h"
#include "UI.h"

	//old 'constructor' for excersize 1, new ones below
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

int Taxi::s_ID = 0, s_counter = 0;
	
//constructor and destructor
	Taxi::Taxi(double consumption, double kmCost, double maxTankful) : m_consumption(consumption / 100), m_kmCost(kmCost), m_maxTankful(maxTankful), m_ID(s_ID + 1)
	{
		m_mileage = 0;
		m_currentTankful = maxTankful;
		m_economy = 0;
		s_ID++;
		s_counter++;
	}
	
	Taxi::Taxi(const Taxi *m1) : m_consumption(m1->m_consumption), m_kmCost(m1->m_kmCost), m_maxTankful(m1->m_maxTankful), m_ID(s_ID + 1), /*m_name(m1->m_name),*/ m_economy(m1->m_economy) {
		s_ID++;
		s_counter++;
	}
	Taxi::Taxi(const Taxi &m1) : m_consumption(m1.m_consumption), m_kmCost(m1.m_kmCost), m_maxTankful(m1.m_maxTankful), m_ID(s_ID + 1), /*m_name(m1.m_name),*/ m_economy(m1.m_economy) {
		s_ID++;
		s_counter++;
	}
/* removed since instead of a string name, we use the ID
	Taxi::Taxi(double consumption, double kmCost, double maxTankful, std::string name) : m_consumption(consumption / 100), m_kmCost(kmCost), m_maxTankful(maxTankful), m_ID(s_ID + 1), m_economy(0)
	{
		if (name.size() > 8) {
			std::cout << "Name zu lange. Taxi mit bezeichner " << name << " wurde nicht erstellt." << std::endl;
		}
		else if (name.size() <= 8) {
			setName(name);
			m_mileage = 0;
			m_currentTankful = maxTankful;
			s_ID++;
			s_counter++;
		}

	}
*/
	Taxi::Taxi() : m_consumption(0), m_kmCost(0), m_maxTankful(0), m_ID(s_ID + 1),/* m_name(""),*/ m_economy(0)
	{
		m_mileage = 0;
		m_currentTankful = m_maxTankful;
		s_ID++, s_counter++;
	}
	Taxi::~Taxi()
	{
		s_counter--;
	}

//functions/methods
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
	
	std::string Taxi::getState() const {
		std::ostringstream output;
		output << "Taxi_"<< std::setfill('0') << std::setw(4) << m_ID << " >> "
			<< std::setfill(' ') << std::setw(7) << std::setprecision(2) << std::fixed << m_mileage << " km,"
			<< std::setw(7) << m_currentTankful << " l,"
			<< std::setw(8) << ::std::showpos << std::setprecision(2) << std::fixed << m_economy << " Euro";
		return output.str();
	}
	/* old function, new one 'getState()'
	std::string Taxi::toString() const {
		std::ostringstream output;
		output << "Taxi " << m_ID << ":"
			<< "\n >Bezeichner: " << m_name
			<< "\n >Kilometerstand: " << m_mileage << " km"
			<< "\n >Tankinhalt: " << m_currentTankful
			<< " liter\n >Bilanz: " << ::std::showpos << m_economy << " euro";
		return output.str();
	}
	*/

//getter and setter
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
	/*
	void Taxi::setName(std::string name) {		
		m_name = name;
	}
	std::string Taxi::getName() const{
		return m_name;
	}
	*/
	int Taxi::getCounter() const{
		return s_counter;
	}
