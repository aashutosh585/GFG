/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort() {
    // Your code here
    vector<int>arr;
    while(!s.empty()){
        arr.push_back(s.top());
        s.pop();
    }
    std::sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        s.push(arr[i]);
    }

}