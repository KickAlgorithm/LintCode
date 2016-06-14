class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int max_len = max(a.length(), b.length());
        
        int add(0);
        string res(max_len+1, '0');
        
        for(int i = 0;i < max_len;i++) {
            int l = i < a.length() ? a[i] - '0' : 0;
            int r = i < b.length() ? b[i] - '0' : 0;
            res[i] = (l + r + add) % 2 + '0';
            add = (l + r + add) / 2;
        }
        if(add == 1) res[max_len] = '1';
        reverse(res.begin(), res.end());
        while(res.length() > 1 && res[0] == '0') res = res.substr(1);
        return res;
    }
};