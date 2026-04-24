/*
  날짜 : 26.04.24.금
  최적화 포인트 : 이전 코드는 2중 루프로 돌면서 find_max를 그때그때 마다 다시 하고 있으므로, 최대 O(n^2)까지 더 걸릴 수 있는데,
  dp[100]을 하나 만들어서 memoization 하나만 걸어주면 거의 24배 이상 빨라질 수 있다. 중복된 계산은 항상 memoization 할 수 있는지 고려해보면 좋겠다.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, c, rst;
int mp[100], dp[100];

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
	    memset(dp, -1, sizeof(dp));
	    rst = 0;
	    cin >> n >> m >> c;
	    for(int i=0; i<(n*n); i++){
	        cin >> mp[i];
	    }
	    
	    for(int i=0; i<(n*n); i++){
	        if((i%n) + (m-1) >= n)continue;
	        for(int j=i+m; j<(n*n); j++){
	            if((j%n) + (m-1) >= n)continue;
	            
	            if(dp[i] == -1)dp[i] = find_max(i);
	            if(dp[j] == -1)dp[j] = find_max(j);
	            int two_sum = dp[i] + dp[j];
	            
	            rst = max(rst, two_sum);
	        }
	    }
	    
	    cout << "#" << _t << " " << rst << "\n";
	}
    return 0;
}
