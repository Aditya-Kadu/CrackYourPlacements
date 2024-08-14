class Solution {
public:
    bool isPal(int l,int r,string s){
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        if(isPal(l,r,s)) return true;
        while(l<=r){
            if(s[l]!=s[r]){
                break;
            }
            l++;
            r--;
        }
        return (isPal(l+1,r,s) || isPal(l,r-1,s));
    }
};