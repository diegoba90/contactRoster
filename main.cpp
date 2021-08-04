/*
Diego Acuna

 This program will use enumerations to generrate a menu. It will include structs and algorithms. It will use STL containers (vectors) to store data. It will also include exceptions for invalid entries.
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

//declare your struct
struct Contact{
    std::string name;
    std::string email;
    std::string phoneNumber;
};

//function prototypes
void contactList(std::vector<Contact> contactInfo); //will display all contacts
void dispSpecificContact(std::vector<Contact> contactInfo, int num); //will display a specific contact
void addContact(std::vector<Contact> &contactInfo); //will add contact information
void deleteContact(std::vector<Contact> &contactInfo, int num); //will delete contact info

//main function
int main(){
    //declare enumerator
    enum Choice : char{ DISPLAY = 'l' , VIEW = 'v', ADD = 'a', DEL = 'd', EXIT = 'x' };
    
    //declare enum variable
    char input;
    //declare vector
    std::vector<Contact> contact;
    
    //display intro and menu
    std::cout << "Welcome to this program. Please choose from the following options:\n" << std::endl;
    while (true) {
        std::cout << "l - Display all contacts" << std::endl;
        std::cout << "v - View a contact" << std::endl;
        std::cout << "a - Add a contact" << std::endl;
        std::cout << "d - Delete a contact" << std::endl;
        std::cout << "x - Exit program\n" << std::endl;
        std::cout << "Please enter your choice (l, v, a, d, x): ";
        std::cin >> input;
        
        //exception block
        try {
            //swith statement for menu
            switch (input) {
                case DISPLAY:
                    //call function
                    contactList(contact);
                    break;
                    
                case VIEW:
                    //ask for input
                    std::cout << "Enter contact number from list: ";
                    //declare variables
                    int number;
                    std::cin >> number;
                    //call function
                    dispSpecificContact(contact, number);
                    break;
                    
                case ADD:
                    //call add function
                    addContact(contact);
                    break;
                    
                case DEL:
                    //ask for input
                    std::cout << "Please enter contact number from list: ";
                    std::cin >> number;
                    //call function
                    deleteContact(contact, number);
                    
                case EXIT:
                    exit(0);
                    
                default:
                    break;
            }
        }
        //catch the invalid arguments
        catch (const char *message) {
            //display message
            std::cout << message << std::endl;
        }
        
    }
    
    
    
    return 0;
}

//display list function
void contactList(std::vector<Contact> contactInfo){
    //throw exception error if there's no contacts
    if (contactInfo.size() == 0){
        throw "There's no contacts on your list.\n";
    }
    
    //for loop to display all contacts
    std::cout << std::endl;
    for (int i = 0; i < contactInfo.size(); i++){
        std::cout << i + 1 << ". " << contactInfo[i].name << std::endl;
    }
    std::cout << std::endl;
}

//display a specific contact function
void dispSpecificContact(std::vector<Contact> contactInfo, int num){
    //throw exception if there's no numbers in the info
    if ((num > contactInfo.size()) || (num < 1)) {
        throw "Invalid phone number.\n";
    } else {
        num--;
        std::cout << "Contact name: " << contactInfo[num].name << std::endl;
        std::cout << "Contact email address: " << contactInfo[num].email << std::endl;
        std::cout << "Contact phone number: " << contactInfo[num].phoneNumber << std::endl;
        std::cout << std::endl;
        
    }
}

//add contact function
void addContact(std::vector<Contact> &contactInfo){
    //declare struct variables
    Contact c;
    //ask for input
    std::cout << "Contact Name (first and last): ";
    std::cin.ignore();
    std::getline(std::cin, c.name);
    std::cout << "Contact email: ";
    std::getline(std::cin, c.email);
    std::cout << "Contact phone number (XXX-XXX-XXXX): ";
    std::getline(std::cin, c.phoneNumber);
    std::cout << c.name << " has been added!!\n" << std::endl;
    //add to vector
    contactInfo.push_back(c);
}

//delete contact function
void deleteContact(std::vector<Contact> &contactInfo, int num){
    //throw exception error message
    if ((num < contactInfo.size() || num < 1)) {
        throw "Invalid number.\n";
    }
    //erase contact
    contactInfo.erase(contactInfo.begin() + num -1);
    std::cout << "Your contact has been deleted." << std::endl;
}
