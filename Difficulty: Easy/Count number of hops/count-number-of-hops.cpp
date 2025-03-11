//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {
        // your code here
        int a=0,b=0,c=1,d=0;
        for(int i=n-1;i>=0;i--){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};



//{ Driver Code Starts.
int main() {
    // taking testcases
    int t;
    cin >> t;

    while (t--) {
        // taking number of steps in stair
        int n;
        cin >> n;
        Solution ob;
        // calling function countWays()
        cout << ob.countWays(n) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends