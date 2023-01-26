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
    unordered_map<int,int> m;
    int fun(TreeNode* root){     
    int sum=root->val;
        if(root->left) sum+=fun(root->left);
        if(root->right) sum+=fun(root->right);
         m[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        int k = fun(root);
        k=INT_MIN;
        for(auto p:m){
            k = max(k,p.second);
        }
        for(auto p:m){
            if(p.second==k) ans.push_back(p.first);
        }
        return ans;
    }
};