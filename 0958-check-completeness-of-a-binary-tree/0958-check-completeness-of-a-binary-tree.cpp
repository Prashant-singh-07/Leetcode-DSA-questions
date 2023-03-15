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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) return true;
        int flag=0;
        int n;
        TreeNode* temp;
        q.push(root);
        while(!q.empty()){
            n = q.size();
            while(n>0){
                temp=q.front();
                q.pop();
                if(!temp->left && temp->right) return false;
                else if(temp->left && !temp->right){
                    if(flag==0){
                    flag=1;
                    q.push(temp->left);
                    }
                    else{
                        return false;
                    }
                }
                else if(temp->left && temp->right){
                    if(flag==1) return false;
                    q.push(temp->left);
                    q.push(temp->right);
                }
                else if(!temp->left && !temp->right){
                    flag=1;
                }
                n--;
            }
        }
        return true;
    }
};