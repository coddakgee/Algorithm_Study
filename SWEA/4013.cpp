/*
  날짜 : 26.04.25.토
  문제 : SWEA 4013. [모의 SW 역량테스트] 특이한 자석
  풀이 시간 : 42분
  로직 : 시뮬레이션
  총평 : 백준에 있던 문제라 특별히 어렵진 않았음
*/

#include <bits/stdc++.h>
#define move _move
using namespace std;

vector<vector<int>> magnet(5, vector<int>(8));
int move[5];
int k;

int main() {
	int t; cin >> t;
	for(int _t=1; _t<=t; _t++){
	    cin >> k;
	    for(int i=1; i<=4; i++){
	        for(int j=0; j<8; j++){
	            cin >> magnet[i][j];
	        }
	    }
	    
	    for(int _k=0; _k<k; _k++){
	        int num, dir; cin >> num >> dir;
	        move[num] = dir;
	        for(int i=num+1; i<=4; i++){
	            if(magnet[i][6] != magnet[i-1][2]) move[i] = -move[i-1];
	            else move[i] = 0;
	        }
	        for(int i=num-1; i>=1; i--){
	            if(magnet[i][2] != magnet[i+1][6]) move[i] = -move[i+1];
	            else move[i] = 0;
	        }
	        
	        for(int i=1; i<=4; i++){
	            if(move[i] == 1){
	                rotate(magnet[i].rbegin(), magnet[i].rbegin()+1, magnet[i].rend());
	            }
	            else if(move[i] == -1){
	                rotate(magnet[i].begin(), magnet[i].begin()+1, magnet[i].end());
	            }
	        }
	    }
	    int ret = 0;
	    for(int i=1; i<=4; i++){
	        if(magnet[i][0]){
	            ret += 1<<(i-1);
	        }
	    }
	    cout << "#" << _t << " " << ret << "\n";
	}
    return 0;
}
