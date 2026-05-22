/*
  날짜 : 26.05.22.금
  문제 : LeetCode 380. Insert Delete GetRandom O(1)
  로직 : Hash
  총평 : 조금 더 최적화를 해보자. 
*/


class RandomizedSet {
private:
    const static int max_node = 200001;
    const static int max_table = 1000007;

    struct Node{
        int val;
        int data_idx;
        Node* nxt;
    };

    Node pool[max_node];
    int pool_cnt;

    Node* table[max_table];

    int data_list[max_node];
    int data_cnt;

    void init(){
        pool_cnt = 0;
        data_cnt = 0;
        for(int i=0; i<max_table; i++){
            table[i] = nullptr;
        }
    }

    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    int get_hash(int val){
        int h = val % max_table;
        if(h<0) h+= max_table;
        return h;
    }

    void change(int idx, int val){
        int h = get_hash(val);

        Node* curr = table[h];
        while(curr != nullptr){
            if(curr->val == val){
                curr->data_idx = idx;
            }
            curr = curr->nxt;
        }
    }
public:
    RandomizedSet() {
        init();
    }
    
    bool insert(int val) {
        int h = get_hash(val);

        Node* curr = table[h];
        while(curr != nullptr){
            if(curr->val == val)return false;
            curr = curr->nxt;
        }

        Node* new_node = &pool[pool_cnt++];
        new_node->nxt = table[h];
        table[h] = new_node;
        new_node->val = val;
        data_list[data_cnt] = val;
        new_node->data_idx = data_cnt++;
        return true;
    }
    
    bool remove(int val) {
        int h = get_hash(val);

        Node* curr = table[h];
        Node* bef = nullptr;
        while(curr != nullptr){
            if(curr->val == val){
                swap(data_list[curr->data_idx], data_list[--data_cnt]);
                
                change(curr->data_idx, data_list[curr->data_idx]);

                if(bef == nullptr){
                    table[h] = curr->nxt;
                }
                else{
                    bef->nxt = curr->nxt;
                }
                return true;
            }
            bef = curr;
            curr = curr->nxt;
        }
        return false;
    }
    
    int getRandom() {
        return data_list[rand() % data_cnt];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
