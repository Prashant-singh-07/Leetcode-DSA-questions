/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
    let diameter = 0;
    
    dfs(root);
    
    return diameter;
    
    function dfs(node, level) {
        if (!node) return 0;
        
        const left = dfs(node.left);
        const right = dfs(node.right);
        
        // update diameter at every node
        diameter = Math.max(diameter, left + right);

        // update the largest number of edge so far
        return 1 + Math.max(left, right);
    }
//     if(this.val==0){
//         return 0;
//     }
//     let l=0,r=0;
// if(this.left!=null)
//      l = diameterOfBinaryTree(this.left);
//     if(this.right!=null)
//      r = diameterOfBinaryTree(this.right);
//     let x = Math.max(l,r);
//     ans = Math.max(ans,l+r);
//     return ans;
};