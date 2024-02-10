// https://leetcode.com/problems/palindromic-substrings/description/

class Solution {
public:

    bool isPalindrome(string S)
    {
        string P = S;
        reverse(P.begin(), P.end());
        if (S == P)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
}

    int countSubstrings(string s) {
        int n=s.size();
        int i=1,count=0;
        string str;
        for(int j=0;j<n;j++)
        {
            str="";
            for(int k=j;k<n;k++)
            {
                str+=s[k];
                if(isPalindrome(str))
                    count++;

            }
        }
        return count;
    }
};
