class Solution {
public:
    string reverseWords(string s) {
        string temp=\\;
        vector <string> ans;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else{
                if(!temp.empty()){
                    ans.push_back(temp);
                    temp=\\;
                }
            }

        }
        if (!temp.empty()) {
            ans.push_back(temp);
        }
        string n=\\;
        for(int i=ans.size()-1; i>=0; i--){
            n+=ans[i];
            n+=\ \;
        }
        n.pop_back();
        return n;
        
    }
};