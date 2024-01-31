// https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<pair<int, int>> stk; stk.push({t[n-1], n-1});
        vector<int> res(n); res[n-1] = 0;
        for(int i = n-2; i >= 0; --i){
            while(!stk.empty() && stk.top().first <= t[i]){
                stk.pop();
            }
            res[i] = (stk.empty()) ? 0 : (stk.top().second - i);
            stk.push({t[i], i});
        }
        return res;
    }
};
