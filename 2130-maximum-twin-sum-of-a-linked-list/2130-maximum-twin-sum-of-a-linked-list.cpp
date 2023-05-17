/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* curr){
        ListNode* prev = new ListNode();
        ListNode* next = new ListNode();
        while (curr != NULL) {
            // Store next
            next = curr->next;
            // Reverse current node's pointer
            curr->next = prev;
            // Move pointers one position ahead.
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    
    int pairSum(ListNode* head) {
        
        if(head == NULL)
            return 0;
        
        ListNode* slow;
        slow=head;
        ListNode* fast;
        fast=head;
        
        while(fast){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=reverse(slow);
        
        int maxi=0;
        while(prev){
            maxi=max(head->val+prev->val,maxi);
            head=head->next;
            prev=prev->next;
                
        }
        return maxi;
    }
};