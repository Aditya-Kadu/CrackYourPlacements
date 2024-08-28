class Solution {
public:
    vector<int> nse(vector<int>& heights){
        int n=heights.size();
        vector<int> a(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                a[i]=n-1;
            }
            else{
                a[i]=st.top()-1;
            }
            st.push(i);
        }
        return a;
    }

    vector<int> lse(vector<int>& heights){
        int n=heights.size();
        vector<int> a(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                a[i]=0;
            }
            else{
                a[i]=st.top()+1;
            }
            st.push(i);
        }
        return a;
    }


    int largestRectangleArea(vector<int>& heights) {
        vector<int> a = nse(heights);
        vector<int> b = lse(heights);
        int maxi = 0;
        for(int i=0;i<heights.size();i++){
            cout<<a[i]<<\ \<<b[i]<<endl;
            maxi=max(maxi, (a[i]-b[i]+1)*heights[i]);
            // cout<<maxi;
        }
        return maxi;

    }
};