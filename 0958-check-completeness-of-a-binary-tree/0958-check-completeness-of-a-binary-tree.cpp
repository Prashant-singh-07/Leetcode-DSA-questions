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
    // bool ans=true;
    // int fun(TreeNode* root){
    //     if(!root) return 0;
    //     int left = fun(root->left);
    //     int right = fun(root->right);
    //     if(left<right) ans=false;
    //     return 1+left+right;
    // }
    bool isCompleteTree(TreeNode* root) {
       queue<TreeNode*> q;
        if(!root) return true;
        q.push(root);
        TreeNode* temp;
        int n;
        bool flag=true;
        while(!q.empty()){
            n = q.size();
            while(n>0){
                temp = q.front();
                q.pop();
                if(temp->left==NULL) flag=false;
                else{
                    if(!flag) return false;
                    q.push(temp->left);
                }
                if(temp->right==NULL) flag=NULL;
                else{
                    if(!flag) return false;
                    q.push(temp->right);
                }
                n--;
            }
        }
        return true;
    }
};