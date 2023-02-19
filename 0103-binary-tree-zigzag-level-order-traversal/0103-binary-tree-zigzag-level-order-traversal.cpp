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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<vector<int>> v;
        if(root==NULL){
            return v;
        }
        vector<int> f(1);
        f[0] = root->val;
        v.push_back(f);
        if(root->left==NULL && root->right==NULL){
            return v;
        }
        
        if(root->left!=NULL){
        s1.push(root->left);
        }
        if(root->right!=NULL){
        s1.push(root->right);
        }
        while(!s1.empty()){
            vector<int> a;
            while(!s1.empty()){
                TreeNode* newnode = s1.top();
                a.push_back(newnode->val);
                if(newnode->right!=NULL){
                    s2.push(newnode->right);
                }
                if(newnode->left!=NULL){
                    s2.push(newnode->left);
                }
                s1.pop();
            }
            v.push_back(a);
            if(!s2.empty()){
            vector<int> r;
            
            while(!s2.empty()){
                TreeNode* newnode = s2.top();
                r.push_back(newnode->val);
                if(newnode->left!=NULL){
                    s1.push(newnode->left);
                }
                if(newnode->right!=NULL){
                    s1.push(newnode->right);
                }
                s2.pop();
            }
            v.push_back(r);
            }
            
            
        }
        
        return v;
    }
};