// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/

class Solution {
public:
    int minSteps(string s, string t) {
        if(s.size() != t.size()) {
            return -1;
        }
        unordered_map <int, int> mp;
        for(auto c: s) {
            mp[c]++;
        }
        for(auto c: t) {
            if(mp.find(c) != mp.end() && mp[c] > 0) {
                mp[c]--;
            }
        }
        int ans = 0;
        for(auto x: mp) {
            ans += x.second;
        }
        return ans;
    }
};
