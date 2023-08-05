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
    vector<TreeNode*> ans;
    vector<TreeNode*> fun(int start,int end){
         vector<TreeNode*> v;
        if(start>end) return v;
        TreeNode* root;
        vector<TreeNode*> le,r;
        for(int i=start;i<=end;i++){
             le = fun(start,i-1);
            r = fun(i+1,end);
          if(le.size()==0 || r.size()==0){
              if(r.size()>0){
                  for(int j=0;j<r.size();j++){
                      root = new TreeNode(i);
                      root->right=r[j];
                      v.push_back(root);

                  }
              }
              else if(le.size()>0){
                   for(int j=0;j<le.size();j++){
                      root = new TreeNode(i);
                      root->left=le[j];
                      v.push_back(root);
                  }
              }
              else if(le.size()==0 && r.size()==0){
                  root = new TreeNode(i);
                      v.push_back(root);
              }
          }
            else{
                for(int j=0;j<le.size();j++){
                    for(int k=0;k<r.size();k++){
                        root = new TreeNode(i);
                        root->left = le[j];
                      root->right=r[k];
                      v.push_back(root);
                    }
                }
            }
        }
        return v;
        
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return fun(1,n);
    }
};