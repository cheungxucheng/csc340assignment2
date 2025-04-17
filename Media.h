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
		Media(const Media& original);
		~Media();
		virtual bool sell(int quantity);
		Media& operator=(const Media& rhs);
		friend ostream& operator<<(ostream& out, const Media& media);
		friend istream& operator>>(istream& in, Media& media);
};

#endif
