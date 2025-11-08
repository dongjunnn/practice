// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, bool> p_map;
    unordered_map<TreeNode*, bool> q_map;
    TreeNode* res = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }

    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return;
        }
        dfs(root->left, p, q);
        dfs(root->right, p, q);
        if (root==p) {
            p_map[root] = true;
        }
        if (root==q) {
            q_map[root] = true;
        }
        if (p_map[root->left]||p_map[root->right]) {
            p_map[root] = true;
        }
        if (q_map[root->right]||q_map[root->left]) {
            q_map[root] = true;
        }
        if (!res && p_map[root] && q_map[root]) {
            res = root;
            // cout <<res->val ;
        }
    }
};

// can be optimised without map