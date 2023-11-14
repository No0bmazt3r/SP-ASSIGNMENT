#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
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
        int counter = 0;

        while (getline(file, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);

            if (pos1 != string::npos && pos2 != string::npos) {
                string productName = line.substr(0, pos1);
                double price = stod(line.substr(pos1 + 1, pos2 - pos1));
                int quantity = stoi(line.substr(pos2 + 1));

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

        if (counter == 0) {
            cout << "No record found" << endl;
        }

        file.close();
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

        if (counter == 0) {
            cout << "No record found" << endl;
        }

        file.close();
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
    cin >> search;

    bool userFound = false;
    int index = -1;

    for (int x = 0; x < maxrow; ++x) {
        if (UsernameT[x] == search) {
            userFound = true;
            index = x;

            cout << "\t\t\t\t\t\tUser found:" << endl;
            cout << "\t\t\t\t\t\tUsername: " << UsernameT[x] << endl;
            cout << "\t\t\t\t\t\tPassword: " << PasswrodT[x] << endl;

            char confirm;
            cout << "\n\t\t\t\t\t\tAre you sure you want to delete this user? (y/n): ";
            cin >> confirm;

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
    string search;
    cout << "\t\t\t\t\t\tEnter the product name: ";
    cin >> search;

    bool productFound = false;
    int index = -1;

    for (int x = 0; x < maxrow; ++x) {
        if (ProductNameT[x] == search) {
            productFound = true;
            index = x;

            cout << "\t\t\t\t\t\tProduct found:" << endl;
            cout << "\t\t\t\t\t\tName: " << ProductNameT[x] << endl;
            cout << "\t\t\t\t\t\tPrice: RM" << PriceT[x] << endl;
            cout << "\t\t\t\t\t\tQuantity available: " << QuantityT[x] << endl;

            char confirm;
            cout << "\n\t\t\t\t\t\tAre you sure you want to delete this product? (y/n): ";
            cin >> confirm;

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
        if (ProductName[x] == "\0") {
            break;
        } else {
            myfile << ProductName[x] + "," + to_string(Price[x]) + "," + to_string(Quantity[x]) << endl;
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

    cout << "\t\t\t\t\t\tAdd Product to Stock\n";
    cout << "\t\t\t\t\t\tProduct Name: ";cin >> productName;cout<<endl;
    cout << "\t\t\t\t\t\tQuantity: ";cin >> quantity;cout<<endl;
    cout << "\t\t\t\t\t\tPrice: ";cin >> price;cout<<endl;

    for (int x = 0; x < maxrow; x++) {
        if (ProductName[x] == "\0") {
            ProductName[x] = productName;
            Quantity[x] = quantity;
            Price[x] = price;
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
    4. If the product name is found, display current details and prompt for new details.
    5. Update the temporary arrays with the new details.
    6. Write the updated details to the "products.txt" file.
    7. Display a success message if the product details are updated.
    8. If the product name is not found, display a corresponding message.
    */

    temp_Products_data();
    string search;
    cout << "\t\t\t\t\t\tEnter the product name: ";
    cin >> search;

    bool productFound = false;
    int index = -1;
    for (int x = 0; x < maxrow; ++x) {
        if (ProductNameT[x] == search) {
            productFound = true;
            index = x;

            cout << "\t\t\t\t\t\tProduct found:" << endl;
            cout << "\t\t\t\t\t\tName: " << ProductNameT[x] << endl;
            cout << "\t\t\t\t\t\tPrice: RM" << PriceT[x] << endl;
            cout << "\t\t\t\t\t\tQuantity available: " << QuantityT[x] << endl;

            cout << "\n\t\t\t\t\t\tEnter new details:" << endl;
            cout << "\t\t\t\t\t\tNew Name: ";
            cin >> ProductNameT[x];
            cout << "\t\t\t\t\t\tNew Price: $";
            cin >> PriceT[x];
            cout << "\t\t\t\t\t\tNew Quantity: ";
            cin >> QuantityT[x];

            cout << "\t\t\t\t\t\tProduct details updated successfully." << endl;

            ofstream file("products.txt");

            for (int i = 0; i < maxrow; ++i) {
                if (ProductName[i] != "\0") {
                    file << ProductNameT[i] << "," << PriceT[i] << "," << QuantityT[i] << endl;
                }
            }

            file.close();

            break;
        }
    }

    if (!productFound) {
        cout << "\t\t\t\t\t\tProduct not found." << endl;
        return;
    }
}

void admin_view_products() {

    /*
    This function allows an admin to view, add, edit, or delete products.
    1. Call the Open_all_files() function to ensure all necessary files are open.
    2. Display the current list of products using the ListProducts() function.
    3. Present a menu to the admin with options to add, edit, delete products, or exit to the main menu.
    4. Validate the user input to ensure a valid option is selected.
    5. Perform the corresponding action based on the selected option.
    6. Repeat the menu until the admin chooses to exit to the main menu.
    */

    Open_all_files();
    int option;
    do
    {
        system("cls");
        ListProducts();

        cout << "\n\t\t\t\t\t\tPlease select any option below." << endl;
        cout << "\t\t\t\t\t\t1. Add a Product." << endl;
        cout << "\t\t\t\t\t\t2. Edit a Product." << endl;
        cout << "\t\t\t\t\t\t3. Delete a Product." << endl;
        cout << "\t\t\t\t\t\t4. Exit to main menu." << endl;
        cout<<"\t\t\t\t\t\tChoose an Option: ";cin>>option;cout<<endl;

        if (option == 1 || option == 2 || option == 3 || option == 4){
        }
        else{
            while (!(cin>>option))
            {
                cout<<"\n\t\t\t\t\t\tPlease enter a valid option only : ";
                cin.clear();
                cin.ignore(1230, '\n');
            }
        }

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
            default:
                break;
        }
    } while (option != 4);
    
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
    cin >> search;
    bool userFound = false;
    int index = -1;

    for (int x = 0; x < maxrow; ++x) {
        if (UsernameT[x] == search) {
            userFound = true;
            index = x;
            system("cls");
            cout << "\t\t\t\t\t\tUser found:" << endl;
            cout << "\t\t\t\t\t\tName: " << UsernameT[x] << endl;
            cout << "\t\t\t\t\t\tPassword: " << PasswrodT[x] << endl;

            cout << "\t\t\t\t\t\tDo you wish to update the user details??? (y/n): ";
            cin >> decision;
            cout << endl;

            if (decision == 'y' || decision == 'Y') {
                cout << "\n\t\t\t\t\t\tEnter new details:" << endl;
                cout << "\t\t\t\t\t\tNew Name: ";
                cin >> UsernameT[x];  

                cout << "\t\t\t\t\t\tNew Password: ";
                cin >> PasswrodT[x];  

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

void admin_edit_users(){

    /*
    This function allows the administrator to edit or delete user accounts.
    1. Display the current list of users using the ViewUsers() function.
    2. Present a menu to the administrator with options to edit a user, delete a user, or exit.
    3. Validate the user input to ensure a valid option is selected.
    4. Perform the corresponding action based on the selected option.
    5. Repeat the menu until the administrator chooses to exit.
    */

    int option;
    do
    {
        system("cls");
        ViewUsers();
        cout << "\n\t\t\t\t\t\tPlease select any option below." << endl;
        cout << "\t\t\t\t\t\t1. Edit User." << endl;
        cout << "\t\t\t\t\t\t2. Delete User." << endl;
        cout << "\t\t\t\t\t\t3. Exit." << endl;
        cout<<"\t\t\t\t\t\tChoose an Option: ";cin>>option;cout<<endl;

        if (option == 1 || option == 2 || option == 3){
        }
        else{
            while (!(cin>>option))
            {
                cout<<"\n\t\t\t\t\t\tPlease enter a valid option only : ";
                cin.clear();
                cin.ignore(1230, '\n');
            }
        }

        switch (option) {
            case 1:
                ViewUsers();
                edit_user();
                break;
            case 2:
                ViewUsers();
                admin_delete_user();
                break;
            default:
                break;
        }
    } while (option != 3);
}

void admin(){

    /*
    This function provides the main menu for administrators.
    1. Display a welcome message with the administrator's username.
    2. Present a menu with options to view all users, view all admins, view all products, or log out.
    3. Validate user input to ensure a valid option is selected.
    4. Perform the corresponding action based on the selected option.
    5. Repeat the menu until the administrator chooses to log out.
    */

    system("cls");
    Open_all_files();
    int option;

    do
    {
        cout << "\t\t\t\t\t\tHello and welcome "<< CUsername<<endl;
        cout<<"\n\t\t\t\t\t\tPlease select any option below. "<<endl;
        cout<<"\t\t\t\t\t\t1. View All users"<<endl;
        cout<<"\t\t\t\t\t\t2. Vies all admins. "<<endl;
        cout<<"\t\t\t\t\t\t3. View all products. "<<endl;
        cout<<"\t\t\t\t\t\t4. Log Out."<<endl;
        cout << "\n\t\t\t\t\t\tPlease choose one of the option: ";cin>>option;cout<<endl;

        if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5){
        }
        else{
            while (!(cin>>option) || option != 1 || option != 2 || option != 3 || option != 4 || option != 5)
            {
                cout<<"\t\t\t\t\t\tPlease enter a valid option only : ";
                cin.clear();
                cin.ignore(1230, '\n');
            }
        }

        switch (option)
        {
        case 1:
            admin_edit_users();
            break;
        case 2:
            ViewAdmin();
            break;
        case 3:
            admin_view_products();
            break;
        }

    } while (option != 4);

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
        cout << "\t\t\t\t\t\tYour overall total for the items you have bought is " << overalltotal << " . \n\t\t\t\t\t\tThank you and please come again " << CUsername << endl;

        string option;
        cout << "\t\t\t\t\t\tWould you like to pay in cash or card? : ";
        cin >> option;
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

    /*
    This function allows the customer to add a product to their cart.
    1. Call temp_Products_data() to load product data into temporary arrays.
    2. Prompt the user to enter the product name.
    3. Search for the product in the array and display its details.
    4. Ask the user if they want to buy the product.
    5. If yes, prompt the user for the quantity to buy.
    6. Update the product quantity in the array.
    7. Calculate the total price of the purchase.
    8. Find an empty slot in the cart and update the cart values.
    9. Update the products file with the new product quantity.
    10. Write the purchase information to the customer's cart file.
    */

    temp_Products_data();
    
    string search;
    cout << "\t\t\t\t\t\tEnter the product name: ";
    cin >> search;

    bool productFound = false;
    int index = -1;

    // Search for the product in the array
    for (int x = 0; x < maxrow; ++x) {
        if (ProductNameT[x] == search) {
            productFound = true;
            index = x;

            cout << "\t\t\t\t\t\tProduct found:" << endl;
            cout << "\t\t\t\t\t\tName: " << ProductNameT[x] << endl;
            cout << "\t\t\t\t\t\tPrice: $" << PriceT[x] << endl;
            cout << "\t\t\t\t\t\tQuantity available: " << QuantityT[x] << endl;
            break;
        }
    }

    if (!productFound) {
        cout << "\t\t\t\t\t\tProduct not found." << endl;
        return;
    }

    char response;
    double totprice;
    int quantityToBuy;

    cout << "\t\t\t\t\t\tDo you wish to buy this product? (y/n): ";
    cin >> response;

    if (response == 'y' || response == 'Y') {
        cout << "\t\t\t\t\t\tHow much would you like to buy? Enter quantity: ";
        cin >> quantityToBuy;

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

void Customer(){

    /*
    This function represents the customer menu.
    1. Display a welcome message.
    2. Allow the customer to choose from the following options:
        - View Available Products
        - View Cart
        - Log Out
    3. Validate the user input.
    4. Perform the corresponding action based on the user's choice.
    5. Continue the loop until the customer chooses to log out.
    */

    int option;
    cout << "\t\t\t\t\t\tHello and welcome "<< CUsername<<endl;

    do
    {
        cout<<"\t\t\t\t\t\tPlease select any option below. "<<endl;
        cout<<"\t\t\t\t\t\t1. View Available Products."<<endl;
        cout<<"\t\t\t\t\t\t2. View Cart. "<<endl;
        cout<<"\t\t\t\t\t\t3. Log Out. "<<endl;
        cout<<"\t\t\t\t\t\tChoose an option: ";cin>>option;cout<<endl;

        if (option == 1 || option == 2 || option == 3 || option == 4){
        }
        else{
            while (!(cin>>option) || option != 1 || option != 2 || option != 3 || option != 4)
            {
                cout<<"\t\t\t\t\t\tPlease enter a valid option only : ";
                cin.clear();
                cin.ignore(1230, '\n');
            }
        }

        switch (option)
        {
        case 1:
            ListProducts();
            add_to_cart();
            break;
        case 2:
            view_cart();
            break;
        }
    } while (option != 3);
    
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

    cout << "\n\t\t\t\t\t\tUsername: "; cin >> username; cout << endl;
    cout << "\t\t\t\t\t\tPassword: "; cin >> password; cout << endl;

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
        admin();  
    } else {
        cout << "Invalid username or password" << endl;
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

void sign_up(){

    /*
    This function simulates the user sign-up process for the C-Stock Market.
    1. Temporarily load existing user data into memory.
    2. Clear the console screen.
    3. Prompt the user for a username and password.
    4. Iterate through the user data array to find the first available slot.
    5. Store the new user's information in the available slot.
    */

    temp_Customer_user();
    system("cls");
    string username, password;
    cout<<"\t\t\t\t\t\tHello and welcome to C-Stock Market Sign Up Page"<<endl;
    cout<<"\t\t\t\t\t\tPlease enter your Username: ";cin>>username;
    cout<<"\n\t\t\t\t\t\tPlease enter your Password: ";cin>>password; cout<<endl;
    
    for (int x = 0; x < maxrow; x++)
    {
        if (UsernameT[x] == "\0")
        {
            UsernameT[x] = username;
            PasswrodT[x] = password;
            break;
        }
    }

}

void header() {

    /*
    This function displays the header and provides options for the user.
    1. Clear the console screen.
    2. Display the welcome message and available options (Login, Sign Up, Exit).
    3. Prompt the user to choose an option.
    4. Validate the user input to ensure it's a valid option.
    5. Call the corresponding function based on the chosen option.
    6. Repeat the process until the user chooses to exit.
    */

    int output;  
    do
    {
        system("cls");
        cout << "\t\t\t\t\t\tWelcome to C-Stock Manager" << endl;
        cout << "\t\t\t\t\t\t1. Login" << endl;
        cout << "\t\t\t\t\t\t2. Sign Up" << endl;
        cout << "\t\t\t\t\t\t3. Exit" << endl; 
        cout << "\n\t\t\t\t\t\tPlease choose one of the option: ";cin>>output;cout<<endl;

        if (output == 1 || output == 2 || output == 3){
        }
        else{
            while (!(cin>>output))
            {
                cout<<"\n\t\t\t\t\t\tPlease enter a valid option only : ";
                cin.clear();
                cin.ignore(1230, '\n');
            }
        }

        switch (output) {
        case 1:
            Log_in();
            break;
        case 2:
            sign_up();
            store();
            break;
        default:
            cout << "\t\t\t\t\t\tExiting C-Stock Manager. Goodbye!" << endl;
        }

    } while (output != 3);
    
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
    }
    file.close();
    

}

int main(){

    /*
    Welcome to the main function this is the comment for the code line below. 
    1. Below you can see three functions which maps to check,Open_all_files and header. 
    2. This function serves a purpose so that it is easy to debug if there is any issue thats why it is separated. 
    3. Now you can go each function one by one.
    */

    check();
    Open_all_files();
    header();
}
