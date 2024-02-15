// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum = 0;
        long long ans = -1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<sum)ans = nums[i] + sum;
            sum+=nums[i];
        }
        
        return ans;

        // 1 1 2 3 5 12 50
    }
};



