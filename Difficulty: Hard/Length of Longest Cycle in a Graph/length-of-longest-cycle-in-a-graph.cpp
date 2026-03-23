class Solution {
  public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj(V, -1);
        
        // Since each node has at most one outgoing edge
        for (auto &e : edges) {
            adj[e[0]] = e[1];
        }
        
        vector<int> vis(V, 0);
        vector<int> step(V, 0);
        int ans = -1;
        
        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;
            
            int node = i;
            int cnt = 0;
            unordered_map<int, int> mp;
            
            while (node != -1 && !vis[node]) {
                vis[node] = 1;
                mp[node] = cnt++;
                node = adj[node];
                
                if (node != -1 && mp.count(node)) {
                    ans = max(ans, cnt - mp[node]);
                    break;
                }
            }
        }
        
        return ans;
    }
};