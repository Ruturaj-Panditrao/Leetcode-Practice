// https://leetcode.com/problems/length-of-last-word/description/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ptr = s.length()-1;
        int len = 0;
        while(ptr>=0 && s[ptr]==' ')
        {
            ptr-=1;
        }
         while(ptr>=0 && s[ptr]!=' ')
        {
            ptr-=1;
            len++;
        }
        return len;

    }
};
