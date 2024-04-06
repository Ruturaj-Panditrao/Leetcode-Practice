// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count =0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(') count++;
            else if(s[i]==')')
            {
                // This guy is invalid, he doesn't have matching pair
                if(count==0) s[i]='$';
                else count--; 
                // Valid pair exists with this guy             
            }
        }
        count = 0;
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i]==')') count++;
            else if(s[i]=='(')
            {
                if(count==0) s[i]='$';
                else count--;
                
            }
        }
        string ans = "";
        for(auto it : s) if(it!='$') ans.push_back(it);
        return ans;
    }
};
