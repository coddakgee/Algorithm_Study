/*
    날짜 : 26.04.24.금
    문제 : SWEA 1953. [모의 SW 역량테스트] 탈주범 검거
    풀이 시간 : 47분
    로직 : BFS
    총평 : BFS와 하드코딩을 하니 쉽게 풀렸다.

*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, r, c, l;
int mp[50][50];
bool visited[50][50];
struct cordi{
    int y, x;
};
queue<cordi>q;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool _in(int num, int dir){
    if(num==1)return true;
    else if(num==2 && dir%2==1)return true;
    else if(num==3 && dir%2==0)return true;
    else if(num==4 && (dir==1 || dir==2))return true;
    else if(num==5 && (dir==2 || dir==3))return true;
    else if(num==6 && (dir==3 || dir==0))return true;
    else if(num==7 && (dir==0 || dir==1))return true;
    return false;
}

bool _out(int num, int dir){
    if(num==1)return true;
    else if(num==2 && dir%2==1)return true;
    else if(num==3 && dir%2==0)return true;
    else if(num==4 && (dir==0 || dir==3))return true;
    else if(num==5 && (dir==0 || dir==1))return true;
    else if(num==6 && (dir==2 || dir==1))return true;
    else if(num==7 && (dir==2 || dir==3))return true;
    return false;
}

int main(){
    int t; cin >> t;

    for(int _t=1; _t<=t; _t++){
        int ret = 0;
        cin >> n >> m >> r >> c >> l;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> mp[i][j];
            }
        }

        memset(visited, 0, sizeof(visited));

        while(q.size())q.pop();
        visited[r][c] = 1;
        q.push({r,c});

        int cnt = 1;
        while(cnt < l && !q.empty()){
            int p = q.size();
            while(p--){
                int y=q.front().y, x=q.front().x;
                q.pop();
                
                for(int i=0; i<4; i++){
                    int ny=y+dy[i], nx=x+dx[i];
                    if(ny<0 || nx<0 || ny>=n || nx>=m)continue;
                    if(mp[ny][nx] == 0)continue;
                    if(!_out(mp[y][x], i))continue;
                    if(visited[ny][nx])continue;
                    if(!_in(mp[ny][nx], i))continue;

                    visited[ny][nx] = 1;
                    q.push({ny,nx});
                }
            }
            cnt++;
        }


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j])ret++;
            }
        }
        

        cout << "#" << _t << " " << ret << "\n";
    }

    return 0;
}