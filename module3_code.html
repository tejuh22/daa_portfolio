#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>

// Utility functions for date and time

std::string getCurrentTimestamp()
{
    std::time_t now = std::time(nullptr);
    char buf[80];
    std::strftime(buf, sizeof(buf),
                   "%Y-%m-%d %H:%M:%S",
                   std::localtime(&now)
                  );

    return std::string(buf);
}

// Struct for user details

struct User

{
    std::string name;

    std::string email;

    int rentedBikeId = -1;

    int rentalDurationHours = 0;

    std::string rentalStartDate;

    int totalRentalTime = 0;

    double totalRentalCost = 0.0;

    std::vector<int> rentalHistory;

    void rentBike(int bikeId,
                  const std::string& startDate,
                  int durationHours)

                   {

        rentedBikeId = bikeId;

        rentalStartDate = startDate;

        rentalDurationHours = durationHours;

    }

    
    void returnBike()
    {
        rentedBikeId = -1;
    }

    void addRentalHistory
    (int bikeId)
    
     {
        rentalHistory.push_back(bikeId);
    }

    void updateTotalRentalTime(int hours)
    
    {
        totalRentalTime += hours;
    }

    void updateTotalRentalCost(double cost)
    
     {
        totalRentalCost += cost;
    }

    void printDetails()
    const
    
    {
        std::cout << "Name: " << name << ", Email: " << email << std::endl;
    }
};

// Struct for bike details

struct Bike

 {
     
    int id;
    std::string model;
    std::string type;
    double hourlyRate;
    bool available = true;

    void setAvailability(bool availability)
    
    {
        available = availability;
    }

    void printDetails()
    const
    
    {
        std::cout << "Bike ID: " << id << ", Model: " << model
                  << ", Type: " << type << ", Hourly Rate: $" << hourlyRate
                  << ", Available: " << (available ? "Yes" : "No") << std::endl;
    }
};

// Struct for dealer details

struct Dealer

{
    std::string name;
    
    std::string location;

    void printDetails()
    const
    
    {
        std::cout << "Dealer: " << name << ", Location: " << location << std::endl;
    }
};

// Struct for managing the rental system
struct RentalManager
{
    std::vector<User> users;
    
    std::vector<Bike> bikes;
    
    std::vector<Dealer> dealers;

    void addUser
    (const User& user)
    
     {
        users.push_back(user);
    }

    void addBike
    (const Bike& bike)
    
    {
        bikes.push_back(bike);
    }

    void addDealer
    (const Dealer& dealer)
    
    {
        dealers.push_back(dealer);
    }

    void listUsers()
    const
    
     {
         
        for (const auto& user : users)
        {
            user.printDetails();
        }
    }

    void listBikes()
    const
    
    {
        for (const auto& bike : bikes)
        {
            bike.printDetails();
        }
    }

    void listDealers()
    const
    
    {
        for (const auto& dealer : dealers)
        {
            dealer.printDetails();
        }
    }

    bool rentBike(const std::string& userName,
                  int bikeId,
                  const std::string& startDate,
                   int durationHours)
                   
                   {
                       
        for (auto& bike : bikes)
            {
            if (bike.id == bikeId && bike.available)
            {
                for (auto& user : users)
                {
                    if (user.name == userName)
                     {
                        user.rentBike(bikeId, startDate, durationHours);
                        
                        bike.setAvailability(false);
                        
                        user.updateTotalRentalTime(durationHours);
                        
                        user.updateTotalRentalCost(calculateTotalRentalCost(durationHours, bike.hourlyRate));
                        
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

    
    bool returnBike(const std::string& userName)
    {
        for (auto& user : users)
            
            {
                
            if (user.name == userName)
            
            {
                
                int bikeId = user.rentedBikeId;
        
                if (bikeId != -1)
                    
                 {
                     
                    for (auto& bike : bikes)
                    
                     {
                         
                        if (bike.id == bikeId)
                        
                         {
                             
                            bike.setAvailability(true);
                
                            user.returnBike();
                            
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }

    bool userExists(const std::string& userName)
    const
    
    {
        return std::any_of(users.begin(),
                           users.end(),
                           [&](const User& user)
                           
                           {
                               
            return user.name == userName;
        }
        );
    }

    bool bikeExists(int bikeId)
     const
     
     {
        return std::any_of(bikes.begin(),
                            bikes.end(),
                            [&](const Bike& bike)
                           
                           {
                               
            return bike.id == bikeId;
        }
        );
    }

    bool dealerExists(const std::string& dealerName)
     const
     
     {
        return std::any_of(dealers.begin(),
                            dealers.end(),
                           [&](const Dealer& dealer)
                           
                           {
                               
            return dealer.name == dealerName;
            
        }
        );
    }

    void viewContract(const std::string& userName)
     const
     
     {
        for (const auto& user : users)
            
            {
                
            if (user.name == userName)
            
             {
                std::cout << "Rental Contract for " << userName << ":\n";
        
                std::cout << "Name: " << user.name << ", Email: " << user.email << std::endl;
                
                std::cout << "Rental Start Date: " << user.rentalStartDate << std::endl;
                
                std::cout << "Rental Duration: " << user.rentalDurationHours << " hours" << std::endl;
                
                double totalCost = calculateTotalRentalCost(user.rentalDurationHours, 10.0);
                
                std::cout << "Total Rental Cost: $" << totalCost << std::endl;
                
                return;
            }
        }
        
        std::cout << "User not found.\n";
    }

    double calculateTotalRentalCost(int durationHours, double hourlyRate)
     const
     
     {
        return durationHours * hourlyRate;
    }

    User* searchUserByName
    (const std::string& userName)
    
    {
        for (auto& user : users)
            
            {
                
            if (user.name == userName)
            
            {
                return &user;
            }
        }
        
        return nullptr;
    }

    Bike* findCheapestBike()
     const
     
      {
        if (bikes.empty()) return nullptr;
        
        return const_cast<Bike*>(&(*std::min_element(bikes.begin(),
                                                     bikes.end(),
                                                     [](const Bike& a,
                                                    const Bike& b)
                                                     
                                                      {
                                                          
            return a.hourlyRate < b.hourlyRate;
            
        }
        )
        )
        );
    }

    void displayRentalSummary()
     const
     
      {
          
        std::cout << "Rental Summary:\n";
        
        for (const auto& user : users)
            
            {
                
            if (user.rentedBikeId != -1)
            
            {
                std::cout << "User Name: " << user.name << ", Bike ID: " << user.rentedBikeId
                          << ", Rental Start Date: " << user.rentalStartDate
                          << ", Rental Duration: " << user.rentalDurationHours << " hours\n";
            }
        }
    }
};

void clearScreen()

{
    std::cout << "\033[2J\033[1;1H";
}

void pause()
{
    std::cout << "Press Enter to continue...";
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cin.get();
}


void displayMenu()
{
    std::cout << "Bike Rental System Menu\n";
    
    std::cout << "1. Register User\n";

    std::cout << "2. List Users\n";
    
    std::cout << "3. Add Dealer\n";
    
    std::cout << "4. List Dealers\n";
    
    std::cout << "5. Add Bike\n";
    
    std::cout << "6. List Bikes\n";
    
    std::cout << "7. Rent a Bike\n";

    std::cout << "8. Return a Bike\n";
    
    std::cout << "9. View Contract\n";
    
    std::cout << "10. Search User by Name\n";
    
    std::cout << "11. Find Cheapest Bike\n";
    
    std::cout << "12. Display Rental Summary\n";
    
    std::cout << "13. Exit\n";
    
    std::cout << "Enter your choice: ";
}

int main()

{
    RentalManager rentalManager;

    int choice;
    
    std::string userName, userEmail, dealerName, dealerLocation, bikeModel, bikeType, startDate;
    
    int bikeId, rentalHours;

    while (true)
        
        {
            
        clearScreen();
    
        displayMenu();
        
        std::cin >> choice;
        
        
        switch (choice)
        
        {
            case 1:
                
                std::cin.ignore();
                
                std::cout << "Enter your name: ";
                
                std::getline(std::cin, userName);
                
                std::cout << "Enter your email: ";
                
                std::getline(std::cin, userEmail);
                
                if
                    
                (!rentalManager.userExists(userName))
                
                {
                    
                    rentalManager.addUser({userName, userEmail});
                    std::cout << "User registered successfully.\n";
                }
                
           else
            
                  {
                    std::cout << "User already exists.\n";
                }
           
                pause();
                
                break;

            case 2:
                
                rentalManager.listUsers();
                
                pause();
                
                break;

            case 3:
                
                std::cin.ignore();
                
                std::cout << "Enter dealer name: ";
                
                std::getline(std::cin, dealerName);
                
                std::cout << "Enter dealer location: ";
                
                std::getline(std::cin, dealerLocation);
                
                rentalManager.addDealer({dealerName, dealerLocation});
                
                std::cout << "Dealer added successfully.\n";
                
                pause();
                
                break;

            case 4:
                
                rentalManager.listDealers();
                
                pause();
                
                break;

            case 5:
                
                std::cin.ignore();
                
                std::cout << "Enter bike ID: ";
                
                
                std::cin >> bikeId;
                
                std::cin.ignore();
                
                std::cout << "Enter bike model: ";
                
                std::getline(std::cin, bikeModel);
                
                std::cout << "Enter bike type: ";
                
                std::getline(std::cin, bikeType);
                
                double hourlyRate;
                
                std::cout << "Enter hourly rate: ";
                
                std::cin >> hourlyRate;
                
                rentalManager.addBike({bikeId, bikeModel, bikeType, hourlyRate});
                
                std::cout << "Bike added successfully.\n";
                
                pause();
                
                break;

            case 6:
                
                rentalManager.listBikes();
                
                pause();
                
                break;

            case 7:
                
                std::cin.ignore();
                
                std::cout << "Enter your name: ";
                
                std::getline(std::cin, userName);
                
                std::cout << "Enter bike ID: ";
                
                std::cin >> bikeId;
                
                std::cin.ignore();
                
                std::cout << "Enter rental start date (YYYY-MM-DD): ";
                
                std::getline(std::cin, startDate);
                
                std::cout << "Enter rental duration in hours: ";
                
                std::cin >> rentalHours;
                
                if
                    
                (rentalManager.rentBike(userName, bikeId, startDate, rentalHours))
                
                    {
                        
                    std::cout << "Bike rented successfully.\n";
                }
                
                else
                    
                    {
                        
                    std::cout << "Bike rental failed.\n";
                }
                
                pause();
                
                break;

            case 8:
                
                std::cin.ignore();
                
                std::cout << "Enter your name: ";
                
                
                std::getline(std::cin, userName);
                
                if
                    
                    (rentalManager.returnBike(userName))
                    
                    {
                    std::cout << "Bike returned successfully.\n";
                }
                
                else
                    
                    {
                        
                    std::cout << "Bike return failed.\n";
                }
                
                pause();
                
                break;

            case 9:
                
                std::cin.ignore();
                
                std::cout << "Enter your name: ";
                
                std::getline(std::cin, userName);
                
                rentalManager.viewContract(userName);
                
                pause();
                
                break;


            case 10:
                
                std::cin.ignore();
                
                std::cout << "Enter your name: ";
                
                std::getline(std::cin, userName);
                
                if
                    (User* user = rentalManager.searchUserByName(userName))
                    
                    {
                    user->printDetails();
                }
                else
                    {
                    std::cout << "User not found.\n";
                }
                
                pause();
                
                break;

            case 11:
                
                if
                    (Bike* bike = rentalManager.findCheapestBike())
                    
                    {
                    std::cout << "Cheapest Bike: \n";
                    
                    bike->printDetails();
                }
                
                else
                    
                    {
                    std::cout << "No bikes available.\n";
                }
                
                pause();
                
                break;

            case 12:
                
                rentalManager.displayRentalSummary();
                
                pause();
                
                break;

            case 13:
                
                std::cout << "Exiting system.\n";
                
                return 0;

            default:
                
                std::cout << "Invalid choice. Try again.\n";
                
                pause();
        }
    }
}
