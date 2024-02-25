// https://leetcode.com/problems/greatest-common-divisor-traversal/

class Solution {
public:
    bool dfs(vector<int>& nums, unordered_map<int, bool>& dp, int current, int target) 
    {
    // if(current == target)
    // { // Uske taraf pohuch gaye hain
    //     return true;
    // }
    // visited.insert(current);
    // for (int i = 0; i < nums.size(); i++) 
    // {
    //     if (!visited[i] || gcd(nums[current], nums[i]) >= 1) 
    //     {
    //         if (dfs(nums,visited,i, target)) return true
    // }
  
    // for (int i = 0; i < nums.size(); i++) 
    // {
    //     // Check krna hoga agar gcd greater than 1, only then I can traverse 
    //     if (visited.count(i) == 0 && __gcd(nums[current], nums[i]) > 1) 
    //     {// Only if it hasnt been vis yet and count for that particular position is 0
    //         if (dfs(nums, visited, i, target))
    //         {
    //             return true;
    //         }
    //     }
    // }
    return false;
}
 class DisjointSet {
    private:
        vector<int> parent;
        vector<int> rank;

    public:
        DisjointSet(int size) {
            parent.resize(size);
            rank.resize(size, 1);
            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    if (rank[rootX] == rank[rootY]) {
                        rank[rootX]++;
                    }
                }
            }
        }
    };

bool canTraverseAllPairs(vector<int>& nums)
{
//     int n = nums.size();
// //      int n = nums.size();
// //     int max_positive = 1, max_negative = 1, max_strength = INT_MIN;

// //   for(int i = 0; i < n; i++) 
// //   {
// //         if (nums[i] == 0) 
//         // {
// //             max_positive = 1;
// //             max_negative = 1;
// //             continue;
// //         }
    
//      unordered_map<int, bool> memo;
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++) 
//         {
//             // unordered_set<int> visited;
//             if (dfs(nums, memo, i, j)==false)
//             {
//                 // If ek bhi traversal not possible simply return false
//                 return false;
//             }
//         }
//     }
//     return true;
//      int n = nums.size();
//      unordered_map<int, bool> memo;
        
//         for (int i = 0; i < n - 1; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 stack<int> stack;
//                 stack.push(i);
//                 std::unordered_map<int, bool> visited;
//                 visited[i] = true;
                
//                 while (!stack.empty()) 
//                 {
//                     int current = stack.top();
//                     stack.pop();
//                     if (current == j) break; 
//                     // No need to check for this one already reached
//                     for (int k = 0; k < n; k++)
//                     {
//                         if (!visited[k] &&__gcd(nums[current], nums[k]) > 1)
//                         {
//                             stack.push(k);
//                             visited[k] = true;
//                         }
//                     }
//                 }
//                 if (!visited[j]) return false;
//             }
//         }
        
//         return true;
//     int n = nums.size();
//         vector<unordered_set<int>> adjList(n);
        
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (__gcd(nums[i], nums[j]) > 1) {
//                     adjList[i].insert(j);
//                     adjList[j].insert(i);
//                 }
//             }
//         }
        
//         for (int i = 0; i < n - 1; i++) 
//         {
//             vector<bool> visited(n, false);
//             visited[i] = true;
            
//             queue<int> q;
//             q.push(i);
            
//             while (!q.empty()) 
//             {
//                 int current = q.front();
//                 q.pop();     
//                 for (int neighbor : adjList[current]) 
//                 {
//                     if (!visited[neighbor]) 
//                     {
//                         visited[neighbor] = true;
//                         q.push(neighbor);
//                     }
//                 }
//             }
            
//             for (int j = 0; j < n; j++) 
//             {
//                 if (j != i && !visited[j]) 
//                 {
//                     return false;
//                 }
//             }
//         }
//         return true;
// }
    int n = nums.size();
        DisjointSet ds(n);
        unordered_map<int, vector<int>> factors;
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            for (int j = 2; j * j <= num; j++) 
            {
                if (num % j == 0) {
                    factors[j].push_back(i);
                    while (num % j == 0)
                    {
                        num /= j;
                    }
                }
            }
            if (num > 1) {
                factors[num].push_back(i);
            }
        }

        for (auto& factorPair : factors)
        {
            vector<int>& indices = factorPair.second;
            for (int i = 1; i < indices.size(); i++) 
            {
                ds.unite(indices[i - 1], indices[i]);
            }
        }

        int root = ds.find(0);
        for (int i = 1; i < n; i++)
        {
            if (ds.find(i) != root) return false;
        }

        return true;
}
};
