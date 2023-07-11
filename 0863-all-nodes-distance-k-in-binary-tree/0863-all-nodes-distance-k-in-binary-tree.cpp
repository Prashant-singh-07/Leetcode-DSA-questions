/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<int,pair<int,int>> m;
    bool flag=false;
    vector<TreeNode*> path;
    vector<int> ans;
    void fun(TreeNode* root,TreeNode* target,vector<TreeNode*>& v){
        if(!root) return ;
        if(root==target){
            //v.push_back(root);
            path=v;
            flag=true;
            return ;
        }
        if(!flag && root->left){
            v.push_back(root->left);
            fun(root->left,target,v);
            v.pop_back();
        }
        if(!flag && root->right){
            v.push_back(root->right);
            fun(root->right,target,v);
            v.pop_back();
        }
        return ;
    }
    void result(TreeNode* root,int k){
        if(!root) return ;
        if(k==0){
            ans.push_back(root->val);
            return ;
        }
        if(root->left){
            result(root->left,k-1);
        }
        if(root->right){
            result(root->right,k-1);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> v;
        v.push_back(root);
        fun(root,target,v);
        int count=1,side=0;
        int n = path.size();
        if(n-2>=0){
        if(path[n-2]->left==target) side=-1;
            else side = 1;
        }
        result(target,k);
        for(int i=n-2;i>=0;i--){
            if(k-count==0){
                ans.push_back(path[i]->val);
                break;
            }
            if(path[i]->right==path[i+1]){
                result(path[i]->left,k-count-1);
            }
            else{
                 result(path[i]->right,k-count-1);
            }
            count++;
        }
        return ans;
    }
};