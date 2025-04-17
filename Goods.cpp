#include <iostream>
#include <string> 
#include "Goods.h" 

Goods::Goods() {
	expirationDate = "";
	quantity = 0;
}

Goods::Goods(const string& name, const string& description, const int& rating, const int& soldCount, const string& expirationDate, const int& quantity) : Product(name, description, rating, soldCount) {
	this->expirationDate = expirationDate;
	this->quantity = quantity;
}

Goods::Goods(const Goods& original) : Product(original), expirationDate(original.expirationDate), quantity(original.quantity) {
}

Goods::~Goods() {
	//cout << "Deleting Goods obj " << getName() << "....\n";
}

bool Goods::sell(int quantity) {
	if (this->quantity >= quantity) {
		this->quantity -= quantity;
		setSoldCount(getSoldCount() + quantity);
		return true;
	}
	else {
		cout << "This product is out of stock.\n";
		return false;
	}
}

Goods& Goods::operator=(const Goods& rhs) {
	Product::operator=(rhs);
	if (this != &rhs) {
		expirationDate = rhs.expirationDate;
		quantity = rhs.quantity;
	}

	return *this;
}

ostream& operator<<(ostream& out, const Goods& goods) {
	out << "Name: " << goods.getName() << "\nDescription: " << goods.getDescription() << "\nRating: " << goods.getRating() << "\nSold Count: " << goods.getSoldCount() << "\nQuantity:" << goods.quantity << "\nExpiration Date: " << goods.expirationDate;
	return out;
}

istream& operator>>(istream& in, Goods& goods) {
	string name;
	string description;

	cout << "Enter product name: ";
	in >> name;
	goods.setName(name);
	cout << "Enter product description: ";
	in.ignore();
	getline(in, description);
	goods.setDescription(description);
	cout << "Enter product expiration date:";
	in >> goods.expirationDate;
	cout << "Enter product quantity: ";
	in >> goods.quantity;
	return in;
}