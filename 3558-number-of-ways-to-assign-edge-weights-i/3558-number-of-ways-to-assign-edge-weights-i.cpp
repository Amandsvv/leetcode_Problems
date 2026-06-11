class Solution {
public:
    int maxDepth(vector<vector<int>>& edges){
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);

        for(auto& e :edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth = -1;
        vector<bool> visited(n+1, false);
        queue<int>q;
        q.push(1);
        visited[1] = true;

        while(!q.empty()){
            int sz = q.size();
            depth++;

            while(sz--){
                int node = q.front();
                q.pop();

                for(int nei : adj[node]){
                    if(!visited[nei]){
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }
        return depth;
    }
    long long pow(long long a, long b, long long mod){
        long long res = 1;
        while(b){
            if(b & 1){
                res = (res * a) % mod;
            }

            a = (a* a) % mod;
            b >>= 1;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int height = maxDepth(edges);
        int mod = 1e9 + 7;
        return (int)pow(2 , (height -1) ,mod);
    }
};