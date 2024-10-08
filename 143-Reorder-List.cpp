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
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(temp){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }

    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode* mid = middle(head);
        ListNode* tempB=reverse(mid);

        ListNode* tempA=head;
        ListNode* dum=head;
        while(tempB->next){
            dum=dum->next;
            tempA->next=tempB;
            tempB=tempB->next;
            tempA->next->next=dum;
            tempA=tempA->next->next;

        }

        // return head;
    }
};