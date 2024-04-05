// https://leetcode.com/problems/make-the-string-great/description/

class Solution {
public:
// Can also use string instead of a stack
// Say it is stackstr
// Just see stackstr.back() and stackstr.pop_back()
    string makeGood(string s) {
        stack<char>st;
        for(int i=s.length()-1; i>=0; i--)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if(abs(int(s[i])-int(st.top()))==32) st.pop();
                else st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
