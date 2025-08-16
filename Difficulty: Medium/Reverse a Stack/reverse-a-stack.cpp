
class Solution {
  public:
  
    void insert(stack<int>&st,int val){
        if(st.size() < 1){
            st.push(val);
            return;
        }
        int temp=st.top(); st.pop();
        insert(st,val);
        st.push(temp);
    }
    
    void reverse(stack<int> &st) {
        // code here
        if(st.empty()) return;
        
        int val=st.top(); st.pop();
        reverse(st);
        insert(st,val);
        
    }
};