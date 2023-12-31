// https://leetcode.com/problems/largest-substring-between-two-equal-characters/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        int ans = -1;

        for(int i=0; i<s.length(); i++)
        {
            for(int j=1; j<s.length(); j++)
            {
                if(s[i]==s[j])
                {
                    ans = max(ans,j-i-1);
                }
            }
        }

        return ans;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(1)

class Solution 
{
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        int ans = -1;
        map<char,int>mp;

        for(int i=0; i<s.length(); i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                ans = max(ans,i-mp[s[i]]-1);
            }
            else
            {
                mp[s[i]] = i;
            }
        }        

        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(26) only 26 characters at max
