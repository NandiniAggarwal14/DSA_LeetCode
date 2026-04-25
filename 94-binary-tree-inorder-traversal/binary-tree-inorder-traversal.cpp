/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void findInorder(TreeNode* root, vector<int>&res)
    {
        if(root==NULL)
            return;
        findInorder(root->left, res);
        res.push_back(root->val);
        findInorder(root->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        findInorder(root, res);
        return res;
    }
};