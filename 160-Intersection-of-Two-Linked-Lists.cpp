/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        // while(tempA->next!=NULL || tempB->next!=NULL){
        //     tempA=tempA->next;
        //     tempB=tempB->next;
        // }
        // if(tempA->next==NULL){
        //     tempA=headB;
        //     tempB=tempB->next;
        //     while(tempB->next!=NULL){
        //         tempB=tempB->next;
        //         tempA=tempA->next;
        //     }
        //     tempB=headA;
        //     tempA=tempA->next;
        //     while(tempA->next!=NULL || tempB->next!=NULL){
        //         if(tempA->next==tempB->next){
        //             return tempA->next;
        //         }
        //         tempB=tempB->next;
        //         tempA=tempA->next;
        //     }
        // }
        // if(tempB==NULL){
        //     tempB=headA;
        //     tempA=tempA->next;
        //     while(tempA->next!=NULL){
        //         tempA=tempA->next;
        //         tempB=tempB->next;
        //     }
        //     tempA=headB;
        //     tempB=tempB->next;
        //     while(tempA->next!=NULL || tempB->next!=NULL){
        //         if(tempB->next==tempA->next){
        //             return tempA->next;
        //         }
        //         tempB=tempB->next;
        //         tempA=tempA->next;
        //     }
        // }
        while (tempA!=tempB){
            tempA=(tempA==NULL)?headB : tempA->next;
            tempB=(tempB==NULL)?headA : tempB->next;
        }
        return tempA;
    }
};