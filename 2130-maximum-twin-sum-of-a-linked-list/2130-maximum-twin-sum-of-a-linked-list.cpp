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
    int pairSum(ListNode* head) {
        
        if(head == NULL)
            return 0;
        
        ListNode* temp = head;
        stack<int> st;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        int n=st.size();
        temp=head;
        int maxi=0;
        while(n!=0){
            maxi=max(temp->val+ st.top(),maxi);
            st.pop();
            temp=temp->next;
            n-=2;
        }
       
        
       
        return maxi;
    }
};