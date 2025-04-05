//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>>dp;
    int solve(int idx,int sum,vector<int>&arr){
        if(idx==arr.size()) {
            return sum==0;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        
        int take=0;
        if(arr[idx]<=sum){
            take=solve(idx+1,sum-arr[idx],arr);
        }
        int Ntake=solve(idx+1,sum,arr);
        
        return dp[idx][sum]=Ntake+take;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum-d<0 || (sum+d)%2 !=0) return 0;
        int target =(sum+d)/2;
        dp.resize(arr.size(),vector<int>(target+1,-1));
        return solve(0,target,arr);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends