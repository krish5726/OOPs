#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
using namespace std;

class cartItem{
    private:
    int productID;
    string name;
    int price;
    int quantity;

    public:
    cartItem(int id, string n, int p, int q){
        this->productID = id;
        this->name = n;
        this->price = p;
        this->quantity = q;
    };
    void setProductID(int productID)
    {
        this->productID = productID;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setPrice(int price)
    {
        this->price = price;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }

    int getProductID()
    {
        return this->productID;
    }
    string getName()
    {
        return this->name;
    }
    int getPrice()
    {
        return this->price;
    }
    int getQuantity()
    {
        return this->quantity;
    }
};

class ShoppingCart{
    private:
    int customerID;
    vector<cartItem*>cart;
    public:
    ShoppingCart(int customerID)
    {
        this->customerID = customerID;
    }
    void setCustomerID(int customerID)
    {
        this->customerID = customerID;
    }
    int getCustomerID()
    {
        return this->customerID;
    }
    vector<cartItem*> getCart()
    {
        return this->cart;
    }
    void addItem(int productID,string name,int price,int quantity){
        cartItem *product = new cartItem(productID,name,price,quantity);
        this->cart.push_back(product);
    }
    void removeItem(string name, int quantity){
        for(auto i = 0; i<this->cart.size(); i++){
            if(this->cart[i]->getName() == name){
                this->cart[i]->setQuantity(this->cart[i]->getQuantity()-quantity);
            }
        }
    }
    int totalPrice(){
        int fin = 0;
        for(auto i = 0; i<this->cart.size(); i++){
            fin+=this->cart[i]->getPrice() * this->cart[i]->getQuantity();
        }
        return fin;
    }
};

class Customer{
    private:
    vector <ShoppingCart*> shopping_cart;
    string name;
    int customerID;
    public:
    Customer(string name,int customerID)
    {
        this->name = name;
        this->customerID = customerID;
    }
    int getCustomerID()
    {
        return this->customerID;
    }
    string getCustomerName()
    {
        return this->name;
    }  
    void addShoppingCart(ShoppingCart *s)
    {
        shopping_cart.push_back(s);
    }  
    vector<ShoppingCart*> getShoppingList()
    {
        return shopping_cart;
    }
};

class CustomerManager{
    private:
    vector<Customer*>customer;
    public:
    void createCustomer(Customer *c)
    {
        this->customer.push_back(c);
    }
    vector<Customer*> getCustomerList(){
        return this->customer;
    }
    void addShoppingCart1(Customer *c, ShoppingCart *s){
        for(auto i = 0; i<this->customer.size(); i++){
            if(c->getCustomerID() == this->customer[i]->getCustomerID()){
                this->customer[i]->addShoppingCart(s);
            }
        }
    }
    vector<ShoppingCart*> getShoppingList(Customer *c){
        for(auto i = 0; i<this->customer.size(); i++){
            if(c->getCustomerID() == this->customer[i]->getCustomerID()){
                return this->customer[i]->getShoppingList();
            }
        }
    }
    int totalShoppingCart(Customer *c, int s){
        vector<ShoppingCart*> cart;
        for(auto i = 0; i<this->customer.size(); i++){
            if(c->getCustomerID() == this->customer[i]->getCustomerID()){
                cart =  this->customer[i]->getShoppingList();
                break;
            }
        }

        int total = 0;
        int i = 0;
        for(auto i = 0; i<cart.size(); i++){
            if(i == s-1){
                for(auto j = 0; j<cart[i]->getCart().size(); j++){
                    total += cart[i]->getCart()[j]->getPrice() * cart[i]->getCart()[j]->getQuantity();
                }
            }
        }

        return total;
    }

    int totalAllItems(Customer *c){
        vector<ShoppingCart*> cart;
        for(auto i = 0; i<this->customer.size(); i++){
            if(c->getCustomerID() == this->customer[i]->getCustomerID()){
                cart =  this->customer[i]->getShoppingList();
                break;
            }
        }

        int total = 0;
        int i = 0;
        for(auto i = 0; i<cart.size(); i++){
            for(auto j = 0; j<cart[i]->getCart().size(); j++){
                total += cart[i]->getCart()[j]->getPrice() * cart[i]->getCart()[j]->getQuantity();
            }
        }

        return total;
    }
};


int main(){
    CustomerManager flip = CustomerManager();
    int noCustomers;
    int noShopping;
    cin >> noCustomers;
    for(int i = 0; i<noCustomers; i++){
        Customer *c1 = new Customer("Krish", i+1);
        cin >> noShopping;
        for(int j = 0; j<noShopping; j++){
            ShoppingCart *s = new ShoppingCart(i+1);
            c1->addShoppingCart(s);
        }
        flip.createCustomer(c1);
    }

    int ops;
    cin >> ops;
    std::string input;
    for(auto j = 0; j<ops + 1; j++){
        std::getline(std::cin, input);
        std::istringstream iss(input);
        std::vector<std::string> words;
        while(iss>>input){
            words.push_back(input); 
        }
        vector<string> list;
        for(const std::string& word: words){
            list.push_back(word);
        }
        int custID;
        for(auto i = 0; i<list.size(); i++){
            if(i == 0){
                custID = stoi(list[i]);
            }
        }
        vector<Customer*> custList = flip.getCustomerList();
        vector<ShoppingCart*> cart;
        Customer cus = Customer("Krish", -1);
        for(auto it = custList.begin(); it != custList.end(); it++){
            if((*it)->getCustomerID() == custID){
                cus = **it;
            }
        } 
        if(list.size()>3){
            int shopID = stoi(list[1]);
            string name = list[3];
            string op = list[2];
            if(op == "add"){
                int p = stoi(list[4]);
                int quan = stoi(list[5]);
                cart = flip.getShoppingList(&cus);
                cart[shopID-1]->addItem(1, name,p, quan);
            }
            if(op == "remove"){
                int quan = stoi(list[4]);
                cart = flip.getShoppingList(&cus);
                cart[shopID-1]->removeItem(name, quan);
            }
        }
        if(list.size() == 2){
            int tot = flip.totalAllItems(&cus);
            cout << tot << endl;
        }
        if(list.size() == 3){
            int shopID = stoi(list[1]);
            int tot = flip.totalShoppingCart(&cus, shopID);
            cout << tot << endl;
        }
    }

}