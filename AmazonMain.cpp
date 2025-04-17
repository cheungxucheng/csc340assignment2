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
		cout << "\nHi, "<< vendor.getUsername() <<", what would you like to do:\n"
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
				cout << vendor;
				break;
			}
			case 2: {
				cin >> vendor;
				break;
			}
			case 3: {
				// TO DO: ask vendor to choose product type, then ask them to input product details.
				// Create the product and add it to the vendor's products
				string in;
				cout << "\nEnter product type in lowercase: ";
				cin >> in;
				if (in == "media") {
					Media media;
					cin >> media;
					shared_ptr<Product> product = make_shared<Media>(media);
					vendor.createProduct(product);
				} else if (in == "goods") {
					Goods goods;
					cin >> goods;
					shared_ptr<Product> product = make_shared<Goods>(goods);
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
	// testing menu
	Amazon340 amazon340; 
	cout << amazon340;
	cin >> amazon340;
	Vendor currVendor = amazon340.getVendor();
	displayVendorMenu(currVendor);
	
	return 0;
}
