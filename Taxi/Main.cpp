#include <iostream>
#include "taxi.h"

int main() {
	
	taxi taxi1, taxi2;

	taxi1.init(0.0f, 55.0f, 0.0572f, 2.0f);
	taxi2.init(25.0f, 80.0f, 0.07f, 2.5f);

	taxi1.drive(100.0f, true);
	taxi1.output();

	taxi2.drive(10.0f, false);
	taxi2.output();

	taxi1.refuel(1.36f);
	taxi1.output();

	taxi2.refuel(1.23f);
	taxi2.output();

	return 0;
}