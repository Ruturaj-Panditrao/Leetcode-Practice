// https://leetcode.com/problems/set-mismatch/description/

class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        map<int,int>mp;
        int n = nums.size();
        vector<int>ans;
        for(auto it : nums) mp[it]++;
        for(int i=1;i<=n;i++)
        {
            if(mp[i]==0)
            {
                for(auto it : mp)
                {
                    if(it.second>1)
                    {
                        ans.push_back(it.first);
                        break;
                    }
                }
                ans.push_back(i);
            }
        }
        return ans;
    }
};
