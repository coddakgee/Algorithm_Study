/*
  Node를 자료형으로 가지는 pool에 연속적으로 메모리 정보를 저장한다. 실제 자료구조는 Node*형의 table이다. chaining 기법을 활용해 해시 값 충돌 문제를 효과적으로 회피하였다. 
  해시값은 문자열을 unsigned long long으로 바꾸는 알고리즘 중 하나인 djb2 알고리즘을 활용하였고, insert, del의 수많은 쿼리를 메모리 낭비없이 처리하기 위해서 
  Node* free_list를 도입하여 사용하지 않는 pool 공간을 Linked List로 저장해 두었다. 단순히 포인터 변경만으로 메모리를 저장할 수 있어서 효율적인 알고리즘인거 같다. 

  <26.06.02>
  또한 추가로 change에 바꿀 데이터가 없는 경우, 바꿔서 나오는 데이터가 이미 있는 경우에 대한 예외처리하여 조금 더 코드의 안정성을 강화하였다. 
  또한 table을 dummy node하나에 연결되는 구조로 설계하여, del 연산에서 불필요하게 나오는 if else문을 제거하고 코드를 더 간결화 하였다. 
*/

typedef unsigned long long ull;

class MyHashMap{
    private:
        const int pool_size = 100005;
        const int table_size = 200003;
        
        struct Node{
            char key[20];
            Node* nxt;
        };
        
        Node pool[pool_size];
        Node table[table_size]; //dumy node 하나를 table에 배정함으로써 del 과정을 쉽게 처리함.
        int pool_cnt;
        Node* free_list; //free_list로 insert, del이 반복될때, 메모리 낭비없이 해결함.
        
        ull get_hash(char str[]){
            ull hash = 5381;
            
            while(*str){
                hash = (hash << 5) + hash + *str++;
            }
            return hash % table_size;
        }
        
        void mstrcpy(char a[], char b[]){ //a에 b값을 넣음
            while((*a++ = *b++));
        }
        
        bool mstrcmp(char a[], char b[]){
            while(*a && (*a == *b)){
                a++, b++;
            }
            return *a == *b;
        }
    
    public:
        void init(){ 
            pool_cnt = 0;
            free_list = nullptr;
            for(int i=0; i<table_size; i++)table[i].nxt = nullptr; 
        }
        
        bool find(char str[]){
            ull h = get_hash(str);
            
            Node* nd = &table[h];
            while(nd->nxt){
                if(mstrcmp(nd->nxt->key, str))return true;
                nd = nd->nxt;
            }
            return false;
        }
        
        bool insert(char str[]){
            if(find(str))return false; //이미 있으면 false;
            
            ull h = get_hash(str);
            
            Node* new_node;
            
            if(free_list == nullptr){
                new_node = &pool[pool_cnt++];
            }
            else{
                new_node = free_list;
                free_list = free_list->nxt;
            }
            
            mstrcpy(new_node->key, str);
            new_node->nxt = table[h].nxt;
            table[h].nxt = new_node;
    
            return true;
        }
        
        bool del(char str[]){
            ull h = get_hash(str);
            
            Node* nd = &table[h];
            while(nd->nxt){
                if(mstrcmp(nd->nxt->key, str)){
                    Node* del_nd = nd->nxt;
                    nd->nxt = del_nd->nxt;
                    
                    del_nd->nxt = free_list;
                    free_list = del_nd;
                    
                    return true;
                }
                nd = nd->nxt;
            }
            return false;
        }
        
        bool change(char bef[], char str[]){
            if(find(str))return false;
            if(!del(bef))return false;
            insert(str);
            return true;
        }
};
