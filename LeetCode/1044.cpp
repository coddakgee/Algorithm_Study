/*
  날짜 : 26.05.27.수
  문제 : LeetCode 1044. Longest Duplicate Substring
  로직 : Rolling Hash, Binary Search
  총평 : B형 스타일로 풀어보았다. 길이가 k인 문자열이 반복된다고 하면 k보다 작은 문자열들은 모두 무조건 반복된다는 원리에 기반하여 이분탐색을 쓸 수 있게 되었고, Rabin-Karp 알고리즘을 활용한
  슬라이딩 윈도우 + 해시로 문자열의 해시값을 구할때, O(1)에 접근할 수 있게 되면서, 총 시간복잡도 O(nlogn)을 달성할 수 있게 되었다. 또한 B형 스타일로 동적할당보다는 메모리 pool을 활용하여 
  CPU의 캐시적중률과 String을 써서 문자열 복사보다는 idx로 깔끔하게 처리하면서 시간복잡도와 공간복잡도 둘 다 잡을 수 있게 하였다. 
*/

#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const static int str_size = 200005;
const static ll table_size = 1000003; 

class MyHash {
    private:
        struct Node {
            int idx;
            Node* nxt;
        };
        
        Node pool[str_size];
        int node_count;
        Node* table[table_size];
        
        bool mstrcmp(const string& str, int i, int j, int m) {
            for (int p = 0; p < m; p++) {
                if (str[i + p] != str[j + p]) return false;
            }
            return true;
        }
        
    public:
        void init() {
            for (int i = 0; i < table_size; i++) {
                table[i] = nullptr;
            }
            node_count = 0;
        }
        
        ll rolling_hash(ll prev, int m, ll power_31, const string& str, int idx) {
            ll h;
            h = (prev - (str[idx - 1] * power_31 % table_size) + table_size) % table_size;
            h = h * 31 + str[idx + m - 1];
            return h % table_size;
        }
        
        bool find_insert(ll h, int idx, const string& str, int m) {
            Node* curr = table[h];
            
            while (curr != nullptr) {
                if (mstrcmp(str, curr->idx, idx, m)) {
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

class Solution {
public:
    string longestDupSubstring(string s) {
        int size = s.length();
        int max_len = 0;
        int best_start_idx = 0;
        
        int l = 1, r = size - 1;
        
        while (l <= r) {
            Hash.init();
            int m = (l + r) / 2;
            
            ll power_31 = 1;
            for (int i = 0; i < (m - 1); i++) {
                power_31 = (power_31 * 31) % table_size;
            }
            
            ll prev = 0;
            for (int i = 0; i < m; i++) {
                prev = (prev * 31 + s[i]) % table_size;
            }
            
            Hash.find_insert(prev, 0, s, m);
            
            bool flag = false;
            int found_idx = -1;
            
            for (int idx = 1; idx + m - 1 < size; idx++) {
                ll h = Hash.rolling_hash(prev, m, power_31, s, idx);
                if (Hash.find_insert(h, idx, s, m)) {
                    flag = true;
                    found_idx = idx;
                    break;
                }
                prev = h;
            }
            
            if (flag) {
                if (m > max_len) {
                    max_len = m;
                    best_start_idx = found_idx;
                }
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        
        if (max_len == 0) return "";
        return s.substr(best_start_idx, max_len);
    }
};
