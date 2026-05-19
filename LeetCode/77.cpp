/*
  날짜 : 26.05.19.
  문제 : LeetCode 77. Combinations
  풀이 시간 : 5분
  로직 : 백트래
  총평 : 멤버변수로 ret과 v를 선언하는 것이 유지보수성이나 확장성 부분에서 좋은거 같다.
*/

class Solution {
public:
    void combi(int start, int n, int k, vector<vector<int>>& ret, vector<int>& v){
        if(v.size() == k){
            ret.push_back(v);
            return;
        }

        for(int i=start; i<=n; i++){
            v.push_back(i);
            combi(i+1, n, k, ret , v);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ret;
        vector<int>v;
        combi(1, n, k, ret, v);
        return ret;
    }
};
