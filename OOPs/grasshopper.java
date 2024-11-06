import java.util.*;
import java.io.*;

class gp{

    public static void main(String args[]){
        int T, x, k;
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        while(T-->0){
            x = sc.nextInt();
            k = sc.nextInt();
            if(x % k != 0){
                System.out.println(1);
                System.out.println(x);
            }
            else{
                for(int i = x-1; i>0; i--){
                    if(i % k != 0){
                        System.out.println(2);
                        System.out.println(i + " " + (x-i));
                        break;
                    } 
                }
            }
        }
    }
}