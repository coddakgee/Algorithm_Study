class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ret = 0;

        while(l<r){
            if(height[l] < height[r]){
                int k = (r-l) * height[l];
                ret = max(ret, k);
                l++;
            }
            else{
                int k = (r-l) * height[r];
                ret = max(ret, k);
                r--;
            }
        }

        return ret;
    }
};
