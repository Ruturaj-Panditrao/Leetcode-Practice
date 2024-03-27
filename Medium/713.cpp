// https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int ans = 0;
        int left = 0;
        long long int curprod = 1;
        if(k<=1) return 0;
        for(int right=0; right<nums.size(); right++)
        {
            curprod*=nums[right];
            while(curprod >= k)
            {
                curprod/=nums[left];
                left+=1;
            }
            ans+=right-left+1;
        }

        return ans;
    }
};
