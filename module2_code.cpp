#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

// Structure to store car details
// Structure to store car details

struct Car {

    // Dealer selling the car
    string dealer;

    // Car's brand (e.g., Tesla, Ford)
    string brand;

    // Car's model name (e.g., Model X)
    string name;

    // Car type: Petrol/Electric
    string type;

    // Car's cost (e.g., 25000 USD)
    string cost;

    // Engine capacity in CC (e.g., 2000 CC)
    string cc;

    // Model year (e.g., 2021)
    string modelYear;

    // Mileage in km/l (e.g., 15 km/l)
    string mileage;

    // Track if the car is booked
    bool booked = false;

    // Track if the car is purchased
    bool purchased = false;

    // Store customer name and payment method for purchase

    string customerName;    // Customer name who purchased or booked the car
    string paymentMethod;   // Payment method chosen by the customer (Credit Card, Cash, etc.)

    // Method to display car details

    void display() const
    {
        cout << "\n------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Dealer: " << dealer << ", Brand: " << brand << ", Car: " << name
             << ", Type: " << type << ", Cost: " << cost
             << ", CC: " << cc << ", Model Year: " << modelYear
             << ", Mileage: " << mileage << " km/l\n";
        if (booked) cout << "Status: Booked\n";
        if (purchased) cout << "Status: Purchased\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------\n";
    }

};


// Structure to store bike details

struct Bike
{
    string dealer;
    string brand;
    string name;
    string type; // Petrol/Electric
    string cost;
    string cc;  // Engine CC
    string modelYear;  // Model Year
    string mileage;  // Mileage

    void display() const
    {
        cout << "\n------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "Dealer: " << dealer << ", Brand: " << brand << ", Bike: " << name
             << ", Type: " << type << ", Cost: " << cost
             << ", CC: " << cc << ", Model Year: " << modelYear
             << ", Mileage: " << mileage << " km/l\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------\n";
    }

};

// Rabin-Karp algorithm for searching patterns

bool rabinKarpSearch(const string& text, const string& pattern)
{
    int m = pattern.size();
    int n = text.size();

    const int d = 256; // Number of characters in the input alphabet
    const int q = 101; // A prime number for hashing

    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    int patternHash = 0, textHash = 0;
    for (int i = 0; i < m; i++)
    {
        patternHash = (d * patternHash + pattern[i]) % q;
        textHash = (d * textHash + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (patternHash == textHash)
        {
            if (text.substr(i, m) == pattern)
            {
                return true;
            }
        }

        if (i < n - m)
            {
            textHash = (d * (textHash - text[i] * h) + text[i + m]) % q;
            if (textHash < 0)
            {
                textHash += q;
            }
        }
    }


    return false;
}

// KMP algorithm for searching patterns

bool kmpSearch(const string& text, const string& pattern)
{
    int m = pattern.size();
    int n = text.size();

    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            } else
            {
                lps[i] = 0;
                i++;
            }

        }

    }

    i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            return true;
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return false;
}

// Load cars from the file
// Load cars from the file

vector<Car> loadCars(const string& filePathCar)
{
    vector<Car> cars;
    ifstream file(filePathCar);

    if (!file)
    {
        cout << "Error: Could not open the file '" << filePathCar << "'\n";
        return cars;
    }

    string line, dealer, brand, name, type, cost, cc, modelYear, mileage;
    while (getline(file, line)) {
        if (line.rfind("Dealer:", 0) == 0)
        {
            dealer = line.substr(8);
        }
        else if (line.rfind("Brand:", 0) == 0)
        {
            brand = line.substr(7);
        }
        else if (line.rfind("Car:", 0) == 0)
        {
            name = line.substr(5);
        }
        else if (line.rfind("Type:", 0) == 0)
        {
            type = line.substr(6);
        }
        else if (line.rfind("Cost:", 0) == 0)
        {
            cost = line.substr(6);
        }
        else if (line.rfind("CC:", 0) == 0)
        {
            cc = line.substr(3);
        }
        else if (line.rfind("Model Year:", 0) == 0)
        {
            modelYear = line.substr(12);
        } else if (line.rfind("Mileage:", 0) == 0)
        {
            mileage = line.substr(8);
            cars.push_back({dealer, brand, name, type, cost, cc, modelYear, mileage});
        }

    }

    return cars;

}

// Load bikes from the file

vector<Bike> loadBikes(const string& filePathBike)
{
    vector<Bike> bikes;
    ifstream file(filePathBike);

    if (!file)
    {
        cout << "Error: Could not open the file '" << filePathBike << "'\n";
        return bikes;
    }

    string line, dealer, brand, name, type, cost, cc, modelYear, mileage;
    while (getline(file, line))
    {
        if (line.rfind("Dealer:", 0) == 0)
        {
            dealer = line.substr(8);
        }
        else if (line.rfind("Brand:", 0) == 0)
        {
            brand = line.substr(7);
        }
        else if (line.rfind("Bike:", 0) == 0)
        {
            name = line.substr(5);
        }
        else if (line.rfind("Type:", 0) == 0)
        {
            type = line.substr(6);
        }
        else if (line.rfind("Cost:", 0) == 0)
        {
            cost = line.substr(6);
        }
        else if (line.rfind("CC:", 0) == 0)
        {
            cc = line.substr(3);
        }
        else if (line.rfind("Model Year:", 0) == 0)
        {
            modelYear = line.substr(12);
        }
        else if (line.rfind("Mileage:", 0) == 0)
        {
            mileage = line.substr(8);
            bikes.push_back({dealer, brand, name, type, cost, cc, modelYear, mileage});
        }

    }

    return bikes;

}

// Function to search bikes by brand

void searchByBrandBike(const vector<Bike>& bikes, const string& type)
{
    cout << "\n-------------------------------------------------------\n";
    cout << "Enter brand to search for: ";
    string brandSearch;
    cin.ignore();

    getline(cin, brandSearch);
    cout << "\n-------------------------------------------------------\n";

    bool found = false;

    for (const auto& bike : bikes)
    {
        if (rabinKarpSearch(bike.type, type) && rabinKarpSearch(bike.brand, brandSearch))
        {

            bike.display();
            found = true;

        }
    }

    if (!found)
    {

        cout << "No bikes found for the specified brand.\n";

    }
}
// Function to search cars by brand
// Function to search cars by brand

void searchByBrand(const vector<Car>& cars, const string& type)
{
    cout << "\n-------------------------------------------------------\n";
    cout << "Enter brand to search for: ";
    string brandSearch;
    cin.ignore();

    getline(cin, brandSearch);
    cout << "\n-------------------------------------------------------\n";


    bool found = false;
    for (const auto& car : cars)
    {
        if (kmpSearch(car.type, type) && rabinKarpSearch(car.brand, brandSearch))
        {

            car.display();
            found = true;

        }

    }

    if (!found)
    {

        cout << "No cars found for the specified brand.\n";

    }

}

// Function to search bikes by name or dealer

void searchByBikeOrDealer(const vector<Bike>& bikes, const string& type)
{
    cout << "\n======================================================================\n";
    cout << "Search by:\n";
    cout << "\n======================================================================\n";
    cout << "1. Bike Name\n";
    cout << "2. Dealer\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    cout << "Enter search term: ";
    string searchTerm;
    cin.ignore();

    getline(cin, searchTerm);

    bool found = false;
    for (const auto& bike : bikes)
    {
        if (rabinKarpSearch(bike.type, type))
        {
            // Match only the selected bike type

            if ((choice == 1 && rabinKarpSearch(bike.name, searchTerm)) ||
                (choice == 2 && rabinKarpSearch(bike.dealer, searchTerm)))
            {
                bike.display();
                found = true;
            }

        }

    }

    if (!found)
    {

        cout << "No matching bikes found.\n";

    }
}

// Function to search cars by name or dealer
// Function to search cars by name or dealer

void searchByCarOrDealer(const vector<Car>& cars, const string& type)
{
    cout << "\n======================================================================\n";
    cout << "Search by:\n";
    cout << "\n======================================================================\n";
    cout << "1. Car Name\n";
    cout << "2. Dealer\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    cout << "Enter search term: ";
    string searchTerm;
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    for (const auto& car : cars)
    {
        if (kmpSearch(car.type, type))
        {  // Match only the selected car type
            if ((choice == 1 && rabinKarpSearch(car.name, searchTerm)) ||
                (choice == 2 && rabinKarpSearch(car.dealer, searchTerm)))
            {
                car.display();
                found = true;
            }
        }
    }

    if (!found)
    {

        cout << "No matching cars found.\n";

    }

}

// Function to display bikes by type (Petrol or Electric)

void displayBikesByType(const vector<Bike>& bikes, const string& type)
{
    cout << "\nDisplaying " << type << " bikes:\n";
    for (const auto& bike : bikes)
    {
        if (rabinKarpSearch(bike.type, type))
        {
            // Use Rabin-Karp to match the type
            bike.display();

        }
    }
}

// Function to make a booking Bike

void bookBike(vector<Bike>& bikes)
{
    cout << "\nEnter the bike name you want to book: ";
    string bikeName;

    cin.ignore();  // Clear the input buffer

    getline(cin, bikeName);  // Get the bike name entered by the user

    bool found = false;
    for (auto& bike : bikes)
    {
        if (bike.name == bikeName)
        {
            found = true;

            // Confirm booking

            cout << "\nBooking successful for: " << bike.name << " from dealer: " << bike.dealer << "\n";
            break;
        }

    }

    if (!found)
    {
        cout << "Bike not found.\n";
    }
}

// Function to cancel a booking Bike
void cancelBooking(vector<Bike>& bikes)
{
    cout << "\nEnter the bike name you want to cancel the booking for: ";
    string bikeName;
    cin.ignore();  // Clear the input buffer
    getline(cin, bikeName);  // Get the bike name entered by the user

    bool found = false;
    for (auto& bike : bikes)
    {
        if (bike.name == bikeName)
        {
            found = true;
            // Cancel booking
            cout << "\nBooking canceled for: " << bike.name << " from dealer: " << bike.dealer << "\n";
            break;
        }

    }

    if (!found)
    {
        cout << "Bike not found.\n";
    }

}
// Function to handle the purchase of a bike

void purchaseBike(vector<Bike>& bikes)
{
    cout << "\nEnter the name of the Bike you want to purchase: ";
    string bikeName;
    cin.ignore();  // Clear the input buffer
    getline(cin, bikeName);

    vector<Bike> matchingBikes;
    for (const auto& bike : bikes)
    {
        if (rabinKarpSearch(bike.name, bikeName))
        {
            matchingBikes.push_back(bike);
        }

    }

    if (matchingBikes.empty())
    {
        cout << "No bikes found with that name.\n";
        return;
    }

    cout << "\nMatching bikes found:\n";
    for (size_t i = 0; i < matchingBikes.size(); ++i)
    {
        cout << i + 1 << ". ";
        matchingBikes[i].display();
    }

    cout << "\nChoose a dealer (enter the number): ";
    int dealerChoice;
    cin >> dealerChoice;

    if (dealerChoice < 1 || dealerChoice > matchingBikes.size())
    {
        cout << "Invalid choice.\n";
        return;
    }

    Bike selectedBike = matchingBikes[dealerChoice - 1];
    cout << "\nYou selected: ";
    selectedBike.display();
    cout << "\n======================================================================\n";
    cout << "\nChoose payment method:\n";
    cout << "\n======================================================================\n";
    cout << "1. Debit Card"<<endl;
    cout <<" 2. Credit Card"<<endl;
    cout <<" 3. Cash:"<<endl;
    cout <<"----------------------------------------------------------------------\n";
    int paymentMethod;
    cin >> paymentMethod;

    string payment;
    switch (paymentMethod)
    {
        case 1: payment = "Debit Card"; break;
        case 2: payment = "Credit Card"; break;
        case 3: payment = "Cash"; break;
        default: cout << "Invalid payment method.\n"; return;
    }

    cout << "\nPayment successful via " << payment << ".\n";

    // Collect feedback for the dealer
    cout << "\nEnter your feedback for the dealer: ";
    cin.ignore();  // Clear the input buffer
    string dealerFeedback;
    getline(cin, dealerFeedback);

    // Collect feedback for the system
    cout << "\nEnter your feedback for the system: ";
    string systemFeedback;
    getline(cin, systemFeedback);

    cout << "\nThank you for your feedback!\n";
}

// Function to display cars by type (Petrol or Electric)
void displayCarsByType(const vector<Car>& cars, const string& type)
{
    cout << "\nDisplaying " << type << " cars:\n";
    for (const auto& car : cars)
        {
        if (kmpSearch(car.type, type))
        {  // Use KMP to match the type
            car.display();
        }

    }

}

void savePurchaseAndBookingDetails(const vector<Car>& cars, const string& filePathCar)
{
    ofstream file(filePathCar, ios::app);  // Open in append mode to keep old records

    if (!file)
    {
        cout << "Error: Could not open the file for saving purchase and booking details: " << filePathCar << "\n";
        return;
    }

    file << "-------------------- Purchase and Booking Details --------------------\n";

    // Loop through the cars and save details of booked and purchased cars
    for (const auto& car : cars)
    {
        if (car.booked || car.purchased)
        {
            file << "Dealer: " << car.dealer << "\n";
            file << "Brand: " << car.brand << "\n";
            file << "Car: " << car.name << "\n";
            file << "Type: " << car.type << "\n";
            file << "Cost: " << car.cost << "\n";
            file << "CC: " << car.cc << "\n";
            file << "Model Year: " << car.modelYear << "\n";
            file << "Mileage: " << car.mileage << "\n";

            // Add booking or purchase status
            if (car.purchased)
            {
                file << "Status: Purchased\n";
            }
            else if (car.booked)
            {
                file << "Status: Booked\n";
            }

            file << "--------------------------------------------------------------------\n";

        }

    }

    cout << "Purchase and booking details saved successfully to the file.\n";

}

void purchaseCar(std::vector<Car>& cars, const string& type)
{
    const string filePathPurchase = "C:\\Users\\HP\\OneDrive\\Desktop\\Books_to_Read\\Purchase_and_booking.txt";  // File path

    cout << "\nEnter the car name you want to purchase: ";
    string carName;
    cin.ignore();  // Clear the input buffer
    getline(cin, carName);  // Get the car name entered by the user

    // Searching for the car in the list
    vector<Car*> matchingCars;  // Changed to hold pointers to Car (non-const)
    for (auto& car : cars)
    {
        if (car.name == carName && car.type == type && !car.booked)
        {
            matchingCars.push_back(&car);
        }

    }

    if (matchingCars.empty())
    {
        cout << "Car not found or already booked.\n";
        return;
    }

    Car* selectedCar = nullptr;

    // If multiple dealers have the same car, ask the user to select a dealer
    if (matchingCars.size() > 1)
    {
        cout << "\nMultiple dealers have this car. Please choose the dealer from which you want to buy:\n";
        for (size_t i = 0; i < matchingCars.size(); ++i)
        {
            cout << i + 1 << ". Dealer: " << matchingCars[i]->dealer
                 << ", Price: " << matchingCars[i]->cost << "\n";
        }

        cout << "Enter the dealer number (1-" << matchingCars.size() << "): ";
        int dealerChoice;
        cin >> dealerChoice;

        if (dealerChoice < 1 || dealerChoice > matchingCars.size())
        {
            cout << "Invalid choice.\n";
            return;
        }

        selectedCar = matchingCars[dealerChoice - 1];  // Select the chosen car
        cout << "\nYou selected " << selectedCar->name << " from dealer " << selectedCar->dealer << ".\n";
    }
    else
    {
        selectedCar = matchingCars[0];  // If only one dealer has the car, use that one
        cout << "\nYou selected " << selectedCar->name << " from dealer " << selectedCar->dealer << ".\n";
    }

    // Take customer's name
    cout << "\nEnter your name: ";
    string customerName;
    cin.ignore();  // Clear input buffer before taking the name
    getline(cin, customerName);

    // Payment Methods
    cout << "\n======================================================================\n";
    cout << "Payment Methods:\n";
    cout << "\n======================================================================\n";
    cout << "1. Credit Card\n";
    cout << "2. Debit Card\n";
    cout << "3. Cash\n";
    cout << "-----------------------------------------------------------------------\n";
    cout << "Enter your choice: ";
    int paymentChoice;
    cin >> paymentChoice;

    string paymentMethod;
    switch (paymentChoice)
    {
        case 1: paymentMethod = "Credit Card"; break;
        case 2: paymentMethod = "Debit Card"; break;
        case 3: paymentMethod = "Cash"; break;
        default: paymentMethod = "Invalid"; break;
    }

    // Ask if the user wants to print the bill
    cout << "\nWould you like to print the bill? (y/n): ";
    char printBill;
    cin >> printBill;

    if (printBill == 'y' || printBill == 'Y' || printBill == 'Yes' || printBill == 'yes')
    {
        cout << "\n======================================================================\n";
        cout << "Bill:\n";
        cout << "\n======================================================================\n";
        cout << "Customer Name: " << customerName << "\n";
        cout << "Car Purchased: " << selectedCar->name << "\n";
        cout << "Brand: " << selectedCar->brand << "\n";
        cout << "Dealer: " << selectedCar->dealer << "\n";
        cout << "Cost: " << selectedCar->cost << "\n";
        cout << "CC: " << selectedCar->cc << "\n";
        cout << "Model Year: " << selectedCar->modelYear << "\n";
        cout << "Mileage: " << selectedCar->mileage << "\n";
        cout << "Payment Method: " << paymentMethod << "\n";
        cout << "------------------------------------------------------------------------\n";
    }

    // Save purchase details to the file

    ofstream outFile(filePathPurchase, ios::app);  // Open in append mode
    if (outFile.is_open())
    {
        outFile << "Purchase Details:\n";
        outFile << "Customer Name: " << customerName << "\n";
        outFile << "Car Purchased: " << selectedCar->name << "\n";
        outFile << "Brand: " << selectedCar->brand << "\n";
        outFile << "Dealer: " << selectedCar->dealer << "\n";
        outFile << "Cost: " << selectedCar->cost << "\n";
        outFile << "CC: " << selectedCar->cc << "\n";
        outFile << "Model Year: " << selectedCar->modelYear << "\n";
        outFile << "Mileage: " << selectedCar->mileage << "\n";
        outFile << "Payment Method: " << paymentMethod << "\n";
        outFile << "-------------------------------------------------------\n";
        outFile.close();  // Close the file after writing
    }
    else
    {
        cout << "Error saving purchase details.\n";
    }

    // Mark the car as purchased
    selectedCar->booked = true;

}

void bookCar(std::vector<Car>& cars, const string& type)
{
    const string filePathPurchase = "C:\\Users\\HP\\OneDrive\\Desktop\\Books_to_Read\\Purchase_and_booking.txt";  // File path

    cout << "\nEnter the car name you want to book: ";
    string carName;
    cin.ignore();  // Clear the input buffer
    getline(cin, carName);  // Get the car name entered by the user

    // Searching for the car in the list

    vector<Car*> matchingCars;  // Changed to hold pointers to Car (non-const)
    for (auto& car : cars)
    {
        if (car.name == carName && car.type == type && !car.booked)
        {
            matchingCars.push_back(&car);
        }

    }

    if (matchingCars.empty())
    {
        cout << "Car not found or already booked.\n";
        return;
    }

    Car* selectedCar = nullptr;

    // If multiple dealers have the same car, ask the user to select a dealer
    if (matchingCars.size() > 1)
    {
        cout << "\nMultiple dealers have this car. Please choose the dealer from which you want to book:\n";
        for (size_t i = 0; i < matchingCars.size(); ++i)
        {
            cout << i + 1 << ". Dealer: " << matchingCars[i]->dealer
                 << ", Price: " << matchingCars[i]->cost << "\n";
        }

        cout << "Enter the dealer number (1-" << matchingCars.size() << "): ";
        int dealerChoice;
        cin >> dealerChoice;

        if (dealerChoice < 1 || dealerChoice > matchingCars.size())
        {
            cout << "Invalid choice.\n";
            return;
        }

        selectedCar = matchingCars[dealerChoice - 1];  // Select the chosen car
        cout << "\nYou selected " << selectedCar->name << " from dealer " << selectedCar->dealer << ".\n";
    }
    else
    {
        selectedCar = matchingCars[0];  // If only one dealer has the car, use that one
        cout << "\nYou selected " << selectedCar->name << " from dealer " << selectedCar->dealer << ".\n";
    }

    // Take customer's name
    cout << "\nEnter your name: ";
    string customerName;
    cin.ignore();  // Clear input buffer before taking the name
    getline(cin, customerName);
    cout << "Booking Successful !"<<endl;

    // Save booking details to the file
    ofstream outFile(filePathPurchase, ios::app);  // Open in append mode
    if (outFile.is_open())
    {
        outFile << "Booking Details:\n";
        outFile << "Customer Name: " << customerName << "\n";
        outFile << "Car Booked: " << selectedCar->name << "\n";
        outFile << "Brand: " << selectedCar->brand << "\n";
        outFile << "Dealer: " << selectedCar->dealer << "\n";
        outFile << "Cost: " << selectedCar->cost << "\n";
        outFile << "CC: " << selectedCar->cc << "\n";
        outFile << "Model Year: " << selectedCar->modelYear << "\n";
        outFile << "Mileage: " << selectedCar->mileage << "\n";
        outFile << "-------------------------------------------------------\n";
        outFile.close();  // Close the file after writing
    }
    else
    {
        cout << "Error saving booking details.\n";
    }

    // Mark the car as booked
    selectedCar->booked = true;

}

void cancelBooking(vector<Car>& cars, const string& type)
{
    cout << "\nEnter the car name you want to cancel booking for: ";
    string carName;
    cin.ignore();  // Clear the input buffer
    getline(cin, carName);  // Get the car name entered by the user

    for (auto& car : cars)
    {
        if (car.name == carName && car.type == type)
        {
            if (!car.booked)
            {
                cout << "\nThis car has not been booked yet.\n";
                return;
            }

            car.booked = false;
            cout << "\nYou have successfully canceled the booking for car: " << car.name << ".\n";
            return;

        }

    }

    cout << "\nCar not found.\n";

}



int main()
{
    string filePathCar = R"(C:\Users\HP\OneDrive\Desktop\Books_to_Read\New_path\New_cars.txt)";
    string filePathPurchase = "C:\\Users\\HP\\OneDrive\\Desktop\\Books_to_Read\\Purchase_and_booking.txt";

    vector<Car> cars = loadCars(filePathCar);

    string filePathBike = R"(C:\Users\HP\OneDrive\Desktop\Books_to_Read\Bike.txt)";

    vector<Bike> bikes = loadBikes(filePathBike);
    string type;

    int ch;
    cout << "\n======================================================================\n";
    cout << "\nMain Menu:\n";
    cout << "\n======================================================================\n";
    cout << "1.Cars Menu"<<endl;
    cout << "2.Bike Menu"<<endl;
    cout << "3.Exit\n";
    cout << "----------------------------------------------------------------------\n";
    cout << "Enter your choice:"<<endl;
    cin >> ch;
    if(ch==1)
    {

     if (cars.empty())
     {
        cout << "No cars available in the file.\n";
        return 0;
     }

     while (true)
     {
        cout << "\n======================================================================\n";
        cout << "\nMain Menu For Car:\n";
        cout << "\n======================================================================\n";
        cout << "1. Petrol Cars\n";
        cout << "2. Electric Cars\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 3)
        {
            cout << "Exiting program.\n";
            break;  // Exit the main loop
        }

        // Petrol or Electric car options
        while (true)
        {
            string carType = (choice == 1) ? "Petrol" : "Electric";
            cout << "\n======================================================================\n";
            cout << "\n" << carType
            << " Car Options:\n";
            cout << "\n======================================================================\n";
            cout << "1. Search by Brand\n";
            cout << "2. Search by Car Name or Dealer\n";
            cout << "3. Display All Cars\n";
            cout << "4. Purchase\n";
            cout << "5. Book Car\n";
            cout << "6. Cancel Booking\n";
            cout << "7. Exit to Main Menu\n";
            cout << "----------------------------------------------------------------------\n";
            cout << "Enter your choice: ";

            int subChoice;
            cin >> subChoice;

            if (subChoice == 7)
            {
                break;  // Return to the main menu if 'Exit to Main Menu' is selected
            }

            switch (subChoice)
            {
                case 1:
                    cout << "Search Cars by Brand\n";
                    searchByBrand(cars, carType);
                    break;

                case 2:
                    cout << "Search Cars by Car Name or Dealer\n";
                    searchByCarOrDealer(cars, carType);
                    break;

                case 3:
                    displayCarsByType(cars, carType);
                    break;

                case 4:
                    purchaseCar(cars, carType);
                    break;

                case 5:
                    bookCar(cars, carType);  // Call the bookCar function
                    break;

                case 6:
                    cancelBooking(cars, carType);  // Call the cancelBooking function
                    break;

                default:
                    cout << "Invalid option. Please try again.\n";

            }

        }

     }

    }

    else if(ch==2)
    {
        if (bikes.empty())
      {
        cout << "No bikes available in the file.\n";
        return 0;
      }

     while (true)
      {
        cout << "\n======================================================================\n";
        cout << "\nMain Menu For Bike:\n";
        cout << "\n======================================================================\n";
        cout << "1. Petrol Bikes\n";
        cout << "2. Electric Bikes\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 3)
            {
            cout << "Exiting program.\n";
            break;  // Exit the main loop
        }

        // Petrol or Electric bike options

        while (true)
            {
            string bikeType = (choice == 1) ? "Petrol" : "Electric";
            cout << "\n======================================================================\n";
            cout << "\n" << bikeType
            << " Bike Options:\n";
            cout << "\n======================================================================\n";
            cout << "1. Search by Brand\n";
            cout << "2. Search by Bike Name or Dealer\n";
            cout << "3. Display All Bikes\n";
            cout << "4. Book a Bike\n";
            cout << "5. Cancel Booking\n";
            cout << "6. Purchase a Bike\n";
            cout << "7. Exit to Main Menu\n";
            cout << "Enter your choice: ";

            int subChoice;
            cin >> subChoice;

            if (subChoice == 7)
                {
                break;  // Return to the main menu if 'Exit to Main Menu' is selected
            }

            switch (subChoice)
            {
                case 1:
                    cout << "Search Bikes by Brand\n";
                    searchByBrandBike(bikes, bikeType);
                    break;

                case 2:
                    cout << "Search Bikes by Bike Name or Dealer\n";
                    searchByBikeOrDealer(bikes, bikeType);
                    break;

                case 3:
                    displayBikesByType(bikes, bikeType);
                    break;

                case 4:
                    bookBike(bikes);
                    break;

                case 5:
                    cancelBooking(bikes);
                    break;

                case 6:
                    purchaseBike(bikes);
                    break;

                default:
                    cout << "Invalid option. Please try again.\n";

            }

        }

    }

    }
     else
        {

        cout << "Exiting program.\n";

     }

    return 0;

}
