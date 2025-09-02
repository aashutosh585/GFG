/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        Node* curr=head;
        int n=0;
        while(curr){
            n++;
            curr=curr->next;
        }
        
        if(n<k) return head;
        
        int m=n-k;
        k=k-1;
        
        Node *temp1=head, *temp2=head;
        while(k--){
            temp1=temp1->next;
        }
        
        while(m--){
            temp2=temp2->next;
        }
        swap(temp1->data,temp2->data);
        
        return head;
        
        // Node *next1=temp1->next->next,*next2=temp2->next->next;
        // Node *pre1=temp1->next,*pre2=temp2->next;
        
        
        
        
        
        
        
        
        
    }
};