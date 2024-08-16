class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int c=0;
        for(auto x: s){
            if(st.empty()){
                st.push({x,1});
                continue;
            }
            if(st.top().first==x){
                int c=st.top().second;
                st.push({x,c+1});
                int ind=c+1;
                if((ind)==k){
                    while(ind!=0){
                        st.pop();
                        ind--;
                    }
                }
            }
            else{
                st.push({x,1});
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};