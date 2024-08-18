//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node* root) {
    Node* temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* ne=NULL;
        
        while(curr){
            ne=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ne;
        }
        return prev;
    }
    Node *compute(Node *head) {
        // your code goes here
        if(!head) return NULL;
        Node* temp = reverse(head);
        // priority_queue<int,vector<int>,greater<int>> pq;
        Node* dumi = new Node(temp->data);
        Node* dum=dumi;
        
        if(temp->next==NULL) return temp;
        temp=temp->next;
        
        while(temp){
            if(dum->data<=temp->data){
                Node* dummy = new Node(temp->data);
                dum->next=dummy;
                dum=dummy;
            }
            temp=temp->next;
            
        }
        return reverse(dumi);
        
        
    }
};



//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }
        Solution ob;
        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Node* result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends