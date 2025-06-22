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
        if(p==nullptr) return false;
        if(q==nullptr) return false;

        stack<TreeNode*> pst,qst;
        map<TreeNode*,bool> pmark,qmark;
        pmark[nullptr]=true;
        qmark[nullptr]=true;
        pst.push(p);
        qst.push(q);

        while(!pst.empty() && !qst.empty()) {

            TreeNode* pcur = pst.top();
            TreeNode* qcur = qst.top();

            while(pcur->left!=nullptr && pmark[pcur->left]!=true) {
                pcur = pcur->left;
                cout<<"pcur val: "<<pcur->val<<endl;
                pst.push(pcur);
            }
            while(qcur->left!=nullptr && qmark[qcur->left]!=true) {
                qcur = qcur->left;
                cout<<"qcur val: "<<qcur->val<<endl;
                qst.push(qcur);
            }

            //visited
            pmark[pst.top()]=true;
            qmark[qst.top()]=true;

            // if their structure is not similar
            cout<<endl;
            cout<<"pst.size(): "<<pst.size()<<endl;
            cout<<"pst.top()->val: "<<pst.top()->val<<endl;
            cout<<"qst.size(): "<<qst.size()<<endl;
            cout<<"qst.top()->val: "<<qst.top()->val<<endl;
            if(pst.size()!=qst.size()) {
                cout<<endl;
                cout<<pst.size()<<endl;
                cout<<qst.size()<<endl;
                return false;

            }

            
            if(pst.top()->val!=qst.top()->val)
                return false;

            pcur=pst.top()->right;

            qcur=qst.top()->right;

            pst.pop();
            qst.pop();

            if(pcur!=nullptr) pst.push(pcur);
            if(qcur!=nullptr) qst.push(qcur);

        }

        if(!pst.empty()) return false;
        if(!qst.empty()) return false;

        return true;
        
    }
};