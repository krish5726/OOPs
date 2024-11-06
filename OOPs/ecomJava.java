import java.util.*;

class ecomm{
    public class CartItem
    {
        private int productID;
        private String name;
        private int price;
        private int quantity;

        public CartItem(int productID,String name,int price,int quantity)
        {
            this.productID = productID;
            this.name = name;
            this.price = price;
            this.quantity = quantity;
        }
        //Getter Setters
        public void setProductID(int productID)
        {
            this.productID = productID;
        }
        public void setName(String name)
        {
            this.name = name;
        }
        public void setPrice(int price)
        {
            this.price = price;
        }
        public void setQuantity(int quantity)
        {
            this.quantity = quantity;
        }

        public int getProductID()
        {
            return this.productID;
        }
        public String getName()
        {
            return this.name;
        }
        public int getPrice()
        {
            return this.price;
        }
        public int getQuantity()
        {
            return this.quantity;
        }
    }

    public class ShoppingCart
    {
        private int customerID;
        private ArrayList<CartItem> cart;
        public ShoppingCart(int customerID)
        {
            this.customerID = customerID;
            this.cart = new ArrayList<CartItem>();
        }
        public void setCustomerID(int customerID)
        {
            this.customerID = customerID;
        }
        public int getCustomerID()
        {
            return this.customerID;
        }
        public ArrayList<CartItem> getCart()
        {
            return this.cart;
        }

        public void addItem(int productID,String name,int price,int quantity)
        {
            //Use composition to represent the relationship between a ShoppingCart and its CartItem objects
            CartItem product = new CartItem(productID,name,price,quantity);
            cart.add(product);
        }

        public void removeItem(String name, int quantity)
        {
            for(int i=0;i<cart.size();i++)
            {
                if(name.compareTo(cart.get(i).getName()) == 0)
                {
                    cart.get(i).setQuantity(cart.get(i).getQuantity() - quantity);
                    break;
                }
            }
        }

        public int totalPrice()
        {
            int finalPrice = 0;
            for(int i=0;i<cart.size();i++)
            {
                finalPrice+=cart.get(i).getPrice()*cart.get(i).getQuantity();
            }
            return finalPrice;
        }
    }

    public class Customer
    {
        private ArrayList <ShoppingCart> shopping_cart;
        private String name;
        private int customerID;
        public Customer(String name,int customerID)
        {
            this.shopping_cart = new ArrayList<ShoppingCart>();
            this.name = name;
            this.customerID = customerID;
        }
        public int getCustomerID()
        {
            return this.customerID;
        }
        public String getCustomerName()
        {
            return this.name;
        }  
        public void addShoppingCart(ShoppingCart s)
        {
            shopping_cart.add(s);
        }  
        public ArrayList<ShoppingCart> getShoppingList()
        {
            return shopping_cart;
        }
    }

    public class CustomerManager
    {
        private ArrayList<Customer>customer;
        public CustomerManager()
        {
            this.customer = new ArrayList<Customer>();
        }
        public void createCustomer(Customer c)
        {
            this.customer.add(c);
        }
        public ArrayList<Customer> getCustomerList(){
            return this.customer;
        }
        public void customers()
        {
        for(int i = 0; i<customer.size(); i++)
        {
            System.out.println(customer.get(i).getCustomerName());
        }
        }
        public void addShoppingCart1(Customer c,ShoppingCart s)
        {
            for(int i = 0; i<customer.size(); i++)
            {
                if(customer.get(i).getCustomerID() == c.getCustomerID())
                    customer.get(i).addShoppingCart(s);
            }
        }
        public ArrayList<ShoppingCart> getShoppingList1(Customer c)
        {
            for(int i = 0; i<customer.size(); i++)
            {
                if(customer.get(i).getCustomerID() == c.getCustomerID())
                    return customer.get(i).getShoppingList();
            }
            return customer.get(0).getShoppingList();
        }
        public int totalShoppingCart(Customer c, int s){
            ArrayList<ShoppingCart> cart = new ArrayList<ShoppingCart>();
            for(int i = 0; i<customer.size(); i++)
            {
                if(customer.get(i).getCustomerID() == c.getCustomerID())
                {
                    cart = customer.get(i).getShoppingList();
                    break;
                }
                else
                {
                    cart = customer.get(0).getShoppingList();
                }
            }
            int cost = 0;
            for(int i=0;i<cart.size();i++)
            {
                if(i == s-1){
                    for(int j=0;j<cart.get(i).getCart().size();j++)
                    {
                        cost+=(cart.get(i).getCart().get(j).getPrice() * cart.get(i).getCart().get(j).getQuantity());
                    }
                }
            }
            return cost;
        }
        public int totalAllCostItems(Customer c)
        {
            ArrayList<ShoppingCart> cart = new ArrayList<ShoppingCart>();
            for(int i = 0; i<customer.size(); i++)
            {
                if(customer.get(i).getCustomerID() == c.getCustomerID())
                {
                    cart = customer.get(i).getShoppingList();
                    break;
                }
                else
                {
                    cart = customer.get(0).getShoppingList();
                }
            }
            int cost = 0;
            for(int i=0;i<cart.size();i++)
            {
                for(int j=0;j<cart.get(i).getCart().size();j++)
                {
                    cost+=(cart.get(i).getCart().get(j).getPrice() * cart.get(i).getCart().get(j).getQuantity());
                }
            }
            return cost;
        }
    }

    public static void main(String[] args){
        ecomm x = new ecomm();
        CustomerManager flip = x.new CustomerManager();
        Scanner sc = new Scanner(System.in);
        int noCustomers = sc.nextInt();
        for(int i = 0; i<noCustomers; i++){
            Customer c1 = x.new Customer("Krish", i + 1);
            int noShopping = sc.nextInt();
            for(int j = 0; j<noShopping; j++){
                ShoppingCart s = x.new ShoppingCart(i + 1);
                c1.addShoppingCart(s);
            }
            flip.createCustomer(c1);
        }
        int ops = sc.nextInt();
        String s = sc.nextLine();
        for(int i = 0; i<ops; i++){
            String line = sc.nextLine();
            String[] list = line.split(" ");
            int custID = Integer.parseInt(list[0]);
            ArrayList<Customer> customerList = flip.getCustomerList();
            ArrayList<ShoppingCart> cart = new ArrayList<>();
            Customer cus = x.new Customer("Krish", -1);
            for(Customer c: customerList){
                if(c.getCustomerID() == custID){
                    cus = c;
                }
            }
            if(list.length > 3){
                int shopID = Integer.parseInt(list[1]);
                if(list[2].compareTo("add") == 0){
                    int quan = Integer.parseInt(list[5]);
                    cart = flip.getShoppingList1(cus);
                    cart.get(shopID - 1).addItem(1, list[3], Integer.parseInt(list[4]), quan);
                }
                if(list[2].compareTo("remove") == 0){
                    int quan = Integer.parseInt(list[4]);
                    cart = flip.getShoppingList1(cus);
                    cart.get(shopID - 1).removeItem(list[3], quan);
                }
            }
            if(list.length == 2){
                System.out.println(flip.totalAllCostItems(cus));
            }
            if(list.length == 3){
                int shopID = Integer.parseInt(list[1]);
                System.out.println(flip.totalShoppingCart(cus, shopID));
            }
        }
        sc.close();
    }
}


