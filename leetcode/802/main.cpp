class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n = graph.size();

       vector<int> ans, out(n);
       vector<int> adj[n];

       for (int i = 0; i < n; ++i) {
         for (auto node: graph[i]) {
           out[i]++;
           adj[node].push_back(i);
         }
       } 

       queue<int> q;
       for (int i = 0; i < n; ++i) {
         if (out[i] == 0) {
           q.push(i);
         }
       }

       while (!q.empty()) {
         int front = q.front(); q.pop();
         ans.push_back(front);

         for (auto node: adj[front]) {
           --out[node];

           if (out[node] == 0) q.push(node);
         }
       }

       sort(ans.begin(), ans.end());
       return ans;
    }
};
