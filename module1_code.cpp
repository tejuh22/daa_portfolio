#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;

// Enhanced structures
struct Car {
    string id;
    string name;
    string brand;
    string dealer;
    double pricePerDay;
    bool isAvailable;
    string condition;  // New, Good, Fair
    int year;
    string color;

    void display() const {
        cout << "ID: " << id << " | Dealer: " << dealer << " | Brand: " << brand
             << " | Car: " << name << " | Price/Day: $" << fixed << setprecision(2)
             << pricePerDay << " | Available: " << (isAvailable ? "Yes" : "No")
             << " | Condition: " << condition << " | Year: " << year
             << " | Color: " << color << endl;
    }
};

struct Rental {
    string rentalId;
    string username;
    string carId;
    string startDate;
    string endDate;
    double totalCost;
    bool isActive;
};

struct User {
    string username;
    string password;
    string role;
    string fullName;
    string contact;
    string email;
    string securityQuestion;  // Added for password recovery
    string securityAnswer;    // Added for password recovery
    vector<string> rentalHistory;
};

// Global data
vector<User> users;
vector<Car> cars;
vector<Rental> rentals;
const string userFile = "users.txt";
const string carFile = "cars.txt";
const string rentalFile = "rentals.txt";
const string loginHistoryFile = "login_history.txt";

// Function prototypes
void loadData();
void saveData();
void registerUser(const string& role);
bool loginUser(const string& role);
void userDashboard(const string& username);
void dealerDashboard(const string& username);
void adminDashboard();
void addCar(const string& dealer);
void removeCar(const string& dealer);
void viewAllCars();
void viewAvailableCars();
void rentCar(const string& username);
void returnCar(const string& username);
void viewRentalHistory(const string& username);
void generateReport();
void manageUsers();
string generateId(const string& prefix);
void displayWelcomeMessage();
void logAction(const string& username, const string& action);
double calculateRentalCost(const Car& car, int days);
void searchCars();
void displayUserProfile(const string& username);
void updateUserProfile(const string& username);
void displayCarStatistics();
void forgotPassword();
bool resetPassword(const string& username);
bool verifySecurityQuestion(const string& username);
void viewAllUsers();  // Added declaration
void deleteUser();    // Added declaration
string getCurrentTimestamp();  // Added declaration

// Additional function implementations
void viewAvailableCars() {
    cout << "\nAvailable Cars:\n";
    bool found = false;
    for (const auto& car : cars) {
        if (car.isAvailable) {
            car.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No cars available at the moment.\n";
    }
}

void rentCar(const string& username) {
    cout << "\nAvailable Cars for Rent:\n";
    vector<Car*> availableCars;
    for (auto& car : cars) {
        if (car.isAvailable) {
            car.display();
            availableCars.push_back(&car);
        }
    }

    if (availableCars.empty()) {
        cout << "No cars available for rent.\n";
        return;
    }

    string carId;
    cout << "\nEnter Car ID to rent: ";
    cin >> carId;

    for (auto car : availableCars) {
        if (car->id == carId) {
            car->isAvailable = false;
            Rental newRental;
            newRental.rentalId = "R" + to_string(rentals.size() + 1);
            newRental.username = username;
            newRental.carId = carId;
            newRental.startDate = getCurrentTimestamp();
            newRental.isActive = true;
            rentals.push_back(newRental);
            cout << "Car rented successfully!\n";
            return;
        }
    }
    cout << "Invalid Car ID.\n";
}

void returnCar(const string& username) {
    cout << "\nYour Active Rentals:\n";
    bool found = false;
    for (auto& rental : rentals) {
        if (rental.username == username && rental.isActive) {
            for (auto& car : cars) {
                if (car.id == rental.carId) {
                    car.display();
                    found = true;
                }
            }
        }
    }

    if (!found) {
        cout << "No active rentals found.\n";
        return;
    }

    string carId;
    cout << "\nEnter Car ID to return: ";
    cin >> carId;

    for (auto& rental : rentals) {
        if (rental.username == username && rental.carId == carId && rental.isActive) {
            rental.isActive = false;
            rental.endDate = getCurrentTimestamp();
            for (auto& car : cars) {
                if (car.id == carId) {
                    car.isAvailable = true;
                }
            }
            cout << "Car returned successfully!\n";
            return;
        }
    }
    cout << "Invalid Car ID or no active rental found.\n";
}

void viewRentalHistory(const string& username) {
    cout << "\nRental History:\n";
    bool found = false;
    for (const auto& rental : rentals) {
        if (rental.username == username) {
            for (const auto& car : cars) {
                if (car.id == rental.carId) {
                    cout << "Rental ID: " << rental.rentalId
                         << " | Car: " << car.brand << " " << car.name
                         << " | Start: " << rental.startDate;
                    if (!rental.isActive) {
                        cout << " | End: " << rental.endDate;
                    }
                    cout << " | Status: " << (rental.isActive ? "Active" : "Returned") << endl;
                    found = true;
                }
            }
        }
    }
    if (!found) {
        cout << "No rental history found.\n";
    }
}

void displayUserProfile(const string& username) {
    for (const auto& user : users) {
        if (user.username == username) {
            cout << "\nUser Profile:\n";
            cout << "Username: " << user.username << endl;
            cout << "Role: " << user.role << endl;
            cout << "Full Name: " << user.fullName << endl;
            cout << "Contact: " << user.contact << endl;
            cout << "Email: " << user.email << endl;
            return;
        }
    }
    cout << "User not found.\n";
}

void updateUserProfile(const string& username) {
    for (auto& user : users) {
        if (user.username == username) {
            cout << "\nUpdate Profile:\n";
            cout << "Enter new full name (or press enter to skip): ";
            string input;
            cin.ignore();
            getline(cin, input);
            if (!input.empty()) user.fullName = input;

            cout << "Enter new contact (or press enter to skip): ";
            getline(cin, input);
            if (!input.empty()) user.contact = input;

            cout << "Enter new email (or press enter to skip): ";
            getline(cin, input);
            if (!input.empty()) user.email = input;

            saveData();
            cout << "Profile updated successfully!\n";
            return;
        }
    }
    cout << "User not found.\n";
}

void addCar(const string& dealer) {
    Car newCar;
    newCar.dealer = dealer;
    newCar.id = "C" + to_string(cars.size() + 1);
    newCar.isAvailable = true;

    cout << "\nAdd New Car:\n";
    cout << "Enter car brand: ";
    cin.ignore();
    getline(cin, newCar.brand);
    cout << "Enter car name: ";
    getline(cin, newCar.name);
    cout << "Enter car year: ";
    cin >> newCar.year;
    cout << "Enter price per day: $";
    cin >> newCar.pricePerDay;
    cin.ignore();
    cout << "Enter car color: ";
    getline(cin, newCar.color);
    cout << "Enter condition (New/Good/Fair): ";
    getline(cin, newCar.condition);

    cars.push_back(newCar);
    cout << "Car added successfully!\n";
}

void removeCar(const string& dealer) {
    cout << "\nYour Cars:\n";
    vector<Car*> dealerCars;
    for (auto& car : cars) {
        if (car.dealer == dealer) {
            car.display();
            dealerCars.push_back(&car);
        }
    }

    if (dealerCars.empty()) {
        cout << "You have no cars listed.\n";
        return;
    }

    string carId;
    cout << "\nEnter Car ID to remove: ";
    cin >> carId;

    auto it = remove_if(cars.begin(), cars.end(),
        [&](const Car& car) { return car.id == carId && car.dealer == dealer; });

    if (it != cars.end()) {
        cars.erase(it, cars.end());
        cout << "Car removed successfully!\n";
    } else {
        cout << "Car not found or you don't have permission to remove it.\n";
    }
}

void displayCarStatistics() {
    cout << "\nCar Statistics:\n";
    int totalCars = cars.size();
    int availableCars = count_if(cars.begin(), cars.end(),
        [](const Car& car) { return car.isAvailable; });
    int rentedCars = totalCars - availableCars;

    cout << "Total Cars: " << totalCars << endl;
    cout << "Available Cars: " << availableCars << endl;
    cout << "Rented Cars: " << rentedCars << endl;

    if (totalCars > 0) {
        cout << "\nCar Brands Distribution:\n";
        map<string, int> brandCount;
        for (const auto& car : cars) {
            brandCount[car.brand]++;
        }
        for (const auto& pair : brandCount) {
            cout << pair.first << ": " << pair.second << " cars\n";
        }
    }
}

void viewAllCars() {
    cout << "\nAll Cars in System:\n";
    if (cars.empty()) {
        cout << "No cars in the system.\n";
        return;
    }

    for (const auto& car : cars) {
        car.display();
    }
}

void generateReport() {
    cout << "\nSystem Report:\n";
    cout << "1. User Statistics:\n";
    cout << "Total Users: " << users.size() << endl;
    int userCount = count_if(users.begin(), users.end(),
        [](const User& u) { return u.role == "User"; });
    int dealerCount = count_if(users.begin(), users.end(),
        [](const User& u) { return u.role == "Dealer"; });
    cout << "Regular Users: " << userCount << endl;
    cout << "Dealers: " << dealerCount << endl;

    cout << "\n2. Car Statistics:\n";
    displayCarStatistics();

    cout << "\n3. Rental Statistics:\n";
    int activeRentals = count_if(rentals.begin(), rentals.end(),
        [](const Rental& r) { return r.isActive; });
    cout << "Total Rentals: " << rentals.size() << endl;
    cout << "Active Rentals: " << activeRentals << endl;
    cout << "Completed Rentals: " << rentals.size() - activeRentals << endl;
}

void manageUsers() {
    while (true) {
        cout << "\nUser Management:\n";
        cout << "1. View All Users\n";
        cout << "2. Delete User\n";
        cout << "3. Back to Admin Dashboard\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                viewAllUsers();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice!\n";
        }
    }
}

// Main function
int main() {
    displayWelcomeMessage();
    loadData();

    while (true) {
        cout << "\nMain Menu:\n";
        cout << "1. User Access\n";
        cout << "2. Dealer Access\n";
        cout << "3. Admin Access\n";
        cout << "4. Forgot Password\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 5) break;

        if (choice >= 1 && choice <= 3) {
            string role = (choice == 1) ? "User" : (choice == 2) ? "Dealer" : "Admin";

            cout << "\n1. Login\n";
            cout << "2. Register\n";
            cout << "Enter choice: ";
            int subChoice;
            cin >> subChoice;

            if (subChoice == 1) {
                if (loginUser(role)) {
                    cout << "Login successful!\n";
                }
            } else if (subChoice == 2) {
                registerUser(role);
            }
        } else if (choice == 4) {
            forgotPassword();
            return 0;
        }
    }

    saveData();
    return 0;
}

void displayWelcomeMessage() {
    cout << "********************************************************\n";
    cout << "*                  SECOND SPIN RENTALS                   *\n";
    cout << "*              Premium Car Rental Service                *\n";
    cout << "********************************************************\n";
}

void loadData() {
    // Implementation for loading data from files
    // This would read from userFile, carFile, and rentalFile
    // and populate the respective vectors
}

void saveData() {
    // Implementation for saving data to files
    // This would write the current state of vectors to their respective files
}

void registerUser(const string& role) {
    User newUser;
    cout << "\nRegistration Form\n";
    cout << "Enter username: ";
    cin >> newUser.username;

    // Check if username exists
    if (find_if(users.begin(), users.end(),
        [&](const User& u) { return u.username == newUser.username; }) != users.end()) {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!newUser.password.empty()) {
                cout << "\b \b";
                newUser.password.pop_back();
            }
        } else {
            newUser.password.push_back(ch);
            cout << "*";
        }
    }
    cout << endl;

    cout << "For account security, please set up a security question.\n";
    cout << "Enter your security question: ";
    cin.ignore();
    getline(cin, newUser.securityQuestion);
    cout << "Enter your security answer: ";
    getline(cin, newUser.securityAnswer);

    cout << "Enter full name: ";
    getline(cin, newUser.fullName);
    cout << "Enter contact number: ";
    getline(cin, newUser.contact);
    cout << "Enter email: ";
    getline(cin, newUser.email);

    newUser.role = role;
    users.push_back(newUser);
    saveData();
    cout << "Registration successful!\n";
}

bool loginUser(const string& role) {
    string username, password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";

    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        } else {
            password.push_back(ch);
            cout << "*";
        }
    }
    cout << endl;

    auto it = find_if(users.begin(), users.end(),
        [&](const User& u) { return u.username == username && u.password == password && u.role == role; });

    if (it != users.end()) {
        logAction(username, "Login");
        if (role == "User") userDashboard(username);
        else if (role == "Dealer") dealerDashboard(username);
        else if (role == "Admin") adminDashboard();
        return true;
    }

    cout << "Invalid credentials!\n";
    return false;
}

void userDashboard(const string& username) {
    while (true) {
        cout << "\nUser Dashboard\n";
        cout << "1. View Available Cars\n";
        cout << "2. Rent a Car\n";
        cout << "3. Return a Car\n";
        cout << "4. View Rental History\n";
        cout << "5. Search Cars\n";
        cout << "6. View/Update Profile\n";
        cout << "7. Logout\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: viewAvailableCars(); break;
            case 2: rentCar(username); break;
            case 3: returnCar(username); break;
            case 4: viewRentalHistory(username); break;
            case 5: searchCars(); break;
            case 6: {
                displayUserProfile(username);
                cout << "Update profile? (y/n): ";
                char update;
                cin >> update;
                if (update == 'y' || update == 'Y')
                    updateUserProfile(username);
                break;
            }
            case 7: return;
            default: cout << "Invalid choice!\n";
        }
    }
}

void dealerDashboard(const string& username) {
    while (true) {
        cout << "\nDealer Dashboard\n";
        cout << "1. Add New Car\n";
        cout << "2. Remove Car\n";
        cout << "3. View My Cars\n";
        cout << "4. View Active Rentals\n";
        cout << "5. Car Statistics\n";
        cout << "6. Logout\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: addCar(username); break;
            case 2: removeCar(username); break;
            case 3: {
                cout << "\nMy Cars:\n";
                for (const auto& car : cars) {
                    if (car.dealer == username)
                        car.display();
                }
                break;
            }
            case 4: {
                cout << "\nActive Rentals:\n";
                for (const auto& rental : rentals) {
                    if (rental.isActive) {
                        auto car = find_if(cars.begin(), cars.end(),
                            [&](const Car& c) { return c.id == rental.carId && c.dealer == username; });
                        if (car != cars.end()) {
                            cout << "Rental ID: " << rental.rentalId
                                 << " | User: " << rental.username
                                 << " | Car: " << car->name << endl;
                        }
                    }
                }
                break;
            }
            case 5: displayCarStatistics(); break;
            case 6: return;
            default: cout << "Invalid choice!\n";
        }
    }
}

void adminDashboard() {
    while (true) {
        cout << "\nAdmin Dashboard\n";
        cout << "1. View All Users\n";
        cout << "2. View All Cars\n";
        cout << "3. View All Rentals\n";
        cout << "4. Generate Reports\n";
        cout << "5. Manage Users\n";
        cout << "6. Logout\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nAll Users:\n";
                for (const auto& user : users) {
                    cout << "Username: " << user.username
                         << " | Role: " << user.role
                         << " | Name: " << user.fullName << endl;
                }
                break;
            }
            case 2: viewAllCars(); break;
            case 3: {
                cout << "\nAll Rentals:\n";
                for (const auto& rental : rentals) {
                    cout << "ID: " << rental.rentalId
                         << " | User: " << rental.username
                         << " | Car ID: " << rental.carId
                         << " | Active: " << (rental.isActive ? "Yes" : "No") << endl;
                }
                break;
            }
            case 4: generateReport(); break;
            case 5: manageUsers(); break;
            case 6: return;
            default: cout << "Invalid choice!\n";
        }
    }
}

void searchCars() {
    cout << "\nSearch by:\n";
    cout << "1. Brand\n";
    cout << "2. Price Range\n";
    cout << "3. Year\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            string brand;
            cout << "Enter brand: ";
            cin >> brand;
            for (const auto& car : cars) {
                if (car.brand == brand && car.isAvailable)
                    car.display();
            }
            break;
        }
        case 2: {
            double min, max;
            cout << "Enter min price: ";
            cin >> min;
            cout << "Enter max price: ";
            cin >> max;
            for (const auto& car : cars) {
                if (car.pricePerDay >= min && car.pricePerDay <= max && car.isAvailable)
                    car.display();
            }
            break;
        }
        case 3: {
            int year;
            cout << "Enter year: ";
            cin >> year;
            for (const auto& car : cars) {
                if (car.year == year && car.isAvailable)
                    car.display();
            }
            break;
        }
        default:
            cout << "Invalid choice!\n";
    }
}

string generateId(const string& prefix) {
    static int counter = 1;
    stringstream ss;
    ss << prefix << setw(4) << setfill('0') << counter++;
    return ss.str();
}

void logAction(const string& username, const string& action) {
    ofstream logFile(loginHistoryFile, ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    logFile << username << " | " << action << " | " << dt;
    logFile.close();
}

void forgotPassword() {
    string username;
    cout << "\nEnter your username: ";
    cin >> username;

    // Check if username exists
    auto it = find_if(users.begin(), users.end(),
        [&username](const User& user) { return user.username == username; });

    if (it == users.end()) {
        cout << "Username not found!\n";
        return;
    }

    if (verifySecurityQuestion(username)) {
        if (resetPassword(username)) {
            cout << "Password has been successfully reset!\n";
        } else {
            cout << "Failed to reset password.\n";
        }
    } else {
        cout << "Incorrect security answer. Password reset failed.\n";
    }
}

bool verifySecurityQuestion(const string& username) {
    string answer;
    for (const auto& user : users) {
        if (user.username == username) {
            cout << "\nSecurity Question: " << user.securityQuestion << endl;
            cout << "Enter your answer: ";
            cin.ignore();
            getline(cin, answer);
            return (answer == user.securityAnswer);
        }
    }
    return false;
}

bool resetPassword(const string& username) {
    string newPassword;
    cout << "\nEnter new password: ";

    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!newPassword.empty()) {
                cout << "\b \b";
                newPassword.pop_back();
            }
        } else {
            newPassword.push_back(ch);
            cout << "*";
        }
    }
    cout << endl;

    // Update password in users vector
    for (auto& user : users) {
        if (user.username == username) {
            user.password = newPassword;
            saveData();
            return true;
        }
    }
    return false;
}

string getCurrentTimestamp() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);
}

void viewAllUsers() {
    cout << "\nList of all registered users:\n";
    for (const auto& user : users) {
        cout << "Username: " << user.username
             << " | Role: " << user.role
             << " | Full Name: " << user.fullName << endl;
    }
}

void deleteUser() {
    string username;
    cout << "\nEnter username to delete: ";
    cin >> username;

    auto it = remove_if(users.begin(), users.end(),
        [&username](const User& user) { return user.username == username; });

    if (it != users.end()) {
        users.erase(it, users.end());
        saveData();
        cout << "User " << username << " deleted successfully.\n";
    } else {
        cout << "User " << username << " not found.\n";
    }
}
