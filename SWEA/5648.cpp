/*
    날짜 : 26.04.17.금
    문제 : SWEA 5648. [모의 SW 역량테스트] 원자 소멸 시뮬레이션
    풀이 시간 : 1시간 54분
    로직 : 시뮬레이션
    총평 : 코드는 1시간 정도만에 작성했으나, 디버깅에 1시간을 씀.
    간단한 오타와 int& x, y이렇게 참조자를 지정하는 방법에 있어서 문법을 모름. 
    또한 for(auto it = s.begin(); it!=s.end(); it++) 이렇게 set을 참조하는 방법도 배움.
    vector에 sort하고 인접한 좌표가 같으면 없애는 방법도 있음.
*/


#include <bits/stdc++.h>
using namespace std;
const int MAX = 4000;
struct atom{
    int x, y, dir, e;
};
atom arr[1004];
int mp[MAX+4][MAX+4]; //0부터 4000까지 있을 수 있음
set<pair<int,int>>s; //충돌한 좌표 체크
int n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	
	for(int _t=1; _t <=t; _t++){
	    int ret = 0;
	    cin >> n;
	    for(int i=1; i<=n; i++){
	        int x, y, d, e; cin >> x >> y >> d >> e;
	        x+=1000, y+=1000; x*=2, y*=2;
	        arr[i] = {x,y,d,e};
	    }
	    
	    int _time = 5000;
	    while(_time--){
	        s.clear();
	        for(int i=1; i<=n; i++){ //이동
	            int& x=arr[i].x;
	            int& y=arr[i].y;
	            int dir=arr[i].dir, e=arr[i].e;
	            if(x<0 || y<0 || x>MAX || y>MAX)continue;
	            int nx=x+dx[dir], ny=y+dy[dir];
	            if(nx<0 || ny<0 || nx>MAX || ny>MAX){
	                x = -1, y = -1;
	                continue;
	            }
	            if(mp[nx][ny]){
	                x = -1, y = -1;
	                s.insert({nx,ny});
	                ret += e;
	                continue;
	            }
	            x = nx, y = ny;
	            mp[nx][ny] = i;
	        }
	        
	        
	        if(s.size()){
	            for(auto it = s.begin(); it!=s.end(); it++){
	                int x=(*it).first, y=(*it).second;
	                
	                int idx = mp[x][y];
	                ret += arr[idx].e;
	                
	                mp[x][y] = 0;
	                arr[idx].x = -1, arr[idx].y = -1;
	            }
	        }
	        
	        for(int i=1; i<=n; i++){ //map 지움
	            int x=arr[i].x, y=arr[i].y;
	            if(x<0 || y<0 || x>MAX || y>MAX)continue;
	            mp[x][y] = 0;
	        }
	        
	        
	    }
	    
	    cout << "#" << _t << " " << ret << "\n";
	}
    return 0;
}
