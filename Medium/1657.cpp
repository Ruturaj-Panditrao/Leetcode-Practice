// https://leetcode.com/problems/determine-if-two-strings-are-close/description/

class Solution 
{
public:
    bool closeStrings(string word1, string word2) 
{
		//base case if the length is not same of both the strings then the answer is **FALSE**
        if(word1.size()!=word2.size())
            return false;
		//to see the occurence of a particular alphabet in string 1
        unordered_set<int> st;
		
		//to store the frequencies of a particular alphabet
        vector<int> freq1(26,0), freq2(26,0);
		
		//traversing the word1 to find the frequency and sort the occurence of that alphabet in the set  TC=O(n)
        for(int i=0;i<word1.size();i++)
        {
            freq1[word1[i]-'a']++;
            st.insert(word1[i]);
        }
        for(int i=0;i<word2.size();i++){
		
			//if a particular alphabet is not present in word1 then we cannot convert the strings
            if(st.find(word2[i])==st.end())
                return false;
            freq2[word2[i]-'a']++;
        }
		//sorting the frequencies and if they are equal then we can convert else not  TC=nlog(n)
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
		
        if(freq1==freq2)
            return true;
        return false;
    }
};
