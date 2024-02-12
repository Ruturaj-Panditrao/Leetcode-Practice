// https://leetcode.com/problems/majority-element/

// Using Hashmap
// SC->O(N) 
// TC->O(N)

class Solution 
{
public:
    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
       map<int,int>mp;
       for(auto it : nums) mp[it]++;
       int ans = -1;
       for(auto it : mp) if(it.second>n/2) ans = it.first;
       return ans;
    }
};

// Using Sorting
// SC->O(1)
// TC->O(N)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int candidate = nums[0];
        int vote = 0;
        for(int i=0; i<nums.size();i++)
        {
            if(vote==0) candidate = nums[i];
            if(nums[i]==candidate) vote++;
            else vote--;
        }
        return candidate;
    }
};
};

// Using Moore's Algorithm
// SC->O(1)
// TC->O(N)

class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int candidate = nums[0];
        int vote = 0;
        for(int i=0; i<nums.size();i++)
        {
            if(vote==0) candidate = nums[i];
            if(nums[i]==candidate) vote++;
            else vote--;
        }
        return candidate;
    }
};
