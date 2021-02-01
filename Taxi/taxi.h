#pragma once

class taxi {
private:
	float m_km;
	float m_current_tank_capacity;
	float m_max_tank_capacity;
	float m_consumption;
	float m_fare_per_kilometer;
	float m_balance;

public:
	void init(float km, float max_tank_capacity, float consumption, float fare_per_kilometer);

	void drive(float distance, bool guest);

	void refuel(float gas_price);

	void output();
};