import java.util.Scanner;
public class jeffDigits {
    public static void main(String args[]){
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int arr[] = new int[n];
        int count0 = 0;
        int count5 = 0;
        boolean zero = false;
        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
            if(arr[i] == 5){
                count5++;
            }
            if(arr[i] == 0){
                zero = true;
                count0++;
            }
        }
       
        if(!zero){
            System.out.println(-1);
        }
        else{
            for(int i = 0; i<(count5/9)*9; i++){
                System.out.print(5);
            }
            if(count5/9 > 0){
                for(int i = 0; i<count0; i++){
                    System.out.print(0);
                }
            }
            else{
                System.out.print(0);
            }
        }
    }
}
