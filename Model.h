
#ifndef MODEL_H_
#define MODEL_H_

#include <string>
#include <vector>
#include <iostream>


class Model {

public:
	struct Movie {
		std::string id;
		std::string title;
		std::string client_id;
		std::string model;
		std::string year;
		std::string duration;
		void print() {
			std::cout << "title: " << title << std::endl;
			std::cout << "year: " << year << std::endl;
			std::cout << "duration: " << duration << std::endl;
			std::cout << "--------------------------------" << std::endl;
		}

	};

	struct Client {
		std::string model;
		std::string id;
		std::string name;
		std::string address;
		std::string city;
		std::string state;
		std::string zip;
		std::string phone;
		std::vector<Movie> movies;
		void print() {
			std::cout << "name: " << name << std::endl;
			std::cout << "address: " << address << std::endl;
			std::cout << "city: " << city << std::endl;
			std::cout << "phone: " << phone << std::endl;
			std::cout << "state: " << state << std::endl;
			std::cout << "zip: " << zip << std::endl;
			std::cout << "Movies in posession:" << std::endl;
			for (int i = 0; i < movies.size(); i++) {
				movies.at(i).print();
			}
		}

	};
};

#endif /* CUSTOMER_H_ */
