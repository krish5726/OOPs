import java.util.*;
public class lab3b{
    static class Student{
        String name;
        int grade;
        int age;
        int id;
        public String getAttName(){
            return this.name;
        }
        public int getAttGrade(){
            return this.grade;
        }
        public int getAttAge(){
            return this.age;
        }
        public int getAttID(){
            return this.id;
        }
        public Student(String t, int a, int i, int grade){
            this.name = t;
            this.age = a;
            this.id = i;
            this.grade = grade;
        }
    }
    public static int newId = 1;
    static class Classroom{
        /* Classroom has a Student */
        ArrayList<Student> arr;
        int classID;
        public Classroom(int id){
            this.arr = new ArrayList<>();
            this.classID = id;
        }
        public int getId(){
            return this.classID;
        }
        public void add(Student b1){
            arr.add(b1);
        }
        public void remove(Student b1){
            arr.remove(b1);
        }
        public void display(){
            System.out.println("Class ID: " + this.classID);
            for(int i= 0; i<arr.size(); i++){
                Student b = arr.get(i);
                System.out.println("Student name: " + b.getAttName() );
                System.out.println("Student age: " + b.getAttAge());
                System.out.println("Student id: " + b.getAttID());
                System.out.println("Student grade: " + b.getAttGrade());
            }
        }
    }
    public static void main(String args[]){
        HashSet<Integer> set = new HashSet<>();
        ArrayList<Classroom> arr = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int cnum = sc.nextInt();
        int snum = sc.nextInt();
        for(int i = 0; i<snum; i++){
            int id = sc.nextInt();
            int roll = sc.nextInt();
            int age = sc.nextInt();
            int grade = sc.nextInt();
            String name = sc.next();
            if(!set.contains(id)){
                Classroom c1 = new Classroom(id);
                arr.add(c1);
                Student s1 = new Student(name, roll, age, grade);
                set.add(id);
                c1.add(s1);
            }
            else{
                Student s1 = new Student(name, roll, age, grade);
                for(int j =0; j<arr.size(); j++){
                    if(arr.get(j).getId() == id){
                        arr.get(j).add(s1);
                    }
                }
            }
        }
        for(int i =0; i<arr.size(); i++){
            arr.get(i).display();
        }
        
    }
}