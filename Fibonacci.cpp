class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int a(0), b(1), c(0);
        
        for(int i = 1;i < n;i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return a;
    }
};