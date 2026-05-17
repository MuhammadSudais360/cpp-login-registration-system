#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Check if username already exists
bool userExists(const string &username)
{
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass)
    {
        if (user == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Register user
void registerUser()
{
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Validation
    if (username.empty() || password.empty())
    {
        cout << "Error: Username and password cannot be empty.\n";
        return;
    }

    if (password.length() < 6)
    {
        cout << "Error: Password must be at least 6 characters long.\n";
        return;
    }

    // Duplicate check
    if (userExists(username))
    {
        cout << "Error: Username already exists.\n";
        return;
    }

    // Save to file
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Login user
void loginUser()
{
    string username, password;
    string user, pass;
    bool found = false;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> user >> pass)
    {
        if (user == username && pass == password)
        {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Login successful!\n";
    else
        cout << "Error: Invalid username or password.\n";
}

// Main menu
int main()
{
    int choice;

    while (true)
    {
        cout << "\n===== LOGIN SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
