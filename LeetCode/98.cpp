/*
  날짜 : 26.06.07.일
  문제 : 98. Validate Binary Search Tree.
  총평 : Inorder에 대해서 제대로 알게되었다. 유효한지 확인, BST에서 정렬된 원소를 얻는데 사용.
*/

class Solution {
private:
    bool check = true;
    int prev;
    bool is_first = true;
    void DFS(TreeNode* curr){
        if(!check)return;
        if(!curr)return;

        DFS(curr->left);

        if(is_first){
            is_first = false;
        }
        else{
           if(prev >= curr->val){
                check = false;
            return;
           }
        }
        prev = curr->val;
        DFS(curr->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        DFS(root);
        return check;
    }
};
