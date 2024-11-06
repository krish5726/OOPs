import java.util.*;
public class lab3{
    static class Book{
        private String title;
        private String author;
        private int ISBN;
        private boolean available;

        public String getAttTitle(){
            return this.title;
        }
        public String getAttAuthor(){
            return this.author;
        }
        public int getAttISBN(){
            return this.ISBN;
        }
        public boolean getAttAvail(){
            return this.available;
        }
        public void setAttAvail(boolean b){
            this.available = b;
        }
        public Book(String t, String a, int i){
            this.title = t;
            this.author = a;
            this.ISBN = i;
            this.available = true;
        }
    }

    static class Library{
        /* Library has a Book */
        public static ArrayList<Book> arr = new ArrayList<>();

        public static void addBook(Book b1){
            arr.add(b1);
        }
        public static void removeBook(Book b1){
            int a = arr.indexOf(b1);
            Book b = arr.get(a);
            b.setAttAvail(false);
            arr.add(b);
        }
        public static void displayBook(){
            for(int i= 0; i<arr.size(); i++){
                Book b = arr.get(i);
                if(b.getAttAvail() == true){
                    System.out.println("Book name: " + b.getAttTitle() );
                    System.out.println("Book author: " + b.getAttAuthor());
                    System.out.println("ISBN: " + b.getAttISBN());
                }
            }
        }
    }
    public static void main(String args[]){
        Book b1 = new Book("Harry Met Sejal", "Sanjay Leela Bhansali", 14567);
        Book b2 = new Book("Pathaan", "Siddhart Anand", 8971);
        Book b3 = new Book("Jawan", "Atlee", 354467);

        Library l1 = new Library();
        l1.addBook(b1);
        l1.addBook(b2);
        l1.addBook(b3);
        l1.removeBook(b1);
        l1.displayBook();
    }
}