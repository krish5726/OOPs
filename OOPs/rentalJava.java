
import java.util.*;
public class fleet {
    class custMan{
        private ArrayList<customer> cus;
        public custMan(){
            this.cus = new ArrayList<>();
        }
        public ArrayList<customer> getCusList(){
            return this.cus;
        }
        public void setCustList(ArrayList<customer> c){
            this.cus = c;
        }
        public void addCust(customer c){
            System.out.print("Customer ");
            System.out.print(c.getID());
            System.out.println(" added");
            this.cus.add(c);
        }
        public void print(int i){
            for(customer c: cus){
                if(c.getID() == i){
                    c.history();
                }
            }
        }
    }
    class customer{
        private int custID;
        private ArrayList<vehicle> rentals;
        private ArrayList<Integer> days;
        public customer(int id){
            this.custID = id;
            this.rentals = new ArrayList<>();
            this.days = new ArrayList<>();
        }
        public void rent(vehicle e, int days){
            this.rentals.add(e);
            this.days.add(days);
        }
        public int getID(){
            return this.custID;
        }
        public void history(){
            System.out.print("Customer ");
            System.out.print(this.custID);
            System.out.println(" Rental History:");
            for(int i = 0; i<rentals.size(); i++){
                System.out.print("- Vehicle ID: ");
                System.out.print(rentals.get(i).getID());
                System.out.print(", ");
                System.out.print("Brand: ");
                System.out.print(rentals.get(i).getBrand());
                System.out.print(", ");
                System.out.print("Rental Duration: ");
                System.out.print(days.get(i));
                System.out.print(" days, ");
                System.out.print("Rental Cost: ");
                if(rentals.get(i) instanceof car){
                    car c = (car)rentals.get(i);
                    System.out.print((c.getRent() * days.get(i)));
                }
                if(rentals.get(i) instanceof truck){
                    truck c = (truck)rentals.get(i);
                    System.out.print((c.getRent() * days.get(i)));
                }
                if(rentals.get(i) instanceof bicycle){
                    bicycle c = (bicycle)rentals.get(i);
                    System.out.print((c.getRent() * days.get(i)));
                }
                if(rentals.get(i) instanceof drone){
                    drone c = (drone)rentals.get(i);
                    System.out.print((c.getRent() * days.get(i)));
                }
                System.out.println("");
            }
        }
    }
    class listOfVehicles{
        private double totVal;
        private double totCargo;
        private ArrayList<vehicle> vehicles;
        public listOfVehicles(){
            this.vehicles = new ArrayList<>();
            this.totCargo = 0;
            this.totVal = 0;
        }
        public void add(vehicle e){
            this.vehicles.add(e);
        }
        public double totalVal(){
            for(vehicle v: vehicles){
                totVal += v.getPrice();
            }
            return totVal;
        }
        public double totalCargo(){
            for(vehicle v: vehicles){
                if(v instanceof truck){
                    truck t = (truck)v;
                    totCargo += t.getCargo();
                }
            }
            return totCargo;
        }
        public ArrayList<vehicle> getVehicles(){
            return this.vehicles;
        }
        public void details(){
            for(vehicle v: this.vehicles){
                if(v instanceof car){
                    car c = (car)v;
                    System.out.print("Car - ID: ");
                    System.out.print(v.getID());
                    System.out.print(", ");
                    System.out.print("Brand: ");
                    System.out.print(v.getBrand());
                    System.out.print(", ");
                    System.out.print("Price: ");
                    System.out.print(String.format("%.2f", v.getPrice()));
                    System.out.print(", ");
                    System.out.print("Rental Cost: ");
                    System.out.print(c.getRent());
                    System.out.print("/day, ");
                    System.out.print("Type: ");
                    System.out.print(c.getType());
                    System.out.print(", ");
                    System.out.print("Fuel: ");
                    System.out.print(c.getFuel());
                    System.out.print(", ");
                    System.out.print("Transmission: ");
                    System.out.println(c.getTrans());
                }
                if(v instanceof truck){
                    truck c = (truck)v;
                    System.out.print("Truck - ID: ");
                    System.out.print(v.getID());
                    System.out.print(", ");
                    System.out.print("Brand: ");
                    System.out.print(v.getBrand());
                    System.out.print(", ");
                    System.out.print("Price: ");
                    System.out.print(String.format("%.2f", v.getPrice()));
                    System.out.print(", ");
                    System.out.print("Rental Cost: ");
                    System.out.print(c.getRent());
                    System.out.print("/day, ");
                    System.out.print("Cargo Capacity: ");
                    System.out.print(String.format("%.2f", c.getCargo()));
                    System.out.print(" kg, ");
                    System.out.print("Bed Length: ");
                    System.out.print(String.format("%.2f", c.getBed()));
                    System.out.print(" m, ");
                    System.out.print("Axles: ");
                    System.out.print(c.getAxles());
                    System.out.print(", ");
                    System.out.print("Mileage: ");
                    System.out.print(String.format("%.2f", c.getFuel()));
                    System.out.println(" miles/gallon");
                }
                if(v instanceof bicycle){
                    bicycle c = (bicycle)v;
                    System.out.print("Bicycle - ID: ");
                    System.out.print(v.getID());
                    System.out.print(", ");
                    System.out.print("Brand: ");
                    System.out.print(v.getBrand());
                    System.out.print(", ");
                    System.out.print("Price: ");
                    System.out.print(String.format("%.2f", v.getPrice()));
                    System.out.print(", ");
                    System.out.print("Rental Cost: ");
                    System.out.print(c.getRent());
                    System.out.print("/day, ");
                    System.out.print("Type: ");
                    System.out.print(c.getType());
                    System.out.print(", ");
                    System.out.print("Frame: ");
                    System.out.print(c.getFrame());
                    System.out.print(", ");
                    System.out.print("Gears: ");
                    System.out.println(c.getGears());
                }
                if(v instanceof drone){
                    drone c = (drone)v;
                    System.out.print("Drone - ID: ");
                    System.out.print(v.getID());
                    System.out.print(", ");
                    System.out.print("Brand: ");
                    System.out.print(v.getBrand());
                    System.out.print(", ");
                    System.out.print("Price: ");
                    System.out.print(String.format("%.2f", v.getPrice()));
                    System.out.print(", ");
                    System.out.print("Rental Cost: ");
                    System.out.print(c.getRent());
                    System.out.print("/day, ");
                    System.out.print("Max Altitude: ");
                    System.out.print(String.format("%.2f", c.getAlt()));
                    System.out.print(" m, ");
                    System.out.print("Flight time: ");
                    System.out.print(String.format("%.2f", c.getFly()));
                    System.out.print(" min, ");
                    System.out.print("Camera Resolution: ");
                    System.out.print(c.getCam());
                    System.out.println(" MP");
                }
            }
            System.out.print("Total Value of All Vehicles: ");
            System.out.print(String.format("%.2f", this.totalVal()));
            System.out.println("");
            System.out.print("Total Cargo Capacity of Trucks: ");
            System.out.print(String.format("%.2f", this.totalCargo()));
            System.out.println(" kg");
        }
    }
    class vehicle{
        private int vehicleID;
        private String brand;
        private double price;
        public vehicle(int id, String b, double p){
            this.price = p;
            this.vehicleID = id;
            this.brand = b;
        }
        public int getID(){
            return this.vehicleID;
        }
        public double getPrice(){
            return this.price;
        }
        public String getBrand(){
            return this.brand;
        }
        public void setPrice(double p){
            this.price = p;
        }
    }

    class car extends vehicle{
        private int rental;
        private String type;
        private String fuel;
        private String transmission;
        public car(int id, String b, double price, int rental, String type, String fuel, String trans){
            super(id, b, price);
            this.type = type;
            this.fuel = fuel;
            this.transmission = trans;
            this.rental = rental;
        }
        public int getRent(){
            return this.rental;
        }
        public String getType(){
            return this.type;
        }
        public String getFuel(){
            return this.fuel;
        }
        public String getTrans(){
            return this.transmission;
        }
    }
    class truck extends vehicle{
        private int rental;
        private double cargo;
        private double bedLen;
        private int noOfAxles;
        private double fueleff;
        public truck(int id, String b, double price, double cargo, int rental, double bedLen, int noOfAxles, double fueleff){
            super(id, b, price);
            this.rental = rental;
            this.bedLen = bedLen;
            this.noOfAxles = noOfAxles;
            this.fueleff = fueleff;
            this.cargo = cargo;
        }
        public int getRent(){
            return this.rental;
        }
        public double getCargo(){
            return this.cargo;
        }
        public double getBed(){
            return this.bedLen;
        }
        public double getFuel(){
            return this.fueleff;
        }
        public int getAxles(){
            return this.noOfAxles;
        }

    }
    class bicycle extends vehicle{
        private int rental;
        private String type;
        private String frame;
        private int gears;
        public bicycle(int id, String b, double price, int rental, String type, String frame, int gears){
            super(id, b, price);
            this.rental = rental;
            this.type = type;
            this.frame = frame;
            this.gears = gears;
        }
        public int getRent(){
            return this.rental;
        }
        public int getGears(){
            return this.gears;
        }
        public String getType(){
            return this.type;
        }
        public String getFrame(){
            return this.frame;
        }
    }
    class drone extends vehicle{
        private int rental;
        private double maxAlt;
        private double fly;
        private int cam;
        public drone(int id, String b, double price, int rental, double maxAlt, double fly, int cam){
            super(id, b, price);
            this.rental = rental;
            this.maxAlt = maxAlt;
            this.fly = fly;
            this.cam =cam;
        }
        public int getRent(){
            return this.rental;
        }
        public int getCam(){
            return this.cam;
        }
        public double getAlt(){
            return this.maxAlt;
        }
        public double getFly(){
            return this.fly;
        }
    }

    public static void main(String args[]){
        fleet x = new fleet();
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int id = 1;
        custMan cm = x.new custMan();
        listOfVehicles vehicles = x.new listOfVehicles();
        while(str.compareTo("END") != 0){
            if(str.compareTo("ADD_VEHICLE") == 0){
                String s = sc.next();
                if(s.compareTo("c") == 0){
                    int vid = sc.nextInt();
                    String brand = sc.next();
                    double p = sc.nextDouble();
                    int rent = sc.nextInt();
                    String type = sc.next();
                    String fuel = sc.next();
                    String trans = sc.next();
                    car c = x.new car(vid, brand, p, rent, type, fuel, trans);
                    vehicles.add(c);
                }
                if(s.compareTo("t") == 0){
                    int vid = sc.nextInt();
                    String brand = sc.next();
                    double p = sc.nextDouble();
                    int rent = sc.nextInt();
                    double cargo = sc.nextDouble();
                    double bed = sc.nextDouble();
                    int axles = sc.nextInt();
                    double fuel = sc.nextDouble();
                    truck c = x.new truck(vid, brand, p, cargo, rent, bed, axles, fuel);
                    vehicles.add(c);
                }
                if(s.compareTo("b") == 0){
                    int vid = sc.nextInt();
                    String brand = sc.next();
                    double p = sc.nextDouble();
                    int rent = sc.nextInt();
                    String type = sc.next();
                    String frame = sc.next();
                    if(frame.compareTo("Carbon") == 0){
                        sc.next();
                        int gears = sc.nextInt();
                        bicycle b = x.new bicycle(vid, brand, p, rent, type, "Carbon Fibre", gears);
                        vehicles.add(b);
                    }
                    else{
                        int gears = sc.nextInt();
                        bicycle b = x.new bicycle(vid, brand, p, rent, type, frame, gears);
                        vehicles.add(b);
                    }
                }
                if(s.compareTo("d") == 0){
                    int vid = sc.nextInt();
                    String brand = sc.next();
                    double p = sc.nextDouble();
                    int rent = sc.nextInt();
                    double alt = sc.nextDouble();
                    double fly = sc.nextDouble();
                    int cam = sc.nextInt();
                    drone c = x.new drone(vid, brand, p, rent, alt, fly, cam);
                    vehicles.add(c);
                }
            }
            if(str.compareTo("FLEET_STATISTICS") == 0){
                vehicles.details();
            }
            if(str.compareTo("ADD_CUSTOMER") == 0){
                customer c = x.new customer(id);
                cm.addCust(c);
                id++;
            }
            if(str.compareTo("RENT") == 0){
                ArrayList<customer> c = cm.getCusList();
                ArrayList<vehicle> vh = vehicles.getVehicles();
                vehicle rent = x.new vehicle(1, "K", 2);
                int cid = sc.nextInt();
                int vid = sc.nextInt();
                int days = sc.nextInt();
                int price = 0;
                boolean t = false;
                for(vehicle v: vh){
                    if(v.getID() == vid){
                        rent = v;
                        t = true;
                        if(v instanceof car){
                            car r = (car)v;
                            price = r.getRent();
                        }
                        if(v instanceof truck){
                            truck r = (truck)v;
                            price = r.getRent();
                        }
                        if(v instanceof bicycle){
                            bicycle r = (bicycle)v;
                            price = r.getRent();
                        }
                        if(v instanceof drone){
                            drone r = (drone)v;
                            price = r.getRent();
                        }
                    }
                }
                for(customer ct: c){
                    if(ct.getID() == cid && t){
                        ct.rent(rent, days);
                    }
                }
                System.out.print("Vehicle ");
                System.out.print(vid);
                System.out.print(" Rented for ");
                System.out.print(days);
                System.out.print(" days by customer ");
                System.out.print(cid);
                System.out.print(". Rental Cost: ");
                System.out.println((price * days));
            }
            if(str.compareTo("CUSTOMER_HISTORY") == 0){
                int cid = sc.nextInt();
                cm.print(cid);
            }
            str = sc.next();
        }
    }
}
