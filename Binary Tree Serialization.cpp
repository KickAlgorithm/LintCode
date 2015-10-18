#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
#include<stack>
#include<sstream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};


class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    
    void help_serialize(TreeNode *p, string& result)
    {
        if (!p) {
            result +="# ";
        } else {
            result = result + to_string(p->val)  + " ";
            help_serialize(p->left, result);
            help_serialize(p->right, result);
        }
    }
    
    string serialize(TreeNode *root) {
        // write your code here
        string result("");
        help_serialize(root, result);
        return result;
    }
    
    bool readNextToken(int& token, stringstream &ss, bool &isNumber)
    {
        string s;
        ss >> s;
        if(s.length() == 0) return false;
        if(s == "#")
        {
            isNumber = false;
            return true;
        }
        token = stoi(s, nullptr);
        isNumber = true;
        return true;
    }
    
    TreeNode* readBSTHelper(stringstream &ss) {
        int token;
        bool isNumber;
        TreeNode *p(nullptr);
        if (!readNextToken(token, ss, isNumber))
            return nullptr;
        if (isNumber) {
            p = new TreeNode(token);
            p->left = readBSTHelper(ss);
            p->right = readBSTHelper(ss);
        }
        return p;
    }
    
    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        stringstream ss(data);
        TreeNode* root = readBSTHelper(ss);
        return root;
    }
    
};

int main()
{
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(20);
    TreeNode *n4 = new TreeNode(15);
    TreeNode *n5 = new TreeNode(7);
    //n1 -> left = n2;
    n1 ->right = n2;
    //n3 ->left = n4;
    //n3 ->right = n5;
    
    Solution s;
    string res = s.serialize(n1);
    cout << res << endl;
    TreeNode* root = s.deserialize(res);
    cout << s.serialize(root);
    return 0;
}