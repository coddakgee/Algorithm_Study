/*
  날짜 : 26.05.14.목
  문제 : LeetCode 88. Merge Sorted Array
  풀이 시간 : 15분
  로직 : 시뮬레이션
  총평 : Easy 문제였지만, O(n+m)으로 줄이기 위해서, nums1을 뒤에서 부터 채우는 방식을 사용했고, nums1 안에서 처리하여 메모리도 추가적으로 사용하지 않았다. 
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--, i--;
            }
            else{
                nums1[k] = nums2[j];
                k--, j--;
            }
        }

        while(j>=0){
            nums1[k] = nums2[j];
            k--, j--;
        }
    }
};
