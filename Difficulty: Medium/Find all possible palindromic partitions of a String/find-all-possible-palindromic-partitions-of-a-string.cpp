//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void substring(string s, int ind, vector<vector<string>>& ans, vector<string>& v){
        if(ind==s.size()){
            ans.push_back(v);
            return;
        }
        for(int i=ind; i<s.size();++i){
            if(isPal(s, ind, i)){
                v.push_back(s.substr(ind, i - ind + 1));
                substring(s, i+1, ans, v);
                v.pop_back();
            }
        }
        

    }

    bool isPal(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<string> v;
        vector<vector<string>> ans;
        substring( S,  0, ans,  v);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends