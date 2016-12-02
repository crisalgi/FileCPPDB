#include "Model.h"
#include "Database.h"
#include "Controller.h"
int main() {
	Database *db = new Database("database.txt");
//	db.saveRecord("name:jorge nitales;age:30;email:pocheche.nitales@yahoo.com");
//	db.saveRecord("name:pocheche;age:26;email:pocheche@gmail.com");
	//std::cout << db.findRecord("age", "30");
	//db.deleteRecord("age", "30");
	Controller cont(db);
	Model::Client client;
	client.name = "pocheche";
	cont.displayCustomer(client);
	Model::Movie movie;
	movie.title = "pasion de cristo";
	movie.year = "2004";
	movie.duration = "2 hrs";
	cont.createNewMovie(movie);

	cont.ClientRentMovie(client, movie);

	return 0;
}



