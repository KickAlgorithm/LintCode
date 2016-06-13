class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size() <= 1) return nums.size();
        
        int i(1), j(1);
        
        for(;j < nums.size();j++) {
            if(nums[j] == nums[j-1]) continue;
            nums[i++] = nums[j];
        }
        return i;
    }
};