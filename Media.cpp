#include <iostream>
#include <string>
#include "Media.h"

using namespace std;

Media::Media() {
	type = "";
	targetAudience = "";
}

Media::Media(const string& name, const string& description, const int& rating, const int& soldCount, const string& type, const string& targetAudience) : Product(name, description, rating, soldCount) {
	this->type = type;
	this->targetAudience = targetAudience;
}

Media::~Media() {
	//cout << "Deleting Media Object " << getName() << "....\n";
}

bool Media::sell(int quantity) {
	setSoldCount(getSoldCount() + quantity);
	cout << "One time access code: " << this; // whatever for now
	return true;
}
