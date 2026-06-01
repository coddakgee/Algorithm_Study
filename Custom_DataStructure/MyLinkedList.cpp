/*
  연결 리스트를 vector<vector<int>>v 를 쓰지않고 직접 구현해보았다. BFS를 통해 그래프 탐색이 가능하다. 
*/

class MyLinkedList{
    private:
        static const int head_size = 110;
        static const int pool_size = 110 * 110;
        
        struct Node{
            int node;
            Node* nxt;
        };
         
        Node head[head_size];
        Node pool[pool_size];
        Node* tail[head_size];
        int visited[head_size];
        int pool_count;
    
    public:
        void init(){
            pool_count = 0;
            for(int i=0; i<head_size; i++){
                visited[i] = 0;
                head[i].nxt = nullptr;
                tail[i] = nullptr;
            }
        }
        
        void addadj(int u, int v){ //u->v만 연결함.
            Node* new_node = &pool[pool_count++];
            
            new_node->node = v;
            new_node->nxt = nullptr;
            
            if(tail[u] == nullptr){
                head[u].nxt = new_node;
            }
            else{
                tail[u]->nxt = new_node;
            }
            tail[u] = new_node;
        }
        
        int BFS(){
            int ret = 0;
            queue<int>q;
            q.push(1);
            visited[1] = 1;
            
            while(!q.empty()){
                int curr = q.front(); q.pop();
                for(Node* k = head[curr].nxt; k != nullptr; k = k->nxt){
                    if(!visited[k->node]){
                        visited[k->node] = 1;
                        q.push(k->node);
                        ret++;
                    }
                }
            }
            return ret;
        }
};
