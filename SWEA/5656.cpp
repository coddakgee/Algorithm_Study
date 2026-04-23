/*
  날짜 : 26.04.20.월
  문제 : SWEA 5656. [모의 SW 역량테스트] 벽돌 깨기
  풀이 시간 : 1시간 38분
  로직 : 중복 순열 + 시뮬레이션 + BFS + 백트래킹
  총평 : 오타 몇개 때문에 많은 시간을 잡아먹음. 앞으로는 함수 하나를 만들고 그 함수가 잘 작동하는지 중간점검을 해볼것.
  memcpy(tmp, mp, sizeof(mp)); 를 써서 시간을 줄일것! mp 데이터를 블록 단위로 tmp로 옮기는 함수!
*/
#include <bits/stdc++.h>
using namespace std;

int ret, n, w, h;
int mp[16][16], visited[16][16];
struct wall{
    int y, x;
};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};


int count_wall(){
    int sum = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(mp[i][j])sum++;
        }
    }
    return sum;
}

void break_wall(int y, int x){
    memset(visited, 0, sizeof(visited));
    queue<wall>q;
    q.push({y,x});
    visited[y][x] = 1;
    
    while(!q.empty()){
        int y=q.front().y, x=q.front().x;
        q.pop();
        int k=mp[y][x];
        mp[y][x] = 0;
        
        for(int i=0; i<4; i++){
            for(int j=0; j<k; j++){
                int ny=y+(j*dy[i]), nx=x+(j*dx[i]);
                if(ny<0 || nx<0 || ny>=h || nx>=w)continue;
                if(visited[ny][nx])continue;
                if(mp[ny][nx] == 0)continue;
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
    }
    
}

void fall_wall(){
    queue<int>q;
    
    for(int j=0; j<w; j++){
        while(q.size())q.pop();
        for(int i=h-1; i>=0; i--){
            if(mp[i][j]){
                q.push(mp[i][j]);
                mp[i][j] = 0;
            }
        }
        
        for(int i=h-1; i>=0; i--){
            if(q.empty())break;
            mp[i][j] = q.front();
            q.pop();
        }
    }
}

void go(int depth){
    if(depth == n){
        ret = min(ret, count_wall());
        return;
    }
    int tmp[16][16];
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            tmp[i][j] = mp[i][j];
        }
    }
    
    bool is_empty = false;
    for(int j=0; j<w; j++){
        bool flag = false;
        for(int i=0; i<h; i++){
            if(mp[i][j]){
                flag = true;
                break_wall(i, j);
                break;
            }
        }
        is_empty |= flag;
        if(!flag)continue;
        fall_wall();
        
        go(depth+1);
        
        for(int p=0; p<h; p++){
            for(int q=0; q<w; q++){
                mp[p][q] = tmp[p][q];
            }
        }
    }
    
    if(!is_empty){
        ret = 0;
        return;
    }
}

void init(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

int main() {
    init();
	int t; cin >> t;
	for(int _t=1; _t<=t; _t++){
	    ret = 1000;
	    cin >> n >> w >> h;
	    for(int i=0; i<h; i++){
	        for(int j=0; j<w; j++){
	            cin >> mp[i][j];
	        }
	    }
	    
	    go(0);
	    
	    cout << "#" << _t << " " << ret << "\n";
	}

}
