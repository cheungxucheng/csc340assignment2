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
		Goods(const Goods& original);
		~Goods();
		virtual bool sell(int quantity);
		Goods& operator=(const Goods& rhs);
		friend ostream& operator<<(ostream& out, const Goods& goods);
		friend istream& operator>>(istream& in, Goods& goods);
};

#endif
