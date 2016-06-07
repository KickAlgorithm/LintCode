class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(!source || !target) return -1;
        int i(0), j(0);
        int slen(strlen(source)), tlen(strlen(target));
        while(i <= slen - tlen) {
            bool flag(true);
            for(int k = 0; k < tlen; k++) {
                if(source[i+k] != target[k]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
            i++;
        }
        return -1;
    }
};