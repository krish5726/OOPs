import java.util.*;
public class skiResort {
    public static void main(String args[]){
        int T;
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        while(T-->0){
            int n, k, q;
            n = sc.nextInt();
            k = sc.nextInt();
            q = sc.nextInt();
            long count = 0;
            int arr[] = new int[n];
            for(int i = 0; i<n; i++){
                arr[i] = sc.nextInt();
            }
            long maxi = 0;
            long ans = 0;
            for(int i = 0; i<n; i++){
                if(Math.max(maxi, arr[i]) <= q){
                    count++;
                    maxi = Math.max(maxi, arr[i]);
                }
                else{
                    if(count >=k){
                        long help = count - k + 1;
                        long helper = (help * (help + 1))/2;
                        ans += helper;
                    }
                    count = 0;
                    maxi = 0;
                    if(arr[i] <= q){
                        maxi = arr[i];
                        count = 1;
                    }
                }
            }
            if(count>=k){
                long help = count - k + 1;
                long helper = (help * (help + 1))/2;
                ans += helper;
            }
            System.out.println(ans);
        }
    }
}
