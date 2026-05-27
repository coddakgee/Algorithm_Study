/*
날짜 : 26.05.28.목
문제 : 백준 13507번 좋은 부분 문자열의 개수
총평 : B형 스타일로 롤링해시를 라빈-카프 알고리즘을 구현하여 풀어냈다. 트라이 자료구조로도 풀 수 있다는데 나중에 공부해봐야겠다. 
*/

#include <iostream>
#include <cstdio>
using namespace std;

char str[1505], alpha[27];
int k;
static const int pool_size = 1505;
static const int table_size = 100003;

typedef long long ll;

class MyHash{
    private:
        struct Node{
            int idx;
            Node* nxt;
        };
        
        Node pool[pool_size];
        int node_count;
        Node* table[table_size];
        
        bool mstrcmp(int idx1, int idx2, int size){
            for(int i=0; i<size; i++){
                if(str[idx1 + i] != str[idx2 + i])return false;
            }
            return true;
        }
        
    public:
        void init(){
            node_count = 0;
            for(int i=0; i<table_size; i++)table[i] = nullptr;
        }
        
        ll rolling_hash(ll pre, int idx, int size, ll pow_31){
            ll h = 0;
            h = ((pre - str[idx-1] * pow_31) % table_size + table_size)%table_size;
            h = h * 31 + str[idx+size-1];
            return h % table_size;
        }
        
        bool find_insert(ll h, int idx, int size){
            Node* curr = table[h];
            while(curr != nullptr){
                if(mstrcmp(idx, curr->idx, size)){
                    return true;
                }
                curr = curr->nxt;
            }
            
            Node* new_node = &pool[node_count++];
            new_node->idx = idx;
            new_node->nxt = table[h];
            
            table[h] = new_node;
            return false;
        }
};

MyHash Hash;

int main(){
    scanf("%s", str);
    scanf("%s", alpha);
    scanf("%d", &k);
    
    int size = 0;
    while(str[size] != 0){
        size++;
    }
    
    
    int ret = 0;
    for(int i=1; i<=size; i++){
        Hash.init();
        int prev = 0, curr = 0;
        ll pre = 0;
        ll pow_31 = 1;
        
        for(int j=0; j<i-1; j++){
            pow_31 *= 31;
            pow_31 %= table_size;
        }
        
        for(int j=0; j<i; j++){
            if(alpha[str[j] - 'a'] == '0')prev++;
            pre = pre*31 + str[j];
        }
        if(prev <= k){
            ret++;
        }
        pre = pre % table_size;
        Hash.find_insert(pre, 0, i);
        
        for(int j=1; j+i-1<size; j++){
            curr = prev;
            ll h = Hash.rolling_hash(pre, j, i, pow_31);
            if(alpha[str[j-1] - 'a'] == '0')curr--;
            if(alpha[str[j+i-1] - 'a'] == '0')curr++;
            if(!Hash.find_insert(h, j, i) && curr <= k){
                ret++;
            }
            prev = curr;
            pre = h;
        }
    }
    
    printf("%d", ret);
    return 0;
}
