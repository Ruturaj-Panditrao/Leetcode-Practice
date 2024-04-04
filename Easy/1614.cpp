// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int counter = 0;
        int ans = 0;
        for(auto it : s)
        {
            if(it=='(') counter++;
            else if(it==')') counter--;
            ans = max(ans,counter);
        }
        return ans;
    }
};
