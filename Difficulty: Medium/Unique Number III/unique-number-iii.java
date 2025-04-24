//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String[] arr1Str = sc.nextLine().split(" ");
            int[] arr = Arrays.stream(arr1Str).mapToInt(Integer::parseInt).toArray();
            Solution ob = new Solution();
            int ans = ob.getSingle(arr);
            System.out.println(ans);

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int getSingle(int[] arr) {
       int ans = 0;
       for(int i=0;i<32;i++){
           int ct1 = 0;
           int ct0 = 0;
           for(int j=0;j<arr.length;j++){
               int bit = ((arr[j]>>i)&1);
               if(bit==1){
                   ct1++;
               }
               else{
                   ct0++;
               }
           }
           if(ct0%3 == 0){
               ans|=(1<<i);
           }
       }
       return ans;
    }
}