


                                          // start of the program

//header files
#include <iostream> // cout->output cin->input
#include <fstream> // File System ifstream(read) ofsream(write) fstream(both read and write)
#include <string> // to use string data type to store text
using namespace std;

// Parent class to present features of products
class Product
{
protected:
    // Prices for products of different category using array
    int prices[16] = {250, 150, 300, 450, 20000, 45000, 123000, 3000, 30, 15, 10, 25, 300, 150, 250, 150};

    // Quantities of each product initialized to zero using array
    int quantities[16] = {0};

public:
    string name;
    string address;

    // Function to display shop information
    void shopInfo();

    // Function to get customer information
    void customerInfo();

    // Function to display product categories
    void displayProduct();

    // Function to write invoice details in a specific file
    void programtoFile();
};

// Child class subproducts derived from parents class product
class subProducts : public Product
{
public:
    // Functions for displaying respective product categories
    void clothing();
    void electronics();
    void stationary();
    void groceries();
};

// Further child class derived from subproducts class for handling shopping and displaying receipt of customer
class Menu : public subProducts
{
public:
    // Function to handle the shopping process
    void shopProducts();

    // Function to display the final receipt of customer
    void displayReceipt();
};

// Function to display shop information
void Product::shopInfo()
{
    cout << "\t\t\t\t\tWelcome to Express Supermarket" << endl;
    cout << "\t\t\t\t\tMay your shopping be fruitful" << endl;
}

// Function to get customer information
void Product::customerInfo()
{
    cout << "\nEnter customer's name: ";
    getline(cin, name); //getline function is used to read the entire line with spaces and store in name variable

    cout << "Enter customer's address: ";
    getline(cin, address); //getline function is used to read the entire line with spaces and store in address variable
}

// Function to display product categories
void Product::displayProduct()
{
    int choice;
    cout << "\nCategories of Products: ";
    cout << "\n-----------------------";
    cout << "\n1. Clothing                   2. Electronics";
    cout << "\n3. Stationary                 4. Groceries";
    cout << "\n\nSelect the number of category: ";
    cin >> choice;

    subProducts s1; //creating an object of s1 of subproducts class to access functions of subproducs class as it is inside the displayproduct() function of class product

    switch (choice)
    {
    case 1:
        s1.clothing();
        break;
    case 2:
        s1.electronics();
        break;
    case 3:
        s1.stationary();
        break;
    case 4:
        s1.groceries();
        break;
    default:
        cout << "Invalid choice. Please enter a valid choice." << endl;
    }
}

// Function to display clothing products
void subProducts::clothing()
{
    string products[4] = {"Pant", "Shirt", "Sweater", "Hoodie"};
    cout << "\nID:\tCategory:\tProduct Name:\tPrice:" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << "\tClothing\t" << products[i] << "\t\tRs. " << prices[i] << endl;
    }
}

// Function to display electronics products
void subProducts::electronics()
{
    string products[4] = {"Printer", "Phone", "TV", "Speaker"};
    cout << "\nID:\tCategory:\tProduct Name:\tPrice:" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 5 << "\tElectronics\t" << products[i] << "\t\tRs. " << prices[i + 4] << endl;
    }
}

// Function to display stationary products
void subProducts::stationary()
{
    string products[4] = {"Pen", "Pencil", "Eraser", "Scale"};
    cout << "\nID:\tCategory:\tProduct Name:\tPrice:" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 9 << "\tStationary\t" << products[i] << "\t\tRs. " << prices[i + 8] << endl;
    }
}

// Function to display groceries products
void subProducts::groceries()
{
    string products[4] = {"Tomato", "Spinach", "Potato", "Carrot"};
    cout << "\nID:\tCategory:\tProduct Name:\tPrice(per kg):" << endl;
    cout << "----------------------------------------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 13 << "\tGroceries\t" << products[i] << "\t\tRs. " << prices[i + 12] << endl;
    }
}

// Function to handle the shopping process
void Menu::shopProducts()
{
    int id;
    char type;

    do
    {
        cout << "\nEnter the ID number of the product to buy: ";
        cin >> id;

        if (id >= 1 && id <= 16)
        {
            int quantity;
            cout << "Enter the quantity: ";
            cin >> quantity;

            // Add the specified quantity for the selected product
            quantities[id - 1] = quantities[id-1] + quantity;
        }
        else
        {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

        cout << "\nDo you want more products?" << endl;
        cout << "If yes, press y, if no, press n: ";
        cin >> type;

        if (type == 'y')
        {
            // If the user wants more products then it goes back to choose category section
            displayProduct();
        }

    } while (type == 'y');
}

// Function to display the final receipt of the customer
void Menu::displayReceipt()
{
    int Sum = 0;
    cout << "\n\n-----------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tINVOICE" << endl;
    cout << "\n\t\t\t\t Express Supermarket" << endl;
    cout << "\t\t\t\tBuddhanagar, Sankhamul" << endl;
    cout << "\t\t\t\t   Tel: +01-4472028" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "Name: " << name << "\t\t\t\t\t\tAddress: " << address << endl;
    cout << "\nID:\tCategory:\t\tProduct Name:\t\tQuantity:\tPrice:" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 16; ++i)
    {
        if (quantities[i] > 0)
        {
            string category;
            if (i >= 0 && i <= 3)
            {
                category = "Clothing";
            }
            else if (i >= 4 && i <= 7)
            {
                category = "Electronics";
            }
            else if (i >= 8 && i <= 11)
            {
                category = "Stationary";
            }
            else
            {
                category = "Groceries";
            }
            string products[16] = {"Pant", "Shirt", "Sweater", "Hoodie", "Printer", "Phone", "TV", "Charger", "Pen", "Pencil", "Eraser", "Scale", "Tomato", "Spinach", "Potato", "Carrot"};

            cout << i + 1 << "\t" << category << "\t\t" << products[i]<< "\t\t\t   " << quantities[i] << "\t\tRs. " << prices[i] * quantities[i] << endl;
            Sum = Sum + prices[i] * quantities[i];
        }
    }
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t\tTotal: Rs. " << Sum << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tThank You!" << endl;
    cout << "\t\t\t\tGlad to see you again!";
}


// Function to write invoice details to a specific file
void Product::programtoFile()
{
    fstream newfile; //create object to class fstream and name it newfile
    newfile.open("customerinvoice.txt", ios::app); //opens the file by the name customerinvoice.txt in append mode which helps to add further data to the existing file

    if (!newfile) //checks if the created file does not exist
    {
        cout << "File not opened" << endl;
    }
    else
    {
        cout << "\n\n\n\n\nFile created" << endl; //if file exists then it writes the same invoice in file using newfile object

        int Sum = 0;

        newfile << "-----------------------------------------------------------------------------------------" << endl;
        newfile << "\t\t\t\t\tINVOICE" << endl;
        newfile << "\n\t\t\t\t Express Supermarket" << endl;
        newfile << "\t\t\t\tBuddhanagar, Sankhamul" << endl;
        newfile << "\t\t\t\t   Tel: +01-4472028"<<endl;
        newfile << "Name: " << name << "\t\t\t\t\t\tAddress: " << address << endl;
        newfile << "-----------------------------------------------------------------------------------------" << endl;
        newfile << "\nID:\tCategory:\t\tProduct Name:\t\tQuantity:\tPrice:" << endl;

        for (int i = 0; i < 16; i++)
        {
            if (quantities[i] > 0)
            {
                string category;
                if (i >= 0 && i <= 3)
                {
                    category = "Clothing";
                }
                else if (i >= 4 && i <= 7)
                {
                    category = "Electronics";
                }
                else if (i >= 8 && i <= 11)
                {
                    category = "Stationary";
                }
                else
                {
                    category = "Groceries";
                }
                string products[16] = {"Pant", "Shirt", "Sweater", "Hoodie", "Printer", "Phone", "TV", "Charger", "Pen", "Pencil", "Eraser", "Scale", "Tomato", "Spinach", "Potato", "Carrot"};

                newfile << i + 1 << "\t" << category << "\t\t" << products[i]<< "\t\t\t   " << quantities[i] << "\t\tRs. " << prices[i] * quantities[i] << endl;
                Sum = Sum + prices[i] * quantities[i];
            }
        }

        newfile << "-----------------------------------------------------------------------------------------" << endl;
        newfile << "\t\t\t\t\t\t\t\t\tTotal: Rs. " << Sum << endl;
        newfile << "----------------------------------------------------------------------------------------" << endl;

        newfile.close();
    }
}

// Main function
int main()
{
    Menu m1;  // Creating an object of the Menu class

    m1.shopInfo();        // Accessing function from the Product class
    m1.customerInfo();    // Accessing function from the Product class
    m1.displayProduct();  // Accessing function from the Product class
    m1.shopProducts();    // Accessing function from the subProducts and Menu classes
    m1.displayReceipt();   // Accessing function from the subProducts and Menu classes
    m1.programtoFile();    // Accessing function from the Product class

    return 0;
}


                 //end of the program
