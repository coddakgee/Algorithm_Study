/*
날짜 : 26.04.18.토
실패 이유 : DFS든 BFS든 한 노드에서 다른 노드로 갈 때마다 모든 wordList를 순회하면서 다음 노드를 찾는데 이렇게 되면 한 노드당 2500번의 계산을 해야하고, 
DFS 부분에서 TimeLimitExceeded가 나올 가능성이 농후하다.  
-> unordered_set 이나 unordered_map 를 사용하여 정보 탐색에 O(1)을 쓸 필요가 있다. 

*/


class Solution {
private:
    vector<vector<string>>ret;
    vector<string>tmp;
    vector<bool>visited;

    int BFS(string beginWord, string endWord, vector<string>& wordList){
        queue<string>q;
        q.push(beginWord);

        int path = 1;
        while(!q.empty()){
            int p = q.size();
            path++;
            while(p--){
                string here = q.front(); q.pop();

                for(int i=0; i<wordList.size(); i++){
                    if(visited[i])continue;

                    int cnt = 0;
                    for(int j=0; j<here.length(); j++){
                        if(here[j] != wordList[i][j])cnt++;
                    }
                    if(cnt == 1){
                        if(wordList[i] == endWord){
                            return path;
                        }
                        q.push(wordList[i]);
                        visited[i] = 1;
                    }
                }
            }
        }

        return -1;
    }

    void DFS(int short_path, string here, string endWord, vector<string>& wordList){
        if(tmp.size() == short_path){
            if(here == endWord){
                ret.push_back(tmp);
            }
            return;
        }

        for(int i=0; i<wordList.size(); i++){
            if(visited[i])continue;

            int cnt = 0;
            for(int j=0; j<here.length(); j++){
                if(here[j] != wordList[i][j])cnt++;
            }
            if(cnt == 1){
                visited[i] = 1;
                tmp.push_back(wordList[i]);
                DFS(short_path, wordList[i], endWord, wordList);
                visited[i] = 0;
                tmp.pop_back();
            }
        }
    }


public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        visited = vector<bool>(wordList.size(), 0);

        int short_path = BFS(beginWord, endWord, wordList);

        if(short_path == -1)return ret;

        visited = vector<bool>(wordList.size(), 0);
        tmp.push_back(beginWord);
        DFS(short_path, beginWord, endWord, wordList);

        return ret;
    }
};
