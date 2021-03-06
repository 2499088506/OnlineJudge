#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        stack<TreeNode *> st;
        TreeNode *p = root;
        st.push(p);
        while (!st.empty()) {
            p = st.top();
            st.pop();
            res.push_back(p->val);
            if (p->right) {
                st.push(p->right);
            }
            if (p->left) {
                st.push(p->left);
            }
        }
        return res;
    }
};

