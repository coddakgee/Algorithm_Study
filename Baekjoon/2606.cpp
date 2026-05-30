/*
  날짜 : 26.05.31.일
  문제 : 백준 2606. 바이러스
  총평 : 링크드 리스트를 vector만 사용해서 구현했었는데, 정적배열과 pooling으로 구현하는 법을 알게돼서 의미깊었던거 같다. 그래프를 구현하는 건 문제가 없어보인다. 
*/

#include <bits/stdc++.h>
using namespace std;

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
        int visited[head_size];
        int pool_count;
    
    public:
        void init(){
            pool_count = 0;
            for(int i=0; i<head_size; i++){
                visited[i] = 0;
                head[i].nxt = nullptr;
            }
        }
        
        void addadj(int u, int v){ //u->v만 연결함.
            Node* new_node = &pool[pool_count++];
            
            new_node->node = v;
            new_node->nxt = head[u].nxt;
            head[u].nxt = new_node;
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

MyLinkedList LL;

int main(){
    LL.init();
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b; scanf("%d %d", &a, &b);
        LL.addadj(a,b);
        LL.addadj(b,a);
    }
    
    printf("%d\n", LL.BFS());
    return 0;
}
