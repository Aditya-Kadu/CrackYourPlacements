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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=1;
        ListNode* temp=head;
        vector<int> v;
        while(i<left){
           temp=temp->next;
           i++; 
        }
        for(int j=0;j<=(right-left);j++){
            v.push_back(temp->val);
            temp=temp->next;
        }
        reverse(v.begin(),v.end());
        ListNode* temp1=head;
        int k=1;
        while(k<left){
           temp1=temp1->next;
           k++; 
        }
        for(int x: v){
            temp1->val = x;
            temp1=temp1->next;
        }
        return head;
    }
};