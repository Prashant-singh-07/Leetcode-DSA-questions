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
    TreeNode* par=NULL;
    TreeNode* curr=NULL;
    int pari=0,lefty=0,righty=0;
    void searchit(TreeNode* root,int x){
        if(!root) return ;
        if(curr!= NULL) return ;
        if(root->left){
            if(root->left->val==x){
                par=root;
                curr=root->left;
                return ;
            }
            searchit(root->left,x);
        }
        if(root->right){
            if(root->right->val==x){
                par=root;
                curr=root->right;
                return ;
            }
            searchit(root->right,x);
        }
    }
    
    int count(TreeNode* root){
        if(!root) return 0;
        return 1+count(root->left)+count(root->right);
    }
    
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(root->val==x) par=NULL,curr=root;
        else searchit(root,x);
        
        //pari = count(par);
        lefty= count(curr->left);
        righty= count(curr->right);
        //if(pari>0)
        pari = n - (lefty+righty+1);
        if(pari>=lefty+righty+1 || lefty>=pari+righty+1 || righty>=pari+lefty+1) return true;
              
        return false;
    }
};