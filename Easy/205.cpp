// https://leetcode.com/problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp1,mp2;
        for(int i=0; i<s.length(); i++)
        {
            if(mp1[s[i]] && t[i]!=mp1[s[i]]) return false;
            if(mp2[t[i]] && s[i]!=mp2[t[i]]) return false;
            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};
