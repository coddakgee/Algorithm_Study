/*
  Hash의 chaining 기법을 익히기 위해 일단 LinkedList를 먼저 공부했다. 
  메모리 풀에 LinkedList를 구현했기 때문에 아래의 main 함수 안의 예외 케이스를 처리하지 못한다. 
  예외 케이스 : 인덱스 기반 삽입 삭제를 하므로, 같은 인덱스에 삭제를 하고 삽입을 할 경우 제대로 인식을 못한다는 문제가 있다.
  이는 Hash를 배우고 Hash(key) => idx 이 구조로 가서, 해시함수에 key를 넣으면 넣을 idx를 바로 반환하는 방법을 배운 뒤에 추가로 수정하려고 한다. 
*/
#include <iostream>
using namespace std;

struct Node{
    int dat, pre, nxt;
};

static const int MX = 1000005;
Node pool[MX];
int node_cnt; //얘부터 pool에 넣을 수 있다는 뜻.
//1번 인덱스 부터 추가 삭제 가능.

void init(){ //0번째 인덱스는 dummy head 로 생각. 예외 처리 안해도 되므로 편리함
    node_cnt = 1;
    pool[0].pre = -1;
    pool[0].nxt = -1;
}

void insert(int target_idx, int data){ //target 인덱스 뒤에 data 추가
   int new_idx = node_cnt++;
   //새 노드 연결 설정
   pool[new_idx].dat = data;
   pool[new_idx].pre = target_idx;
   pool[new_idx].nxt = pool[target_idx].nxt;
   
   //기존 노드 연결 변경
   if(pool[target_idx].nxt != -1){
       pool[pool[target_idx].nxt].pre = new_idx;
   }
   pool[target_idx].nxt = new_idx;
   return;
}

void erase(int target_idx){ //target_idx 삭제 -> 연결만 끊으면 됨.
    int pre_idx = pool[target_idx].pre;
    int nxt_idx = pool[target_idx].nxt;
    
    if(pre_idx != -1) pool[pre_idx].nxt = nxt_idx;
    if(nxt_idx != -1) pool[nxt_idx].pre = pre_idx;
    return;
}

void traverse(){
    int cur = pool[0].nxt;
    while(cur != -1){
        cout << pool[cur].dat << " ";
        cur = pool[cur].nxt;
    }
    cout << "\n";
    return;
}


int main(){
    init();
    insert(0, 10);
    insert(1, 20);
    insert(2, 300000);
    insert(3,40);
    
    traverse();
    
    erase(2);
    traverse();
    
    insert(2,30);
    traverse();
    return 0;
}
