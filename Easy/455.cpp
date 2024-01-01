// https://leetcode.com/problems/assign-cookies/description/

class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
{
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int gi = 0;
        int si = 0;
        int ans = 0;
        while(si<s.size() && gi<g.size())
        {
            if(s[si]>=g[gi])
            {
                ans++;
                si++;
                gi++;
            }
            else si++;
        }
        return ans;
    }
};

// Time Complexity : O(n⋅logn+m⋅logm)
// Space Complexity : O(1)
