class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Store all rotten oranges and count fresh ones
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 2) {
                    q.push({i, j});
                }
                else if(mat[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        int time = 0;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        // BFS
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            
            while(size--) {
                auto p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                
                for(int k = 0; k < 4; k++) {
                    int nx = x + dir[k][0];
                    int ny = y + dir[k][1];
                    
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            time++;
        }
        
        if(fresh > 0) return -1;
        return time;
    }
};