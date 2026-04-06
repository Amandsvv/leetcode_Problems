class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        set<pair<int,int>> ob;
        for(auto obs : obstacles){
            ob.insert({obs[0], obs[1]});
        }
        
        // Direction vectors: North, East, South, West
        vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int dir = 0; // Start facing North
        int maxDist = 0;
        
        for(int move : commands){
            if(move == -2) dir = (dir + 3) % 4;  // Turn left
            else if(move == -1) dir = (dir + 1) % 4;  // Turn right
            else {
                // Move forward
                for(int i = 0; i < move; i++){
                    int nx = x + dirs[dir].first;
                    int ny = y + dirs[dir].second;
                    if(ob.count({nx, ny})) break;  // Hit obstacle
                    x = nx;
                    y = ny;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        return maxDist;
    }
};