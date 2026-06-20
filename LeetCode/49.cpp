class Solution {
private:
    unordered_map<string, int> um;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ret;
        for(string& a : strs){
            string tmp = a;
            sort(tmp.begin(), tmp.end());
            auto it = um.find(tmp);
            if(it != um.end()){
                int index = it->second;
                ret[index].push_back(a);
            }
            else{
                vector<string>v;
                v.push_back(a);
                ret.push_back(v);
                um[tmp] = ret.size()-1;
            }
        }
        return ret;
    }
};
