#include <iostream>
#include "taxi.h"

void taxi::init(float km, float max_tank_capacity, float consumption, float fare_per_kilometer) {
	this->m_km = km;
	this->m_max_tank_capacity = max_tank_capacity;
	this->m_consumption = consumption;
	this->m_fare_per_kilometer = fare_per_kilometer;

	this->m_current_tank_capacity = this->m_max_tank_capacity;
	this->m_balance = 0.0f;
}

void taxi::drive(float distance, bool guest) {
	if (distance>=0.0f) {
		if (!distance * this->m_consumption > this->m_current_tank_capacity) {
			this->m_km = this->m_km + distance;
			this->m_current_tank_capacity = this->m_current_tank_capacity - distance * this->m_consumption;
			if (guest) {
				this->m_balance = this->m_balance + distance * this->m_fare_per_kilometer;
			}
			std::cout << "Folgende Fahrt wurde durchgef�hrt." << std::endl;
			std::cout << "Gefahrene Kilometer: " << distance << std::endl;
			std::cout << "Genutzter Treibstoff: " << distance * this->m_consumption << std::endl;
			std::cout << "Eingenommenes Geld: " << distance * this->m_fare_per_kilometer << std::endl;
		}
		else {
			std::cout << "F�r die eingegebene Distanz reicht der momentane Tankinhalt nicht mehr aus. Die Fahrt wird nicht begonnen" << std::endl;
		}
	}
	else {
		std::cout << "Diese Eingabe ist nicht korrekt. Die Angabe der Distanz ist negativ." << std::endl;
	}
}

void taxi::refuel(float gas_price) {
	float missing_fuel = this->m_max_tank_capacity - this->m_current_tank_capacity;

}

void taxi::output() {
	std::cout << "Aktueller Kilometerstand: " << this->m_km << std::endl;
	std::cout << "Aktueller Tankinhalt: " << this->m_current_tank_capacity << std::endl;
	std::cout << "Aktuelle Geldbilanz: " << this->m_balance << std::endl;
}