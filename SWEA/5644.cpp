/*
  날짜 : 26.04.18.토
  문제 : SWEA 5644. [모의 SW 역량테스트] 무선 충전
  풀이 시간 : 56분
  로직 : 시뮬레이션
  총평 : 그렇게 어렵지 않은 문제였음. 
  a.size(), b.size() 있는 지 없는 지 체크하면서 for문을 돌리면 코드 상 좀 복잡해지는 문제가 있는데, 이것보다는 a[0], b[0]에 결과에 영향을 미치지 않는 값을 넣어놓으면
  코드를 더 간결하게 짤 수 있음!
*/
#include <bits/stdc++.h>
using namespace std;

struct user{
    int x, y;
};
struct BC{
    int x, y, c, p;
};

int m, k;
int mv_a[104], mv_b[104]; //사용자 이동정보 0~5;
BC bc[10]; //BC 정보
user A, B; //A,B의 위치정보
int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, -1, 0, 1, 0};
vector<int>a, b;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    
    for(int _t=1; _t <= t; _t++){
        A = {1, 1};
        B = {10, 10};
        cin >> m >> k;
        for(int i=1; i<=m; i++){ //i==0일땐 원래 위치임.
            cin >> mv_a[i];
        }
        for(int i=1; i<=m; i++){ //i==0일땐 원래 위치임.
            cin >> mv_b[i];
        }
        mv_a[0] = 0, mv_b[0] = 0;
        
        for(int i=1; i<=k; i++){
            int x, y, c, p; cin >> x >> y >> c >> p;
            bc[i] = {x,y,c,p};
        }
        
        int ret = 0;
        for(int i=0; i<=m; i++){
            int tmp = 0;
            a.clear(); b.clear();
            A.x += dx[mv_a[i]]; A.y += dy[mv_a[i]];
            B.x += dx[mv_b[i]]; B.y += dy[mv_b[i]];
            for(int j=1; j<=k; j++){
                int x=bc[j].x, y=bc[j].y, c=bc[j].c;
                int dist_a = abs(A.x - x) + abs(A.y - y);
                int dist_b = abs(B.x - x) + abs(B.y - y);
                if(dist_a <= c)a.push_back(j);
                if(dist_b <= c)b.push_back(j);
            }
            
            if(a.size()){
                if(b.size()){
                    for(auto _a : a){
                        for(auto _b : b){
                            if(_a == _b)tmp = max(tmp, bc[_a].p);
                            else{
                                tmp = max(tmp, bc[_a].p + bc[_b].p);
                            }
                        }
                    }
                }
                else{
                    for(auto _a : a){
                        tmp = max(tmp, bc[_a].p);
                    }
                }
            }
            else{
                if(b.size()){
                    for(auto _b : b){
                        tmp = max(tmp, bc[_b].p);
                    }
                }
                else{
                    continue;
                }
            }
            
            ret += tmp;
        }
        
        cout << "#" << _t << " " << ret << "\n";
    }
}
