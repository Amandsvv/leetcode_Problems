class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int room){
        vis[room] = true;
        for(int key : rooms[room]){
            if(!vis[key]){
                dfs(rooms, vis, key);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(rooms, visited, 0);

        for(auto check: visited){
            if(!check) return false;
        }
        return true;
    }
};