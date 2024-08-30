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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // int i=0;
        // ListNode* temp1 = l1;
        // ListNode* temp2 = l2;
        // long long num1=0;
        // long long num2=0;
        // while(temp1!=NULL){
        //     long long value = pow(10,i);
        //     num1 += value*(temp1->val);
        //     i++;
        //     temp1=temp1->next;  
        // }
        // int j=0;
        // while(temp2!=NULL){
        //     num2 += pow(10,j)*(temp2->val);
        //     temp2=temp2->next;
        //     j++;
        // }
        // long long num3=num1+num2;
        // cout<<num3;
        // ListNode* head = new ListNode(num3 % 10);
        // num3 /= 10;
        // ListNode* temp3 = head;
        // while(num3!=0){
        //     temp3->next = new ListNode(num3%10);
        //     num3 = floor(num3/10);
        //     temp3=temp3->next;
        // }
        // return head;

        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};