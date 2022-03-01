#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
using namespace std;

class Product { //creates a class called "Product"
protected:
    string productName; //creates a protected variable for the product name
    double productPrice;    //creates a protected variable for the product price
    int quantity;   //creates a variable for the quantity
public:
    Product() {}    //creates a default constructor for the product class

    Product(string name, double price, int qty) {   //creates a constructor for the product class
        productName = name; //initializes the product name protected variable
        productPrice = price;   //initializes the product price protected variable
        quantity = qty; //initializes the quantity protected variable
    }

    void setName(string name) { //seter function used to set the product name protected variable
        productName = name; //initializes the product name protected variable
    }

    void setPrice(double price) {   //seter function used to set the product price protected variable
        productPrice = price;   //initializes the product price protected variable
    }

    void setQuantity(int qty) { //seter function used to set the quantity protected variable
        quantity = qty; //initializes the quantity protected variable
    }

    string getName() {  //get function used to get the product name protected variable
        return productName; //returns product name
    }

    double getPrice() { //get function used to get the product price protected variable
        return productPrice;    //returns product price
    }

    int getQuantity() { //get function used to get the quantity protected variable
        return quantity;    //returns quantity
    }

    virtual void display() const {  //function used to display the information of the product
        cout << setw(45) << left << productName << "|" << setw(3) << left << " $" << setw(15) << right << fixed << setprecision(2) << productPrice << "|" << setw(12) << left << " Quantity: " << setw(5) << right << quantity << "| Expiration Date: N/A" << endl;
    }

    virtual void displayNames() const { //function used to displey just the names of the products
        cout << productName << endl;    //outputs the product name
    }
};

class FoodProduct : public Product {    //creates a derived class called "FoodProduct"
private:
    string expirationDate;  //creates a private variable for the expiration date
public:
    FoodProduct(string name, double price, int qty, string expireDate) {    //creates a constructor for the food product class
        setName(name);  //uses the set name function to initialize the product name
        setPrice(price);    //uses the set price function to initialize the product price
        setQuantity(qty);   //uses the set quantity function to initialize the quantity
        expirationDate = expireDate;    //initializes the expiration date private variable
    }

    void setExpirationDate(string expireDate) { //set function used to set the expiration date private variable
        expirationDate = expireDate;    //initializes the expiration date private variable
    }

    string getExpirationDate() {    //get function used to get the expiration date private variable
        return expirationDate;  //returns expiration date
    }

    virtual void display() const override{  //function used to display the information of the food product
        cout <<setw(45) << left << productName << "|" << setw(3) << left << " $" << setw(15) << right << fixed << setprecision(2) << productPrice << "|" << setw(12) << left << " Quantity:" << setw(5) << right << quantity << "|" << " Expiration Date: " << expirationDate << endl;
    }

    virtual void displayNames() const override {    //function used to display just the names of the food products
        cout << productName << endl;    //outputs the product name
    }
};

void validateExpirationDate(bool &day, bool &month, bool &year, int expirationDay, int expirationMonth, int expirationYear) { //creates a function used to validate the expiration date
    const int MONTH_MAX = 12;        //declares and intializes a variable used as the maximum months in a year
    const int DAY_MAX = 31;         //declares and intializes a variable used as the maximum number of days in a month
    const int DAY_MONTH_MIN = 1;     //declares and intializes a variable used as the minimum number of months and days in a week
    const int curYear = 2021;       //declares and intializes a variable used to validate the year


    if (expirationDay >= DAY_MONTH_MIN && expirationDay <= DAY_MAX) {  //if-statement used to see if the day is valid
        day = true;    //changes day to true
    }

    else day = false;   //else-statement used to initialize day to false

    if (expirationMonth >= DAY_MONTH_MIN && expirationMonth <= MONTH_MAX) { //if-statement used to see if the month is valid
        month = true;       //changes month to true
    }

    else month = false; //else-statement used to initialize month to false

    if (expirationYear >= curYear) {    //if-statement used to see if the year is valid
        year = true;    //changes year to true
    }

    else year = false;  //else-statement used to initialize year to false

    if (year == false) {
        cout << "Error, please enter a valid year." << endl;    //outputs an error message
    }

    if (month == false) {        //if-statement used if the month is invalid
        cout << "Error, please enter a valid month." << endl;    //outputs an error message
    }

    if (day == false) {    //if-statement used if the day is invalid
        cout << "Error, please enter a valid day." << endl;       //outputs an error message
    }
}

void displayMainMenu(int &mainSelection, const int MAIN_EXIT, int count) {  //creates a function used to display the main menu and receive user input
    string mainMenuOptions[4] = {"1. Add Item", "2. Remove Item", "3. Display All Items", "4. Exit"};   //creates an array used to store the main menu options
    const int MAIN_MIN = 1; //creates a variable used to validate for main menu

    while (mainSelection < MAIN_MIN || mainSelection > MAIN_EXIT) { //while loop used to display the main menu if exit condition has not been met
        cout << "Main Menu: Select an option." << endl; //prompts user to select an option in the main menu

        for (count = 0; count < MAIN_EXIT; count++) {   //for-loop used to output the main menu options
            cout << mainMenuOptions[count] << endl; //outputs the main menu options
        }

        cin >> mainSelection;   //initializes "mainSelection" with selection from user

        if (mainSelection < MAIN_MIN || mainSelection > MAIN_EXIT) {    //if-statement used if user input is invalid
            cout << "\nSelection not valid, please try again.\n" << endl;   //outputs to user that the input is invalid
        }
    }
}

void displayFirstMenu(int &firstSelection, const int FIRST_EXIT, int count) {   //creates a function used to display the first menu and receive user input
    string firstMenuOptions[3] = {"1. Non-Food Item", "2. Food Item", "3. Back To Main Menu"};  //creates an array used to store the first menu options
    const int FIRST_MIN = 1;    //creates a variable used to validate for first menu

    while (firstSelection < FIRST_MIN || firstSelection > FIRST_EXIT) { //while loop used to display the first menu if exit condition has not been met
        cout << endl << "Please select the item you would like to add to your inventory list or go back to main menu." << endl;  //prompts user to select an item to add to the list

        for (count = 0; count < FIRST_EXIT; count++) {  //for-loop used to output the first menu options
            cout << firstMenuOptions[count] << endl;    //outputs the first menu options
        }

        cin >> firstSelection;  //initializes "firstSelection" with selection from user

        if (firstSelection < FIRST_MIN || firstSelection > FIRST_EXIT) {    //if-statement used if user input is invalid
            cout << "\nSelection not valid, please try again." << endl; //outputs to user that the input is invalid
        }
    }
}

void addItem(string &itemName, double &price, int &qty, string &expireDate, int firstSelection) {   //creates a function used to receive input from user to add an item to the list
    const int VALID_PRICE_AND_QUANTITY = 0; //creates a variable used to validate the price and quantity
    int month;  //creates a variable for the month of the expiration date
    int day;    //creates a variable for the day of the expiration date
    int year;//creates a variable for the year of the expiration date
    const int FOOD = 2; //creates a variable used to add a food item
    bool validMonth = false;    //creates a variable used to validate the month
    bool validDay = false;  //creates a variable used to validate the day
    bool validYear = false; //creates a variable used to validate the year

    cout << endl << "Enter name of product: ";  //prompts user to enter the product name
    cin.ignore();   //ignores a character
    getline(cin,itemName);  //initializes "itemName" with input from user

    while (price <= VALID_PRICE_AND_QUANTITY) { //while-loop used to enter the price of the product
        cout << "Enter price of product per unit: $";   //prompts user to enter the price of the product
        cin >> price;   //initializes "price" with input from user

        if (price <= VALID_PRICE_AND_QUANTITY) {    //if-statement used if user input is invalid
            cout << "Invalid price, please try again." << endl; //outputs to user that the input is invalid
        }
    }

    if (firstSelection == FOOD) {   //if-statement used if the user selected to enter a food item
        cout << "Please properly dispose of all expired food before entering quantity and expiration date." << endl;
    }

    while (qty < VALID_PRICE_AND_QUANTITY) {    //while-loop used to enter the quantity of the product
        cout << "Enter quantity remaining: ";   //prompts user to enter the quantity of the product
        cin >> qty; //initializes "qty" with input from user

        if (qty < VALID_PRICE_AND_QUANTITY) {   //if-statement used if user input is invalid
            cout << "Invalid quantity, please try again." << endl;  //outputs to user that the input is invalid
        }
    }

    if (firstSelection == FOOD) {   //if-statement used if the user selected to enter a food item

        while ((validMonth == false) || (validDay == false) || (validYear == false)) {  //while-loop used to enter the expiration date
            cout << "Enter earliest expiration date that has not passed yet on all units (mm/dd/yyyy): ";   //prompts user to enter the earlieat expiration date
            cin >> month;   //initializes "month" with input from user
            cin.get();  //gets the "/" from input
            cin >> day; //initializes "day" with input from user
            cin.get();  //gets the "/" from input
            cin >> year;    //initializes "year" with input from user

            validateExpirationDate(validDay, validMonth, validYear, day, month, year);   //calls the function to validate the expiration date entered by user
        }

        expireDate = to_string(month) + "/" + to_string(day) + "/" + to_string(year);   //creates a string from the month, day, and year variables to make the expiration date
    }
}

int main() {
    vector<unique_ptr<Product>>productList; //creates a vector using smart pointers to store items from the product class
    struct MainMenu {   //creates a struct used to store variables for the main menu
        const int MAIN_MENU_EXIT = 4;   //creates a varible used as the main menu exit condition
        int mainMenuSelection = 0;  //creates a variable used to make a selection in the main menu
        const int ADD_ITEM = 1; //creates a variable used for the main menu
        const int REMOVE_ITEM = 2;  //creates a variable used for the main menu
    };
    struct FirstMenu {  //creates a struct used to store variables for the first menu
        const int FIRST_MENU_EXIT = 3;  //creates a variable used as an exit condition for the first menu
        const int ADD_NON_FOOD_ITEM = 1;    //creates a variable used for the first menu
        int firstMenuSelection = 0; //creates a variable used to make a selection in the first menu
        string productName; //creates a variable to store the product name
        double productPrice = 0;    //creates a variable to store the product price
        int quantity = -1;  //creates a variable to store the product quantity reamining
        string expirationDate;  //creates a variable to store the expiration date of a food item
    };
    struct SecondMenu { //creates a struct used to store variables for the second menu
        int secondMenuSelection = 0;    //creates a variable used to make a selection in the second menu
        int secondMenuExit; //creates a variable used as an exit condition for the second menu
        const int SECOND_MENU_MIN = 1;  //creates a variable used to validate for second menu
    };
    int i = 0;  //creates a variable used in loops
    MainMenu main;  //creates an object for the "MainMenu" struct
    FirstMenu first;    //creates an object for the "FirstMenu" struct
    SecondMenu second;  //creates an object for the "SecondMenu" struct

    while (main.mainMenuSelection != main.MAIN_MENU_EXIT) { //while-loop used to display the main menu if exit condition has not been met
        displayMainMenu(main.mainMenuSelection, main.MAIN_MENU_EXIT, i);    //calls the function to display the main menu options and receive input from user

        if (main.mainMenuSelection != main.MAIN_MENU_EXIT) {    //if-statement used if user did not want to exit program

            if (main.mainMenuSelection == main.ADD_ITEM) {  //if-statement used if user wanted to add an item to list

                while (first.firstMenuSelection != first.FIRST_MENU_EXIT) { //while-loop used to display the first menu if exit condition has not been met
                    first.firstMenuSelection = 0;   //initializes "firstMenuSelection" to 0

                    displayFirstMenu(first.firstMenuSelection, first.FIRST_MENU_EXIT, i);   //calls the function to display the first menu options and receive input from user

                    if (first.firstMenuSelection != first.FIRST_MENU_EXIT) {    //if-statement used if user did not want to leave the first menu
                        addItem(first.productName, first.productPrice, first.quantity, first.expirationDate, first.firstMenuSelection); //calls function to receive input from user to add an item to the list

                        if (first.firstMenuSelection == first.ADD_NON_FOOD_ITEM) {  //if-statement used if user added a non-food item
                            productList.push_back(make_unique<Product>(first.productName, first.productPrice, first.quantity)); //adds an item to the vector using smart pointers and constructor from product class using the input from user
                        }

                        else {  //else-statement used if user added a food item
                            productList.emplace_back(make_unique<FoodProduct>(first.productName, first.productPrice, first.quantity, first.expirationDate));    //adds an item to the vector using smart pointers and constructor from food product class using the input from user
                        }
                        first.productPrice = 0; //initializes "productPrice" to 0
                        first.quantity = -1;    //initializes "quantity" to -1
                        first.firstMenuSelection = 0;   //initializes "firstMenuSelection" to 0
                    }
                    cout << endl;   //outputs a blank line
                }
                first.firstMenuSelection = 0;   //initializes "firstMenuSelection" to 0
            }

            else if (main.mainMenuSelection == main.REMOVE_ITEM) {  //if-statement used if user wanted to remove an item from list
                second.secondMenuExit = 1 + productList.size(); //intitializes "secondMenuExit" to the number after the size of the list
                second.secondMenuSelection = 0; //initializes "secondMenuSelection" to 0

                while (second.secondMenuSelection != second.secondMenuExit) {   //while-loop used to display the list of items to remove if exit condition has not been met
                    i = 0;  //intitializes "i" to 0
                    cout << endl <<"Select which product to remove from inventory." << endl;    //prompts user to select the product to remove from the list

                    for (auto& product: productList) {  //for-loop used to display the names of the products on the list using smart pointers
                        i++;    //adds 1 to "i"
                        cout << i << ". ";  //outputs the number used to select that product
                        product->displayNames();    //calls the function used to display just the product names in vector
                    }
                    cout << second.secondMenuExit << ". Back To Main Menu " << endl;    //outputs the option used to exit the second menu
                    cin >> second.secondMenuSelection;  //initializes "secondMenuSelection" with input from user

                    if (second.secondMenuSelection != second.secondMenuExit) {  //if-statement used if the user did not want to exit the second menu
                        second.secondMenuSelection--;   //subtracts 1 from "secondMenuSelection"

                        productList.erase(productList.begin() + second.secondMenuSelection);    //erases the item in the vector using smart pointers that the user entered
                        second.secondMenuExit = 1 + productList.size(); //intitializes "secondMenuExit" to the number after the new size of the list
                        second.secondMenuSelection = 0; //initializes "secondMenuSelection" to 0
                    }

                    cout << endl;   //outputs a blank line
                }
            }

            else {  //else-statement used if user wanted to display the list
                cout << endl << "Inventory List:" << endl;  //outputs the inventory list
                for (auto& product: productList) {  //for-loop used to display the information of the products on the list using smart pointers
                    cout << setfill('-') << setw(112) << "" << endl;    //outputs a line
                    cout << setfill(' ');   //sets "setfill" to " "
                    product->display(); //calls the function used to display the product information in vector
                }
                cout << setfill('-') << setw(112) << "" << endl;    //outputs a line
                cout << setfill(' ');   //sets "setfill" to " "
                cout <<endl;    //outputs a blank line
            }

            main.mainMenuSelection = 0; //initializes "mainMenuSelection" to 0
        }
    }

    cout << "\nGoodbye!\n"; //outputs a goodbye message to user

   return 0;
}
