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
    int getDecimalValue(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        ListNode* dum=head;
        int ans=0;
        while(dum){
            cnt--;
            if(dum->val==1){
                ans+=(pow(2,cnt));
                
            }
            dum=dum->next;
            
        }
        return ans;
    }
};