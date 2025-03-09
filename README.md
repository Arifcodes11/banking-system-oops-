# Bank and ATM Management System

## Overview
The **Bank and ATM Management System** is a C++-based application implementing fundamental Object-Oriented Programming (OOP) principles such as inheritance, encapsulation, polymorphism, and abstraction. This system allows users to securely perform banking operations, including cash withdrawals, deposits, balance inquiries, and account management. To enhance security, a custom encryption algorithm is used to protect user PINs.

## Features
- 🔑 **User Authentication**: Secure login and account verification using encrypted PINs.
- 🏦 **Account Management**: Users can view account details, check balances, and update their information.
- 💳 **Transaction Operations**: Supports cash withdrawals and deposits, with real-time balance updates.
- 🔐 **Data Security**: Implements a custom encryption algorithm for secure storage of sensitive data.

## Technology Stack
- **Programming Language**: C++
- **Concepts Used**: OOP principles (Abstraction, Inheritance, Encapsulation, Polymorphism)
- **Security**: Custom encryption for PIN protection
- **Data Structures**: Vectors for user management

## Installation & Execution
```bash
# Clone the repository
git clone https://github.com/yourusername/bank-atm-management.git
cd bank-atm-management

# Compile the code using g++
g++ -o bank_atm bank_atm.cpp

# Run the executable
./bank_atm  # On Linux/macOS
bank_atm.exe  # On Windows
```

## How It Works
1. **User Registration**:
   - Users create an account by entering their details and setting a secure PIN.
2. **User Login**:
   - Users log in using their account number and encrypted PIN.
3. **Banking Operations**:
   - Users can perform transactions like checking balances, depositing, and withdrawing cash.
   - The system automatically updates account balances in real-time.
4. **Account Management**:
   - Users can update their phone numbers after authentication.
5. **Data Security**:
   - The system encrypts user PINs using a custom encryption mechanism to ensure privacy.

## Code Structure
- **`BankUser` Class**: Implements user account details with encapsulation.
- **`Transaction` Abstract Class**: Defines transaction operations for ATM users.
- **`Atm` Class**: Inherits from `BankUser` and implements transaction functionalities.
- **`BankSystem` Class**: Manages multiple users using a vector.
- **Main Function**: Handles user interactions via a command-line interface (CLI).

## Future Enhancements
- 🏦 **Multi-Branch Support**: Extend system functionality to support multiple bank branches.
- 📱 **Mobile App Integration**: Develop a mobile app for easy access to banking operations.
- 🛡 **Advanced Security**: Implement multi-factor authentication for improved security.

## Contributors
- **[Arif]** - Developer



