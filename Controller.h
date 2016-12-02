
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Model.h"
#include "Database.h"

class Controller {
public:
	Controller(Database* db);
	void findCustomer(Model::Client &client);
	void findMovie(Model::Movie &movie);
	void createNewCustomer(Model::Client customer);
	void createNewMovie(Model::Movie customer);
	void ClientRentMovie(Model::Client customer, Model::Movie movie);
	void removeMovieFromClient(Model::Movie movie);
	void displayCustomer(Model::Client &customer);
	bool deleteCustomer(Model::Client customer);
	bool deleteMovie(Model::Movie movie);
	virtual ~Controller();
private:
	Database *db;
	Model::Client stringToClient(std::string input);
	Model::Movie stringToMovie(std::string input);
	std::string clientToString(Model::Client input);
	std::string movieToString(Model::Movie input);
};

#endif /* CONTROLLER_H_ */
