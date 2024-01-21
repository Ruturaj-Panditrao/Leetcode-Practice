// https://leetcode.com/problems/house-robber/description/

// Recursive TC->Exponential, SC->O(n)
class Solution
{
public:

    int f(int index, int prevIndex, vector<int>&nums)
    {
        if(index>=nums.size()) return 0;
        if(index!=prevIndex+1 || prevIndex==-1)
        {
            return max(nums[index]+f(index+1,index,nums),f(index+1,prevIndex,nums));
        }
        else return f(index+1,prevIndex,nums);
    }
    int rob(vector<int>& nums) 
    {
        return f(0,-1,nums);
    }
};

// Memoized TC->O(N*N), SC->O(N*N)
class Solution
{
public:

    int f(int index, int prevIndex, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(index>=nums.size()) return 0;
        if (dp[index][prevIndex + 1] != -1) return dp[index][prevIndex + 1];
        
        if (index != prevIndex + 1 || prevIndex == -1) 
        {
            return dp[index][prevIndex + 1] = max(nums[index] + f(index + 1, index, nums, dp), f(index + 1, prevIndex, nums, dp));
        } else {
            return dp[index][prevIndex + 1] = f(index + 1, prevIndex, nums, dp);
        }
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0,-1,nums,dp);
    }
};
