// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

class Solution {
public:

    bool isPalindrome(string s)
    {
        // string t = s;
        // reverse(s.begin(),s.end());
        // return s==t;

        int n = s.length();
        int start = 0;
        int end = n-1;

        while(start<=end)
        {
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }

        return true;
        // aabaa
        // 01234

        // bbbb
        // 0123
    }
    
    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for(auto it : words) 
        {
            if(isPalindrome(it))
            {
                ans = it;
                break;
            }
        }
        return ans;
    }
};
