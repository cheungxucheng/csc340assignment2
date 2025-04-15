#include <iostream> 
#include <memory>
#include <string>

// TO DO: #include any other libraries you need
#include "Amazon340.h"
#include "Vendor.h"
#include "Product.h"
#include "Media.h"
#include "Goods.h"

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Vendor
 * @param vendor object to interact with
 * 
 * */
void displayVendorMenu(Vendor& vendor){
	int vendorChoice = 0;
	do {
		cout << "\n Hi, "<< vendor.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Product\n"
		<< "4. Display All Products\n"
		<< "5. Display Kth Product\n"
		<< "6. Modify Product\n"
		<< "7. Sell Product\n"
		<< "8. Delete Product\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> vendorChoice;

		switch (vendorChoice) {
			case 1: {
				vendor.displayProfile();
				break;
			}
			case 2: {
				string password;
				cout << "\nEnter new password: ";
				cin >> password;
				vendor.modifyPassword(password);
				break;
			}
			case 3: {
				// TO DO: ask vendor to choose product type, then ask them to input product details.
				// Create the product and add it to the vendor's products
				string in;
				cout << "\nEnter product type in lowercase: ";
				cin >> in;
				if (in == "media") {
					string name;
					string description;
					string type;
					string targetAudience;

					cout << "Enter product name: ";
					cin >> name;
					cout << "Enter product description: ";
					cin >> description;
					cout << "Enter product media type: ";
					cin >> type;
					cout << "Enter product target audience: ";
					cin >> targetAudience;

					shared_ptr<Product> product = make_shared<Media>(name, description, 0, 0, type, targetAudience);
					vendor.createProduct(product);
				} else if (in == "goods") {
					string name;
					string description;
					string expDate;
					int quantity;

					cout << "Enter product name: ";
					cin >> name;
					cout << "Enter product description: ";
					cin >> description;
					cout << "Enter product expiration date:";
					cin >> expDate;
					cout << "Enter product quantity: ";
					cin >> quantity;

					shared_ptr<Product> product = make_shared<Goods>(name, description, 0, 0, expDate, quantity);
					vendor.createProduct(product);
				} else {
					cout << "Accepted product types are 'media' and 'goods'." << "\n";
				}
				break;
			}
			case 4: {
				// TO DO: display all vendor's products
				//        You may re-use code from class demo
				vendor.displayAllProducts();
				break;
			}
			case 5: {
				// TO DO: ask the vendor for a value k
				// Find the Kth product, if k > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				int index;
				cout << "\nEnter product index: ";
				cin >> index;
				vendor.displayProduct(index);
				break;
			}
			case 6: {
				// TO DO: ask the vendor for the index of the product they want to modify.
				// Find the product, then prompt them for the new name and description.
				// Modify the product accordingly. 
				// If index > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				int index;
				cout << "\nEnter product index: ";
				cin >> index;
				vendor.modifyProduct(index);
				break;
			}
			case 7: {
				// TO DO: ask the vendor for the index of the product they want to sell 
				// Find the product, then sell the product. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				int index;
				int quantity;
				cout << "\nEnter product index: ";
				cin >> index;
				cout << "Enter amount to sell: ";
				cin >> quantity;
				vendor.sellProduct(index, quantity);
				break;
			}
			case 8: {
				// TO DO: ask the vendor for the index of the product they want to delete 
				// Find the product, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				int index;
				cout << "\nEnter product index: ";
				cin >> index;
				vendor.deleteProduct(index);
				break;
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (vendorChoice != 0);
}


int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one vendor
	Amazon340 amazon340; 
	cout << amazon340;
	cin >> amazon340;
	Vendor currVendor = amazon340.getVendor();
	currVendor.displayProfile();
	// cout << "\n Welcome to Amazon340:" << endl;
	// // TO DO: Ask the vendor to enter their information 
	// //        Instantiate a new Vendor object
	// string username;
	// string email;
	// string password;
	// string bio;
	// string profilePicture;
	// cout << "To create a new profile, enter your username: ";
	// cin >> username;
	// cout << "Enter your email: ";
	// cin >> email;
	// cout << "Enter your password: ";
	// cin >> password;
	// cout << "Enter your bio: ";
	// cin >> bio;
	// cout << "Enter a link to your profile picture: ";
	// cin >> profilePicture;

	// // call amazon340 createVendor function 
	// // replace /*...*/ with the right parameters
	// amazon340.createVendor(username, email, password, bio, profilePicture);

	// // Retrieve the vendor 
	// Vendor currentVendor = amazon340.getVendor();

	// // Display the main menu
	// displayVendorMenu(currentVendor);

	return 0;
}
