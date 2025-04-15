#include <iostream>
#include <string>
#include "Vendor.h"

using namespace std;

Vendor::Vendor() {
	username = "";
	email = "";
	password = "";
	bio = "";
	profilePicture = "";
}

Vendor::Vendor(const string& username, const string& email, const string& password, const string& bio, const string& profilePicture) {
	this->username = username;
	this->email = email;
	this->password = password;
	this->bio = bio;
	this->profilePicture = profilePicture;
}

Vendor::~Vendor() {
	//cout << "Deleting Vendor obj " << username << "\n";
}

void Vendor::displayProfile() { // should this be kept with the output operator overloading?
	cout << username << "\n" << email << "\n" << bio << "\n" << profilePicture << "\n";
}

bool Vendor::modifyPassword(string password) {
	this->password = password;
	cout << password << "\n";
	return true;
}

bool Vendor::createProduct(shared_ptr<Product> product) {
	products.appendK(product, 0);
	return true;
}

void Vendor::displayProduct(int index) {
	if (index >= products.getCurrentSize()) {
		cout << "Error: product index out of range, there are only " << products.getCurrentSize() << " products available" << "\n";
		return;
	}

	cout << *products.reverseFindKthItem(index)->getItem();
}

void Vendor::displayAllProducts() {
	for (int i = 0; i < products.getCurrentSize(); i++) {
		displayProduct(i);
		cout << "\n";
	}
}

bool Vendor::modifyProduct(int index) {
	if (index >= products.getCurrentSize()) {
		cout << "Error: product index out of range, there are only " << products.getCurrentSize() << " products available" << "\n";
		return false;
	}

	cin >> *products.reverseFindKthItem(index)->getItem();
	return true;
}

bool Vendor::sellProduct(int index, int quantity) {
	if (index >= products.getCurrentSize()) {
		cout << "Error: product index out of range, there are only " << products.getCurrentSize() << " products available" << "\n";
		return false;
	}

	products.reverseFindKthItem(index)->getItem()->sell(quantity);
	return true;
}

bool Vendor::deleteProduct(int index) {
	if (index >= products.getCurrentSize()) {
		cout << "Error: product index out of range, there are only " << products.getCurrentSize() << " products available" << "\n";
		return false;
	}

	products.remove(products.reverseFindKthItem(index)->getItem());
	return true;
}

// Operator == overloading implementation
bool Vendor::operator==(const Vendor& otherVendor) const {
	return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
}

ostream& operator<<(ostream& out, const Vendor& vendor) {
	out << "Username: " << vendor.username << "\nEmail: " << vendor.email << "\nBio: " << vendor.bio << "\nProfile Pic: " << vendor.profilePicture << "\n";
	return out;
}

istream& operator>>(istream& in, Vendor& vendor) {
	cout << "\nEnter new password: ";
	in >> vendor.password;
	return in;
}
