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
    ListNode* partition(ListNode* head, int z) {
        ListNode* a = new ListNode();
        ListNode* b = new ListNode();
        ListNode* x = a;
        ListNode* y = b;
        while(head!=NULL){
            if(head->val<z){
                x->next=head;
                x=x->next;
            }
            else{
                y->next=head;
                y=y->next;
            }
            head=head->next;
        }
        if(a->next==NULL){
            return b->next;
        }
        x->next = b->next;
        y->next=NULL;
        return a->next;
        // return head;
    }
};