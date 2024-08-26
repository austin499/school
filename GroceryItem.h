#pragma once
#include<string>
#include<functional>

extern class GroceryItem {

public:
	
	GroceryItem(std::string& name);

	
	GroceryItem(std::string& name, int quantity);

	
	std::string getName() const;

	
	int getQuantity() const;

private:
	std::string name;
	int quantity;
};
