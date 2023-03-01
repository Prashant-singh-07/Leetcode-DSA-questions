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
    int ans;
    int res=INT_MIN;
    void fun(TreeNode* root,int k){
        if(root->left) fun(root->left,k);
        ans++;
        if(ans==k && res==INT_MIN) res=root->val; 
        if(root->right) fun(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        ans=0;
        res=INT_MIN;
        fun(root,k);
        return res;
    }
};