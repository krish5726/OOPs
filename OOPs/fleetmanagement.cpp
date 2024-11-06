#include <bits/stdc++.h>
using namespace std;
template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}
class vehicle{
    private:
    int vehicleID;
    string brand;
    double price;
    public:
    virtual ~vehicle() {}
    vehicle(int id, string b, double p){
        this->price = p;
        this->vehicleID = id;
        this->brand = b;
    }
    int getID(){
        return this->vehicleID;
    }
    double getPrice(){
        return this->price;
    }
    string getBrand(){
        return this->brand;
    }
    void setPrice(double p){
        this->price = p;
    }
};
class car: public vehicle{
    private:
    int rental;
    string type;
    string fuel;
    string transmission;
    public:
    car(int id, string b, double price, int rental, string type, string fuel, string trans) : vehicle(id, b, price){
        this->type = type;
        this->fuel = fuel;
        this->transmission = trans;
        this->rental = rental;
    }
    int getRent(){
        return this->rental;
    }
    string getType(){
        return this->type;
    }
    string getFuel(){
        return this->fuel;
    }
    string getTrans(){
        return this->transmission;
    }
};

class truck: public vehicle{
        private:
        int rental;
        double cargo;
        double bedLen;
        int noOfAxles;
        double fueleff;
        public:
        truck(int id, string b, double price, double cargo, int rental, double bedLen, int noOfAxles, double fueleff) : vehicle(id, b, price){
            this->rental = rental;
            this->bedLen = bedLen;
            this->noOfAxles = noOfAxles;
            this->fueleff = fueleff;
            this->cargo = cargo;
        }
        int getRent(){
            return this->rental;
        }
        double getCargo(){
            return this->cargo;
        }
        double getBed(){
            return this->bedLen;
        }
        double getFuel(){
            return this->fueleff;
        }
        int getAxles(){
            return this->noOfAxles;
        }

};

class bicycle: public vehicle{
        private:
        int rental;
        string type;
        string frame;
        int gears;
        public:
        bicycle(int id, string b, double price, int rental, string type, string frame, int gears) : vehicle(id, b, price){
            this->rental = rental;
            this->type = type;
            this->frame = frame;
            this->gears = gears;
        }
        int getRent(){
            return this->rental;
        }
        int getGears(){
            return this->gears;
        }
        string getType(){
            return this->type;
        }
        string getFrame(){
            return this->frame;
        }
    };

class drone:public vehicle{
        private:
        int rental;
        double maxAlt;
        double fly;
        int cam;
        public:
        drone(int id, string b, double price, int rental, double maxAlt, double fly, int cam) : vehicle(id, b, price){
            this->rental = rental;
            this->maxAlt = maxAlt;
            this->fly = fly;
            this->cam =cam;
        }
        int getRent(){
            return this->rental;
        }
        int getCam(){
            return this->cam;
        }
        double getAlt(){
            return this->maxAlt;
        }
        double getFly(){
            return this->fly;
        }
    };
class customer{
        private:
        int custID;
        vector<vehicle*> rentals;
        vector<int> days;
        public:
        customer(int id){
            this->custID = id;
        }
        void rent(vehicle *e, int days){
            this->rentals.push_back(e);
            this->days.push_back(days);
        }
        int getID(){
            return this->custID;
        }
        void history(){
            cout << "Customer ";
            cout << (this->custID);
            cout << " Rental History:" << endl;
            for(auto i = 0; i<this->rentals.size(); i++){
                cout << "- Vehicle ID: ";
                cout << (this->rentals[i]->getID());
                cout << ", ";
                cout << "Brand: ";
                cout << (this->rentals[i]->getBrand());
                cout << ", ";
                cout << "Rental Duration: ";
                cout << (this->days[i]);
                cout << " days, ";
                cout << "Rental Cost: ";
                if(instanceof<car>(rentals[i])){
                    car* c = dynamic_cast<car*>(this->rentals[i]);
                    cout << ((c->getRent() * this->days[i]));
                }
                else if(instanceof<truck>(rentals[i])){
                    truck* c = dynamic_cast<truck*>(this->rentals[i]);
                    cout << ((c->getRent() * this->days[i]));
                }
                else if(instanceof<bicycle>(rentals[i])){
                    bicycle* c = dynamic_cast<bicycle*>(this->rentals[i]);
                    cout << ((c->getRent() * this->days[i]));
                }
                else if(instanceof<drone>(this->rentals[i])){
                    drone* c = dynamic_cast<drone*>(this->rentals[i]);
                    cout << ((c->getRent() * this->days[i]));
                }
                cout << "" << endl;
            }
        }
    };


class listOfVehicles{
        private:
        vector<vehicle*> vehicles;
        public:

        void add(vehicle *e){
            this->vehicles.push_back(e);
        }
        double totalVal(){
            double totVal = 0;
            for(auto i = 0; i<this->vehicles.size(); i++){
                totVal += (this->vehicles[i])->getPrice();
            }
            return totVal;
        }
        double totalCargo(){
            double totCargo = 0;
            for(auto i = 0; i<this->vehicles.size(); i++){
                if(instanceof<truck>(this->vehicles[i])){
                    truck* t = dynamic_cast<truck*>(this->vehicles[i]);
                    totCargo += t->getCargo();
                }
            }
            return totCargo;
        }
        vector<vehicle*> getVehicles(){
            return this->vehicles;
        }
        void details(){
            for(vehicle *v: this->vehicles){
                if(instanceof<car>(v)){
                    car* c = dynamic_cast<car*>(v);
                    cout << "Car - ID: ";
                    cout << v->getID();
                    cout << ", ";
                    cout << "Brand: ";
                    cout << v->getBrand();
                    cout << ", ";
                    cout << "Price: ";
                    cout << fixed << setprecision(2) << v->getPrice();
                    cout << ", ";
                    cout << "Rental Cost: ";
                    cout << c->getRent();
                    cout << "/day, ";
                    cout << "Type: ";
                    cout << c->getType();
                    cout << ", ";
                    cout << "Fuel: ";
                    cout << c->getFuel();
                    cout << ", ";
                    cout << "Transmission: ";
                    cout << c->getTrans() << endl;
                }
                else if(instanceof<truck>(v)){
                    truck* c = dynamic_cast<truck*>(v);
                    cout << "Truck - ID: ";
                    cout << v->getID();
                    cout << ", ";
                    cout << "Brand: ";
                    cout << v->getBrand();
                    cout << ", ";
                    cout << "Price: ";
                    cout << fixed << setprecision(2) << v->getPrice();
                    cout << ", ";
                    cout << "Rental Cost: ";
                    cout << c->getRent();
                    cout << "/day, ";
                    cout << "Cargo Capacity: ";
                    cout << fixed << setprecision(2) << c->getCargo();
                    cout << " kg, ";
                    cout << "Bed Length: ";
                    cout << fixed << setprecision(2) << c->getBed();
                    cout << " m, ";
                    cout << "Axles: ";
                    cout << c->getAxles();
                    cout << ", ";
                    cout << "Mileage: ";
                    cout << fixed << setprecision(2) << c->getFuel();
                    cout << " miles/gallon" << endl;
                }
                else if(instanceof<bicycle>(v)){
                    bicycle* c = dynamic_cast<bicycle*>(v);
                    cout << "Bicycle - ID: ";
                    cout << v->getID();
                    cout << ", ";
                    cout << "Brand: ";
                    cout << v->getBrand();
                    cout << ", ";
                    cout << "Price: ";
                    cout <<  fixed << setprecision(2) << v->getPrice();
                    cout << ", ";
                    cout << "Rental Cost: ";
                    cout << c->getRent();
                    cout << "/day, ";
                    cout << "Type: ";
                    cout << c->getType();
                    cout << ", ";
                    cout << "Frame: ";
                    cout << c->getFrame();
                    cout << ", ";
                    cout << "Gears: ";
                    cout << c->getGears() << endl;
                }
                else if(instanceof<drone>(v)){
                    drone* c = dynamic_cast<drone*>(v);
                    cout << "Drone - ID: ";
                    cout << v->getID();
                    cout << ", ";
                    cout << "Brand: ";
                    cout << v->getBrand();
                    cout << ", ";
                    cout << "Price: ";
                    cout << fixed << setprecision(2) <<  v->getPrice();
                    cout << ", ";
                    cout << "Rental Cost: ";
                    cout << c->getRent();
                    cout << "/day, ";
                    cout << "Max Altitude: ";
                    cout << fixed << setprecision(2) <<  c->getAlt();
                    cout << " m, ";
                    cout << "Flight time: ";
                    cout << fixed << setprecision(2) <<  c->getFly();
                    cout << " min, ";
                    cout << "Camera Resolution: ";
                    cout << c->getCam();
                    cout << " MP" << endl;
                }
            }
            cout << "Total Value of All Vehicles: ";
            cout << fixed << setprecision(2) <<  this->totalVal();
            cout << "" << endl;
            cout << "Total Cargo Capacity of Trucks: ";
            cout << fixed << setprecision(2) <<  this->totalCargo();
            cout << " kg" <<endl;
        }
    };
    class custMan{
        private:
        vector<customer *> cus;
        public:
        vector<customer *> getCusList(){
            return this->cus;
        }
        void setCustList(vector<customer *> c){
            this->cus = c;
        }
        void addCust(customer *c){
            cout << "Customer ";
            cout << (c->getID());
            cout << " added" << endl;
            this->cus.push_back(c);
        }
        void print(int j){
            for(auto i = 0; i<this->cus.size(); i++){
                if(this->cus[i]->getID() == j){
                    this->cus[i]->history();
                }
            }
        }
    };
    
    int main(){
        int id = 1;
        custMan cm = custMan();
        listOfVehicles vehicles = listOfVehicles();
        while(true){
            string input;
            cin >> input;
            if(input.compare("END") == 0){
                break;
            }
            else if(input.compare("ADD_VEHICLE") == 0){
                string s;
                cin >> s;
                if(s.compare("c") == 0){
                    int vid, rent;
                    string brand, type, fuel, trans;
                    double p;
                    cin >> vid;
                    cin >> brand;
                    cin >> p;
                    cin >> rent;
                    cin >> type;
                    cin >> fuel;
                    cin >> trans;
                    car *c = new car(vid, brand, p, rent, type, fuel, trans);
                    vehicles.add(c);
                }
                else if(s.compare("t") == 0){
                    int vid, rent, axles;
                    double p, cargo, bed, fuel;
                    string brand;
                    cin >> vid;
                    cin >> brand;
                    cin >> p;
                    cin >> rent;
                    cin >> cargo;
                    cin >> bed;
                    cin >> axles;
                    cin >> fuel;
                    truck *c = new truck(vid, brand, p, cargo, rent, bed, axles, fuel);
                    vehicles.add(c);
                }
                else if(s.compare("b") == 0){
                    int vid, rent, gears;
                    string brand, type, frame;
                    double p;
                    cin >> vid;
                    cin >> brand;
                    cin >> p;
                    cin >> rent;
                    cin >> type;
                    cin >> frame;
                    if(frame == "Carbon"){
                        string st;
                        cin >> st;
                        cin >> gears;
                        bicycle *b = new bicycle(vid, brand, p, rent, type, "Carbon Fibre", gears);
                        vehicles.add(b);
                    }
                    else{
                        cin >> gears;
                        bicycle *b = new bicycle(vid, brand, p, rent, type, frame, gears);
                        vehicles.add(b);
                    }
                }
                else if(s.compare("d") == 0){
                    int vid, rent, alt, fly, cam;
                    string brand;
                    double p;
                    cin >> vid;
                    cin >> brand;
                    cin >> p;
                    cin >> rent;
                    cin >> alt;
                    cin >> fly;
                    cin >> cam;
                    drone *c = new drone(vid, brand, p, rent, alt, fly, cam);
                    vehicles.add(c);
                }
            }
            else if(input.compare("FLEET_STATISTICS") == 0){
                vehicles.details();
            }
            else if(input.compare("ADD_CUSTOMER") == 0){
                customer *c = new customer(id);
                cm.addCust(c);
                id++;
            }
            else if(input.compare("RENT") == 0){
                vector<customer*> c = cm.getCusList();
                vector<vehicle*> vh = vehicles.getVehicles();
                vehicle *rent = new vehicle(1, "K", 2);
                int cid;
                int vid;
                int days;
                cin >> cid;
                cin >> vid;
                cin >> days;
                int price = 0;
                for(vehicle *v: vh){
                    if(v->getID() == vid){
                        rent = v;
                        if(instanceof<car>(v)){
                            car* r = dynamic_cast<car*>(v);
                            price = r->getRent();
                        }
                        else if(instanceof<truck>(v)){
                            truck* r = dynamic_cast<truck*>(v);
                            price = r->getRent();
                        }
                        else if(instanceof<bicycle>(v)){
                            bicycle* r = dynamic_cast<bicycle*>(v);
                            price = r->getRent();
                        }
                        else if(instanceof<drone>(v)){
                            drone* r = dynamic_cast<drone*>(v);
                            price = r->getRent();
                        }
                    }
                }
                for(customer *ct: c){
                    if(ct->getID() == cid){
                        ct->rent(rent, days);
                    }
                }
                cout << "Vehicle ";
                cout << vid;
                cout << " Rented for ";
                cout << days;
                cout << " days by customer ";
                cout << cid;
                cout << ". Rental Cost: ";
                cout << (price * days) << endl;
            }
            else if(input.compare("CUSTOMER_HISTORY") == 0){
                int cid;
                cin >> cid;
                cm.print(cid);
            }
            
        }
    }
