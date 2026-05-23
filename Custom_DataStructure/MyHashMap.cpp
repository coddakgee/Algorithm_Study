/*
  Node를 자료형으로 가지는 pool에 연속적으로 메모리 정보를 저장한다. 실제 자료구조는 Node*형의 table이다. chaining 기법을 활용해 해시 값 충돌 문제를 효과적으로 회피하였다. 
  해시값은 문자열을 unsigned long으로 바꾸는 알고리즘 중 하나인 djb2 알고리즘을 활용하였고, insert, del의 수많은 쿼리를 메모리 낭비없이 처리하기 위해서 
  Node* free_list를 도입하여 사용하지 않는 pool 공간을 Linked List로 저장해 두었다. 단순히 포인터 변경만으로 메모리를 저장할 수 있어서 효율적인 알고리즘인거 같다. 
*/

class MyHashMap{
    private:
        const int node_size = 100005;
        const int table_size = 200003;
        struct Node{
            string key;
            Node* nxt;
        };
        Node pool[node_size];
        int node_count;
        Node* table[table_size];
        Node* free_list;
        
        unsigned long get_hash(const string& str){
            unsigned long h = 5381;
            
            for(char c : str){
                h = ((h<<5) + h) + c;
            }
            return h % table_size;
        }
    
    public:
        void init(){
            node_count = 0;
            free_list = nullptr;
            for(int i=0; i<table_size; i++){
                table[i] = nullptr;
            }
        }
        
        void insert(const string& str){
            unsigned long h = get_hash(str);
            
            if(find(str))return; //같은 값이 이미 있다면 return
            Node* new_node = nullptr;
            
            if(free_list != nullptr){
                new_node = free_list;
                free_list = free_list->nxt;
            }
            else{
                new_node = pool[node_count++];
            }
            
            new_node->key = str;
            new_node->nxt = table[h];
            table[h] = new_node;
        }
        
        bool find(const string& str){
            unsigned long h = get_hash(str);
            
            Node* curr = table[h];
            while(curr != nullptr){
                if(curr->key == str){
                    return true;
                }
                curr = curr->nxt;
            }
            return false;
        }
        
        void del(const string& str){
            unsigned long h = get_hash(str);
            
            Node* curr = table[h];
            Node* prev = nullptr;
            
            while(curr != nullptr){
                if(curr->key == str){
                    if(prev == nullptr){
                        table[h] = curr->nxt;
                    }
                    else{
                        prev->nxt = curr->nxt;
                    }
                    curr->nxt = free_list;
                    free_list = curr;
                    return;
                }
                prev = curr;
                curr = curr->nxt;
            }
        }
};
