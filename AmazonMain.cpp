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
	
	Vendor copyTest(currVendor);
	copyTest.displayAllProducts();
	Vendor assignTest;
	assignTest = currVendor;
	assignTest.displayAllProducts();
	
	displayVendorMenu(currVendor);
	copyTest.displayAllProducts();
	assignTest.displayAllProducts();
	// // Testing the Amazon340 copy constructor
	// cout << "\nTesting the Amazon340 copy constructor\n";
	// Amazon340 orig;
	// orig.createVendor("t", "t", "t", "t", "t");
	// Amazon340 copy(orig);
	// copy.getVendor().displayProfile(); // should display four t's

	// // Testing the Amazon340 operator= 
	// cout << "\nTesting the Amazon340 operator= \n";
	// Amazon340 orig1;
	// orig.createVendor("t", "t", "t", "t", "t");
	// Amazon340 copy1;
	// copy = orig;
	// copy.getVendor().displayProfile(); // should display four t's

	// //Testing the Vendor copy constructor
	// cout << "\nTesting the Vendor copy constructor\n";
	// Vendor origVen("a", "b", "c", "d", "e");
	// Vendor copyVen(origVen);
	// copyVen.displayProfile(); // should display abce

	// //Testing the Vendor operator=
	// cout << "\nTesting the Vendor operator=\n";
	// Vendor origVen2("a", "b", "c", "d", "e");
	// Vendor copyVen2;
	// copyVen2 = origVen2;
	// copyVen2.displayProfile(); // should display abce

	// //Testing Product copy
	// cout << "\nTesting the Product copy constructor\n";
	// Product originalProd("Book", "A great book", 5, 100);
	// Product copiedProd(originalProd);
	// cout << copiedProd; // should print same info as originalProd

	// //Testing product =
	// cout << "\nTesting the Product operator=\n";
	// Product assignedProd;
	// assignedProd = originalProd;
	// cout << assignedProd; // should print same info as originalProd

	// //Testing Goods
	// cout << "\nTesting the Goods copy constructor\n";
	// Goods originalGoods("Milk", "Organic milk", 4, 20, "2025-05-01", 10);
	// Goods copiedGoods(originalGoods);
	// cout << copiedGoods; // should match originalGoods info

	// cout << "\nTesting the Goods operator=\n";
	// Goods assignedGoods;
	// assignedGoods = originalGoods;
	// cout << assignedGoods; // should match originalGoods info

	// //Testing media
	// cout << "\nTesting the Media copy constructor\n";
	// Media originalMedia("Movie", "Sci-fi movie", 5, 100, "1080p", "SomeVal");
	// Media copiedMedia(originalMedia);
	// cout << copiedMedia; // should match originalMedia info

	// cout << "\nTesting the Media operator=\n";
	// Media assignedMedia;
	// assignedMedia = originalMedia;
	// cout << assignedMedia; // should match originalMedia info

	// //testing LinkedBag
	// cout << "\nTesting the LinkedBag copy constructor\n";
	// LinkedBag<string> bag1;
	// bag1.add("apple");
	// bag1.add("banana");
	// bag1.add("cherry");

	// LinkedBag<string> bag2(bag1);
	// vector<string> items2 = bag2.toVector();
	// for (const auto& item : items2) {
	// 	cout << item << " ";
	// }
	// cout << endl; // should print cherry banana apple 

	// cout << "\nTesting the LinkedBag operator=\n";
	// LinkedBag<string> bag3;
	// bag3 = bag1;
	// vector<string> items3 = bag3.toVector();
	// for (const auto& item : items3) {
	// 	cout << item << " ";
	// }
	// cout << endl; // should match items in bag1

	// //testing that it is deep copy
	// bag1.add("date");
	// cout << "After modifying bag1:\n";
	// cout << "bag1: ";
	// for (const auto& item : bag1.toVector()) cout << item << " ";
	// cout << "\nbag2: ";
	// for (const auto& item : bag2.toVector()) cout << item << " ";
	
	return 0;
}
