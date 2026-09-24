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
    vector<int> sortedVals;
public:
    int kthSmallest(TreeNode* root, int k) {
        
        inorder(root);
        for (int n : sortedVals) {
            cout << n << " ";
        }
        return sortedVals[k-1];
    }
    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);
        sortedVals.push_back(node->val);
        inorder(node->right);
    }
};
