#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <string> 
#include "Product.h"

using namespace std;

class Media: public Product {
	private:
		string type;
		string targetAudience;

	public:
		Media();
		Media(const string& name, const string& description, const int& rating, const int& soldCount, const string& type, const string& targetAudience);
		~Media();
		virtual bool sell(int quantity);
};

#endif
