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

        ListNode* prev=head;
        ListNode* temp=head->next;

        while(temp){
            if(prev->val == temp->val){
                temp=temp->next;
                prev->next=temp;   
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};