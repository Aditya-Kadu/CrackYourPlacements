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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;

        ListNode* temp = head;
        for(int i=0;i<k;i++){
            if(!temp) return head;
            temp=temp->next; 
        }

        
        
        ListNode* pre=NULL;
        ListNode* cur=head;
        ListNode* ne=NULL;
        int cnt=0;
        while(cur && cnt<k){
            ne=cur->next;
            cur->next=pre;
            pre=cur;
            cur=ne;
            cnt++;
        }

        if(ne!=NULL){
            head->next=reverseKGroup(ne,k);
        }

        return pre;
        
    
    }
};