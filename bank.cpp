#include <iostream>
#include <vector>
#include <string>
#include <conio.h> // for using _getch()

using namespace std;

// Custom encryption function (simple Caesar cipher with index shift)
string customEncrypt(string input) {
    string encrypted = "";
    int fixed_shift = 3;  // Fixed shift amount for all characters

    // Iterate through each character of the input
    for (int i = 0; i < input.length(); i++) {
        char encrypted_char = input[i] + fixed_shift + i;
        encrypted += encrypted_char;  // Add to the encrypted string
    }
    return encrypted;
}

// Custom decryption function
string customDecrypt(string input) {
    string decrypted = "";
    int fixed_shift = 3;

    // Iterate through each character of the encrypted string
    for (int i = 0; i < input.length(); i++) {
        char decrypted_char = input[i] - fixed_shift - i;
        decrypted += decrypted_char;  // Add to the decrypted string
    }
    return decrypted;
}

// Abstract class Transaction (Abstraction)
class Transaction {
public:
    virtual void cashWithdraw(int amount_a) = 0;
    virtual void cashDeposit(int amount_a) = 0;
    virtual void checkBalance() = 0;
};

// Class to represent Bank Users (Encapsulation)
class BankUser {
private:
    long int account_no;
    string name;
    string phone_no;
    string encrypted_pin;  // Encrypted PIN
    double balance;

public:
    // Constructor for initializing data
    BankUser(long int acc_no, string name_a, string pin_a, double balance_a, string phone_no_a) {
        account_no = acc_no;
        name = name_a;
        encrypted_pin = customEncrypt(pin_a);
        balance = balance_a;
        phone_no = phone_no_a;
    }

    // Getters and Setters for private data members
    long int getAccountNo() {
        return account_no;
    }

    string getName() {
        return name;
    }

    string getPhoneNo() {
        return phone_no;
    }

    // Function to verify PIN
    bool verifyPin(string pin_input) {
        string decrypted_pin = customDecrypt(encrypted_pin);
        return decrypted_pin == pin_input;
    }

    // Function to update phone number
    void setPhone(string old_phone, string new_phone) {
        if (old_phone == phone_no) {
            phone_no = new_phone;
            cout << endl << "Phone number successfully updated.";
        } else {
            cout << endl << "Incorrect old phone number!";
        }
    }

    // Functions for balance handling
    void updateBalance(double amount) {
        balance += amount;
    }

    double getBalance() {
        return balance;
    }
};

// Derived class Atm (Inheritance & Polymorphism)
class Atm : public BankUser, public Transaction {
public:
    Atm(long int acc_no, string name_a, string pin_a, double balance_a, string phone_no_a)
        : BankUser(acc_no, name_a, pin_a, balance_a, phone_no_a) {}

    // Overriding cashWithdraw (Polymorphism)
    void cashWithdraw(int amount_a) override {
        if (amount_a > 0 && amount_a <= getBalance()) {
            updateBalance(-amount_a);
            cout << endl << "Please collect your cash.";
            cout << endl << "Available Balance: " << getBalance();
        } else {
            cout << endl << "Invalid input or insufficient balance.";
        }
    }

    // Overriding cashDeposit (Polymorphism)
    void cashDeposit(int amount_a) override {
        if (amount_a > 0) {
            updateBalance(amount_a);
            cout << endl << "Deposit successful!";
            cout << endl << "Available Balance: " << getBalance();
        } else {
            cout << endl << "Invalid deposit amount!";
        }
    }

    // Overriding checkBalance (Polymorphism)
    void checkBalance() override {
        cout << endl << "Your Balance is: " << getBalance();
    }

    // Function to display user details
    void showUserDetails() {
        cout << endl << "User Details:- ";
        cout << endl << "-> Account Number: " << getAccountNo();
        cout << endl << "-> Account Name: " << getName();
        cout << endl << "-> Balance: " << getBalance();
        cout << endl << "-> Phone Number: " << getPhoneNo();
    }
};

// Bank System to manage multiple users (Basic DSA - using vector)
class BankSystem {
private:
    vector<Atm> users;

public:
    // Function to create an account
    void createAccount() {
        long int acc_no;
        string name, pin, phone_no;
        double initial_balance;

        cout << endl << "Enter Account Number: ";
        cin >> acc_no;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Phone Number: ";
        cin >> phone_no;
        cout << "Enter Initial Balance: ";
        cin >> initial_balance;
        cout << "Set 4-Digit PIN: ";
        cin >> pin;

        // Create a new user and add to the list
        Atm new_user(acc_no, name, pin, initial_balance, phone_no);
        users.push_back(new_user);
        cout << endl << "Account created successfully!";
    }

    // Function to log in an existing account
    Atm* login() {
        long int acc_no;
        string pin_input;

        cout << endl << "Enter Account Number: ";
        cin >> acc_no;
        cout << "Enter PIN: ";
        cin >> pin_input;

        // Search for the user by account number
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getAccountNo() == acc_no && users[i].verifyPin(pin_input)) {
                return &users[i];  // Return pointer to the user if authentication is successful
            }
        }

        cout << endl << "Invalid Account Number or PIN!";
        return nullptr;
    }
};

// Main function
int main() {
    BankSystem bank;
    int main_choice;

    do {
        system("cls");
        cout << endl << "****** Welcome to Bank & ATM Management System ******" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> main_choice;

        switch (main_choice) {
            case 1:
                bank.createAccount();
                _getch(); // To pause screen
                break;

            case 2: {
                Atm* user = bank.login();
                if (user != nullptr) {
                    int choice;
                    do {
                        system("cls");
                        cout << endl << "****** ATM Menu ******" << endl;
                        cout << "1. Check Balance" << endl;
                        cout << "2. Withdraw Cash" << endl;
                        cout << "3. Deposit Cash" << endl;
                        cout << "4. Update Phone Number" << endl;
                        cout << "5. Show User Details" << endl;
                        cout << "6. Logout" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice) {
                            case 1:
                                user->checkBalance();
                                _getch();
                                break;

                            case 2: {
                                int amount;
                                cout << "Enter amount to withdraw: ";
                                cin >> amount;
                                user->cashWithdraw(amount);
                                _getch();
                                break;
                            }

                            case 3: {
                                int amount;
                                cout << "Enter amount to deposit: ";
                                cin >> amount;
                                user->cashDeposit(amount);
                                _getch();
                                break;
                            }

                            case 4: {
                                string old_phone, new_phone;
                                cout << "Enter old phone number: ";
                                cin >> old_phone;
                                cout << "Enter new phone number: ";
                                cin >> new_phone;
                                user->setPhone(old_phone, new_phone);
                                _getch();
                                break;
                            }

                            case 5:
                                user->showUserDetails();
                                _getch();
                                break;

                            case 6:
                                cout << "Logging out...";
                                _getch();
                                break;

                            default:
                                cout << "Invalid choice!";
                                _getch();
                                break;
                        }
                    } while (choice != 6);
                }
                break;
            }

            case 3:
                cout << "Thank you for using the system!" << endl;
                exit(0);

            default:
                cout << "Invalid choice! Please try again.";
                _getch();
        }

    } while (true);

    return 0;
}
