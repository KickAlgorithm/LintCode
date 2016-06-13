class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        if(A.size() == 0) return 0;
        if(A.size() == 1) return A[0];
        vector<long long> p(A.size(), 0);
        p[0] = A[0];
        p[1] = max(A[0], A[1]);
        for(int i = 2;i < A.size();i++)
            p[i] = max(p[i-1], p[i-2]+A[i]);
        return p.back();
    }
};