/*
  날짜 : 26.04.21.화
  문제 : SWEA 5644. [모의 SW 역량테스트] 줄기세포배양
  풀이 시간 : 1시간 12분
  로직 : 시뮬레이션
  총평 : 그렇게 어렵지 않은 문제였음. 출력 부분에서 실수가 있었음. 주의할 것. 
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct cell {
	int y, x;
};
int n, m, k;
int mp[500][500], time_pass[500][500];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
queue<cell> inact_q;
queue<cell> act_q;

void inactive(int size) {
	while (size--) {
		int y = inact_q.front().y, x = inact_q.front().x;
		inact_q.pop();

		time_pass[y][x]++;
		if (time_pass[y][x] == mp[y][x]){
			act_q.push({ y,x });
		}
		else if(time_pass[y][x] < mp[y][x]){
			inact_q.push({ y,x });
		}
	}
}

void active(int size) {
	while (size--) {
		int y = act_q.front().y, x = act_q.front().x;
		act_q.pop();
		time_pass[y][x]++;
		if (time_pass[y][x] < mp[y][x] * 2) {
			act_q.push({ y,x });
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (mp[ny][nx] == 0){
				mp[ny][nx] = mp[y][x];
				inact_q.push({ ny,nx });
			}
			else if (mp[ny][nx] > 0 && time_pass[ny][nx] == 0){
				mp[ny][nx] = max(mp[ny][nx], mp[y][x]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;

	for (int _t = 1; _t <= t; _t++){
		memset(mp, 0, sizeof(mp));
		memset(time_pass, 0, sizeof(time_pass));
		while (inact_q.size())inact_q.pop();
		while (act_q.size())act_q.pop();

		cin >> n >> m >> k;

		for (int i = 225; i < 225 + n; i++){
			for (int j = 225; j < 225 + m; j++){
				cin >> mp[i][j];
				if (mp[i][j]){
					inact_q.push({ i,j });
				}
			}
		}

		for (int i = 1; i <= k; i++) {
			int p = inact_q.size();
			int q = act_q.size();

			inactive(p);
			active(q);
		}
		

		cout << "#" << _t << " " << inact_q.size() + act_q.size() << "\n";
	}

	return 0;
}
