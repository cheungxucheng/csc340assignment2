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

Goods::~Goods() {
	//cout << "Deleting Goods obj " << getName() << "....\n";
}

bool Goods::sell(int quantity) {
	if (this->quantity > quantity) {
		this->quantity -= quantity;
		setSoldCount(getSoldCount() + quantity);
		return true;
	}
	else {
		cout << "This product is out of stock.\n";
		return false;
	}
}

ostream& operator<<(ostream& out, const Goods& goods) {
	out << "Name: " << goods.getName() << "\nDescription: " << goods.getDescription() << "\nRating: " << goods.getRating() << "\nSold Count: " << goods.getSoldCount() << "\nQuantity:" << goods.quantity << "\nExpiration Date: " << goods.expirationDate;
	return out;
}

istream& operator>>(istream& in, Goods& goods) {
	string name;
	string description;

	cout << "Enter product name: ";
	cin >> name;
	goods.setName(name);
	cout << "Enter product description: ";
	cin >> description;
	goods.setDescription(description);
	cout << "Enter product expiration date:";
	cin >> goods.expirationDate;
	cout << "Enter product quantity: ";
	cin >> goods.quantity;
	return in;
}