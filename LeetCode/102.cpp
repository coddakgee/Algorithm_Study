/*
날짜 : 2026.04.18.토
제목 : 102. Binary Tree Level Order Traversal
*/

#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ret;
        vector<int> tmp;
        q.push(root);

        while(!q.empty()){
            int p = q.size();
            tmp.clear();
            while(p--){
                TreeNode* node = q.front();
                q.pop();
                if(node == nullptr)continue;

                tmp.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            if(tmp.size()){
                ret.push_back(tmp);
            }
        }

        return ret;
    }
};
