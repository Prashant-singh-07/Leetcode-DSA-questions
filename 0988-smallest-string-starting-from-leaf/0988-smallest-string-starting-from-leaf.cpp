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
    string ans="";
    char c;
    string temp;
    void fun(TreeNode* root,string& s){
        c = 'a'+root->val;
        s+=c;
    
        if(root->left==NULL && root->right==NULL){
            temp=s;
            reverse(temp.begin(),temp.end());
            if(ans=="") ans=temp;
            else {
                if(ans>temp) ans=temp;
            }
        }
     if(root->left){
            fun(root->left,s);
        }
        if(root->right){
            fun(root->right,s);
        }
        s.pop_back();
        return ;
        
    }
    
    string smallestFromLeaf(TreeNode* root) {
        //fun(root "root->val");
         char c = 'a'+ root->val;
        string s="";
        s+=c;
        if(!root->left && !root->right) return s;
        if(root->left)
        fun(root->left,s);
        if(root->right)
        fun(root->right,s);
        return ans;
    }
};