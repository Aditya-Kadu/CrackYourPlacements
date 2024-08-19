//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int cnt=0;
        vector<int> v;
        for(auto x: mat){
            if(accumulate(x.begin(),x.end(),0)==0){
                v.push_back(cnt);
            }
            cnt++;
        }
        
        
        
        for(auto z: v){
            bool flag=true;
            for(int i=0;i<mat.size();i++){
                if(mat[i][z]==0 && i!=z){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return z;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends