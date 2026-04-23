/*
  날짜 : 26.04.23.목
  문제 : SWEA 1952. [모의 SW 역량테스트] 수영장
  풀이 시간 : 25분
  로직 : DP
  총평 : 쉬운 문제인듯
*/

#include <bits/stdc++.h>
using namespace std;

int arr[4], plan[12], dp[12];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	
	for(int _t=1; _t<=t; _t++){
	    memset(dp, 0, sizeof(dp));
	    for(int i=0; i<4; i++){
	        cin >> arr[i];
	    }
	    bool flag = false;
	    for(int i=0; i<12; i++){
	        cin >> plan[i];
	        if(plan[i])flag = true;
	    }
	    
	    if(!flag){
	        cout << "#" << _t << " " << 0 << "\n";
	        continue;
	    }
	    
	    dp[0] = min(plan[0] * arr[0], arr[1]);
	    dp[1] = dp[0] + min(plan[1] * arr[0], arr[1]);
	    dp[2] = dp[1] + min(plan[2] * arr[0], arr[1]);
	    dp[2] = min(dp[2], arr[2]);
	    
	    for(int i=3; i<12; i++){
	        dp[i] = dp[i-1] + min(plan[i] * arr[0], arr[1]);
	        dp[i] = min(dp[i], dp[i-3] + arr[2]);
	    }
	    dp[11] = min(dp[11], arr[3]);
	    
	    cout << "#" << _t << " " << dp[11] << "\n";
	}

}
