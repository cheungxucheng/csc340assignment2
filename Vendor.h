// TO DO: #include all the standard libraries and your own libraries here
#ifndef VENDOR_H
#define VENDOR_H
// To DO: define the class Vendor with the necessary functions and data fields
#include <iostream>
#include <memory>
#include <string>
#include "LinkedBag.h"
#include "Product.h"

using namespace std;

class Vendor {
	private:
		string username;
		string email;
		string password;
		string bio;
		string profilePicture;
		LinkedBag<shared_ptr<Product>> products;

	public:
		Vendor();
		Vendor(const string& username, const string& email, const string& password, const string& bio, const string& profilePicture);
		virtual ~Vendor();
		void displayProfile();
		bool modifyPassword(string password);
		bool createProduct(shared_ptr<Product> product);
		void displayProduct(int index);
		void displayAllProducts();
		bool modifyProduct(int index);
		bool sellProduct(int index, int quantity);
		bool deleteProduct(int index);

		//getters
		string getUsername() const { return username; }
		string getEmail() const { return email; }
		string getPassword() const { return password; }
		string getBio() const { return bio; }
		string getProfilePicture() const { return profilePicture; }

		// Setters
		void setUsername(const string& newUsername) { username = newUsername; }
		void setEmail(const string& newEmail) { email = newEmail; }
		void setPassword(const string& newPassword) { password = newPassword; }
		void setBio(const string& newBio) { bio = newBio; }
		void setProfilePicture(const string& newProfilePicture) { profilePicture = newProfilePicture; }

		// This is a function that allows you to compare two vendors based on their username and email address.  
		// You may directly include it in your class definition. 
		// You don't need to modify it but will have to put it inside your class. 
		// Operator == overloading function prototype:
		bool operator==(const Vendor& otherVendor) const; 
};

#endif
