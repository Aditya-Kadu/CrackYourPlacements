//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int l1=s.size();
        int l2=p.size();
        
        vector<int> mp(128, 0);
        vector<int> ms(128, 0);
        
        for(int i=0;i<l2;i++){
            mp[p[i]]++;
        }
        
        int st=0;
        int is=-1;
        int min_len=INT_MAX;
        int cnt=0;
        for(int j=0;j<l1;j++){
            ms[s[j]]++;
            if(mp[s[j]]!=0 && ms[s[j]]<=mp[s[j]]){
                cnt++;
            }
            
            if(cnt==l2){
                while(ms[s[st]]>mp[s[st]] || mp[s[st]]==0){
                    if(ms[s[st]]>mp[s[st]]){
                        ms[s[st]]--;
                    }
                    st++;
                }
                int len=j-st+1;
                if (min_len > len) {
                    min_len = len;
                    is = st;
                }
            }
            
            
        }
        
        if(is==-1) return "-1";
        
        return s.substr(is,min_len);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends