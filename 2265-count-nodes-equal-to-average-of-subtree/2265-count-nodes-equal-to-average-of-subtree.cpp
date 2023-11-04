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
    unordered_map<int,int> m;
    int ans =0;
    vector<int> fun(TreeNode* root) {
        vector<int> temp(2);
        if(!root) return temp;
        int sum=root->val,count=1;
        temp = fun(root->left);
        sum+=temp[0];
        count+=temp[1];
        temp=fun(root->right);
        sum+=temp[0];
        count+=temp[1];
        if((sum/count)==root->val) ans++;
        return {sum,count};
        
    }
public:
    int averageOfSubtree(TreeNode* root) {
        vector<int> temp = fun(root);
        return ans;
    }
};