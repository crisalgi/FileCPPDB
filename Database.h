#ifndef DATABASE_H_
#define DATABASE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>

class Database {
public:
	Database(std::string file);
	std::string findRecord(std::string key, std::string value);
	bool saveRecord(std::string line);
	bool deleteRecord(std::string key, std::string value);
	std::vector<std::string> getAll();
	std::string getValue(std::string line, std::string key);
	virtual ~Database();
private:
	std::string Filename;
	int countLine(std::string key, std::string value);
};

#endif /* DATABASE_H_ */
