// https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
       
        long long int res = 0;
        for(int i=0; i<=nums.size(); i++) res^=i;
        for(int i=0; i<nums.size();i++) res^=nums[i];
        return res;
    }
};
