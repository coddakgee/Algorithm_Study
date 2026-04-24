/*
  날짜 : 26.04.24.금
  문제 : SWEA 1949. [모의 SW 역량테스트] 등산로 조성
  풀이 시간 : 51분
  로직 : DFS + DP
  총평 : 시작점이 최대 5개이다. 라는 지문을 미쳐 읽지 못해서 DFS+백트래킹과 DFS+DP 어느것을 할까 고민하다가 시작점이 여러개가 되면 백트래킹을 썼을때 시간복잡도를 관리하기 불편하다고 생각해서 
  DP를 씀. 코드 리뷰를 해보니 DFS+백트래킹이 더 효율적인 방법인거 같다. 
*/

#include <bits/stdc++.h>
using namespace std;

struct coord{
    int y,x;
};
int dp[8][8], mp[8][8];
int n, k, max_height, rst;
vector<coord>v;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int go(int y, int x){
    int& ret = dp[y][x];
    if(~ret)return ret;
    ret = 1;
    
    for(int i=0; i<4; i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(ny<0 || nx<0 || ny>=n || nx>=n)continue;
        if(mp[y][x] > mp[ny][nx]){
            ret = max(ret, 1+go(ny,nx));
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	for(int _t=1; _t<=t; _t++){
	    max_height = 0, rst = 0;
	    cin >> n >> k;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            cin >> mp[i][j];
	            if(max_height < mp[i][j]){
	                max_height = mp[i][j];
	                v.clear();
	                v.push_back({i,j});
	            }
	            else if(max_height == mp[i][j]){
	                v.push_back({i,j});
	            }
	        }
	    }
	    
	    //하나도 안깎는 경우.
	    memset(dp, -1, sizeof(dp));
	    for(auto& p : v){
            rst = max(rst, go(p.y, p.x));
        }
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            for(int _k=1; _k<=k; _k++){
	                memset(dp, -1, sizeof(dp));
	                mp[i][j] -= _k;
	                for(auto& p : v){
	                    if(max_height != mp[p.y][p.x])continue;
	                    rst = max(rst, go(p.y, p.x));
	                }
	                mp[i][j] += _k;
	                if(mp[i][j] - _k <= 0)break; //0을 검사했다면 음수인 경우까지 체크할 필요가 없음.
	            }
	        }
	    }
	    
	    cout << "#" << _t << " " << rst << "\n";
	}
    return 0;
}
