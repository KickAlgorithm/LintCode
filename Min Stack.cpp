class MinStack {
    stack<int> mystack;
    stack<int> minstack;
public:
    MinStack() {
        // do initialization if necessary
    }
    
    void push(int number) {
        // write your code here
        mystack.push(number);
        if(minstack.empty() || number <= minstack.top())
            minstack.push(number);
    }
    
    int pop() {
        // write your code here
        int number = mystack.top();
        mystack.pop();
        if(number == minstack.top())
            minstack.pop();
        return number;
    }
    
    int min() {
        // write your code here
        return minstack.top();
    }
};
