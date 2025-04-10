// TO DO: Implementation of Amazon340 functions
#include <iostream>
#include <string>
#include "Amazon340.h"

Amazon340::Amazon340() {
	vendor = Vendor();
}

Amazon340::~Amazon340() {
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
