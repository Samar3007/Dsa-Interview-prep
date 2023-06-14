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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy= new ListNode();
        dummy->next=head;
        if(head->next==NULL) return NULL;
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        while(fast->next != NULL && fast->next->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
       
        return head;
    }
};