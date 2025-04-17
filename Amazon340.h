#include "LinkedBagDS/LinkedBag.h"
#include "Vendor.h"
 

// This class only contains a vendor
class Amazon340 {
	private:
		Vendor vendor;

	public:
		Amazon340();
		Amazon340(const Amazon340& original);
		~Amazon340();

		void createVendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);
		Vendor getVendor() const;

		Amazon340& operator=(const Amazon340& rhs);

		friend ostream& operator<<(ostream& out, const Amazon340& amazon); 
		friend istream& operator>>(istream& in, Amazon340& amazon);
	};