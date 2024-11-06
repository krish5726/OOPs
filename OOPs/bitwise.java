import java.util.*;
import java.io.*;

public class bitwise{
    public static void main(String args[]){
        int T, x;
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        while(T-->0){
            x = sc.nextInt();
            int n = x;
            if(x % 2 == 1){
                if(x == 1)
                    System.out.println(3);
                else
                    System.out.println(1);
            }
            else{
                int num = 1;
                for(int i = 0; i<31; i++){
                    int first = n & 1;
                    if(first == 1){
                        num = (int) Math.pow(2, i);
                        break;
                    }
                    else{
                        num = (int) Math.pow(2, i);
                    }
                    n = n>>1;
                }
                if(num == x){
                    num++;
                }
                System.out.println(num);
            }
        }
    }
}