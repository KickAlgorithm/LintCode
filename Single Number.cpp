class Solution {
public:
    /**
     * @param A: Array of integers.
     * return: The single number.
     */
    int singleNumber(vector<int> &A) {
        // write your code here
        int res(0);
        for(int e : A)
            res ^= e;
        return res;
    }
};