/*
여러개의 정보를 가진 노드를 O(1)에 탐색하고 싶을떄 MultiHashMap을 쓴다. String 라이브러리를 안쓰고 char 포인터 연산만으로 구현해 보였다. 
*/

class MyMultiHashMap{
    private:
        const static int node_size = 100005;
        const static int table_size = 200003;
        const static int max_len = 20;
        
        struct Node{
            char id[max_len];
            char job[max_len];
            char server[max_len];
            bool is_deleted;
            
            Node* nxt_id;
            Node* nxt_job;
            Node* nxt_server;
        };
        
        Node pool[node_size];
        int node_count;
        Node* free_list;
        
        Node* table_id[table_size];
        Node* table_job[table_size];
        Node* table_server[table_size];
        
        unsigned long get_hash(const char* str){
            unsigned long h = 5381;
            while(*str){
                h = ((h<<5) + h) + *str;
                str++;
            }
            return h % table_size;
        }
    
        void mystrcpy(char* a, const char* b){
            while((*a++ = *b++));
        }
        
        bool mystrcmp(const char* a, const char* b){
            while(*a && *a == *b){
                a++;
                b++;
            }
            return *a == *b;
        }
    
    public:
        void init(){
            for(int i=0; i<table_size; i++){
                table_id[i] = table_job[i] = table_server[i] = nullptr;
            }
            node_count = 0;
            free_list = nullptr;
        }
        
        void insert(const char* id, const char* job, const char* server){
            Node* new_node = nullptr;
            if(free_list != nullptr){
                new_node = free_list;
                free_list = free_list->nxt_id;
            }
            else{
                new_node = &pool[node_count++];
            }
            
            mystrcpy(new_node->id, id);
            mystrcpy(new_node->job, job);
            mystrcpy(new_node->server, server);
            new_node->is_deleted = false;
            
            unsigned long id_h = get_hash(id);
            unsigned long job_h = get_hash(job);
            unsigned long server_h = get_hash(server);
            
            new_node->nxt_id = table_id[id_h];
            table_id[id_h] = new_node;
            
            new_node->nxt_job = table_job[job_h];
            table_job[job_h] = new_node;
            
            new_node->nxt_server = table_server[server_h];
            table_server[server_h] = new_node;
        }
        
        void del_by_id(const char* id){
            unsigned long h = get_hash(id);
            Node* curr = table_id[h];
            
            while(curr != nullptr){
                if(!curr->is_deleted && mystrcmp(curr->id, id)){
                    curr->is_deleted = true;
                    curr->nxt_id = free_list;
                    free_list = curr;
                    return;
                }
                curr = curr->nxt_id;
            }
        }
        
        //예시 : 특정 직업 수 계산
        int count_by_job(const char* job){
            int cnt = 0;
            unsigned long h = get_hash(job);
            
            Node* curr = table_job[h];
            while(curr != nullptr){
                if(!curr->is_deleted && mystrcmp(curr->job, job))cnt++;
                curr = curr->nxt_job;
            }
            return cnt;
        }
};
