/*
  날짜 : 26.05.14.목
  문제 : LeetCode 80. Remove Duplicates from Sorted Array 2
  풀이 시간 : 15분
  로직 : Array
  총평 : Easy 문제였지만, 시간복잡도 O(n), 공간복잡도 O(1)로 나쁘지 않은 코드를 작성하였으나, CPU의 분기 최적화와, 인덱스 오프셋을 활용하여 더욱 최적화 할 수 있는 방법을 공부하게 됨.
  그 부분에 대해서는 Optimization 부분에 정리해 두겠음. 
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())return 0;

        int k=1, cnt=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[k-1] != nums[i]){
                nums[k++] = nums[i];
                cnt = 1;
            }
            else if(cnt < 2){
                nums[k++] = nums[i];
                cnt++;
            }
        }
        return k;
    }
};
