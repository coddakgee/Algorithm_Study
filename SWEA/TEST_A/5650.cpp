#include <iostream>
#include <vector>
using namespace std;

struct loc{
    int y,x;
};
int n;
bool flag = false;
int mp[102][102], dp[102][102][4];
vector<loc> hall[11];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int block[5][4] ={ //[블록 번호][방향] -> 무슨 방향으로 변하는지
    {-1, -1, -1, -1},
    {2, 0, 3, 1},
    {2, 3, 1, 0},
    {1, 3, 0, 2},
    {3, 2, 0, 1}
};
loc start;

int go(int y, int x, int dir){
    if(y==start.y && x==start.x){
        if(flag)return 0;
        flag = true;
    }
    if(mp[y][x] == -1)return 0; //블랙홀
    
    
    int cnt = 0;
    if(y<0 || y>=n || x<0 || x>=n || mp[y][x] == 5){ //벽, 네모 블록
        dir = (dir+2)%4;
        cnt++;
    }
    else if(mp[y][x] >= 1 && mp[y][x] <= 4){ //삼각 블록
        int blk_type = mp[y][x];
        dir = block[blk_type][dir];
        cnt++;
    }
    else if(mp[y][x] >= 6){ //웜홀
        int blk_type = mp[y][x];
        if(y == hall[blk_type][0].y && x == hall[blk_type][0].x){
            y=hall[blk_type][1].y, x=hall[blk_type][1].x;
        }
        else{
            y=hall[blk_type][0].y, x=hall[blk_type][0].x;
        }
    }
    
    int& ret = dp[y][x][dir];
    if(ret != -1)return ret;
    ret = cnt;
    
    int ny=y+dy[dir], nx=x+dx[dir];
    ret += go(ny,nx,dir);

    return ret;
}

int main(){
    int t; cin >> t;
    
    for(int _t=1; _t<=t; _t++){
        cin >> n;
        for(int i=0; i<11; i++){
            hall[i].clear();
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> mp[i][j];
                for(int p=0; p<4; p++){
                    dp[i][j][p] = -1;
                }
                if(mp[i][j] >= 6){
                    int tmp = mp[i][j];
                    hall[tmp].push_back({i,j});
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int p=0; p<4; p++){
                    if(mp[i][j] != 0)continue;
                    if(dp[i][j][p] != -1)continue;
                    start = {i, j};
                    flag = false;
                    go(i, j, p);
                }
            }
        }
        
        int rst = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int p=0; p<4; p++){
                    if(mp[i][j] != 0)continue;
                    if(dp[i][j][p] == -1)continue;
                    rst = max(rst, dp[i][j][p]);
                    
                    if(dp[i][j][p] == 15)cout << "[" << i << " " << j << " " << p << "]\n";
                    
                }
            }
        }
        
        cout << "#" << _t << " " << rst << "\n";
    }
    
    
    return 0;
}
