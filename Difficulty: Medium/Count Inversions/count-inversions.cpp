class Solution {
public:

    int merge(int l, int mid, int h, vector<int>& arr) {

        vector<int> temp;
        int i = l, j = mid + 1;
        int cnt = 0;

        while(i <= mid && j <= h){
            if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
            else {
                cnt += (mid - i + 1);  
                temp.push_back(arr[j++]);
            }
        }

        while(i <= mid) temp.push_back(arr[i++]);
        
        while(j <= h) temp.push_back(arr[j++]);
        
        for(int k = l; k <= h; k++) arr[k] = temp[k - l];
        
        return cnt;
    }

    int solve(int i, int j, vector<int>& arr) {
        if(i >= j) return 0;

        int mid = (i + j) / 2;

        int left = solve(i, mid, arr);
        int right = solve(mid + 1, j, arr);
        int cross = merge(i, mid, j, arr);

        return left + right + cross;
    }

    int inversionCount(vector<int>& arr) {
        return solve(0, arr.size() - 1, arr);
    }
};