// TO DO: #include all the standard libraries and your own libraries here
#include <iostream>
#include <string>
#include "Product.h"
#include "Media.h"
#include "Goods.h"

using namespace std;
// TO DO: function implementations

Product::Product() {
	name = "";
	description = "";
	rating = 0;
	soldCount = 0;
}

Product::Product(const string& name, const string& description, const int& rating, const int& soldCount) {
	this->name = name;
	this->description = description;
	this->rating = rating;
	this->soldCount = soldCount;
}

Product::~Product() {
	//cout << "Deleting Product obj " << name << "....";
}

void Product::display() {
	cout << *this;
}

bool Product::modify() {
	string newName;
	string newDescription;

	cout << "Enter a new name for this product: ";
	cin >> newName;
	name = newName;
	cout << "Enter a new description for this product: ";
	cin >> newDescription;
	description = newDescription;
	
	return true;
}

bool Product::sell(int quantity) {
	return false;
}

// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Product::operator==(const Product& otherProduct) const {
	return Product::name == otherProduct.name;
}

ostream& operator<<(ostream& out, const Product& product) {
	out << "Name: " << product.name << "\nDescription: " << product.description << "\nRating: " << product.rating << "\nSold Count: " << product.soldCount << "\n";
	return out;
}

istream& operator>>(istream& in, Product& product) {
	cout << "Enter product name: ";
	in >> product.name;
	cout << "Enter product description: ";
	in >> product.description;
	cout << "Enter product rating: ";
	in >> product.rating;
	cout << "Enter sold count: ";
	in >> product.soldCount;

	return in;
}