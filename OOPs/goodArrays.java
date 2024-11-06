import java.util.Scanner;
public class goodArrays {
    public static void main(String args[]){
        int T, n;
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        while(T-->0){
            n = sc.nextInt();
            int arr[] = new int[n];
            int sum = 0;
            int one = 0;
            for(int i = 0; i<n; i++){
                arr[i] = sc.nextInt();
                sum += arr[i];
                if(arr[i] == 1){
                    one++;
                }
            }
            if(n == 1){
                System.out.println("NO");
            }
            if(sum - n >= one){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }

        }
    }
}
