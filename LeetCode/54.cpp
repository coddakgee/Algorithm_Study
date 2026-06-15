//외곽부터 벗겨내는 코드는 시간복잡도는 괜찮으나, 공간복잡도를 많이 쓴다는 단점이 있으므로, 조금 교정을 했다. 
//BEFORE
class Solution {
private:
    vector<vector<int>>visited;
    struct codi{
        int y, x;
    };
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        visited = vector<vector<int>>(m, vector<int>(n, 0));
        vector<int>ret;

        queue<codi>q;
        q.push({0, 0});
        visited[0][0] = 1;

        int dir = 0;

        while(!q.empty()){
            int y = q.front().y, x = q.front().x;
            q.pop();
            ret.push_back(matrix[y][x]);
            
            int cnt = 0;
            while(cnt < 4){
                int ny=y+dy[dir], nx=x+dx[dir];
                if(ny<0 || nx<0 || ny>=m || nx>=n || visited[ny][nx]){
                    cnt++; dir = (dir+1)%4;
                    continue;
                }
                visited[ny][nx] = 1;
                q.push({ny,nx});
                break;
            }
        }
        return ret;
    }
};



//AFTER
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int>ret;

        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;

        while(top <= bottom && left <= right){
            for(int i=left; i<=right; i++) ret.push_back(matrix[top][i]);
            top++;

            for(int i=top; i<=bottom; i++) ret.push_back(matrix[i][right]);
            right--;

            if(top<=bottom){
                for(int i=right; i>=left; i--) ret.push_back(matrix[bottom][i]);
                bottom--;
            }

            if(left<=right){
                for(int i=bottom; i>=top; i--) ret.push_back(matrix[i][left]);
                left++;
            }
        }
        return ret;
    }
};
