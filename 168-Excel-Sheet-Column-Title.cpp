class Solution {
public:
    string convertToTitle(int n) {
        string s=\\;
        // unordered_map<int,char> mp={}
        while(n>0){
            n--;
            int a = n%26;
            s+=char('A'+a);
            n/=26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};