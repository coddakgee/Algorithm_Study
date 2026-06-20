class Solution {
private:
    vector<string> split(string& s){
        vector<string>ret;
        string tmp = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                if(!tmp.size())continue;
                ret.push_back(tmp);
                tmp = "";
                continue;
            }
            tmp.push_back(s[i]);
        }
        if(tmp.size()){
            ret.push_back(tmp);
        }
        return ret;
    }
public:
    bool wordPattern(string pattern, string s) {
        string v[26];
        unordered_map<string,int>mp;
        vector<string>k = split(s);

        if(k.size() != pattern.length())return false;

        for(int i=0; i<pattern.length(); i++){
            int idx = pattern[i] - 'a';
            auto it = mp.find(k[i]);
            if(v[idx] == "" && it == mp.end()){
                v[idx] = k[i];
                mp[k[i]] = idx;
            }
            else{
                if(it==mp.end())return false;
                if(v[idx] == k[i] && it->second == idx)continue;
                return false;
            }
        }
        return true;
    }
};
