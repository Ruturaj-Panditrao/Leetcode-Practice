class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        
        int n = nums.size();
        // vector<int>pos;
        // vector<int>neg;
        // vector<int>ans;
        // for(auto it : nums)
        // {
        //     if(it>0) pos.push_back(it);
        //     else neg.push_back(it);
        // }

        // for(int i=0; i<n/2; i++)
        // {
        //     ans.push_back(pos[i]);
        //     ans.push_back(neg[i]);
        // }

        // return ans;

        vector<int>ans(n,0);
        int posptr = 0;
        int negptr = 1;

        for(auto it : nums)
        {
            if(it>0)
            {
                ans[posptr]=it;
                posptr+=2;
            }
            else
            {
                ans[negptr]=it;
                negptr+=2;
            }
        }

        return ans;
    }
};
