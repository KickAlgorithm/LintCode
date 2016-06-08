class Solution {
    
    
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        stack<string> symbols;
        vector<string> res;
        
        for(string str : expression) {
            
            if(str == "(") {
                symbols.push(str);
            } else if(str == "+" || str == "-") {
                if(symbols.empty() || symbols.top() == "(") {
                    symbols.push(str);
                } else {
                    while(!symbols.empty() && symbols.top() != "(") {
                        res.push_back(symbols.top());
                        symbols.pop();
                    }
                    symbols.push(str);
                }
            } else if(str == "*" || str == "/") {
                if(symbols.empty()) {
                    symbols.push(str);
                } else {
                    string tmp = symbols.top();
                    if(tmp == "+" || tmp == "-" || tmp == "(") {
                        symbols.push(str);
                        continue;
                    } else {
                        res.push_back(tmp);
                        symbols.pop();
                        symbols.push(str);
                    }
                }
            } else if(str == ")") {
                while(symbols.top() != "(") {
                    res.push_back(symbols.top());
                    symbols.pop();
                }
                symbols.pop();
            } else {
                res.push_back(str);
            }
        }
        while(!symbols.empty()) {
            string temp = symbols.top();
            symbols.pop();
            res.push_back(temp);
        }
        return res;
    }
};