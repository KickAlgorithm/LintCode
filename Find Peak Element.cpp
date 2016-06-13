class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> nums) {
        // write your code here
        
        int i(0),j(nums.size()-1);
        
        while(i < j)
        {
            int mid = (i+j) / 2;
            
            if(i == mid)
                return (nums[i] > nums[j] ? i : j);
            
            if(nums[mid] > nums[mid-1])
                i = mid;
            else
                j = mid-1;
        }
    }
};
