class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector< vector<string>> v;
        unordered_map <string, vector<string> > mp;
        for(int i=0; i<len; i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        } 

        for(auto it: mp){
            v.push_back(it.second);
        }
        return v;
    }
};