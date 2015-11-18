/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        return build(0, A.size()-1, A);
    }
    
    SegmentTreeNode * build(int start, int end, vector<int>& A) {
        // write your code here
        if(start > end) return nullptr;
        if(start == end) {
            SegmentTreeNode *tree = new SegmentTreeNode(start, end, A[start]);
            return tree;
        }
        if(start < end) {
            SegmentTreeNode * left = build(start, (start+end)/2, A);
            SegmentTreeNode * right = build((start+end)/2+1, end, A);
            SegmentTreeNode *tree = new SegmentTreeNode(start, end, max(left->max, right->max));
            tree -> left = left;
            tree -> right = right;
            return tree;
        }
    }
};
