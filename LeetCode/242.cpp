class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())return false;
        int mp_s[26];
        for(int i=0; i<s.size(); i++){
            mp_s[s[i]-'a']++;
            mp_s[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(mp_s[i])return false;
        }
        return true;
    }
};
