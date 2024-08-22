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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, cmp> pq;

        for(auto x: lists){
            if(x!=NULL){
                pq.push(x);
            }
        }

        ListNode* dum = new ListNode(0);
        ListNode* temp = dum;
        // pq.pop();
        while(!pq.empty()){
            ListNode* nn = pq.top();
            pq.pop();
            temp->next=nn;
            temp=temp->next;
            if(nn->next!=NULL){
                pq.push(nn->next);
            }
        }
        return dum->next;
    }
};