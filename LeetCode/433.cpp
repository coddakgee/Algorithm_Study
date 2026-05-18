/*
  날짜 : 26.05.18.월
  문제 : LeetCode 433. Minimum Genetic Mutation
  풀이 시간 : 20분
  로직 : BFS
  총평 : 잘 푼거 같다. 
*/

class Solution {
private:
    vector<bool>visited;
    queue<string>q;

    bool is_next(string a, string b){
        int cnt = 0;
        for(int i=0; i<8; i++){
            if(a[i] != b[i])cnt++;
        }
        if(cnt == 1)return true;
        return false;
    }

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        visited = vector<bool>(bank.size(), 0);
        q.push(startGene);
        
        int cnt = 0;
        while(!q.empty()){
            int p = q.size();

            while(p--){
                string node = q.front();
                if(node == endGene){
                    return cnt;
                }
                q.pop();

                for(int i=0; i<bank.size(); i++){
                    if(visited[i])continue;
                    if(!is_next(node, bank[i]))continue;
                    visited[i] = 1;
                    q.push(bank[i]);
                }
            }
            cnt++;
        }
        return -1;
    }
};
