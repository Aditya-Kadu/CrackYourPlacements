class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            
            st.push(num[i]);


        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans=\\;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        // int ind=0;
        // while(ans[ind]=='0'){
        //     ind++;
        // }
        // return ans.substr(ind,ans.size()-ind);
        int ind = 0;
        while (ind < ans.size() && ans[ind] == '0') {
            ind++;
        }
        ans = ans.substr(ind);
        if(ans.size()==0) return \0\;
        return ans;

    }
};