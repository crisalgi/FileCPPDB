/*
 * Database.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: cristian
 */

#include "Database.h"

Database::Database(std::string file) {
	this->Filename = file;
}

std::string Database::findRecord(std::string key, std::string name) {
	std::string line = "";
	std::ifstream myfile(Filename.c_str());
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			if (getValue(line, key) == name)
				break;
		}
		if (line == "") {
			std::cout << "Record does not exist" << std::endl;
		}
		myfile.close();
	} else {
		std::cout << "Database file does not exist" << std::endl;
	}
	return line;

}

bool Database::saveRecord(std::string line) {
	bool success = false;
	std::string cline;
	std::ofstream myfile(Filename.c_str(),
			std::ios_base::app | std::ios_base::out);
	if (myfile.is_open()) {
		myfile << line << std::endl;
		myfile.close();
		success = true;
	} else {
		std::cout << "Database file does not exist" << std::endl;
	}
	return success;
}

bool Database::deleteRecord(std::string key, std::string value) {
	bool success = false;
	int lineToErase = this->countLine(key, value);

	//rename original file
	std::rename(Filename.c_str(), ("." + Filename + "_BAK").c_str());
	std::string line;
	std::ifstream oldFile(("." + Filename + "_BAK").c_str());
	std::ofstream newFile(Filename.c_str(),
			std::ios_base::app | std::ios_base::out);
	int lineCount = 0;
	if (oldFile.is_open()) {
		while (getline(oldFile, line)) {
			if (lineCount != lineToErase) {
				newFile << line << std::endl;
			}

			lineCount++;
		}
		oldFile.close();
		newFile.close();
	} else {
		std::cout << "Database file does not exist" << std::endl;
	}


	return success;
}

int Database::countLine(std::string key, std::string name) {

	std::string line = "";
	//std::ifstream myfile(Filename.c_str());
	std::ifstream myfile(Filename.c_str(),
			std::ios_base::app | std::ios_base::out);
	int countLine = 0;
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			if (getValue(line, key) == name) {
				break;
			}
			countLine++;
		}
		if (line == "") {
			std::cout << "Record does not exist" << std::endl;
			countLine = -1;
		}
		myfile.close();
	} else {
		std::cout << "Database file does not exist" << std::endl;
		countLine = -1;
	}
	return countLine;
}


std::vector<std::string> Database::getAll() {
	std::vector<std::string> vec;
	std::string line;
	std::ifstream myfile(Filename.c_str());
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			vec.push_back(line);
		}
		myfile.close();
	} else {
		std::cout << "Database file does not exist" << std::endl;
	}
	return vec;
}

std::string Database::getValue(std::string line, std::string key) {
	int npos = 0;
	std::string token, currentKey, currentValue = "";
	while (npos != -1) {
		token = line.substr(0, line.find(";"));
		currentKey = token.substr(0, token.find(":"));
		if (currentKey == key) {
			currentValue = token.substr(token.find(":") + 1, token.size());
			break;
		}
		npos = line.find(";");
		line = line.substr(npos + 1, line.size());
	}

	return currentValue;
}

Database::~Database() {

}
