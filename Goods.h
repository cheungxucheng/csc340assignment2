#ifndef GOODS_H
#define GOODS_H
#include <iostream>
#include <string> 
#include "Product.h"

class Goods: public Product {
	private:
		string expirationDate;
		int quantity;

	public:
		Goods();
		Goods(const string& name, const string& description, const int& rating, const int& soldCount, const string& expirationDate, const int& quantity);
		~Goods();
		virtual bool sell(int quantity);
};

#endif
