class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // Write your code here
        if(num < 1) return false;
        while(num > 1) {
            if(num % 2 == 0) {
                num /= 2;
            } else if(num % 3 == 0) {
                num /= 3;
            } else if(num % 5 == 0) {
                num /= 5;
            } else {
                return false;
            }
        }
        return true;
    }
};