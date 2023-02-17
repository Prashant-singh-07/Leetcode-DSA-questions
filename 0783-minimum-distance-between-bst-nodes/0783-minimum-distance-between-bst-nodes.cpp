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
public:
    int ans=INT_MAX;
    vector<int> v;
    void fun(TreeNode* root){
        if(root->left) fun(root->left);
         v.push_back(root->val);
        if(root->right) fun(root->right);
    }
    int minDiffInBST(TreeNode* root) {
     fun(root);
        for(int i=1;i<v.size();i++){
            ans = min(ans,abs(v[i]-v[i-1]));
            //ans = min(ans,abs(v[i]-v[i]))
        }
        return ans;
    }
};