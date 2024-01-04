// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
// 2870. Minimum Number of Operations to Make Array Empty
class Solution 
{
public:
    int minOperations(vector<int>& nums) 
    {
      unordered_map<int,int>freq;
      for(auto it : nums) freq[it]++;
      int steps = 0;
      for(auto it: freq)
      {
          if(it.second==1) return -1;
          else
          {
              if(it.second%3==0) steps+=it.second/3;
              if((it.second+1)%3==0) steps+=(it.second+1)/3;
              if((it.second+2)%3==0) steps+=(it.second+2)/3;
          }
      }
      return steps;
    }
};

// Just write down the number of steps required for some entries to find the pattern
// 1->IMPOSSIBLE
// 2->1
// 3->1
// 4->2
// 5->2
// 6->2
// 7->3
// 8->3
// 9->3
// 10->4,
// 11->4,
// 12->4,
// 13->5
// 14->5
// 15->5

// Time Complexity : O(N)
// Space Complexity : O(N)
