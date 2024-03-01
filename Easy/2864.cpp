// https://leetcode.com/problems/maximum-odd-binary-number/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // sort(s.begin(),s.end(),greater<char>());
        // char first = s[0];
        // string ans = "";
        // for(int i=1; i<s.length(); i++){
        //     ans+=s[i];
        // }
        // ans.push_back(first);
        // return ans;

        string ans = "";
        int ones = 0;
        for(int i=0; i<s.length();i++){
            if(s[i]=='1') ones++;
        }
        for(int i=0; i<ones-1; i++){
            ans+="1";
        }

        for(int i=0; i<s.length()-ones;i++){
            ans+="0";
        }

        ans.push_back('1');
        return ans;

    }
};
