class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        string ans=\\;
        int ind1=0;
        int ind2=0;
        int carry=0;
        while(ind1<a.size() && ind2<b.size()){
            if(a[ind1]=='0' && b[ind2]=='0'){
                if(carry==1){
                    ans+=\1\;
                    carry=0;
                }
                else{
                    ans+=\0\;
                }
            }
            else if((a[ind1]=='1' && b[ind2]=='0') || (a[ind1]=='0' && b[ind2]=='1')){
                if(carry==1){
                    ans+=\0\;
                    carry=1;
                }
                else{
                    ans+=\1\;
                }
            }
            else if(a[ind1]=='1' && b[ind2]=='1'){
                if(carry==1){
                    ans+=\1\;
                }
                else{
                    ans+=\0\;
                    carry=1;
                }
                carry=1;
            }
            ind1++;
            ind2++;
        }

        while(ind1<a.size()){
            if(a[ind1]=='1'){
                if(carry==1){
                    ans+=\0\;
                    carry=1;
                }
                else{
                    ans+=\1\;
                }
            }
            else{
                if(carry==1){
                    ans+=\1\;
                    carry=0;
                }
                else{
                    ans+=\0\;
                }
            }
            ind1++;
        }

        while(ind2<b.size()){
            if(b[ind2]=='1'){
                if(carry==1){
                    ans+=\0\;
                    carry=1;
                }
                else{
                    ans+=\1\;
                }
            }
            else{
                if(carry==1){
                    ans+=\1\;
                    carry=0;
                }
                else{
                    ans+=\0\;
                }
            }
            ind2++;
        }

        if(carry==1){
            ans+=\1\;
            carry=0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};