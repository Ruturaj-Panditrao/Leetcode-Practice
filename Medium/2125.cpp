// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

class Solution 
{
public:
    int numberOfBeams(vector<string>& bank) 
    {
        // vector<int>p;
        int c1 = 0;
        int c2 = 0;
        int ans = 0;
        if(bank.size()==1) return 0;
        for(int i=0; i<bank.size(); i++)
        {
            int count = 0;
            for(int j=0; j<bank[i].size(); j++)
            {
                if(bank[i][j]=='1') count++;
            }
            if(c1==0 && count!=0) c1=count;
            else if(c1!=0 && c2==0 && count!=0) c2=count;

            if(c1!=0 && c2!=0)
            {
                ans+=c1*c2;
                c1=c2;
                c2=0;
            }
            // if(count!=0) p.push_back(count);
        }        

        // for(auto it : p) cout<<it<<" ";
        // if(p.size()==0) return 0;
        // for(int i=0; i<p.size()-1; i++)
        // {
        //     ans+= p[i]*p[i+1];
        // }
        
        return ans;
    }
};

// Self-Realized we need to keep track of only 2 variables, not store the count of devices in all the rows
// Time Complexity : O(M*N) Only as much as Traversing the Bank vector Once
// Space Complexity : O(1) Only a couple of variables are used.
