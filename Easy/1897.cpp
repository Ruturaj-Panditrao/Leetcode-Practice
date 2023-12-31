// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

class Solution 
{
public:
    bool makeEqual(vector<string>& words) 
    {
        map<char,int>mp;
        for(int i=0; i<words.size(); i++)
        {
            for(auto it : words[i]) mp[it]++;
        }        

        int n = words.size();

        for(auto jt : mp)
        {
            if(jt.second%n!=0) return false;
        }

        return true;
    }
};

// Time Complexity : O(n*k)
// Space Complexity : O(26) since we know that map contains only lowercase letters/alphabets
