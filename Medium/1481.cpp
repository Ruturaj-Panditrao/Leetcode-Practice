// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
       unordered_map<int,int>mp;
       for(auto it : arr)
       {
           mp[it]++;
       } 

       vector<int>freq;
       for(auto it : mp)
       {
           freq.push_back(it.second);
       }

       sort(freq.begin(),freq.end());
       int temp = 0;

       for(int i=0; i<freq.size(); i++)
       {
           temp+=freq[i];
           if(temp>k) return freq.size()-i;
       }
       return 0;
    }
};
