import java.util.*;

class lib{
    public class Book{
        private String title;
        private String author;
        private int copiesAvailable;
        private int bookID;
        public Book(int id, String t, String a, int c){
            this.bookID = id;
            this.title = t;
            this.author = a;
            this.copiesAvailable = c;
        }
        public int getID(){
            return this.bookID;
        }
        public String getTitle(){
            return this.title;
        }
        public String getAuthor(){
            return this.author;
        }
        public int getCopies(){
            return this.copiesAvailable;
        }
        public void setCopies(int n){
            this.copiesAvailable = n;
        }
    }

    public class Student{
        private int studentID;
        private String name;
        private ArrayList<Book> borrowedBooks;
        public Student(int id, String n){
            this.studentID = id;
            this.name = n;
            borrowedBooks = new ArrayList<>();
        }
        public int getID(){
            return this.studentID;
        }
        public String getString(){
            return this.name;
        }
        public ArrayList<Book> getBorrowedBooks(){
            return this.borrowedBooks;
        }
        public void setBorrowedBooks(ArrayList<Book> b){
            this.borrowedBooks = b;
        }
        public void printBooks(){
            System.out.print("Books borrowed by student ");
            System.out.println(this.studentID + ":");
            if(this.borrowedBooks.size() == 0){
                System.out.println("No books borrowed. ");
            }
            else{
                Collections.sort(borrowedBooks, new BookComparator());
                for(Book b: this.borrowedBooks){
                    System.out.print("Book ID: ");
                    System.out.print(b.getID() + ", ");
                    System.out.print("Title: ");
                    System.out.print("\"" + b.getTitle() + "\", ");
                    System.out.print("Author: ");
                    System.out.println("\"" + b.getAuthor() + "\"");
                }
            }


        }
    }

    public class BookComparator implements Comparator<Book> { 
        // override the compare() method 
        public int compare(Book s1, Book s2) 
        { 
            if (s1.getID() == s2.getID()) 
                return 0; 
            else if (s1.getID() > s2.getID()) 
                return 1; 
            else
                return -1; 
        } 
    } 
    public class StudentComparator implements Comparator<Student> { 
        // override the compare() method 
        public int compare(Student s1, Student s2) 
        { 
            if (s1.getID() == s2.getID()) 
                return 0; 
            else if (s1.getID() > s2.getID()) 
                return 1; 
            else
                return -1; 
        } 
    } 
    public class Transactions{
        private Book b;
        private Student s;
        public Transactions(Book b, Student s){
            this.b = b;
            this.s = s;
        }
        public void borrow(){
            if(b.getCopies() > 0){
                ArrayList<Book> bk = s.getBorrowedBooks();
                bk.add(b);
                s.setBorrowedBooks(bk);
                b.setCopies(b.getCopies()-1);
            }
        }
        public void returnBook(){
            ArrayList<Book> bk = s.getBorrowedBooks();
            bk.remove(b);
            s.setBorrowedBooks(bk);
            b.setCopies(b.getCopies() + 1);
        }
    }

    public class Library{
        private ArrayList<Student> students;
        private ArrayList<Book> books;
        private ArrayList<Transactions> trans;

        public Library(){
            students = new ArrayList<>();
            books = new ArrayList<>();
            trans = new ArrayList<>();
        }
        public ArrayList<Book> getBooks(){
            return this.books;
        }
        public ArrayList<Student> getStudents(){
            return this.students;
        }
        public ArrayList<Transactions> getTrans(){
            return this.trans;
        }
        public void setBooks(ArrayList<Book> b){
            this.books = b;
        }
        public void setStudents(ArrayList<Student> b){
            this.students = b;
        }
        public void setTrans(ArrayList<Transactions> b){
            this.trans = b;
        }
    }

    public static void main(String args[]){
        int n, m ,q;
        Scanner sc = new Scanner(System.in);
        lib x = new lib();
        n = sc.nextInt();
        m = sc.nextInt();
        q = sc.nextInt();
        Library lib = x.new Library();
        ArrayList<Book> books = new ArrayList<>();
        ArrayList<Student> students = new ArrayList<>();
        ArrayList<Transactions> trans = new ArrayList<>();
        String st = sc.nextLine();
        for(int i = 0; i<n; i++){
            String line = sc.nextLine();
            String[] l1 = line.split(" ");
            String[] list = line.split("\"");
            int id = Integer.parseInt(l1[0]);
            String name = list[1];
            String auth = list[3];
            int cop = Integer.parseInt(l1[l1.length-1]);
            Book b1 = x.new Book(id, name, auth, cop);
            books.add(b1);
            lib.setBooks(books);
        }
        for(int i = 0; i<m; i++){
            String line = sc.nextLine();
            String[] list = line.split(" ");
            int id = Integer.parseInt(list[0]);
            String name = list[1];
            Student s1 = x.new Student(id, name);
            students.add(s1);
            lib.setStudents(students);
        }
        Collections.sort(students, x.new StudentComparator());
        lib.setStudents(students);
        for(int i = 0; i<q; i++){
            String line = sc.nextLine();
            String[] list = line.split(" ");
            int bo = Integer.parseInt(list[0]);
            int bid = Integer.parseInt(list[1]);
            int sid = Integer.parseInt(list[2]);
            if(bo == 1){
                Book b1 = x.new Book(1, "K", "K", 1);
                Student s1 = x.new Student(1, "K");
                for(Book bk: books){
                    if(bk.getID() == bid){
                        b1 = bk;
                    }
                }
                for(Student s: students){
                    if(s.getID() == sid){
                        s1 = s;
                    }
                }
                Transactions t = x.new Transactions(b1, s1);
                trans.add(t);
                lib.setTrans(trans);
                t.borrow();
            }
            else{
                Book b1 = x.new Book(1, "K", "K", 1);
                Student s1 = x.new Student(1, "K");
                for(Book bk: books){
                    if(bk.getID() == bid){
                        b1 = bk;
                    }
                }
                for(Student s: students){
                    if(s.getID() == sid){
                        s1 = s;
                    }
                }
                Transactions t = x.new Transactions(b1, s1);
                trans.add(t);
                lib.setTrans(trans);
                t.returnBook();
            }
        }

        for(Student s: students){
            s.printBooks();
        }
        sc.close();
    }
}