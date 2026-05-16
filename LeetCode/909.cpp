/*
  날짜 : 26.05.16.토
  문제 : LeetCode 909. Snakes and Ladders
  풀이 시간 : 30분
  로직 : BFS
  총평 : 처음엔 1차원 벡터 v를 추가로 사용하여 공간복잡도와 초기 세팅을 위한 시간을 더 썼으나, 바뀐 코드에서는 인덱스 최적화를 통해 in-place로 문제를 해결하여 
  공간복잡도 O(1)과 초기화하는 시간을 줄일 수 있었다. 

  +추가
  1차원 인덱스가 k일때, k가 1부터 시작하고, 배열은 0부터 시작할때 이런식으로 나타낼 수 있음.
  1. 행을 구하는 방법 int r = (k-1) / n;
  2. 열을 구하는 방법 int c = (k-1) % n; //만약 추가로 반대로 뒤집어야한다면, c = n-1 - c 를 해주면 됨. 
*/

class Solution {
private:
    vector<bool>visited;
    int n;

public:
    int BFS(vector<vector<int>>& board){
        queue<int>q;
        int ret = 0;
        q.push(1);

        while(!q.empty()){
            int p = q.size();
            while(p--){
                int node = q.front();
                q.pop();
                if(node == (n*n))return ret;

                for(int i=1; i<=6; i++){
                    int nxt = node + i;
                    int r = (n-1) - (nxt-1)/n;
                    int c = (nxt-1) % n;
                    if(r%2 != (n-1)%2) c = n-1 - c;

                    if(nxt > (n*n))break;
                    if(visited[nxt])continue;
                    if(~board[r][c]){
                        q.push(board[r][c]);
                        visited[node+i] = 1;
                    }
                    else{
                        q.push(node+i);
                        visited[node+i] = 1;
                    }
                }
            }
            ret++;
        }
        return -1;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        visited = vector<bool>(n*n + 1, 0);

        return BFS(board);
    }   
};
