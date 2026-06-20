class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set(nums.begin(), nums.end());
        int ret = 0;

        for(auto k : set){
            auto it = set.find(k-1);
            if(it != set.end())continue;
            int len = 0;
            int curr = k;
            while(set.count(curr++)){
                ret = max(ret, ++len);
            }
        }
        return ret;
    }
};
