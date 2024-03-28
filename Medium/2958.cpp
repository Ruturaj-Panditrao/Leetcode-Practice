// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;

        unordered_map<int,int> map;

        while(left<nums.size() && right<nums.size())
        {
            map[nums[right]]++;
            while(map[nums[right]]>k)
            {
                map[nums[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
