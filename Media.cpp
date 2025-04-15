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

ostream& operator<<(ostream& out, const Media& media) {
	out << "Name: " << media.getName() << "\nDescription: " << media.getDescription() << "\nRating: " << media.getRating() << "\nSold Count: " << media.getSoldCount() << "\nTarget Audience:" << media.targetAudience << "\nType: " << media.type;
	return out;
}
istream& operator>>(istream& in, Media& media) {
	string name;
	string description;
	cout << "Enter product name: ";
	in >> name;
	media.setName(name);
	cout << "Enter product description: ";
	in >> description;
	media.setDescription(description);
	cout << "Enter product media type: ";
	in >> media.type;
	cout << "Enter product target audience: ";
	in >> media.targetAudience;
	return in;
}
