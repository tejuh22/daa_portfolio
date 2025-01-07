#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm> // For transform function
#include <iomanip>
#include <fstream>


using namespace std;

struct Vehicle {
    string vehicleType;
    string fuelType;

    Vehicle() : vehicleType(""), fuelType("") {} // Default constructor
    Vehicle(string type, string fuel) : vehicleType(type), fuelType(fuel) {}

    virtual void displayDetails() const {
        cout << "Vehicle Type: " << vehicleType << ", Fuel Type: " << fuelType << endl;
    }
};

struct Traveller : public Vehicle {
    int capacity;

    Traveller(string fuel, int cap) : Vehicle("Traveller", fuel), capacity(cap) {}

    void displayDetails() const override {
        cout << "Traveller, Fuel Type: " << fuelType << " Capacity: " << capacity << endl;
    }
};

struct Bike : public Vehicle {
    string bikeType;

    Bike(string type, string fuel) : Vehicle("Bike", fuel), bikeType(type) {}

    void displayDetails() const override {
        cout << "Bike Type: " << bikeType << ", Fuel Type: " << fuelType << endl;
    }
};

struct Car : public Vehicle {
     string carType;         // Type of car (Hatchback, Sedan, etc.)
    string fuelType;        // Fuel type (Electric, Petrol, Diesel, etc.)
    string brand;           // Car brand (Mini, Toyota, etc.)
    string model;           // Car model (Cooper Electric, etc.)
    string dealer;          // Dealer name (Simran)
    int year;               // Manufacturing year
    string mileage;         // Mileage or range (e.g., "270-290 km")
    string engineCapacity;  // Engine power (e.g., "135 kW")
    double pricePerDay;     // Rental price per day
    string colors;          // Color of the car
    bool isAvailable;       // Indicates if the car is available for rent/purchase
    string feedback;        // Store feedback from users

       Car(string type, string fuel, string br, string mo, string de, int yr, string mi, string en, double pd, string co)
        : Vehicle("Car", fuel), carType(type), brand(br), model(mo), dealer(de), year(yr), mileage(mi),
          engineCapacity(en), pricePerDay(pd), colors(co), isAvailable(true), feedback("") {}

   // Car() : Vehicle(), carType("") {}
   //Car(string type, string fuel) : Vehicle("Car", fuel), carType(type) {}

    // Setter to populate car attributes for demo
 /*   void setDetails(const string& type, const string& fuel, const string& br, const string& mo, const string& yr,
                    const string& mi, const string& en, const string& pd, const string& co) {
        carType = type;
        fuelType = fuel;
        brand = br;
        model = mo;
        year = yr;
        mileage = mi;
        engine_capacity = en;
        price_per_day = pd;
        colors = co;
    }

    // Getter method for carType
    string getCarType() const { return carType; }
};
*/


// Function to display a list of cars in a tabular format
void displayDetails() const override {
        cout << "Car Type: " << carType << ", Brand: " << brand << ", Model: " << model << ", Fuel Type: " << fuelType
             << ", Price Per Day: " << pricePerDay << ", Dealer: " << dealer << ", Year: " << year
             << ", Mileage: " << mileage << ", Engine Capacity: " << engineCapacity << ", Color: " << colors << endl;
        if (!feedback.empty()) {
            cout << "User Feedback: " << feedback << endl;
        }
    }
};

// Function prototypes (implement these functions based on your requirements)
bool compareByPrice(const Car& car1, const Car& car2);
bool compareByYear(const Car& car1, const Car& car2);
bool compareByFuelType(const Car& car1, const Car& car2);
void displayCars(const std::vector<Car>& cars);
void filterCars(const std::vector<Car>& cars);
void purchaseCar(std::vector<Car>& cars);
void rentCar(std::vector<Car>& cars); // Implement car rental functionality
void leaveFeedback(const std::vector<Car>& cars); // Implement feedback functionality
void returnCar(std::vector<Car>& cars); // Implement car return functionality
void generateInvoice(const Car& car, const std::string& userName, bool toFile = false, int days = 0);


// Sorting function to sort cars by price
bool compareByPrice(const Car& a, const Car& b) {
    return a.pricePerDay < b.pricePerDay;
}

// Sorting function to sort cars by year
bool compareByYear(const Car& a, const Car& b) {
    return a.year < b.year;
}

// Sorting function to sort cars by fuel type
bool compareByFuelType(const Car& a, const Car& b) {
    return a.fuelType < b.fuelType;
}

// Binary search function to find the first car matching a specific price range
int binarySearchByPrice(const vector<Car>& cars, double price) {
    int left = 0, right = cars.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (cars[mid].pricePerDay == price) {
            return mid; // Found car with exact price
        }
        if (cars[mid].pricePerDay < price) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Binary search function to find the first car matching a specific year
int binarySearchByYear(const vector<Car>& cars, int year) {
    int left = 0, right = cars.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (cars[mid].year == year) {
            return mid; // Found car with exact year
        }
        if (cars[mid].year < year) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Binary search function to find the first car matching a specific fuel type
int binarySearchByFuelType(const vector<Car>& cars, const string& fuelType) {
    int left = 0, right = cars.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (cars[mid].fuelType == fuelType) {
            return mid; // Found car with exact fuel type
        }
        if (cars[mid].fuelType < fuelType) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Display cars by a given filter
void displayFilteredCarsByPrice(const vector<Car>& cars, double price) {
    int index = binarySearchByPrice(cars, price);
    if (index != -1) {
        cout << "\nCars with price " << price << " per day:\n";
        while (index < cars.size() && cars[index].pricePerDay == price) {
            cars[index].displayDetails();
            index++;
        }
    } else {
        cout << "No cars found with the price: " << price << endl;
    }
}

void displayFilteredCarsByYear(const vector<Car>& cars, int year) {
    int index = binarySearchByYear(cars, year);
    if (index != -1) {
        cout << "\nCars from year " << year << ":\n";
        while (index < cars.size() && cars[index].year == year) {
            cars[index].displayDetails();
            index++;
        }
    } else {
        cout << "No cars found for the year: " << year << endl;
    }
}

void displayFilteredCarsByFuelType(const vector<Car>& cars, const string& fuelType) {
    int index = binarySearchByFuelType(cars, fuelType);
    if (index != -1) {
        cout << "\nCars with fuel type " << fuelType << ":\n";
        while (index < cars.size() && cars[index].fuelType == fuelType) {
            cars[index].displayDetails();
            index++;
        }
    } else {
        cout << "No cars found with fuel type: " << fuelType << endl;
    }
}

vector<Car> cars = {
    Car{"SUV", "Petrol", "Toyota", "Fortuner", "Rohan", 2019, "10-12 km/l", "2694 cc", 8000, "White"},
    Car{"SUV", "Petrol", "Toyota", "Land Cruiser", "Kiran", 2022, "7-10 km/l", "4600 cc", 15000, "Dark blue"},
    Car{"SUV", "Petrol", "Mahindra", "Thar", "Simran", 2021, "12-14 km/l", "1997 cc", 5000, "Black"},
    Car{"SUV", "Petrol", "Mahindra", "XUV700", "Kiran", 2021, "12-14 km/l", "1997 cc", 6000, "White"},
    Car{"SUV", "Diesel", "Hyundai", "Creta", "Ankush", 2018, "19-21 km/l", "1493 cc", 3500, "Red"},
    Car{"SUV", "Diesel", "Hyundai", "Tucson", "Rohan", 2019, "16-18 km/l", "1995 cc", 5500, "Grey"},
    Car{"SUV", "Diesel", "BMW", "X1", "Anusha", 2015, "18-20 km/l", "1995 cc", 8200, "Grey"},
    Car{"SUV", "Diesel", "BMW", "X5", "Anshuman", 2019, "12-15 km/l", "2993 cc", 11800, "Blue"},
    Car{"SUV", "Diesel", "Audi", "Q3", "Kiran", 2017, "16-18 km/l", "1968 cc", 8000, "White"},
    Car{"SUV", "Diesel", "Audi", "Q8", "Anusha", 2020, "10-12 km/l", "2967 cc", 22000, "Blue"},
    Car{"SUV", "Electric", "BMW", "iX3", "Simran", 2021, "460-520 km", "210 kW", 17500, "Grey"},
    Car{"SUV", "Electric", "Jaguar", "I pace", "Anusha", 2020, "470-500 km", "294 kW", 29000, "White"},
    Car{"SUV", "Electric", "Ford", "Mustang Mach-E", "Ankush", 2020, "370-490 km", "357 kW", 23000, "Black"},
    Car{"Sedan", "Petrol", "Toyota", "Corolla", "Rohan", 2022, "18-20 km/l", "", 2500, "White"},
    Car{"Sedan", "Petrol", "Toyota", "Avalon", "Ankush", 2023, "14-16 km/l", "", 4500, "Black"},
    Car{"Sedan", "Petrol", "Honda", "Civic", "Stephan", 2021, "16-18 km/l", "", 3000, "Silver"},
    Car{"Sedan", "Petrol", "Honda", "Accord", "Vaishnavi", 2022, "14-16 km/l", "", 4000, "Black"},
    Car{"Sedan", "Petrol", "Mercedes-Benz", "C-Class", "Kiran", 2018, "12-14 km/l", "", 7000, "White"},
    Car{"Sedan", "Petrol", "Kia", "Optima K5", "Simran", 2021, "15-17 km/l", "", 3500, "Red"},
    Car{"Sedan", "Diesel", "BMW", "3 Series", "Anshuman", 2023, "20-22 km/l", "", 6500, "Blue"},
    Car{"Sedan", "Diesel", "BMW", "5 Series", "Ankush", 2019, "18-20 km/l", "", 8000, "Black"},
    Car{"Sedan", "Diesel", "Audi", "A3", "Rohan", 2019, "20-22 km/l", "", 4500, "Red"},
    Car{"Sedan", "Diesel", "Jaguar", "XE", "Rohan", 2020, "15-17 km/l", "", 7000, "Red"},
    Car{"Sedan", "Diesel", "Jaguar", "XF", "Anusha", 2021, "12-14 km/l", "180 kW", 9000, "White"},
    Car{"Sedan", "Electric", "BMW", "i4", "Anshuman", 2020, "480-590 km", "250 kW", 8000, "Blue"},
    Car{"Sedan", "Electric", "Mercedes-Benz", "EQE", "Stephan", 2022, "450-550 km", "288 kW", 10000, "Silver"},
    Car{"Sedan", "Electric", "Mercedes-Benz", "EQS", "Kiran", 2023, "620-700 km", "", 12000, "Black"},
    Car{"Coupe", "Petrol", "Ford", "Mustang EcoBoost", "Stephan", 2021, "12-14 km/l", "224 kW", 9000, "Red"},
    Car{"Coupe", "Petrol", "Porsche", "911", "Kiran", 2016, "9-11 km/l", "", 18000, "Yellow"},
    Car{"Coupe", "Petrol", "Toyota", "GR Supra", "Simran", 2020, "11-13 km/l", "", 10000, "Red"},
    Car{"Coupe", "Diesel", "BMW", "4 Series Coupe", "Vaishnavi", 2021, "18-20 km/l", "", 7500, "White"},
    Car{"Coupe", "Diesel", "Mercedes-Benz", "C-Class Coupe", "Rohan", 2022, "15-17 km/l", "", 8000, "Blue"},
    Car{"Coupe", "Diesel", "Mercedes-Benz", "E-Class Coupe", "Anshuman", 2023, "12-14 km/l", "", 9500, "Black"},
    Car{"Coupe", "Diesel", "Audi", "A5 Coupe", "Ankush", 2019, "16-18 km/l", "", 7500, "Grey"},
    Car{"Coupe", "Diesel", "Audi", "S5 Coupe", "Vaishnavi", 2022, "14-16 km/l", "", 9000, "Black"},
    Car{"Hatchback", "Petrol", "Volkswagen", "Golf", "Ankush", 2022, "16-18 km/l", "", 3000, "White"},
    Car{"Hatchback", "Petrol", "Volkswagen", "Polo", "Akush", 2021, "17-19 km/l", "", 2500, "Red"},
    Car{"Hatchback", "Petrol", "Ford", "Fiesta", "Anshuman", 2017, "16-18 km/l", "", 3000, "White"},
    Car{"Hatchback", "Petrol", "Ford", "Focus", "Simran", 2018, "15-17 km/l", "", 3500, "Grey"},
    Car{"Hatchback", "Diesel", "Hyundai", "i20", "Rohan", 2020, "22-24 km/l", "", 2800, "White"},
    Car{"Hatchback", "Diesel", "Hyundai", "i30", "Stephan", 2021, "20-22 km/l", "", 3200, "Blue"},
    Car{"Hatchback", "Diesel", "Toyota", "Yaris", "Vaishnavi", 2022, "20-22 km/l", "", 3000, "White"},
    Car{"Hatchback", "Diesel", "Toyota", "Corolla Hatchback", "Anusha", 2022, "18-20 km/l", "", 3500, "Grey"},
    Car{"Hatchback", "Electric", "Mini", "Cooper Electric", "Simran", 2023, "270-290 km", "135 kW", 4500, "Yellow"}
};
void purchaseCar(vector<Car>& cars) {
    cout << "Select a car to purchase by index: ";
    int index;
    cin >> index;

    if (index >= 0 && index < cars.size() && cars[index].isAvailable) {
        cout << "You have successfully purchased the following car:\n";
        cout << "Brand: " << cars[index].brand << "\nModel: " << cars[index].model << "\nPrice: Rs" << cars[index].pricePerDay << "\n";
        cars[index].isAvailable = false; // Mark car as purchased

        // Generate Invoice for Purchase
        generateInvoice(cars[index], "User", true, 0); // Pass 0 for days as it's a purchase
    } else {
        cout << "Invalid index or car not available.\n";
    }
}

void rentCar(vector<Car>& cars) {
    cout << "Select a car to rent by index: ";
    int index;
    cin >> index;

    if (index >= 0 && index < cars.size() && cars[index].isAvailable) {
        cout << "Enter rental duration (in days): ";
        int days;
        cin >> days;

        cout << "You have successfully rented the following car:\n";
        cout << "Brand: " << cars[index].brand << "\nModel: " << cars[index].model << "\nPrice per day: Rs" << cars[index].pricePerDay << "\n";
        double totalCost = cars[index].pricePerDay * days;

        // Generate Invoice for Rental
        cout << "\n--- Invoice ---\n";
        cout << "Car Rental Invoice\n";
        cout << "Model: " << cars[index].model << "\nBrand: " << cars[index].brand << "\nDuration: " << days << " days\n";
        cout << "Price per day: Rs" << cars[index].pricePerDay << "\nTotal Cost: Rs" << totalCost << endl;

        cars[index].isAvailable = false; // Mark car as rented
    } else {
        cout << "Invalid index or car not available.\n";
    }
}
void leaveFeedback(vector<Car>& cars) {
    cout << "Select a car to leave feedback on by index: ";
    int index;
    cin >> index;

    if (index >= 0 && index < cars.size()) {
        cout << "Enter your feedback for the car: ";
        cin.ignore();  // To clear the newline character
        string feedback;
        getline(cin, feedback);

        cars[index].feedback = feedback;
        cout << "Thank you for your feedback!\n";
    } else {
        cout << "Invalid car selection.\n";
    }
}

void returnCar(vector<Car>& cars) {
    cout << "Enter the model of the car you want to return: ";
    string model;
    cin.ignore();  // Clear any lingering input
    getline(cin, model);

    auto it = find_if(cars.begin(), cars.end(), [&model](const Car& car) {
        return car.model == model && !car.isAvailable;
    });

    if (it != cars.end()) {
        it->isAvailable = true;
        cout << "You have successfully returned the car: " << it->model << endl;
    } else {
        cout << "Car not found or not rented.\n";
    }
}

void filterCars(const std::vector<Car>& cars) {
    cout << "Filter Options: \n";
    cout << "1. By Price Range\n2. By Year Range\n3. By Mileage Range\n4. By Color\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    vector<Car> filteredCars;

    switch (choice) {
        case 1: {
            cout << "Enter price range (min max): ";
            double minPrice, maxPrice;
            cin >> minPrice >> maxPrice;
            for (const auto& car : cars) {
                if (car.pricePerDay >= minPrice && car.pricePerDay <= maxPrice) {
                    filteredCars.push_back(car);
                }
            }
            break;
        }
        case 2: {
            cout << "Enter year range (start end): ";
            int startYear, endYear;
            cin >> startYear >> endYear;
            for (const auto& car : cars) {
                if (car.year >= startYear && car.year <= endYear) {
                    filteredCars.push_back(car);
                }
            }
            break;
        }
        case 3: {
            cout << "Enter mileage range (min max): ";
            double minMileage, maxMileage;
            cin >> minMileage >> maxMileage;
            for (const auto& car : cars) {
                double carMileage = stod(car.mileage.substr(0, car.mileage.find("-"))); // Extract first number
                if (carMileage >= minMileage && carMileage <= maxMileage) {
                    filteredCars.push_back(car);
                }
            }
            break;
        }
        case 4: {
            cout << "Enter preferred color: ";
            string color;
            cin >> color;
            transform(color.begin(), color.end(), color.begin(), ::tolower); // Convert input to lowercase
            for (const auto& car : cars) {
                string carColor = car.colors;
                transform(carColor.begin(), carColor.end(), carColor.begin(), ::tolower); // Convert car color to lowercase
                if (carColor.find(color) != string::npos) {
                    filteredCars.push_back(car);
                }
            }
            break;
        }
        default:
            cout << "Invalid choice. No filtering applied.\n";
            return;
    }

    // Display filtered cars
    if (!filteredCars.empty()) {
        cout << "\nFiltered Cars:\n";
        for (const auto& car : filteredCars) {
            car.displayDetails();
        }
    } else {
        cout << "No cars match the filter criteria.\n";
    }
}




void rentVehicle(vector<Car>& cars) {
    filterCars(cars);
    if (!cars.empty()) {
        cout << "Select a car by its index (starting from 0): ";
        int index;
        cin >> index;

        if (index >= 0 && index < cars.size()) {
            cout << "You have successfully rented the following car:\n";
            cout << "Brand: " << cars[index].brand << "\n";
            cout << "Model: " << cars[index].model << "\n";
            cout << "Price Per Day: " << cars[index].pricePerDay << "\n";
            cars.erase(cars.begin() + index); // Remove the rented car from the list
        } else {
            cout << "Invalid index selected.\n";
        }
    } else {
        cout << "No cars available to rent after filtering.\n";
    }
}

void displayMenu() {
    cout << "\nCar Rental System\n";
    cout << "1. Display all cars\n";
    cout << "2. Filter cars\n";
    cout << "3. Purchase a Car\n";
    cout << "4. Rent a Car\n";
    cout << "5. Leave Feedback\n";
    cout << "6. Return a Car\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

string selectFuelType() {
    string fuelType;
    cout << "Choose Fuel Type:\n";
    cout << "1. Petrol\n2. Diesel\n3. Electric\n";
    int fuelChoice;
    cin >> fuelChoice;

    switch (fuelChoice) {
        case 1: fuelType = "Petrol"; break;
        case 2: fuelType = "Diesel"; break;
        case 3: fuelType = "Electric"; break;
        default:
            cout << "Invalid fuel type! Defaulting to Petrol.\n";
          fuelType = "Petrol";
    }
    return fuelType;
}

// Function to generate an invoice for a selected car
void generateInvoice(const Car& car, const std::string& userName, bool toFile, int days) {
    double totalCost = car.pricePerDay * days;

    if (toFile) {
        // Write to a file
        std::ofstream invoice("invoice.txt");
        if (invoice.is_open()) {
            invoice << "\n--- Invoice ---\n";
            invoice << "Invoice for " << userName << "\n";
            invoice << "Car Model: " << car.model << "\nBrand: " << car.brand << "\nFuel Type: " << car.fuelType << "\n";
            invoice << "Price per Day: Rs" << car.pricePerDay << "\n";
            if (days > 0) {
                invoice << "Rental Duration: " << days << " days\n";
                invoice << "Total Rental Cost: Rs" << totalCost << "\n";
            } else {
                invoice << "Total Purchase Price: Rs" << car.pricePerDay << "\n";
            }
            invoice << "Thank you for your purchase/rental!\n";
            invoice.close();
        } else {
            std::cerr << "Error: Unable to open the file for writing.\n";
        }
    } else {
        // Print to console
        std::cout << "\n--- Invoice ---\n";
        std::cout << "Invoice for " << userName << "\n";
        std::cout << "Car Model: " << car.model << "\nBrand: " << car.brand << "\nFuel Type: " << car.fuelType << "\n";
        std::cout << "Price per Day: Rs" << car.pricePerDay << "\n";
        if (days > 0) {
            std::cout << "Rental Duration: " << days << " days\n";
            std::cout << "Total Rental Cost: Rs" << totalCost << "\n";
        } else {
            std::cout << "Total Purchase Price: Rs" << car.pricePerDay << "\n";
        }
        std::cout << "Thank you for your purchase/rental!\n";
    }
}



void displayCars(const vector<Car>& cars) {
    cout << "\nList of Cars:\n";
    for (const Car& car : cars) {
        car.displayDetails();
    }
}
void displayInvoice() {
    std::ifstream invoice("invoice.txt"); // Open the invoice file for reading
    if (invoice.is_open()) {
        std::string line;
        std::cout << "Generated Invoice:\n";
        std::cout << std::string(30, '-') << '\n';
        while (std::getline(invoice, line)) {
            std::cout << line << '\n';
        }
        invoice.close(); // Close the file after reading
    } else {
        std::cerr << "Error: Unable to open the invoice file for reading.\n";
    }
}
 int main(){
   int choice;
    while (true) {
        cout << "\nCar Rental System\n";
        cout << "1. Display all cars\n";
        cout << "2. Filter cars\n";
        cout << "3. Rent a Car\n";
        cout << "4. Leave Feedback\n";
        cout << "5. Return a Car\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Display all cars
                displayCars(cars);
                break;
            case 2:
                // Filter cars
                filterCars(cars);
                break;
            //case 3:
                // Purchase a Car
                //purchaseCar(cars);
               // break;
            case 3:
                // Rent a Car
                rentCar(cars);
                break;
            case 4:
                // Leave Feedback
                leaveFeedback(cars);
                break;
            case 5:
                // Return a Car
                returnCar(cars);
                break;
            case 6:
                // Exit
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}
