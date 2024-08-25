class Solution {
public:
    unordered_map<int, string> mp = {
        {0, \\}, {1, \One\}, {2, \Two\}, {3, \Three\}, {4, \Four\},
        {5, \Five\}, {6, \Six\}, {7, \Seven\}, {8, \Eight\}, {9, \Nine\}
    };
    
    unordered_map<int, string> mp_tens = {
        {10, \Ten\}, {11, \Eleven\}, {12, \Twelve\}, {13, \Thirteen\}, {14, \Fourteen\},
        {15, \Fifteen\}, {16, \Sixteen\}, {17, \Seventeen\}, {18, \Eighteen\}, {19, \Nineteen\},
        {2, \Twenty\}, {3, \Thirty\}, {4, \Forty\}, {5, \Fifty\}, {6, \Sixty\},
        {7, \Seventy\}, {8, \Eighty\}, {9, \Ninety\}
    };
    
    unordered_map<int, string> mp_val = {
        {0, \\}, {1, \Thousand\}, {2, \Million\}, {3, \Billion\}, {4, \Trillion\}
    };

    string makeit(string s) {
        string res = \\;
        while (s.size() != 3) {
            s = '0' + s;
        }
        if (s[0] != '0') {
            res += mp[s[0] - '0'] + \ Hundred\;
        }
        if (s[1] == '1') {
            int val = stoi(s.substr(1, 2));
            if (!res.empty()) res += \ \;
            res += mp_tens[val];
        } else {
            if (s[1] != '0') {
                if (!res.empty()) res += \ \;
                res += mp_tens[s[1] - '0'];
            }
            if (s[2] != '0') {
                if (!res.empty() ) res += \ \;
                res += mp[s[2] - '0'];
            }
        }
        return res;
    }

    string numberToWords(int num) {
        if (num == 0) return \Zero\;

        string ans = \\;
        int cnt = 0;
        while (num != 0) {
            int digi = num % 1000;
            if (digi != 0) {
                string res = makeit(to_string(digi));
                if (!mp_val[cnt].empty()) {
                    res += \ \ + mp_val[cnt];
                }
                if (!ans.empty()) {
                    res += \ \ + ans;
                }
                ans = res;
            }
            cnt++;
            num /= 1000;
        }
        return ans;
    }
};
