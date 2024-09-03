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

        queue<TreeNode*> que;
       
        que.push(root);
        
        bool isChild = false;
        while(!que.empty()) {
            TreeNode* parent = que.front();
            que.pop();
            if(parent!=nullptr) {
                if(isChild==true) {
                    return false;
                }
                que.push(parent->left);
                que.push(parent->right);
                
            }
            else {
                isChild = true;
            }

        }
        return true;
        
    }
};