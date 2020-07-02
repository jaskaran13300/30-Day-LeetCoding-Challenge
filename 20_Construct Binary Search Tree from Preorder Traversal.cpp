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
    int idx=0;
    TreeNode* help(vector<int>& preorder,int parent_value=INT_MAX){
        if(idx==preorder.size() || preorder[idx]>parent_value){
            return NULL;
        }
        int curr_val=preorder[idx++];
        TreeNode* root=new TreeNode(curr_val);
        root->left=help(preorder,curr_val);
        root->right=help(preorder,parent_value);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return help(preorder);
    }
};
