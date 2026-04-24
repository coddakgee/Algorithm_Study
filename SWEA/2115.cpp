/*
  날짜 : 26.04.24.금
  문제 : SWEA 2115. [모의 SW 역량테스트] 벌꿀채취
  풀이 시간 : 54분
  로직 : Brute Force + bitmasking
  총평 : 2차원 배열을 1차원 배열로 만들어서 관리했고, 2중 for문을 통해 간단히 조합을 구현할 수 있었다. 또한 비트마스킹을 통해 조합으로 구한 두 묶음에서 비교적 쉽게 최대 합을 구할 수 있었다. 
  최적화 해볼 것 : 이 코드에서는 2중 for문을 통해 i, j를 구하고 그때마다 find_max를 따로따로 구한다. 이렇게 되면 최대 O(n^2)의 시간복잡도가 걸릴 수 있으므로, 간단히 dp[100]을 만들어서 메모이제이션을 걸어주면
  시간을 획기적으로 줄일 수 있을 것이다. 이에 대한 내용은 Optimization/2115.cpp에 기록해두었다. 
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, c, rst;
int mp[100];

int find_max(int s){
    int ret = 0;
    for(int k=0; k<(1<<m); k++){
        int sum=0, tmp=0;
        
        for(int p=0; p<m; p++){
            if(k&(1<<p)){
                if(sum + mp[s+p] > c){
                    tmp = -1;
                    break;
                }
                
                tmp += (mp[s+p] * mp[s+p]);
                sum += mp[s+p];
            }
        }
        
        ret = max(ret, tmp);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	for(int _t=1; _t<=t; _t++){
	    rst = 0;
	    cin >> n >> m >> c;
	    for(int i=0; i<(n*n); i++){
	        cin >> mp[i];
	    }
	    
	    for(int i=0; i<(n*n); i++){
	        if((i%n) + (m-1) >= n)continue;
	        for(int j=i+m; j<(n*n); j++){
	            if((j%n) + (m-1) >= n)continue;
	            
	            int two_sum = find_max(i) + find_max(j);
	            
	            rst = max(rst, two_sum);
	        }
	    }
	    
	    cout << "#" << _t << " " << rst << "\n";
	}
    return 0;
}
