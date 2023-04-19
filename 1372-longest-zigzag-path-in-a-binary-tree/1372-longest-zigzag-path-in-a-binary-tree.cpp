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
    vector<int> fun(TreeNode* root,int &ans){
        vector<int> v(2,0);
        if(!root) return v;
      
          vector<int> k;
        if(root->left){
           k = fun(root->left,ans);
            v[0] = 1+k[1];
        }
        if(root->right){
            k = fun(root->right,ans);
        v[1] = 1+k[0];
        }
        ans = max(v[0],ans);
        ans = max(v[1],ans);
        return v;
    }
public:
    int longestZigZag(TreeNode* root) {
        int ans=INT_MIN;
        fun(root,ans);
        return ans;
    }
};