/*
  날짜 : 26.05.18.월
  문제 : LeetCode 70. Climbing Stairs
  풀이 시간 : 10분
  로직 : DP, Sliding Window
  총평 : 메모리 최적화를 위해 Sliding Window 기법을 적용하였다. 또한, 맨 처음 코드에서는 arr[3]을 설정하여, 나머지 연산으로 계산하였으나, 아래 코드처럼 변수 3개를 두고 관리하면
나머지 연산이라는 복잡한 연산을 할 필요가 없어져 CPU효율이 더 좋아진다. 
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)return n;

        int prev1 = 1, prev2 = 2;
        int curr;

        for(int i=3; i<=n; i++){
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;
    }
};
