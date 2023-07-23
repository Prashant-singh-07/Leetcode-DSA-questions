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
    map<int, vector<TreeNode*> > mp;

    vector<TreeNode*> fun( int n ) {
        if( mp.find(n) != mp.end() )
            return mp[n];
        if( n == 1 ) {
            TreeNode* root = new TreeNode(0);
            return mp[n] = {root};
        }

        vector<TreeNode*> ret;
        for( int i = 2; i<n; i+=2 ) {
            auto v1 = fun( n-i );
            auto v2 = fun( i-1 );
            for( auto it1 : v1 ) {
                for( auto it2 : v2 ) {
                    TreeNode *root = new TreeNode( 0, it1, it2 );
                    // root->left = it1;
                    // root->right = it2;
                    ret.push_back( root );
                }
            }
        }
        return mp[n] = ret;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        if( n&1 == 0 )
            return {};
        return fun( n );
    }
};