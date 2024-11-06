#include<bits/stdc++.h>
using namespace std;

//this is utility function to check the type of object
template<typename Base, typename T>
inline bool isInstanceOf(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}

//data class representing rental info
class RentalInfo {
private:
    int vehicleId;
    string brand;
    int rentalDays;
    int rentalCost;

public:
    RentalInfo(int id, string brand, int days, int cost){
        this->vehicleId = id;
        this->brand = brand;
        this->rentalDays = days;
        this->rentalCost = cost;
    }
    RentalInfo(){

    }
    int getVehicleId(){
        return vehicleId;
    }
    string getBrand(){
        return brand;
    }

    int getDays(){
        return rentalDays;
    }

    int getRentalCost(){
        return rentalCost;
    }
};

class Vehicle {
private:
    int id;
    string brand;
    double price;
    int rental;

public:
    virtual ~Vehicle(){}

    Vehicle(int vehicleId, string brand, double cost, int days){
        this->id = vehicleId;
        this->brand = brand;
        this->price = cost;
        this->rental = days;
    }
    int getRentalDays(){
        return rental;
    }
    string getBrand(){
        return brand;
    }
    double getPrice(){
        return price;
    }
    int getVehicleId(){
    return id;
    }
 
};

class car : public Vehicle {
private:
     string carType;
     string fuelType;
     string transmissionType;

public:
    car(int vehicleId, string brand, double cost, int rentalDays, string type, string fuel, string transmission) : Vehicle(vehicleId, brand, cost, rentalDays){
        this->carType = type;
        this->fuelType = fuel;
        this->transmissionType = transmission;
    }

    void Display(){
        cout << fixed << setprecision(2);
        cout << "Car - ID: " << getVehicleId() << ", Brand: " << getBrand() << ", Price: " << getPrice() << ", Rental Cost: " << getRentalDays() << "/day" << ", Type: " << carType << ", Fuel: " << fuelType << ", Transmission: " << transmissionType << endl;
    }
};

class truck : public Vehicle {
private:
    double cargoCapacity;
    double bedLength;
    int axles;
    double mileage;

public:
    truck(int vehicleId, string brand, double cost, int rentalDays, double capacity, double length, int numAxles, double milesPerGallon): Vehicle(vehicleId, brand, cost, rentalDays){
        this->cargoCapacity = capacity;
        this->bedLength = length;
        this->axles = numAxles;
        this->mileage = milesPerGallon;
    }

    void Display(){
        cout << fixed << setprecision(2);
        cout << "Truck - ID: " << getVehicleId() << ", Brand: " << getBrand() << ", Price: " << getPrice() << ", Rental Cost: " << getRentalDays() << "/day" << ", Cargo Capacity: " << cargoCapacity << " kg, Bed Length: " << bedLength << " m, Axles: " << axles << ", Mileage: " << mileage << " miles/gallon" << endl;
    }

    double getCargoCapacity(){
        return cargoCapacity;
    }
};

class bicycle : public Vehicle {
private:
    int gears;
    string bikeType;
    string frameMaterial;

public:
    bicycle(int vehicleId, string brand, int cost, int rentalDays, string type, string frame, int numGears): Vehicle(vehicleId, brand, cost, rentalDays){
        this->bikeType = type;
        this->frameMaterial = frame;
        this->gears = numGears;
    }

    void Display(){
        cout << fixed << setprecision(2);
        cout << "Bicycle - ID: " << getVehicleId() << ", Brand: " << getBrand() << ", Price: " << getPrice() << ", Rental Cost: " << getRentalDays() << "/day" << ", Type: " << bikeType << ", Frame: " << frameMaterial << ", Gears: " << gears << endl;
    }
};

class drone : public Vehicle {
private:
    double maxAltitude, flightTime;
    int cameraResolution;

public:
    drone(int vehicleId, string brand, double cost, int rentalDays, double altitude, double flightTime, int resolution): Vehicle(vehicleId, brand, cost, rentalDays){
        this->maxAltitude = altitude;
        this->flightTime = flightTime;
        this->cameraResolution = resolution;
    }

    void Display(){
        cout << fixed << setprecision(2);
        cout << "Drone - ID: " << getVehicleId() << ", Brand: " << getBrand() << ", Price: " << getPrice() << ", Rental Cost: " << getRentalDays() << "/day" << ", Max Altitude: " << maxAltitude << " m, Flight time: " << flightTime << " min, Camera Resolution: " << cameraResolution << " MP" << endl;
    }
};
class FleetInformation {
private:
    vector<Vehicle*> vehicles;

public:
    FleetInformation(){

    }
    void Display(vector<Vehicle*> vehicleList){
        double totalValue = 0, totalCargoCapacity = 0;
        for(auto vehicle : vehicleList){
            totalValue += vehicle->getPrice();
            if(isInstanceOf<truck>(vehicle)){
                truck* t = dynamic_cast<truck*>(vehicle);
                totalCargoCapacity += t->getCargoCapacity();
            }
        }
        cout << fixed << setprecision(2);
        cout << "Total Value of All Vehicles: " << totalValue << endl;
        cout << "Total Cargo Capacity of Trucks: " << totalCargoCapacity << " kg" << endl;
    }

    vector<Vehicle*> getVehicles(){
        return vehicles;
    }

    void setVehicles(vector<Vehicle*> vehicleList){
        this->vehicles = vehicleList;
    }

};

class Customer {
private:
    int customerId;
    vector<RentalInfo*> rentalHistory;

public:
    Customer(int id){
        this->customerId = id;
    }

    int getCustomerId(){
        return customerId;
    }

    vector<RentalInfo*> getRentalHistory(){
        return rentalHistory;
    }

    RentalInfo* rent(int customerId, int vehicleId, int rentalDays, vector<Vehicle*> list){
        int totalCost = 0;
        RentalInfo* blankInfo = new RentalInfo();
        for(auto vehicle : list){
            if(vehicle->getVehicleId() == vehicleId){
                totalCost += rentalDays * vehicle->getRentalDays();
                cout << "Vehicle " << vehicleId << " Rented for " << rentalDays << " days by customer " << customerId << ". Rental Cost: " << totalCost << endl;
                RentalInfo* rentalData = new RentalInfo(vehicleId, vehicle->getBrand(), rentalDays, totalCost);
                return rentalData;
            }
        }
        return blankInfo;
    }
    void setRentalHistory(vector<RentalInfo*> rentalData){
        this->rentalHistory = rentalData;
    }
};

int main(){
    FleetInformation* fleetInfo = new FleetInformation();
    vector<Vehicle*> vehicleList;
    vector<RentalInfo*> rentalDataList;
    vector<Customer*> customerList;
    int customerCount = 1;
    
    while(1){
        string input;
        cin >> input;
        
        if(input == "END"){
            break;
        }
        else if(input == "ADD_VEHICLE"){
            string vehicleType;
            cin >> vehicleType;
            if(vehicleType == "d"){
                int vehicleId, rentalDays, cameraResolution;
                string brand;
                double price, maxAltitude, flightTime;
                cin >> vehicleId >> brand >> price >> rentalDays >> maxAltitude >> flightTime >> cameraResolution;
                
                drone* rentalDrone = new drone(vehicleId, brand, price, rentalDays, maxAltitude, flightTime, cameraResolution);
                rentalDrone->Display();
                vehicleList = fleetInfo->getVehicles();
                vehicleList.push_back(rentalDrone);
                fleetInfo->setVehicles(vehicleList);
            }

            else if(vehicleType == "b"){
                int vehicleId, rentalDays, gears;
                double price;
                string brand, bikeType, frameType, frameMaterial, frameType1;
                cin >> vehicleId >> brand >> price >> rentalDays >> bikeType >> frameType;
                
                if(frameType == "Carbon"){
                    cin >> frameType1;
                    frameMaterial = "Carbon Fibre";
                }
                else{
                    frameMaterial = frameType;
                }
                cin >> gears;
              
                bicycle* rentalBicycle = new bicycle(vehicleId, brand, price, rentalDays, bikeType, frameMaterial, gears);
                rentalBicycle->Display();
                vehicleList = fleetInfo->getVehicles();
                vehicleList.push_back(rentalBicycle);
                fleetInfo->setVehicles(vehicleList);
            }
            else if(vehicleType == "t"){
                int vehicleId, rentalDays, axles;
                double price, cargoCapacity, bedLength, mileage;
                string brand;
                cin >> vehicleId >> brand >> price >> rentalDays >> cargoCapacity >> bedLength >> axles >> mileage;
                
                truck* rentalTruck = new truck(vehicleId, brand, price, rentalDays, cargoCapacity, bedLength, axles, mileage);
                rentalTruck->Display();
                vehicleList = fleetInfo->getVehicles();
                vehicleList.push_back(rentalTruck);
                fleetInfo->setVehicles(vehicleList); 
            }
            
            else if(vehicleType == "c"){
                int vehicleId, rentalDays;
                double price;
                string carType, fuelType, transmissionType, brand;
                cin >> vehicleId >> brand >> price >> rentalDays >> carType >> fuelType >> transmissionType;
                car* rentalCar = new car(vehicleId, brand, price, rentalDays, carType, fuelType, transmissionType);
                rentalCar->Display();
                vehicleList = fleetInfo->getVehicles();
                vehicleList.push_back(rentalCar);
                fleetInfo->setVehicles(vehicleList);
            }
            
        }

        else if(input == "ADD_CUSTOMER"){
            Customer* customer = new Customer(customerCount);
            customerList.push_back(customer);
            cout << "Customer " << customerCount << " added" << endl;
            customerCount++;
        }
        
        else if(input == "FLEET_STATISTICS"){
            vehicleList = fleetInfo->getVehicles();
            fleetInfo->Display(vehicleList);
        }

        

        else if(input == "RENT"){
            int customerId, vehicleId, rentalDays;
            cin >> customerId >> vehicleId >> rentalDays;
            for(auto customer : customerList){
                if(customer->getCustomerId() == customerId){
                    RentalInfo* rentalInfo = customer->rent(customerId, vehicleId, rentalDays, fleetInfo->getVehicles());
                    rentalDataList = customer->getRentalHistory();
                    if(rentalInfo->getVehicleId() != 0){
                        rentalDataList.push_back(rentalInfo);
                    }
                    customer->setRentalHistory(rentalDataList);
                    break;
                }
            }
        }

        else if(input == "CUSTOMER_HISTORY"){
            int customerId;
            cin >> customerId;
            for(auto customer : customerList){
                if(customer->getCustomerId() == customerId){
                    cout << "Customer " << customerId << " Rental History:" << endl;
                    rentalDataList = customer->getRentalHistory();
                    for(auto rentalInfo : rentalDataList){
                        cout << "- Vehicle ID: " << rentalInfo->getVehicleId() << ", Brand: " << rentalInfo->getBrand() << ", Rental Duration: " << rentalInfo->getDays() << " days, Rental Cost: " << rentalInfo->getRentalCost() << endl;
                    }
                    break;
                }
            }
        }
    }

    return 0;
}