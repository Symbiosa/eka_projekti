#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIN()           // boolean to check if logged in
{
    string username, password, un, pw;

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
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
    int choice;

    cout << "1. Register\n2: Login\nYour choice: ";
    cin >> choice;
    if(choice == 1)
    {
        string username, password;

        cout << "Register username: ";
        cin >> username;
        cout << "New password: ";
        cin >> password;

        ofstream file;
        file.open("data\\" + username + ".txt");

        file << username << endl << password;
        file.close();

        main();
    }
    else if (choice == 2)
    {
        bool status = IsLoggedIN();

        if (!status)
        {
            cout << "Incorrect Login!" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Succesfully logged in!" << endl;
            system("PAUSE");
            return 1;
        }
    }
}