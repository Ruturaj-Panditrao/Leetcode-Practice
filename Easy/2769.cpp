// 2942. Find Words Containing Character
// https://leetcode.com/problems/find-the-maximum-achievable-number/

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2*t;
    }
};

// Time Complexity : O(1)
// Space Complexity : O(1)

// x is the greatest number possible and hence to make num and x equal, x has to step down and num has to step up.
// The amount by which num has to step up should be equal to the amount by which x should step down.
// Hence the maximum achievable x value is num + 2*t 
// Take an example and see for yourselves.
