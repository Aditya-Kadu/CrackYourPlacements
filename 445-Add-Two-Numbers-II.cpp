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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = reverse(l1);
        ListNode* b= reverse(l2);
        // vector<int> ans;
        int carry=0;
        ListNode* dummy = new ListNode();
        ListNode* dum=dummy;
        while(a!=NULL && b!=NULL){
            int x=a->val+b->val+carry;
            carry=0;
            ListNode* makeit = new ListNode(x%10);
            dum->next=makeit;
            dum=makeit;
            if(x>9){
                carry=x/10;
            }
            a=a->next;
            b=b->next;
        }

        while(a){
            int x=a->val+carry;
            carry=0;
            ListNode* makeit = new ListNode(x%10);
            dum->next=makeit;
            dum=makeit;
            if(x>9){
                carry=x/10;
            }
            a=a->next;
        }

        while(b){
            int x=b->val+carry;
            carry=0;
            ListNode* makeit = new ListNode(x%10);
            dum->next=makeit;
            dum=makeit;
            if(x>9){
                carry=x/10;
            }
            b=b->next;
        }
        if(carry!=0){
            int x=carry;
            ListNode* makeit = new ListNode(x%10);
            dum->next=makeit;
            dum=makeit;
        }
        return reverse(dummy->next);
    }
};