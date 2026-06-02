/*
이분 그래프에 대한 개념을 공부하였으며, Linked List를 직접 구현해 봄으로써 DFS 실력과 메모리 풀링 실력을 키울 수 있었다. 
*/

#include <cstdio>
using namespace std;

struct Node{
    int node;
    Node* nxt;
};

static const int vertex = 20005;
static const int edge = 400005;

class MyLL{
    private:
        Node head[vertex];
        Node pool[edge];
        int pool_cnt;
    public:
        int visited[edge];
        
        void init(int v){
            pool_cnt = 0;
            for(int i=1; i<=v; i++) {
                head[i].nxt = nullptr;
                visited[i] = 0;
            }
        }
        
        void addEdge(int a, int b){
            Node* new_node = &pool[pool_cnt++];
            
            new_node->node = b;
            new_node->nxt = head[a].nxt;
            head[a].nxt = new_node;
        }
        
        int DFS(int k, int color){
            int ret = 0;
            visited[k] = color;
            
            for(Node* curr = head[k].nxt; curr != nullptr; curr = curr->nxt){
                if(visited[curr->node] == 0){
                    ret += DFS(curr->node, -color);
                    if(ret > 0)return 1;
                }
                else if(visited[curr->node] == color)return 1;
            }
            return ret;
        }
};

MyLL LL;


int main() {
	int t; scanf("%d", &t);
	
	for(int _t=1; _t<=t; _t++){
	    int v, e; scanf("%d %d", &v, &e);
	    LL.init(v);
	    
	    for(int i=0; i<e; i++){
	        int a, b; scanf("%d %d", &a, &b);
	        LL.addEdge(a, b);
	        LL.addEdge(b, a);
	    }
	    
	    
	    bool flag = true;
	    for(int i=1; i<=v; i++){
	        if(LL.visited[i])continue;
	        if(LL.DFS(i, 1)){
	            flag = false;
	            break;
	        }
	    }
	    if(flag)printf("YES\n");
	    else printf("NO\n");
	}
	
    return 0;
}
