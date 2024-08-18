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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        if(head->val==val && head->next==NULL) return NULL;

        ListNode* temp=head;
        ListNode* dum=new ListNode();
        ListNode* prev = dum;
        prev->next=head;

        while(temp){
            if(temp->val==val){
                temp=temp->next;
                prev->next = temp;
            }
            else{
                prev=prev->next;
                temp=temp->next;
            }
        }
        return dum->next;
    }
};