// TO DO: Implementation of Amazon340 functions
#include <iostream>
#include <string>
#include "Amazon340.h"

Amazon340::Amazon340() : vendor(){ // constructor
}

Amazon340::Amazon340(const Amazon340& original) : vendor(original.vendor) { //copy constructor
}

Amazon340::~Amazon340() { // 
	//cout << "Deleting Amazon340 obj...\n";
}

void Amazon340::createVendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
	// TO DO: implement function
	vendor = Vendor(username, email, password, bio, profilePicture);
}

Vendor Amazon340::getVendor() const {
	// TO DO: implement function
	return vendor;
}

Amazon340& Amazon340::operator=(const Amazon340& rhs) { // overloading the assignment operator
	if (this != &rhs) {
		vendor = rhs.vendor;
	}
	return *this;
}

ostream& operator<<(ostream& outs, const Amazon340& amazon) {
	outs << "Welcome to Amazon340!\n";
	return outs;
}

istream& operator>>(istream& in, Amazon340& amazon) {
	string username;
	string email;
	string password;
	string bio;
	string profilePicture;
	cout << "To create a new profile, enter your username: ";
	in >> username;
	cout << "Enter your email: ";
	in >> email;
	cout << "Enter your password: ";
	in >> password;
	cout << "Enter your bio: ";
	in.ignore();
	getline(in, bio);
	cout << "Enter a link to your profile picture: ";
	in >> profilePicture;
	amazon.createVendor(username, email, password, bio, profilePicture);
	return in;
}
