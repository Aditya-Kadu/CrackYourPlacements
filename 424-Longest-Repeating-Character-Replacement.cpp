class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int l=0;
        int r=0;
        int ans=0;
        int mf=0;
        for(r=0;r<s.size();r++){
            mp[s[r]]++;
            mf=max(mf,mp[s[r]]);
            if((r-l+1)-mf>k){
                mp[s[l]]-=1;
                l++;
            }
            else{
                ans=max(ans,r-l+1);
            }
        }
        return ans;
    }
};