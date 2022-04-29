#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <direct.h>
#include <dir.h>
#include <process.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define WINDOWS 1
#include "tut9,5.cpp"

using std::cout;
using std::cin;
using std::vector;
using std::string; 

void console_clear_screen() {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}

void folder()                                           // This function was just a quick last minute fix so it will create folder for high score / account info text files
{
    int check;                                          // int for checking
    char const *dirname = "Data";                       // Name for directory
    console_clear_screen();                             // Using void function for console clear, has option for Linux & Windows. Quick solution as I realised that making folder wasn't as simple
    check = mkdir(dirname);                             // Checks dirname
    
    if(!check)
        printf("Directory created \n");
    else
    {
        printf("Folder Data already exists!\n");
    }
    getch();
}


bool IsLoggedIN()                                       // boolean to check if logged in
{
    string username, password, un, pw;                  // Creating strings for username / password

    cout << "Username: ";
    cin >> username;                                    // User input for username, followed by password
    cout << "Password: ";
    cin >> password;

    std::ifstream read("Data\\" + username + ".txt");   // reads file from folder data\\ that's been created during register
    getline(read, un);                                  // gets username from file
    getline(read, pw);                                  // gets password from file

    if (un == username && pw == password)               // Compares if the username&password given matches with ones in txt file
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;                                             // int for storing options
    folder();
    cout << "1. Register\n2: Login\nYour choice: ";
    cin >> choice;                                          // user input for 1 register / 2 login
    if(choice == 1)                                         // if statement to see if 1 was chosen
    {
        string username, password;                          // creates strings for username and password

        cout << "Register username: ";
        cin >> username;                                    // user input for desired 
        cout << "New password: ";
        cin >> password;
        std::ofstream file;
        file.open("Data\\" + username + ".txt");            // opens file (creates if doesn't exist) to folder data using username as file name

        file << username << std::endl << password;          // inputs given username & password to file
        file.close();                                       // closes the file

        main();                                             // returns to main() function (choice between register and login)
    }
    else if (choice == 2)                                   // else if when choosing login option
    {   
        bool status = IsLoggedIN();                         // gets boolean value for function IsLoggedIN

        if (!status)                                        // if statement to check if value is not (!) true 
        {
            cout << "Incorrect Login!" << std::endl;        // outputs message for missmatch of username & password
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Succesfully logged in!" << std::endl;  // else outputs message for matching username & password
            mainmenu();                                     // runs function mainmenu() (in this case from file tut9.5.cpp)
            return 1;
        }
    }
}
