/*
날짜 : 2026.04.18.토
문제 : 103. Binary Tree Zigzag Level Order Traversal
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        vector<int>tmp;
        queue<TreeNode*>q;
        int flag = 1;
        q.push(root);

        while(!q.empty()){
            int p = q.size();
            tmp.clear();

            while(p--){
                TreeNode* node = q.front(); q.pop();

                if(node == nullptr)continue;

                tmp.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            if(tmp.size()){
                if(flag){
                    ret.push_back(tmp);
                }
                else{
                    reverse(tmp.begin(), tmp.end());
                    ret.push_back(tmp);
                }
                flag^=1;
            }
        }
        return ret;
    }
};
