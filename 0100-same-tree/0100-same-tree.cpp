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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(!(p&&q)) return false;

        stack<TreeNode*> pst,qst;
        pst.push(p);
        qst.push(q);

        

        while(!pst.empty() && !qst.empty()) {

            TreeNode* curp = pst.top();
            TreeNode* curq = qst.top();
            if(curp->val != curq->val) return false;
            

            pst.pop();
            qst.pop();

            

            if(curp->right!=nullptr) pst.push(curp->right);
            if(curq->right!=nullptr) qst.push(curq->right);
            if(pst.size()!=qst.size()) return false;
            if(curp->left!=nullptr) pst.push(curp->left);
            if(curq->left!=nullptr) qst.push(curq->left);
            if(pst.size()!=qst.size()) return false;

        }

        return true;
        
    }
};