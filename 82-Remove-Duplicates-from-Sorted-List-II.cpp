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
        if(!head || head->next==NULL) return head;
        ListNode* dum=new ListNode(0,head);
        ListNode* prev=dum;
        ListNode* temp=head;

        while(temp){
            if(temp->next && temp->next->val == temp->val){
                while(temp->next && temp->next->val == temp->val){
                    temp=temp->next;
                }   
                prev->next=temp->next;
                temp=temp->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return dum->next;
    }
};