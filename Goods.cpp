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
