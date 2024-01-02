// 2610. Convert an Array Into a 2D Array With Conditions
// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

// My Approach
// Similar in terms of using an Array instead of a Hashmap to store the numbers with their frequency since we already know that the max size of array is 200 elements only -> O(N) Space Complexity
// However, my approach is a bit slower and requires more iterations in terms of Time Complexity -> O(max occ of any number in nums * len of nums)
class Solution 
{
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>freqs(n+1,0);
        int maxi =0;
        int distincts = 0;
        for(int i=0; i<nums.size(); i++)    
        {
            if(freqs[nums[i]]==0) distincts++;
            freqs[nums[i]]+=1;
            maxi = max(maxi,freqs[nums[i]]);
        }
        vector<vector<int>>ans;
        for(auto it : freqs) cout<<it<<" ";
        for(int j=0; j<=maxi; j++)
        {
            vector<int>temp;
            for(int i=1; i<freqs.size(); i++)
            {
                if(freqs[i]>0)
                {
                    temp.push_back(i);
                    freqs[i]--;
                }
            }

            if(temp.size()!=0) ans.push_back(temp);
        }
        cout<<endl;
        for(auto it : freqs) cout<<it<<" ";
        cout<<maxi<<distincts<<endl;
        return ans;
    }
};

// Editorial Approach 

class Solution 
{
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>freqs(n+1,0);
        vector<vector<int>>ans;

        for(auto i : nums)
        {
            if(freqs[i]>=ans.size())
            {
                ans.push_back({});
            }

            ans[freqs[i]].push_back(i);
            freqs[i]++;
        }

        return ans;
    }
};

// They add the element in the corresponding vector and decide whether to add a new row or not in 1 go.
// Time Complexity : O(N) One Pass
// Space Complexity : O(N)
