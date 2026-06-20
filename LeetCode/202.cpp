/*
Floyd Cycle Detection을 새롭게 공부함. 
이 문제는 unordered_set을 사용하여도 풀 수 있지만, Floyd Cycle Detection을 사용하면 공간복잡도 O(1)에 풀 수 있다는 장점이 잇음.
Floyd Cycle Detection이란, 연결리스트에서 1칸씩 탐색하는 Slow와 2칸씩 탐색하는 Fast가 있을때, 사이클이 있다면 무조건 Fast가 Slow랑 겹치게 된다는 논리에서부터 시작함
*/

class Solution {
private:
    int nextSum(int n){
        int tmp = 0;
        while(n){
            int a = n % 10;
            tmp += a*a;
            n /= 10;
        }
        return tmp;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = nextSum(n);
        while(fast != 1 && fast != slow){
            slow = nextSum(slow);
            fast = nextSum(nextSum(fast));
        }
        return fast == 1;
    }
};
