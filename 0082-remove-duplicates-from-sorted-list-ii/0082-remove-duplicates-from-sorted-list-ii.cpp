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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy, *curr=head;
        
        while(curr){
            
            if(curr->next && curr->val == curr->next->val){
                int node=curr->val;
                while(curr && curr->val==node) curr=curr->next;
                prev->next=curr;
                
            }
            else{
                
                prev=prev->next;
                curr=curr->next;
                
                
            }
        }
        return dummy->next;
    }
};