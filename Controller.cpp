#include "Controller.h"

Controller::Controller(Database *db) {
	this->db = db;
}

void Controller::findCustomer(Model::Client &client) {
	std::string output = db->findRecord("name", client.name);
	client = stringToClient(output);
}

void Controller::findMovie(Model::Movie &movie) {
	std::string output = db->findRecord("title", movie.title);
	movie = stringToMovie(output);
}

void Controller::createNewCustomer(Model::Client customer) {
	db->saveRecord(clientToString(customer));
}

void Controller::createNewMovie(Model::Movie movie) {
	auto s = movieToString(movie);
	std::cout << s;
	db->saveRecord(s);
}

void Controller::ClientRentMovie(Model::Client customer, Model::Movie movie) {
	this->findCustomer(customer);
	this->findMovie(movie);

	if (movie.client_id != "") {
		std::cout << "the movie is already in rent" << std::endl;
		return;
	}
	if (this->deleteMovie(movie)) {
		movie.client_id = customer.id;
		this->createNewMovie(movie);
	}
}

void Controller::removeMovieFromClient(Model::Movie movie) {
	this->findMovie(movie);
	movie.client_id = "";
	if (this->deleteMovie(movie))
		this->createNewMovie(movie);
}

void Controller::displayCustomer(Model::Client &customer) {
	this->findCustomer(customer);
	customer.print();

}

bool Controller::deleteCustomer(Model::Client customer) {
	return db->deleteRecord("name", customer.name);
}
bool Controller::deleteMovie(Model::Movie movie) {
	return db->deleteRecord("title", movie.title);
}

Controller::~Controller() {
}

Model::Client Controller::stringToClient(std::string input) {
	Model::Client output;
	output.model = "client";
	output.id = db->getValue(input, "id");
	output.address = db->getValue(input, "address");
	output.name = db->getValue(input, "name");
	output.city = db->getValue(input, "city");
	output.phone = db->getValue(input, "phone");
	output.state = db->getValue(input, "state");
	output.zip = db->getValue(input, "zip");
	return output;
}
Model::Movie Controller::stringToMovie(std::string input) {
	Model::Movie output;
	output.id = db->getValue(input, "id");
	output.model = "movie";
	output.client_id = db->getValue(input, "client_id");
	output.title = db->getValue(input, "title");
	output.year = db->getValue(input, "year");
	output.duration = db->getValue(input, "duration");
	return output;
}

std::string Controller::clientToString(Model::Client input) {
	std::string output = "name:" + input.name + ";address:"
			+ input.address
			+ ";city:" + input.city + ";phone:" + input.phone + ";state:"
			+ input.state + ";zip:" + input.zip;
	return output;
}

std::string Controller::movieToString(Model::Movie input) {
	std::string output = "title:" + input.title + ";duration:"
			+ input.duration + ";year:" + input.year + ";client_id:"
			+ input.client_id;
	return output;
}
