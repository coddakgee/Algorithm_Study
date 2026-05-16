/*
  날짜 : 26.05.16.토
  문제 : LeetCode 189. Rotate Array
  풀이 시간 : 10분
  로직 : Array
  총평 : std::rotate를 직접 구현해보며 대칭이동 + 대칭이동이 평행이동이라는 결과를 만들어 낸다는 것을 깨달았다. 
*/

class Solution {
public:
    void swtch(int& a, int& b){
        int tmp = b;
        b = a;
        a = tmp;
    }

    void reverse(vector<int>& nums, int s, int e){
        while(s < e){
            swtch(nums[s], nums[e]);
            s++, e--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};
