//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void makeit(vector<int> &arr ,int l, int r, set<vector<int>>& se){
        if(l==r){
            se.insert(arr);
            return;
        }
        
        for(int i=l;i<=r;i++){
            swap(arr[l],arr[i]);
            makeit(arr,l+1,r,se);
            swap(arr[l],arr[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>> se;
        int l=0;
        int r=arr.size()-1;
        makeit(arr,l,r,se);
        vector<vector<int>> ans;
        for(auto x: se){
            ans.push_back(x);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends