// 2942. Find Words Containing Character
// https://leetcode.com/problems/find-words-containing-character/

class Solution 
{
public:
    vector<int> findWordsContaining(vector<string>& words, char x) 
    {
        vector<int>ans;

        for(int i=0; i<words.size(); i++)
        {
            for(auto it : words[i])
            {
                if(it==x)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }    
        return ans;
    }
};

// Time Complexity : O(len(words)*maxlen(words[i]))
// Space Complexity : O(len(words))
