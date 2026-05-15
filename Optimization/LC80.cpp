/*
  날짜 : 26.05.15.금
  최적화 포인트 : 이전 코드는 CPU의 분기 최적화나 별도의 cnt 변수를 쓰지 않고 배열 내부에서 로직을 처리하는 인덱스 오프셋 방식을 사용하지 않고 그냥 풀었는데, 
  이번 최적화에서는 그런 부분들을 적용함으로써 더욱 최적화 해보았다. 
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        
        for(int i=0; i<nums.size(); i++){
            if(k<2 || nums[k-2] < nums[i]){ //if, else를 쓴 이전 코드와 달리, if 하나만 쓰고, ||의 논리연산자를 쓰면서 CPU의 분기예측 확률을 높임. 또한 cnt변수를 쓰지않는 인덱스 오프셋 방식을 활용함
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
