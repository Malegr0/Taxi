#include <iostream>
#include "taxi.h"

void taxi::init(float km, float max_tank_capacity, float consumption, float fare_per_kilometer) {
	this->m_km = km;
	this->m_max_tank_capacity = max_tank_capacity;
	this->m_consumption = consumption;
	this->m_fare_per_kilometer = fare_per_kilometer;

	this->m_current_tank_capacity = m_max_tank_capacity;
	this->m_balance = 0.0f;
}

void taxi::drive(float distance, bool guest) {
	if (distance>=0.0f) {
		if (!(distance * m_consumption > m_current_tank_capacity)) {
			this->m_km = m_km + distance;
			this->m_current_tank_capacity = m_current_tank_capacity - distance * m_consumption;
			if (guest) {
				this->m_balance = m_balance + distance * m_fare_per_kilometer;
			}
			std::cout << "Folgende Fahrt wurde durchgeführt." << std::endl;
			std::cout << "Gefahrene Kilometer: " << distance << std::endl;
			std::cout << "Genutzter Treibstoff: " << distance * m_consumption << std::endl;
			std::cout << "Eingenommenes Geld: " << distance * m_fare_per_kilometer << std::endl << std::endl;
		}
		else {
			std::cout << "Für die eingegebene Distanz reicht der momentane Tankinhalt nicht mehr aus. Die Fahrt wird nicht begonnen" << std::endl << std::endl;
		}
	}
	else {
		std::cout << "Diese Eingabe ist nicht korrekt. Die Angabe der Distanz ist negativ." << std::endl << std::endl;
	}
}

void taxi::refuel(float gas_price) {
	float missing_fuel = m_max_tank_capacity - m_current_tank_capacity;
	char c_input;
	if (missing_fuel * gas_price < m_balance) {
		this->m_current_tank_capacity = m_max_tank_capacity;
		this->m_balance = m_balance - missing_fuel * gas_price;
		std::cout << "Der Tank wurde aufgefühlt. Es wurden " << missing_fuel * gas_price << " berechnet." << std::endl << std::endl;
	} else {
		std::cout << "Der Geldstand von " << this->m_balance << " reicht nicht aus, um den Tank vollzutanken." << std::endl;
		std::cout << "Soll der Tank mit dem vorhandenen Geld so weit wie möglich vollgetankt werden? Folgende Antworten sind möglich:" << std::endl;
		std::cout << "ja -> y" << std::endl;
		std::cout << "nein -> n" << std::endl;
		std::cin >> c_input;
		if (c_input == 'y') {
			float fuel = m_balance / gas_price;
			this->m_current_tank_capacity = m_current_tank_capacity + fuel;
			this->m_balance = 0.0f;
		}
		else if (c_input == 'n') {
			std::cout << "Es wurde nicht aufgetankt." << std::endl;
		}
		else {
			std::cout << "Dies war eine falsche Eingabe." << std::endl;
		}
	}
}

void taxi::output() {
	std::cout << "Aktueller Kilometerstand: " << m_km << std::endl;
	std::cout << "Aktueller Tankinhalt: " << m_current_tank_capacity << std::endl;
	std::cout << "Aktuelle Geldbilanz: " << m_balance << std::endl << std::endl;
}