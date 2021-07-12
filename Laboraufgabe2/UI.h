#include <iostream>
#include <sstream>
#include "Taxi.h"
class UI {
private:
public:
	UI();
	~UI();
	static void printTaxi(Taxi*);
	static int auswahlTaxi();
	static int auswahlAktion(Taxi*);
};