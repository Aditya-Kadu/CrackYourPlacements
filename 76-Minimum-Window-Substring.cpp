class Solution {
public:
    string minWindow(string s, string p) {
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
        
        if(is==-1) return \\;
        
        return s.substr(is,min_len);
    }
};