#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define newln "\n"
#define debug(x) cout<<newln<<#x<<" = "<<x<<newln

class TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
}

class Solution {

    public:
        int MaxWidthOfTree(TreeNode* root) {
            
            if(root==nullptr) return 0;
            queue<pair<TreeNode*,int> que;
            
            que.push({root,0});
            int curIndex=0;
            int ndIndex = 0;
            int maxWidth = 0;
            int left=0,right = 0;

            while(!que.empty()) {
                
                int sz = que.size();
                int min = que.front().second;

                for(int i = 0;i<sz;i++) {
                    
                    TreeNode* node = que.front().first;
                    ndIndex = que.front().second;
                    que.pop();
                    curIndex = (ndIndex-min);
                    if(i==0) left  = curIndex;
                    if(i==sz-1) right = curIndex;
                    if(node->left!=nullptr) {
                        que.push({node->left,2*curIndex+1});
                    }
                    if(node->right!=nullptr) {
                        que.push({node->right,2*curIndex+2});
                    }
                }
                
                maxWidth = max(maxWidth,(right-left+1));
                
            }
            
            return maxWidth;
            



        }



};