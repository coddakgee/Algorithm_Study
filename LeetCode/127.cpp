/*
  날짜 : 26.05.20.수
  문제 : LeetCode 127. Word Ladder
  로직 : BFS, Hash
  총평 : 처음으로 Hash를 직접 구현해봤다. djb2 알고리즘을 사용하여 해시함수를 작성하였다. 
*/

struct MyHashSet{
    static const int MAX_WORDS = 5005;
    static const int HASH_SIZE = 20011;

    struct Node{
        string str;
        bool visited;
        Node* nxt;
    };

    Node pool[MAX_WORDS];
    int node_count;
    Node* hash_table[HASH_SIZE];

    void clear(){
        node_count = 0;
        for(int i=0; i<HASH_SIZE; i++){
            hash_table[i] = nullptr;
        }
    }

    MyHashSet(){
        clear();
    }

    unsigned long get_hash(const string& str) const{
        unsigned long h = 5381;
        for(char c : str){
            h = ((h<<5) + h) + c;
        }
        return h % HASH_SIZE;
    }

    void insert(const string& str){
        unsigned long h = get_hash(str);

        Node* new_node = &pool[node_count++];
        new_node->str = str;
        new_node->visited = false;

        new_node->nxt = hash_table[h];
        hash_table[h] = new_node;
    }

    bool find_and_visit(const string& str){
        unsigned long h = get_hash(str);

        Node* curr = hash_table[h];
        while(curr != nullptr){
            if(curr->str == str && !curr->visited){
                curr->visited = true;
                return true;
            }
            curr = curr->nxt;
        }
        return false;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        MyHashSet word_set;

        bool can_finish = false;
        for(string& str : wordList){
            word_set.insert(str);
            if(str == endWord)can_finish = true;
        }
        if(!can_finish)return 0;

        queue<string>q;
        q.push(beginWord);

        int ret = 0;
        while(!q.empty()){
            ret++;
            int p = q.size();
            while(p--){
                string node = q.front();
                q.pop();
                if(node == endWord)return ret;

                for(int i=0; i<node.length(); i++){
                    for(int j='a'; j<='z'; j++){
                        if((int)node[i] == j)continue;
                        string nxt = node;
                        nxt[i] = (char)j;
                        if(!word_set.find_and_visit(nxt))continue;
                        q.push(nxt);
                    }
                }
            }
        }
        return 0;
    }
};
