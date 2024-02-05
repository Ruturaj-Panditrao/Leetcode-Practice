// https://leetcode.com/problems/first-unique-character-in-a-string/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> ump;
        for(auto ch :s){
            ump[ch]++;
        }
        for(int i=0;i<s.length();i++){
            if(ump[s[i]]==1) return i;
        }
        return -1;
    }
};
