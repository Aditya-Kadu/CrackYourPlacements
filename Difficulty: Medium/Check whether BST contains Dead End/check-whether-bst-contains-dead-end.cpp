//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    Node* pre;
    Node* suc;

    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        if (!root) return;

      
        if (root->data == key) {
          
            if (root->left) {
                Node* tmp = root->left;
                while (tmp->right)
                    tmp = tmp->right;
                pre = tmp;
            }

       
            if (root->right) {
                Node* tmp = root->right;
                while (tmp->left)
                    tmp = tmp->left;
                suc = tmp;
            }
            return;
        }

 
        if (key < root->data) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        } else { 
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }

    void collectLeafNodes(Node* root, vector<int>& leafNodes) {
        if (!root) return;
        if (!root->left && !root->right) leafNodes.push_back(root->data);
        collectLeafNodes(root->left, leafNodes);
        collectLeafNodes(root->right, leafNodes);
    }

    bool isDeadEnd(Node *root) {
        if (!root) return false;

        vector<int> leafNodes;
        collectLeafNodes(root, leafNodes);

        for (int key : leafNodes) {
            pre = suc = NULL;
            findPreSuc(root, pre, suc, key);

    
            int low = (pre == NULL) ? 1 : pre->data + 1;
            int high = (suc == NULL) ? INT_MAX : suc->data - 1;

            if (low == key && high == key) {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends