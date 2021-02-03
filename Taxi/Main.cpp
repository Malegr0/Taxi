#include <iostream>
#include "taxi.h"

int main() {
	
	taxi taxi1, taxi2;

	taxi1.init(0.0f, 55.0f, 0.0572f, 2.0f);
	taxi2.init(25.0f, 80.0f, 0.07f, 2.5f);

	/*taxi1.drive(100.0f, true);
	taxi1.output();

	taxi2.drive(10.0f, false);
	taxi2.output();

	taxi1.refuel(1.36f);
	taxi1.output();

	taxi2.refuel(1.23f);
	taxi2.output();*/

	bool running = true;
	char input = ' ';
	while (running) {
		switch (input) {
			case '1': {
				bool running_taxi_1 = true;
				char t1_input = ' ';
				while (running_taxi_1) {
					switch (t1_input) {
					case '1':
						float distance;
						char c_guest;
						bool b_guest;
						std::cout << "Es soll eine Fahrt verbucht werden." << std::endl;
						std::cout << "Welche Distanz soll die Fahrt haben?" << std::endl;
						std::cin >> distance;
						if (distance < 0) {
							std::cout << "Es können keine negativen Kilometer gefahren werden." << std::endl;
							break;
						}
						std::cout << "Wird ein Kunde befördert? ja -> y; nein ->n" << std::endl;
						std::cin >> c_guest;
						if (c_guest == 'y') {
							b_guest = true;
						}
						else if (c_guest == 'n'){
							b_guest = false;
						}
						else {
							std::cout << "Dies war eine falsche Eingabe!" << std::endl;
							break;
						}
						taxi1.drive(distance, b_guest);
						break;
					case '2':
						std::cout << "Es soll getankt werden." << std::endl;
						taxi1.refuel(1.23);
						break;
					case '3':
						taxi1.output();
						break;
					case 'x':
						running_taxi_1 = false;
						break;
					default:
						std::cout << "\nTaxi 1 wurde ausgewählt. Folgende Optionen sind möglich:" << std::endl;
						std::cout << "Fahrt verbuchen -> 1" << std::endl;
						std::cout << "Tanken -> 2" << std::endl;
						std::cout << "Ausgabe des Taxiinformationen -> 3" << std::endl;
						std::cout << "Zurück zum Hauptmenü -> x" << std::endl;
						break;
					}
					std::cin >> t1_input;
				}
				std::cout << "Es muss eine mögliche Option ausgewählt werden.\n" << "Diese Optionen sind folgende:" << std::endl;
				std::cout << "Taxi 1 -> 1" << std::endl;
				std::cout << "Taxi 2 -> 2" << std::endl;
				std::cout << "Programm beenden -> x" << std::endl;
				break;
			}
			case '2': {
				bool running_taxi_2 = true;
				char t2_input = ' ';
				while (running_taxi_2) {
					switch (t2_input) {
					case '1':
						float distance;
						char c_guest;
						bool b_guest;
						std::cout << "\nEs soll eine Fahrt verbucht werden." << std::endl;
						std::cout << "Welche Distanz soll die Fahrt haben?" << std::endl;
						std::cin >> distance;
						if (distance < 0) {
							std::cout << "Es können keine negativen Kilometer gefahren werden." << std::endl;
							break;
						}
						std::cout << "Wird ein Kunde befördert? ja -> y; nein ->n" << std::endl;
						std::cin >> c_guest;
						if (c_guest == 'y') {
							b_guest = true;
						}
						else if (c_guest == 'n') {
							b_guest = false;
						}
						else {
							std::cout << "Dies war eine falsche Eingabe!" << std::endl;
							break;
						}
						taxi2.drive(distance, b_guest);
						std::cout << "\nTaxi 2 wurde ausgewählt. Folgende Optionen sind möglich:" << std::endl;
						std::cout << "Fahrt verbuchen -> 1" << std::endl;
						std::cout << "Tanken -> 2" << std::endl;
						std::cout << "Ausgabe des Taxiinformationen -> 3" << std::endl;
						std::cout << "Zurück zum Hauptmenü -> x" << std::endl;
						break;
					case '2':
						std::cout << "\nEs soll getankt werden." << std::endl;
						taxi2.refuel(1.23);
						std::cout << "\nTaxi 2 wurde ausgewählt. Folgende Optionen sind möglich:" << std::endl;
						std::cout << "Fahrt verbuchen -> 1" << std::endl;
						std::cout << "Tanken -> 2" << std::endl;
						std::cout << "Ausgabe des Taxiinformationen -> 3" << std::endl;
						std::cout << "Zurück zum Hauptmenü -> x" << std::endl;
						break;
					case '3':
						taxi2.output();
						std::cout << "\nTaxi 2 wurde ausgewählt. Folgende Optionen sind möglich:" << std::endl;
						std::cout << "Fahrt verbuchen -> 1" << std::endl;
						std::cout << "Tanken -> 2" << std::endl;
						std::cout << "Ausgabe des Taxiinformationen -> 3" << std::endl;
						std::cout << "Zurück zum Hauptmenü -> x" << std::endl;
						break;
					case 'x':
						running_taxi_2 = false;
						break;
					default:
						std::cout << "\nTaxi 2 wurde ausgewählt. Folgende Optionen sind möglich:" << std::endl;
						std::cout << "Fahrt verbuchen -> 1" << std::endl;
						std::cout << "Tanken -> 2" << std::endl;
						std::cout << "Ausgabe des Taxiinformationen -> 3" << std::endl;
						std::cout << "Zurück zum Hauptmenü -> x" << std::endl;
						break;
					}
					std::cin >> t2_input;
				}
				std::cout << "Es muss eine mögliche Option ausgewählt werden.\n" << "Diese Optionen sind folgende:" << std::endl;
				std::cout << "Taxi 1 -> 1" << std::endl;
				std::cout << "Taxi 2 -> 2" << std::endl;
				std::cout << "Programm beenden -> x" << std::endl;
				break;
			}
				break;
			case 'x':
				std::cout << "Das Programm wird beendet." << std::endl;
				running = false;
			default:
				std::cout << "Es muss eine mögliche Option ausgewählt werden.\n" << "Diese Optionen sind folgende:" << std::endl;
				std::cout << "Taxi 1 -> 1" << std::endl;
				std::cout << "Taxi 2 -> 2" << std::endl;
				std::cout << "Programm beenden -> x" << std::endl;
		}
		std::cin >> input ;
	}

	return 0;
}