class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k <= 1) return head;

        Node dummy(0);
        dummy.next = head;
        Node* prevGroupEnd = &dummy;
        Node* curr = head;

        while (curr) {
            Node* groupStart = curr;
            Node* prev = nullptr;
            int cnt = 0;

            // Reverse up to k nodes 
            while (curr && cnt < k) {
                Node* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                cnt++;
            }

            prevGroupEnd->next = prev;
            groupStart->next = curr;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};
