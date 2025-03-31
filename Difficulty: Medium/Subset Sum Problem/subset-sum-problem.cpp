//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(int idx,int sum,vector<int>&arr){
        
        if(idx==arr.size() || sum-arr[idx]<0) return false;
        
        if(sum-arr[idx]==0) return true;
        
        bool flag=false;
        for(int i=idx;i<arr.size();i++){
            flag=solve(i+1,sum-arr[idx],arr);
            if(flag) return flag;
        }
        return flag;
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        bool flag=false;
        for(int i=0;i<arr.size();i++){
            flag=solve(i,sum,arr);
            if(flag) return flag;
        }
        return flag;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends