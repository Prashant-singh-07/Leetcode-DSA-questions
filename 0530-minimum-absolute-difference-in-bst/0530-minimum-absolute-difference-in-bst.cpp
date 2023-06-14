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
    int ans=INT_MAX;
        vector<int> fun(TreeNode* root){
            
            int k = root->val;
            int j = root->val;
            int temp;
            vector<int> lefty;
            if(root->left){
                lefty = fun(root->left);
                temp = abs(lefty[1]-root->val);
                ans = min(ans,temp);
                j = min(j,lefty[0]);
            }
            if(root->right){
                lefty = fun(root->right);
                temp = abs(lefty[0]-root->val);
                ans = min(ans,temp);
                k = max(k,lefty[1]);
            }
            return {j,k};
            
        }
public:
    int getMinimumDifference(TreeNode* root) {
        //lets write algorithm for it.
        //firstly, take max from left and then take min from right, after this we can get our desired result.
        //What should we return after processing every node?  simply, return max and min from that node
        
        vector<int> v = fun(root);
        return ans;
    }
};