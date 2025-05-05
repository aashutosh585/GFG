//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n=arr.size(),i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(arr[mid]==target) return mid;
            else if(mid+1<n && arr[mid+1]==target) return mid+1;
            else if(mid-1<n && arr[mid-1]==target) return mid-1;
            else if(arr[mid]<target) i=mid+1;
            else j=mid-1;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends