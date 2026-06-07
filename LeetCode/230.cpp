/*
  날짜 : 26.06.07.일
  문제 : 230. Kth Smallest Element in a BST.
  총평 : 굳이 vector에 다 저장할 필요없이 found 와 ret을 전역변수로 사용해서 메모리를 아낄 수 있다.
*/

class Solution {
private:
    bool found = false;
    int ret = 0;
    int cnt = 0;

    void DFS(TreeNode* curr, int k){
        if(!curr || found)return;

        DFS(curr->left, k);

        cnt++;
        if(cnt == k){
            found = true;
            ret = curr->val;
            return;
        }
        DFS(curr->right, k);
        return;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        DFS(root, k);
        return ret;
    }
};
