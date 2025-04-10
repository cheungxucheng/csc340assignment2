#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>

using namespace std;
// TO DO: #include all the standard libraries and your own libraries here

// To DO: define the class Product with the necessary functions' prototypes and data fields

class Product {
	private:
		string name;
		string description;
		int rating;
		int soldCount;

	public:
		Product();
		Product(const string& name, const string& description, const int& rating, const int& soldCount);
		virtual ~Product();
		void display();
		bool modify();
		virtual bool sell(int quantity);

		// Getters
		string getName() const { return name; }
		string getDescription() const { return description; }
		int getRating() const { return rating; }
		int getSoldCount() const { return soldCount; }

		// Setters
		void setName(const string &newName) { name = newName; }
		void setDescription(const string &newDescription) { description = newDescription; }
		void setRating(const int &newRating) { rating = newRating; }
		void setSoldCount(const int &newSoldCount) { soldCount = newSoldCount; }

		// This is a function that allows you to compare two products based on their name. 
		// You may directly include it in your class definition. 
		// You don't need to modify it but will have to put it inside your class. 
		// Operator overloading function prototype:
		bool operator==(const Product& otherProduct) const; 
};


#endif
