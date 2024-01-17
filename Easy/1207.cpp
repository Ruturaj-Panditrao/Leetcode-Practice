// https://leetcode.com/problems/unique-number-of-occurrences/solutions/1093574/1207-unique-number-of-occurrences/

class Solution 
{
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        map<int,int>mp;
        for(auto it : arr) mp[it]++;
        // for(auto it: mp) cout<<it.first<<" "<<it.second<<endl;
        set<int>s;
        for(auto it : mp)
        {
            if(s.find(it.second)!=s.end()) return false;
            else s.insert(it.second);
        }
        return true;
    }
};
