/*
  날짜 : 26.04.26.일
  문제 : SWEA 4014. [모의 SW 역량테스트] 활주로 건설
  풀이 시간 : 46분
  로직 : 시뮬레이션
  총평 : 음.. 예전 기출이라 그런가 좀 쉽게 풀린다. B형 대비도 슬슬 시작해 봐야겠다. 최적화의 꽃.
*/

#include<iostream>
using namespace std;

int mp[20][20];
int n, x;

void flip(){
	int tmp[20][20];
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
            tmp[j][i] = mp[i][j];
        }
    }
    
     for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
            mp[i][j] = tmp[i][j];
        }
    }
    return;
}

bool can_airstrip(int s){
    int prev = mp[s][0];
    int cnt = 1;
    
 	 for(int i=1; i<n; i++){
          if(mp[s][i] == prev){
              cnt++;
          }
         else if(mp[s][i] < prev){
             if(prev - mp[s][i] > 1)return false;
             if(cnt < 0)return false;
             cnt = -x+1;
             prev = mp[s][i];
         }
         else{
             if(mp[s][i] - prev > 1)return false;
             if(cnt < x)return false;
             cnt = 1;
             prev = mp[s][i];
         }
     }
    if(cnt < 0)return false;
    return true;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int ret = 0;
        cin >> n >> x;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> mp[i][j];
            }
        }
        
        for(int i=0; i<n; i++){
            if(can_airstrip(i)){
                ret++;
            }
        }
        
        flip();
        
        
        for(int i=0; i<n; i++){
            if(can_airstrip(i)){
                ret++;
            }
        }
		

	cout << "#" << test_case << " " << ret << "\n";
	}
	return 0;
}
