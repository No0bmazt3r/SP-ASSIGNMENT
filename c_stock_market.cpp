#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include<iomanip>

using namespace std;

/*
This is the comments for the code below 
1. Declared maxrow as a contant integer datatype. 
2. Declared others as arrray with the max row as the size of the array. 
3. Before you got to any other random function go to the very bottom which is the main function. 
*/

const int maxrow = 50;

string Username[maxrow] = {};
string Password[maxrow] = {};
string UsernameA[maxrow] = {};
string PasswordA[maxrow] = {};
string CUsername;
string ProductName[maxrow] = {};
int Quantity[maxrow] = {};
double Price[maxrow] = {};
int totquantity[maxrow] = {};
double totalprice[maxrow] = {};
string Pname[maxrow] = {};
string UsernameT[maxrow] = {};
string PasswrodT[maxrow] = {};
string ProductNameT[maxrow] = {};
int QuantityT[maxrow] = {};
double PriceT[maxrow] = {};


int getArrowKey() {
    int ch = _getch();
    if (ch == 0 || ch == 224) {
        ch = _getch();
        return ch;
    }
    return ch;
}

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetConsoleColor() {
    setConsoleColor(15); // Set to default color
}


void temp_Products_data(){

    /*
    This function reads data from the "products.txt" file and populates arrays with product information.
    1. Declare necessary variables, including a string to store each line from the file.
    2. Open the "products.txt" file for reading.
    3. Check if the file is successfully opened.
    4. Initialize a counter for tracking the number of products processed.
    5. Iterate through each line in the file using a while loop and getline.
    6. Find the positions of the commas in the line to extract product details.
    7. Check if both commas are found to ensure proper data formatting.
    8. Extract product name, price, and quantity from the line.
    9. Add necessary white spaces to the product name if its length is less than 15 characters.
    10. Check if the counter is within the limit (maxrow) before storing data in arrays.
    11. Display a warning if the maximum number of products is reached.
    12. Check if no records are found in the file and print a corresponding message.
    13. Close the file to prevent data loss.
    */

    string line;
    ifstream file("products.txt");

    if (file.is_open()) {
        ofstream tempFile("temp_products.txt");  // Create a temporary file

        if (tempFile.is_open()) {
            int counter = 0;

            while (getline(file, line)) {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);

                if (pos1 != string::npos && pos2 != string::npos) {
                    string productName = line.substr(0, pos1);
                    double price = stod(line.substr(pos1 + 1, pos2 - pos1));
                    int quantity = stoi(line.substr(pos2 + 1));

                    if (quantity > 0) {
                        if (counter < maxrow) {
                            ProductNameT[counter] = productName;
                            PriceT[counter] = price;
                            QuantityT[counter] = quantity;
                            counter++;
                        } else {
                            cout << "Warning: Maximum number of products reached." << endl;
                        }
                    }
                }
            }

            // Write the data to the temporary file
            for (int i = 0; i < counter; ++i) {
                tempFile << ProductNameT[i] << "," << PriceT[i] << "," << QuantityT[i] << endl;
            }

            if (counter == 0) {
                cout << "No record found" << endl;
            }

            tempFile.close();
        } else {
            cout << "Temporary file is not open" << endl;
        }

        file.close();

        // Replace the original file with the temporary file
        remove("products.txt");
        rename("temp_products.txt", "products.txt");
    } else {
        cout << "File is not open" << endl;
    }
}

void OpenProducts() {

    /*
    This is the comment section for the code belowa: 
    1. Alright this will follow line by line. First I declared line as a string variable. 
    2. Then I will open the "products.txt" file. 
    3. Then it will create a if statement when the file is open it will declared a counter vraible assigned to a integer datatype. 
    4. Then a while loop is form using the getline(file,line).
    5. In order to use getline we have to include the library called string. 
    6. The getline is a function where it will iterate all the line one by one in the textfile. 
    7. Then after also including stdio.h library I use pos where i declared as a unknow data type it will the first comma to exist in the textfile datat. 
    8. Same goes for the other pos which is pos2
    9. Then I made a if statement where it detects wether tht text file has the data or not if not it will print out no record found. 
    10. Then if there is data it will seprate occrodingly in this case productname, price, quantity it will detect the comma to tdetemine the location of the data. 
    11. Then i create another if statement to be saved into the array this will detect the length of the text and it will add necessary white spaces to make it look neat. 
    12. Then i used a counter variable as the array location to be saved in the array in the console so that it can be used later on when displaying. 
    13. Then it should close the file to ensure no lost of data. 
    */

    string line;
    ifstream file("products.txt");

    if (file.is_open()) {
        ofstream tempFile("temp_products1.txt");  // Create a temporary file

        if (tempFile.is_open()) {
            int counter = 0;

            while (getline(file, line)) {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);

                if (pos1 != string::npos && pos2 != string::npos) {
                    string productName = line.substr(0, pos1);
                    double price = stod(line.substr(pos1 + 1, pos2 - pos1));
                    int quantity = stoi(line.substr(pos2 + 1));

                if (productName.length() < 15) {
                    int spacesToAdd = 15 - productName.length();
                    for (int i = 0; i < spacesToAdd; ++i) {
                        productName += " ";
                    }
                }

                    if (quantity > 0) {
                        if (counter < maxrow) {
                            ProductName[counter] = productName;
                            Price[counter] = price;
                            Quantity[counter] = quantity;
                            counter++;
                        } else {
                            cout << "Warning: Maximum number of products reached." << endl;
                        }
                    }
                }
            }

            // Write the data to the temporary file
            for (int i = 0; i < counter; ++i) {
                tempFile << ProductNameT[i] << "," << PriceT[i] << "," << QuantityT[i] << endl;
            }

            if (counter == 0) {
                cout << "No records found" << endl;
            }

            tempFile.close();
        } else {
            cout << "Temporary file is not open" << endl;
        }

        file.close();

        // Replace the original file with the temporary file
        remove("products.txt");
        rename("temp_products1.txt", "products.txt");
    } else {
        cout << "File is not open" << endl;
    }
}

void OpenA() {

    /*
    This function reads admin data from the "admin.txt" file and populates arrays with username and password information.
    1. Declare necessary variables, including a string to store each line from the file.
    2. Open the "admin.txt" file for reading.
    3. Check if the file is successfully opened.
    4. Initialize a counter for tracking the number of admin users processed.
    5. Iterate through each line in the file using a while loop and getline.
    6. Find the position of the comma in the line to extract username and password details.
    7. Check if a comma is found to ensure proper data formatting.
    8. Extract username and password from the line.
    9. Add necessary white spaces to the username if its length is less than 25 characters.
    10. Check if the counter is within the limit (maxrow) before storing data in arrays.
    11. Display a warning if the maximum number of admin users is reached and exit the loop.
    12. Check if no records are found in the file and print a corresponding message.
    13. Close the file to prevent data loss.
    */

    string line;
    ifstream file("admin.txt");

    if (file.is_open()) {
        int counter = 0;

        while (getline(file, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string username = line.substr(0, pos);
                string password = line.substr(pos + 1);

                if (username.length() < 25) {
                    int spacesToAdd = 25 - username.length();
                    for (int i = 0; i < spacesToAdd; ++i) {
                        username += " ";
                    }
                }

                if (counter < maxrow) {
                    UsernameA[counter] = username;
                    PasswordA[counter] = password;
                    counter++;
                } else {
                    cout << "Warning: Maximum number of users reached." << endl;
                    break;
                }
            }
        }

        if (counter == 0) {
            cout << "No record found" << endl;
        }

        file.close();
    } else {
        cout << "File is not open" << endl;
    }
}

void OpenC() {

    /*
    This function reads user data from the "users.txt" file and populates arrays with username and password information.
    1. Declare necessary variables, including a string to store each line from the file.
    2. Open the "users.txt" file for reading.
    3. Check if the file is successfully opened.
    4. Initialize a counter for tracking the number of users processed.
    5. Iterate through each line in the file using a while loop and getline.
    6. Find the position of the comma in the line to extract username and password details.
    7. Check if a comma is found to ensure proper data formatting.
    8. Extract username and password from the line.
    9. Add necessary white spaces to the username if its length is less than 25 characters.
    10. Check if the counter is within the limit (maxrow) before storing data in arrays.
    11. Display a warning if the maximum number of users is reached and exit the loop.
    12. Check if no records are found in the file and print a corresponding message.
    13. Close the file to prevent data loss.
    */

    string line;
    ifstream file("users.txt");

    if (file.is_open()) {
        int counter = 0;

        while (getline(file, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string username = line.substr(0, pos);
                string password = line.substr(pos + 1);

                if (username.length() < 25) {
                    int spacesToAdd = 25 - username.length();
                    for (int i = 0; i < spacesToAdd; ++i) {
                        username += " ";
                    }
                }

                if (counter < maxrow) {
                    Username[counter] = username;
                    Password[counter] = password;
                    counter++;
                } else {
                    cout << "Warning: Maximum number of users reached." << endl;
                    break;
                }
            }
        }

        if (counter == 0) {
            cout << "No record found" << endl;
        }

        file.close();
    } else {
        cout << "File is not open" << endl;
    }
}

void Open_all_files(){

    /*
    This is the comment section for the code below: 
    1. Practically in this function it is called three other function which you can see below. 
    */

    OpenProducts();
    OpenA();
    OpenC();
}

void temp_Customer_user(){

    /*
    This function reads user data from the "users.txt" file and populates temporary arrays with username and password information.
    1. Declare necessary variables, including a string to store each line from the file.
    2. Open the "users.txt" file for reading.
    3. Check if the file is successfully opened.
    4. Initialize a counter for tracking the number of users processed.
    5. Iterate through each line in the file using a while loop and getline.
    6. Find the position of the comma in the line to extract username and password details.
    7. Check if a comma is found to ensure proper data formatting.
    8. Extract username and password from the line.
    9. Check if the counter is within the limit (maxrow) before storing data in temporary arrays.
    10. Display a warning if the maximum number of users is reached and exit the loop.
    11. Check if no records are found in the file and print a corresponding message.
    12. Close the file to prevent data loss.
    */

    string line;
    ifstream file("users.txt");

    if (file.is_open()) {
        int counter = 0;

        while (getline(file, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string username = line.substr(0, pos);
                string password = line.substr(pos + 1);

                if (counter < maxrow) {
                    UsernameT[counter] = username;
                    PasswrodT[counter] = password;
                    counter++;
                } else {
                    cout << "Warning: Maximum number of users reached." << endl;
                    break;
                }
            }
        }

        if (counter == 0) {
            cout << "No record found" << endl;
        }

        file.close();
    } else {
        cout << "File is not open" << endl;
    } 
}

void admin_delete_user(){

    /*
    This function allows an admin to delete a user by searching for the username in temporary arrays.
    1. Call the temp_Customer_user() function to populate temporary arrays with user data.
    2. Prompt the admin to enter the username to be deleted.
    3. Iterate through the temporary arrays to find the specified username.
    4. If the username is found, display user details and prompt for confirmation.
    5. If confirmed, delete the user from temporary arrays and update the "users.txt" file.
    6. Display a success message if the user is deleted; otherwise, display a cancellation message.
    7. If the username is not found, display a corresponding message.
    */

    temp_Customer_user();

    string search;
    cout << "\t\t\t\t\t\tEnter the username to be deleted: ";
    setConsoleColor(2);
    cin >> search;
    resetConsoleColor();

    bool userFound = false;
    int index = -1;

    for (int x = 0; x < maxrow; ++x) {
        if (UsernameT[x] == search) {
            userFound = true;
            index = x;

            cout << "\t\t\t\t\t\tUser found:" << endl;
            cout << "\t\t\t\t\t\tUsername: ";
            setConsoleColor(2);
            cout<< UsernameT[x] << endl;
            resetConsoleColor();
            cout << "\t\t\t\t\t\tPassword: ";
            setConsoleColor(2);
            cout<< PasswrodT[x] << endl;
            resetConsoleColor();

            char confirm;
            cout << "\n\t\t\t\t\t\tAre you sure you want to delete this user? (y/n): ";
            setConsoleColor(2);
            cin >> confirm;
            resetConsoleColor();

            if (confirm == 'y' || confirm == 'Y') {
                UsernameT[x] = "";
                PasswrodT[x] = "";

                cout << "\t\t\t\t\t\tUser deleted successfully." << endl;

                for (int i = x; i < maxrow - 1; ++i) {
                    UsernameT[i] = UsernameT[i + 1];
                    PasswrodT[i] = PasswrodT[i + 1];
                }

                ofstream file("users.txt");
                for (int i = 0; i < maxrow - 1; ++i) {
                    if (UsernameT[i] != "") {
                        file << UsernameT[i] << "," << PasswrodT[i] << endl;
                    }
                }
                file.close();
            } else {
                cout << "\t\t\t\t\t\tUser deletion canceled." << endl;
            }

            break;
        }
    }

    if (!userFound) {
        cout << "\t\t\t\t\t\tUser not found." << endl;
        return;
    }
}

void ListProducts(){

    /*
    This function lists the current products by displaying their names, prices, and quantities.
    1. Call the Open_all_files() function to ensure all necessary files are open.
    2. Clear the console screen using system("cls").
    3. Display a header for the product list.
    4. Initialize a counter for tracking the number of products displayed.
    5. Iterate through the product arrays to print product details.
    6. Display a message if no records are found.
    7. Display a footer for the product list.
    */    

    temp_Products_data();
    Open_all_files();
    system ("cls");

    cout<<"\t\t\t\t\t\tCurrent Products"<<endl;
    cout<<"\t\t\t\t\t\t====================================================="<<endl;

    int counter = 0;

    cout<<"\t\t\t\t\t\t No. |   Product Name    |   Price    |  Quantity   |"<<endl<<"\t\t\t\t\t\t-----------------------------------------------------\n";

    for (int x = 0; x < maxrow; x++)
    {
        if (ProductName[x] != "\0")
        {
            counter++;
            cout<<"\t\t\t\t\t\t  "<< counter << "     "<< ProductName[x]<<"        "<<Price[x]<<"            "<< Quantity[x]<<endl;
        }
        
    }

    if (counter == 0)
    {
        cout<<"\t\t\t\t\t\tNo record found"<<endl;
    }
    
    cout<<"\t\t\t\t\t\t=====================================================\n";
}

void admin_delete_product() {

    /*
    This function allows an admin to delete a product by searching for the product name in temporary arrays.
    1. Call the temp_Products_data() function to populate temporary arrays with product data.
    2. Prompt the admin to enter the product name to be deleted.
    3. Iterate through the temporary arrays to find the specified product name.
    4. If the product name is found, display product details and prompt for confirmation.
    5. If confirmed, delete the product from temporary arrays and update the "products.txt" file.
    6. Display a success message if the product is deleted; otherwise, display a cancellation message.
    7. If the product name is not found, display a corresponding message.
    */

    temp_Products_data();
    ListProducts();
    string search;
    cout << "\t\t\t\t\t\tEnter the product name: ";
    setConsoleColor(2);
    cin >> search;
    resetConsoleColor();

    bool productFound = false;
    int index = -1;

    for (int x = 0; x < maxrow; ++x) {
        if (ProductNameT[x] == search) {
            productFound = true;
            index = x;

            cout << "\t\t\t\t\t\tProduct found:" << endl;
            cout << "\t\t\t\t\t\tName: ";
            setConsoleColor(2);
            cout<< ProductNameT[x] << endl;
            resetConsoleColor();
            cout << "\t\t\t\t\t\tPrice: RM";
            setConsoleColor(2);
            cout<< PriceT[x] << endl;
            resetConsoleColor();
            cout << "\t\t\t\t\t\tQuantity available: ";
            setConsoleColor(2);
            cout<< QuantityT[x] << endl;
            resetConsoleColor();

            char confirm;
            cout << "\n\t\t\t\t\t\tAre you sure you want to delete this product? (y/n): ";
            setConsoleColor(2);
            cin >> confirm;
            resetConsoleColor();

            if (confirm == 'y' || confirm == 'Y') {
                ProductNameT[x] = "";
                PriceT[x] = 0.0;
                QuantityT[x] = 0;

                cout << "\t\t\t\t\t\tProduct deleted successfully." << endl;

                for (int i = x; i < maxrow - 1; ++i) {
                    ProductNameT[i] = ProductNameT[i + 1];
                    PriceT[i] = PriceT[i + 1];
                    QuantityT[i] = QuantityT[i + 1];
                }

                ofstream file("products.txt");
                for (int i = 0; i < maxrow - 1; ++i) {
                    if (ProductNameT[i] != "") {
                        file << ProductNameT[i] << "," << PriceT[i] << "," << QuantityT[i] << endl;
                    }
                }
                file.close();
            } else {
                cout << "\t\t\t\t\t\tProduct deletion canceled." << endl;
            }

            break;
        }
    }

    if (!productFound) {
        cout << "\t\t\t\t\t\tProduct not found." << endl;
        return;
    }
}

void admin_store_product() {
    
    /*
    This function stores product information in the "products.txt" file.
    1. Open the "products.txt" file for writing using ofstream.
    2. Iterate through the product arrays to write product details to the file.
    3. Stop writing when an empty slot in the array is encountered.
    4. Close the file to save changes.
    */

    ofstream myfile;
    myfile.open("products.txt");

    for (int x = 0; x < maxrow; x++) {
        if (ProductNameT[x] == "\0") {
            break;
        } else {
            myfile << ProductNameT[x] + "," + to_string(PriceT[x]) + "," + to_string(QuantityT[x]) << endl;
        }
    }

    myfile.close();
}

void admin_add_product() {

    /*
    This function allows an admin to add a new product to the stock.
    1. Clear the console screen using system("cls").
    2. Prompt the admin to enter product details such as name, quantity, and price.
    3. Iterate through the product arrays to find an empty slot and add the new product.
    */

    system("cls");
    string productName;
    int quantity;
    double price;

    ListProducts();

    cout << "\t\t\t\t\t\tAdd Product to Stock\n";
    cout << "\t\t\t\t\t\tProduct Name: ";
    setConsoleColor(2);
    cin >> productName;cout<<endl;
    resetConsoleColor();
    cout << "\t\t\t\t\t\tQuantity: ";
    setConsoleColor(2);
    cin >> quantity;cout<<endl;
    resetConsoleColor();
    cout << "\t\t\t\t\t\tPrice: ";
    setConsoleColor(2);
    cin >> price;cout<<endl;
    resetConsoleColor();

    for (int x = 0; x < maxrow; x++) {
        if (ProductNameT[x] == "\0") {
            ProductNameT[x] = productName;
            QuantityT[x] = quantity;
            PriceT[x] = price;
            break;
        }
    }
}

void admin_edit_product() {

    /*
    This function allows an admin to edit details of an existing product.
    1. Call the temp_Products_data() function to populate temporary arrays with product data.
    2. Prompt the admin to enter the product name to be edited.
    3. Iterate through the temporary arrays to find the specified product name.
    4. If the product name is found, display current details and prompt for confirmation.
    5. If confirmed, update the temporary arrays with the new details.
    6. Write the updated details to the "products.txt" file.
    7. Display a success message if the product details are updated.
    8. If the product name is not found, display a corresponding message.
    */

    temp_Products_data();
    ListProducts();
    string search;
    cout << "\t\t\t\t\t\tEnter the product name you want to edit: ";
    setConsoleColor(2);
    cin >> search;
    resetConsoleColor();

    bool productFound = false;
    int index = -1;
    for (int x = 0; x < maxrow; ++x) {
        if (ProductNameT[x] == search) {
            productFound = true;
            index = x;

            cout << "\t\t\t\t\t\tProduct found:" << endl;
            cout << "\t\t\t\t\t\tName: ";
            setConsoleColor(2);
            cout<< ProductNameT[x] << endl;
            resetConsoleColor();
            cout << "\t\t\t\t\t\tPrice: RM";
            setConsoleColor(2);
            cout<< PriceT[x] << endl;
            resetConsoleColor();
            cout << "\t\t\t\t\t\tQuantity available: ";
            setConsoleColor(2);
            cout<< QuantityT[x] << endl;
            resetConsoleColor();

            cout << "\t\t\t\t\t\tDo you want to edit this product? (Y/N): ";
            char confirmation;
            setConsoleColor(2);
            cin >> confirmation;
            resetConsoleColor();

            if (confirmation == 'Y' || confirmation == 'y') {
                cout << "\n\t\t\t\t\t\tEnter new details:" << endl;
                cout << "\t\t\t\t\t\tNew Name: ";
                setConsoleColor(2);
                cin >> ProductNameT[x];
                resetConsoleColor();
                cout << "\t\t\t\t\t\tNew Price: RM";
                setConsoleColor(2);
                cin >> PriceT[x];
                resetConsoleColor();
                cout << "\t\t\t\t\t\tNew Quantity: ";
                setConsoleColor(2);
                cin >> QuantityT[x];
                resetConsoleColor();

                cout << "\t\t\t\t\t\tProduct details updated successfully." << endl;

                ofstream file("products.txt");

                for (int i = 0; i < maxrow; ++i) {
                    if (ProductName[i] != "\0") {
                        file << ProductNameT[i] << "," << PriceT[i] << "," << QuantityT[i] << endl;
                    }
                }

                file.close();
            } else {
                cout << "\t\t\t\t\t\tEditing canceled by user." << endl;
            }

            break;
        }
    }

    if (!productFound) {
        cout << "\t\t\t\t\t\tProduct not found." << endl;
        return;
    }
}

void drawAdminViewProducts(int selectedOption, int maxOption) {
    system("cls");
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;
    cout << "\t\t\t\t\t\t\t\t         Products Menu" << endl;
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;

    for (int i = 1; i <= maxOption; ++i) {
        if (i == selectedOption) {
            setConsoleColor(4 + 240);
            cout << "\t\t\t\t\t\t\t\t\t" << i << ". ";
        } else {
            resetConsoleColor(); // Reset text color for non-selected options
            cout << "\t\t\t\t\t\t\t\t\t" << i << ". ";
        }

        switch (i) {
            case 1:
                cout << "Add a Product" << endl;
                break;
            case 2:
                cout << "Edit a Product" << endl;
                break;
            case 3:
                cout << "Delete a Product" << endl;
                break;
            case 4: 
                cout << "Exit to Main Menu" << endl;
        }
    }
    resetConsoleColor(); // Reset text color after drawing the menu
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;
}

void admin_view_products() {
    int option = 1;
    int key;

    do {

        drawAdminViewProducts(option,4);

        key = getArrowKey();

        switch (key) {
            case 72: // Up arrow key
                option = (option == 1) ? 3 : option - 1;
                break;
            case 80: // Down arrow key
                option = (option == 4) ? 1 : option + 1;
                break;
            case 13: // Enter key
                switch (option) {
                    case 1:
                        admin_add_product();
                        admin_store_product();
                        break;
                    case 2:
                        temp_Products_data();
                        admin_edit_product();
                        break;
                    case 3:
                        temp_Products_data();
                        admin_delete_product();
                        break;
                }
                break;
        }
    } while (key != 13 || option != 4);
}

void ViewAdmin(){

    /*
    This function displays the current list of administrators (users) with their usernames and passwords.
    1. Call the Open_all_files() function to ensure all necessary files are open.
    2. Clear the console screen using system("cls").
    3. Display a header for the list of administrators.
    4. Initialize a counter for tracking the number of administrators displayed.
    5. Iterate through the administrator arrays to print administrator details.
    6. Display a message if no records are found.
    7. Display a footer for the list of administrators.
    */

    Open_all_files();
    system("cls");
    cout<<"\n\t\t\t\t\t\tCurrent Users"<<endl;
    cout<<"\t\t\t\t\t\t=============================================="<<endl;

    int counter = 0;

    cout<<"\t\t\t\t\t\t No. |        Username       |   Password    |"<<endl<<"\t\t\t\t\t\t----------------------------------------------\n";

    for (int x = 0; x < maxrow; x++)
    {
        if (UsernameA[x] != "\0")
        {
            counter++;
            cout<<"\t\t\t\t\t\t  "<< counter <<"      " << UsernameA[x]<<PasswordA[x]<<endl;
        }
        
    }

    if (counter == 0)
    {
        cout<<"\t\t\t\t\t\tNo record found"<<endl;
    }
    
    cout<<"\t\t\t\t\t\t==============================================\n";
}

void ViewUsers(){

    /*
    This function displays the current list of users with their usernames and passwords.
    1. Call the Open_all_files() function to ensure all necessary files are open.
    2. Clear the console screen using system("cls").
    3. Display a header for the list of users.
    4. Initialize a counter for tracking the number of users displayed.
    5. Iterate through the user arrays to print user details.
    6. Display a message if no records are found.
    7. Display a footer for the list of users.
    */

    Open_all_files();
    system("cls");
    cout<<"\n\t\t\t\t\t\tCurrent Users"<<endl;
    cout<<"\t\t\t\t\t\t=============================================="<<endl;

    int counter = 0;

    cout<<"\t\t\t\t\t\t No. |        Username       |   Password    |"<<endl<<"\t\t\t\t\t\t----------------------------------------------\n";

    for (int x = 0; x < maxrow; x++)
    {
        if (Username[x] != "\0")
        {
            counter++;
            cout<<"\t\t\t\t\t\t  "<< counter <<"      " << Username[x]<<Password[x]<<endl;
        }
        
    }

    if (counter == 0)
    {
        cout<<"\t\t\t\t\t\tNo record found"<<endl;
    }
    
    cout<<"\t\t\t\t\t\t==============================================\n";
    
}

void edit_user() {

    /*
    This function allows the administrator to edit the details of an existing user.
    1. Call the temp_Customer_user() function to populate temporary arrays with user data.
    2. Prompt the administrator to enter the username to be edited.
    3. Iterate through the temporary arrays to find the specified username.
    4. If the username is found, display current details and prompt for new details.
    5. Update the temporary arrays with the new details.
    6. Write the updated details to the "users.txt" file.
    7. Display a success message if the user details are updated.
    8. If the username is not found, display a corresponding message.
    */

    temp_Customer_user();
    string search;
    char decision;
    cout << "\t\t\t\t\t\tEnter the user you wish to update details: ";
    setConsoleColor(2);
    cin >> search;
    resetConsoleColor();
    bool userFound = false;
    int index = -1;

    for (int x = 0; x < maxrow; ++x) {
        if (UsernameT[x] == search) {
            userFound = true;
            index = x;
            system("cls");
            cout << "\t\t\t\t\t\tUser found:" << endl;
            cout << "\t\t\t\t\t\tName: ";
            setConsoleColor(2);
            cout<< UsernameT[x] << endl;
            resetConsoleColor();
            cout << "\t\t\t\t\t\tPassword: ";
            setConsoleColor(2);
            cout<< PasswrodT[x] << endl;
            resetConsoleColor();

            cout << "\t\t\t\t\t\tDo you wish to update the user details??? (y/n): ";
            setConsoleColor(2);
            cin >> decision;
            resetConsoleColor();
            cout << endl;

            if (decision == 'y' || decision == 'Y') {
                cout << "\n\t\t\t\t\t\tEnter new details:" << endl;
                cout << "\t\t\t\t\t\tNew Name: ";
                setConsoleColor(2);
                cin >> UsernameT[x];
                resetConsoleColor();  

                cout << "\t\t\t\t\t\tNew Password: ";
                setConsoleColor(2);
                cin >> PasswrodT[x];
                resetConsoleColor();  

                cout << "\t\t\t\t\t\tUser details updated successfully." << endl;

                ofstream file("users.txt");

                for (int x = 0; x < maxrow; ++x) {
                    if (Username[x] != "\0") {
                        file << UsernameT[x] << "," << PasswrodT[x] << endl;
                    }
                }

                file.close();
            }

            break;
        }
    }

    if (!userFound) {
        cout << "\t\t\t\t\t\tUser not found." << endl;
    }
}

void drawAdminEditUsersMenu(int selectedOption, int maxOption) {
    system("cls");
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;
    cout << "\t\t\t\t\t\t\t\t    Admin Edit User Menu" << endl;
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;

    for (int i = 1; i <= maxOption; ++i) {
        if (i == selectedOption) {
            setConsoleColor(4 + 240);
            cout << "\t\t\t\t\t\t\t\t\t" << i << ". ";
        } else {
            resetConsoleColor(); // Reset text color for non-selected options
            cout << "\t\t\t\t\t\t\t\t\t" << i << ". ";
        }

        switch (i) {
            case 1:
                cout << "Edit User" << endl;
                break;
            case 2:
                cout << "Delete User" << endl;
                break;
            case 3:
                cout << "Exit" << endl;
                break;
        }
    }
    resetConsoleColor(); // Reset text color after drawing the menu
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;
}

void adminEditUsers() {
    int option = 1;
    int key;

    do {
        drawAdminEditUsersMenu(option, 3);

        key = getArrowKey();

        switch (key) {
            case 72: // Up arrow key
                option = (option == 1) ? 3 : option - 1;
                break;
            case 80: // Down arrow key
                option = (option == 3) ? 1 : option + 1;
                break;
            case 13: // Enter key
                switch (option) {
                    case 1:
                        ViewUsers();
                        edit_user();
                        break;
                    case 2:
                        ViewUsers();
                        admin_delete_user();
                        break;
                }
                break;
        }
    } while (key != 13 || option != 3);
}

void drawAdminMenu(int selectedOption, int maxOption) {
    system("cls");
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;
    cout << "\t\t\t\t\t\t\t\t         Admin Menu" << endl;
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;

    for (int i = 1; i <= maxOption; ++i) {
        if (i == selectedOption) {
            setConsoleColor(4 + 240);
            cout << "\t\t\t\t\t\t\t\t\t" << i << ". ";
        } else {
            resetConsoleColor(); // Reset text color for non-selected options
            cout << "\t\t\t\t\t\t\t\t\t" << i << ". ";
        }

        switch (i) {
            case 1:
                cout << "View All Users" << endl;
                break;
            case 2:
                cout << "View All Products" << endl;
                break;
            case 3: 
                cout << "Log Out" << endl;
        }
    }
    resetConsoleColor(); // Reset text color after drawing the menu
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;
}

void Admin() {
    int option = 1;
    int key;

    do {
        drawAdminMenu(option,3);

        key = getArrowKey();

        switch (key) {
            case 72: // Up arrow key
                option = (option == 1) ? 3 : option - 1;
                break;
            case 80: // Down arrow key
                option = (option == 3) ? 1 : option + 1;
                break;
            case 13: // Enter key
                switch (option) {
                    case 1:
                        adminEditUsers();
                        break;
                    case 2:
                        admin_view_products();
                        break;
                    case 3:
                        cout << "Succefully Logged Out."<<endl;
                }
                break;
        }
    } while (key != 13 || option != 3);
}



void update_products_file() {

    /*
    This function updates the "products.txt" file with the modified product data.
    1. Open the "products.txt" file in write mode.
    2. Iterate through the temporary product arrays to write the updated data to the file.
    3. Close the file after writing.
    */

    ofstream myfile;
    myfile.open("products.txt");

    for (int x = 0; x < maxrow; x++) {
        if (ProductName[x] != "\0") {
            myfile << ProductNameT[x] << "," << PriceT[x] << "," << QuantityT[x] << endl;
        }
    }

    myfile.close();
}

void open_customer_cart_data() {

    /*
    This function reads the customer's cart data from the "cart<Username>.txt" file.
    1. Open the file with the customer's specific cart filename.
    2. Read each line from the file and extract product details (name, quantity, price).
    3. Store the data in the temporary arrays Pname, totquantity, and totalprice.
    4. Display a warning if the maximum number of products is reached.
    5. Display a message if no records are found in the cart.
    6. Close the file after processing.
    */

    string line;
    ifstream file("cart" + CUsername + ".txt");

    if (file.is_open()) {
        int counter = 0;

        while (getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);

            if (pos1 != string::npos && pos2 != string::npos) {
                string productName = line.substr(0, pos1);
                int quantity = stoi(line.substr(pos1 + 1, pos2 - pos1));
                double price = stod(line.substr(pos2 + 1));

                if (productName.length() < 15) {
                    int spacesToAdd = 15 - productName.length();
                    for (int i = 0; i < spacesToAdd; ++i) {
                        productName += " ";
                    }
                }

                if (counter < maxrow) {
                    Pname[counter] = productName;
                    totquantity[counter] = quantity;
                    totalprice[counter] = price;
                    counter++;
                } else {
                    cout << "Warning: Maximum number of products reached." << endl;
                    break;
                }
            }
        }

        if (counter == 0) {
            cout << "No record found" << endl;
        }

        file.close();
    } else {
        cout << "File is not open" << endl;
    }
}

void view_cart() {

    /*
    This function displays the customer's cart, calculates the overall total, and prompts for payment options.
    1. Call open_customer_cart_data() to load cart data into temporary arrays.
    2. Display the current products in the cart with product name, quantity, and price.
    3. Calculate the overall total of the items in the cart.
    4. Prompt the customer for the payment method (cash or card).
    5. Delete the cart file after payment confirmation.
    6. Display a thank you message based on the chosen payment method.
    */

    double overalltotal = 0;
    open_customer_cart_data();

    system("cls");

    cout << "\t\t\t\t\t\tCurrent Products" << endl;
    cout << "\t\t\t\t\t\t======================================================" << endl;

    int counter = 0;

    cout << "\t\t\t\t\t\t No. |   Product Name    |   Quantity    |  Price    |" << endl
         << "\t\t\t\t\t\t------------------------------------------------------\n";

    for (int x = 0; x < maxrow; x++) {
        if (Pname[x] != "\0") {
            counter++;
            cout << "\t\t\t\t\t\t  " << counter << "     " << Pname[x] << "          " << totquantity[x] << "            " << totalprice[x] << endl;

            overalltotal += totalprice[x];
        }
    }

    if (counter == 0) {
        cout << "\t\t\t\t\t\tNo record found" << endl;
    }

    cout << "\t\t\t\t\t\t======================================================\n";

    if (overalltotal > 0) {
        cout << "\n\t\t\t\t\t\tYour overall total for the items you have bought is RM " << overalltotal << ". \n\t\t\t\t\t\tThank you and please come again " << CUsername << endl;

        string option;
        cout << "\n\t\t\t\t\t\tWould you like to pay in cash or card? : ";
        setConsoleColor(2);
        cin >> option;
        resetConsoleColor();
        cout << endl;


        if (option == "cash" || option == "Cash" || option == "CASH") {
            if (remove(("cart" + CUsername + ".txt").c_str()) != 0) {
                perror("\t\t\t\t\t\tError deleting file");
            } else {
                puts("\t\t\t\t\t\tFile successfully deleted");
            }

            cout << "\t\t\t\t\t\tThank you for your payment in cash. Please come again." << endl;
        } else if (option == "card" || option == "Card" || option == "CARD") {
            if (remove(("cart" + CUsername + ".txt").c_str()) != 0) {
                perror("\t\t\t\t\t\tError deleting file");
            } else {
                puts("\t\t\t\t\t\tFile successfully deleted");
            }
            cout << "\t\t\t\t\t\tThank you for your payment with a card. Please come again." << endl;
        } else {
            cout << "\t\t\t\t\t\tInvalid Payment choice." << endl;
        }
    } else {
        cout << "\t\t\t\t\t\tYour cart is empty. No payment required." << endl;
    }
}

void add_to_cart() {
    temp_Products_data();

    string search;
    cout << "\t\t\t\t\t\tEnter the product name: ";
    setConsoleColor(2);
    cin >> search;
    resetConsoleColor();

    bool productFound = false;
    int index = -1;

    // Search for the product in the array
    for (int x = 0; x < maxrow; ++x) {
        if (ProductNameT[x] == search) {
            productFound = true;
            index = x;

            cout << "\n\t\t\t\t\t\tProduct found:" << endl;
            cout << "\t\t\t\t\t\tName: ";
            setConsoleColor(2);
            cout << ProductNameT[x] << endl;
            resetConsoleColor();
            cout << "\t\t\t\t\t\tPrice: RM ";
            setConsoleColor(2);
            cout<< PriceT[x] << endl;
            resetConsoleColor();
            cout << "\t\t\t\t\t\tQuantity available: ";
            setConsoleColor(2);
            cout<< QuantityT[x] << endl;
            resetConsoleColor();
            break;
        }
    }

    if (!productFound) {
        cout << "\n\t\t\t\t\t\tProduct not found." << endl;
        return;
    }

    char response;
    double totprice;
    int quantityToBuy;

    cout << "\n\t\t\t\t\t\tDo you wish to buy this product? (y/n): ";
    setConsoleColor(2);
    cin >> response;
    resetConsoleColor();

    if (response == 'y' || response == 'Y') {
        cout << "\t\t\t\t\t\tHow much would you like to buy? Enter quantity: ";
        setConsoleColor(2);
        cin >> quantityToBuy;
        resetConsoleColor();

        if (quantityToBuy > 0 && quantityToBuy <= QuantityT[index]) {
            QuantityT[index] -= quantityToBuy;

            cout << "\t\t\t\t\t\tPurchase successful. Added " << quantityToBuy << " " << search << " to your cart." << endl;

            totprice = PriceT[index] * quantityToBuy;

            // Find an empty slot in the cart and update values
            int cartIndex = -1;
            for (int x = 0; x < maxrow; x++) {
                if (CUsername != "" && totquantity[x] == 0) {
                    cartIndex = x;
                    totquantity[x] = quantityToBuy;
                    totalprice[x] = totprice;
                    break;  // Exit the loop after updating the values
                }
            }

            // Check if an empty slot was found in the cart
            if (cartIndex != -1) {
                update_products_file();  // Assuming this function writes updated product information to a file

                ofstream myfile;
                myfile.open("cart" + CUsername + ".txt", ios::app);

                // Write information to the cart file
                myfile << search << "," << totquantity[cartIndex] << "," << totalprice[cartIndex] << endl;
                myfile.close();
            } else {
                cout << "\t\t\t\t\t\tError: Cart is full. Purchase unsuccessful." << endl;
                // Roll back the quantity update in the products array
                QuantityT[index] += quantityToBuy;
            }
        } else {
            cout << "\t\t\t\t\t\tInvalid quantity. Purchase unsuccessful." << endl;
        }
    } else {
        cout << "\t\t\t\t\t\tProduct not purchased." << endl;
    }

    system("cls");
}

void drawCustomerMenu(int selectedOption, int maxOption) {
    system("cls");
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;
    cout << "\t\t\t\t\t\t\t\t         Customer Menu" << endl;
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;

    for (int i = 1; i <= maxOption; ++i) {
        if (i == selectedOption) {
            setConsoleColor(4 + 240);
            cout << "\t\t\t\t\t\t\t\t\t" << i << ". ";
        } else {
            resetConsoleColor(); // Reset text color for non-selected options
            cout << "\t\t\t\t\t\t\t\t\t" << i << ". ";
        }

        switch (i) {
            case 1:
                cout << "Add to Cart" << endl;
                break;
            case 2:
                cout << "View Cart" << endl;
                break;
            case 3:
                cout << "Log Out" << endl;
                break;
        }
    }
    resetConsoleColor(); // Reset text color after drawing the menu
    cout << "\t\t\t\t\t\t\t\t===============================" << endl;
}

void Customer() {
    int option;
    int key;

    do {
        drawCustomerMenu(option,3);

        key = getArrowKey();

        switch (key) {
            case 72: // Up arrow key
                option = (option == 1) ? 3 : option - 1;
                break;
            case 80: // Down arrow key
                option = (option == 3) ? 1 : option + 1;
                break;
            case 13: // Enter key
                switch (option) {
                    case 1:
                        system("cls");
                        ListProducts();
                        add_to_cart();
                        break;
                    case 2:
                        system("cls");
                        view_cart();
                        break;
                    case 3:
                        cout << "\n\t\t\t\t\t\t\t\t\tLogging out. Goodbye!" << endl;
                        break;
                }
                break;
        }
    } while (key != 13 || option != 3);
}




void Log_in() {

    /*
    This function simulates the login process for users and administrators.
    1. Prompt the user for a username and password.
    2. Check if the entered credentials match any user or admin in the respective files.
    3. If a match is found, set the CUsername and call the corresponding menu function.
    4. If no match is found, inform the user of invalid credentials.
    */

    string username, password;

    cout << "\n\t\t\t\t\t\tUsername: ";
    setConsoleColor(2);
    cin >> username; cout << endl;
    resetConsoleColor();
    cout << "\t\t\t\t\t\tPassword: "; 
    setConsoleColor(2);
    cin >> password; cout << endl;
    resetConsoleColor();

    bool isUser = false;
    bool isAdmin = false;

    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        string line;
        while (getline(userFile, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string storedUsername = line.substr(0, pos);
                string storedPassword = line.substr(pos + 1);
                if (username == storedUsername && password == storedPassword) {
                    isUser = true;
                    CUsername = username;
                    break;
                }
            }
        }
        userFile.close();
    } else {
        cout << "Unable to open user file." << endl;
        return;
    }

    ifstream adminFile("admin.txt");
    if (adminFile.is_open()) {
        string line;
        while (getline(adminFile, line)) {
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string storedUsername = line.substr(0, pos);
                string storedPassword = line.substr(pos + 1);
                if (username == storedUsername && password == storedPassword) {
                    isAdmin = true;
                    CUsername = username;
                    break;
                }
            }
        }
        adminFile.close();
    } else {
        cout << "Unable to open admin file." << endl;
        return;
    }

    if (isUser) {
        Customer();
    } else if (isAdmin) {
        Admin();  
    } else {
        cout << "\t\t\t\t\t\tInvalid username or password" << endl;
    }
}

void store() {

    /*
    This function updates the 'users.txt' file with the current user data.
    1. Temporarily load the existing user data into memory.
    2. Open 'users.txt' in write mode to overwrite the file.
    3. Iterate through the user data array and write each user's information to the file.
    4. Close the file after writing all the data.
    */
    
    temp_Customer_user();
    ofstream myfile;
    myfile.open("users.txt");

    for (int x = 0; x < maxrow; x++) {
        if (UsernameT[x] == "\0") {
            break;
        } else {
            myfile << UsernameT[x] + "," + PasswrodT[x] << endl;
        }
    }

    myfile.close();
}

bool username_exists(const string& username) {
    for (int x = 0; x < maxrow; x++) {
        if (UsernameT[x] == username) {
            return true;  // Username already exists
        }
    }
    return false;  // Username does not exist
}

int find_user(const string& username) {
    for (int x = 0; x < maxrow; x++) {
        if (UsernameT[x] == username) {
            return x;  // Return the index of the user
        }
    }
    return -1;  // User not found
}

void sign_up() {
    temp_Customer_user();
    system("cls");
    string username, password;
    
    cout << "\t\t\t\t\t\tHello and welcome to C-Stock Market Sign Up Page" << endl;
    cout << "\t\t\t\t\t\tPlease enter your Username: ";
    setConsoleColor(2);
    cin >> username;
    resetConsoleColor();
    
    // Check if the username already exists
    if (username_exists(username)) {
        cout << "\n\t\t\t\t\t\tUsername already exists. Please choose a different one." << endl;
        return;  // Exit the function
    }

    cout << "\n\t\t\t\t\t\tPlease enter your Password: ";
    setConsoleColor(2);
    cin >> password;
    resetConsoleColor();
    cout << endl;

    // Find the first available slot and store the new user's information
    for (int x = 0; x < maxrow; x++) {
        if (UsernameT[x] == "\0") {
            UsernameT[x] = username;
            PasswrodT[x] = password;
            break;
        }
    }
}

void drawMenu(int selectedOption) {
    system("cls");
    cout << "\t\t\t\t\t\t\t\t===========================" << endl;
    cout << "\t\t\t\t\t\t\t\t      C-Stock Manager" << endl;
    cout << "\t\t\t\t\t\t\t\t===========================" << endl;

    for (int i = 1; i <= 3; ++i) {
        if (i == selectedOption) {
            setConsoleColor(4 + 240);
            cout << "\t\t\t\t\t\t\t\t\t" << i << ". ";
        } else {
            resetConsoleColor(); // Reset text color for non-selected options
            cout << "\t\t\t\t\t\t\t\t\t" << i << ". ";
        }

        switch (i) {
            case 1:
                cout << "Login" << endl;
                break;
            case 2:
                cout << "Sign Up" << endl;
                break;
            case 3:
                cout << "Exit" << endl;
                break;
        }
    }
    resetConsoleColor(); // Reset text color after drawing the menu
    cout << "\t\t\t\t\t\t\t\t===========================" << endl;
}

void header() {
    int selectedOption = 1;
    int key;

    do {
        drawMenu(selectedOption);

        key = getArrowKey();

        switch (key) {
            case 72: // Up arrow key
                selectedOption = (selectedOption == 1) ? 3 : selectedOption - 1;
                break;
            case 80: // Down arrow key
                selectedOption = (selectedOption == 3) ? 1 : selectedOption + 1;
                break;
            case 13: // Enter key
                switch (selectedOption) {
                    case 1:
                        system("cls");
                        Log_in();
                        break;
                    case 2:
                        system("cls");
                        sign_up();
                        store();
                        break;
                    case 3:
                        cout << "\n\t\t\t\t\t\t\t\tExiting C-Stock Manager. Goodbye!" << endl;
                        break;
                }
                break;
        }
    } while (key != 13 || selectedOption != 3); // Keep looping until the Enter key is pressed (option selected)
}

void check() {

    /*
    This is the comment section for the code line below. 
    1. We start from ifstream practically it is opening the file in input form and it is assigned to file. 
    2. The next line is opening file called "users.txt"
    3. Then create a if statment when the file is open it will just do nothing but when the file doesnt exist it will create a file named "users.txt"
    4. Same goes for "products.txt" and "admin.txt" file. 
    5. Now this function will be called from the main file once it has completed all the statements in the code it will go to the next step. 
    */

    ifstream file;
    file.open("users.txt");
    
    if (file.is_open()) {
    } 
    else {
        ofstream newFile("users.txt");
    }
    file.close();

    file.open("products.txt");

    if (file.is_open()){
    }
    else{
        ofstream newfile("products.txt");
    }
    file.close();

    file.open("admin.txt");

    if (file.is_open()){
    }
    else{
        ofstream newfile("admin.txt");
        newfile << "admin,admin123"<<endl;
    }
    file.close();

    file.open("totalsales.txt");
    if (file.is_open()){
    }
    else{
        ofstream newfile("totalsales.txt");
    }
    
    

}

int main(){

    /*
    Welcome to the main function this is the comment for the code line below. 
    1. Below you can see three functions which maps to check,Open_all_files and header. 
    2. This function serves a purpose so that it is easy to debug if there is any issue thats why it is separated. 
    3. Now you can go each function one by one.
    */

    check();
    temp_Products_data();
    Open_all_files();
    cout << fixed << setprecision(2);
    header();
}
