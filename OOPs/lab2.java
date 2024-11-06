import java.util.*;

class lab2{
    static class product{
        private static int var = 1;
        int productId;
        String productName;
        double price;
        product(){
            this.productId = var;
            var++;
        }
        product(String name, double p){
            this.productName = name;
            this.price = p;
            this.productId = var;
            var++;
        }
        product(String name){
            this.productName = name;
            this.price = 0;
            this.productId = var;
            var++;
        }

        public void display(){
            System.out.println("Product Details: ");
            System.out.println("Product ID: " + this.productId);
            System.out.println("Product Name: " + this.productName);
            System.out.println("Price: " + this.price);
            System.out.println();
        }

    }

        public static void main(String args[]){
            Scanner sc = new Scanner(System.in);
            String T;
            T = sc.nextLine();
            int num = Integer.parseInt(T);
            while(num-->0){
                String name = sc.nextLine();
                String pri = sc.nextLine();
                product pro;
                if(pri.compareTo("") == 0){
                    pro = new product(name);
                }
                else{
                    double price = Double.parseDouble(pri);
                    pro = new product(name, price);
                }
                pro.display();
                
            }
        }
    
}