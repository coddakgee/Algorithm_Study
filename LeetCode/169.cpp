/*
  날짜 : 26.05.16.토
  문제 : LeetCode 169. Majority Element
  풀이 시간 : 10분
  로직 : Array
  총평 : Easy 문제였지만, O(n)으로 줄이기 위해서 보이어 무어 과반수 투표 알고리즘을 추가로 공부하였다. 
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candi;
        int cnt = 0;

        for(int x : nums){
            if(cnt == 0){
                candi = x;
            }

            if(candi == x){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return candi;
    }
};
