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
    int maxLevelSum(TreeNode* root) {
    int sum=0;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        int ans=0;
       int maxSum=INT_MIN;
        int n;
        TreeNode* temp;
        while(q.size()>0){
          n = q.size();
            sum=0;
            while(n>0){
                temp = q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                n--;
            }
            if(sum>maxSum){
                maxSum=sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};