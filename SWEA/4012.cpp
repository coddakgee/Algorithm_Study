/*
  날짜 : 26.04.22.수
  문제 : SWEA 4012. [모의 SW 역량테스트] 요리사
  풀이 시간 : 40분
  로직 : 조합, 백트래킹
  총평 : 그렇게 어렵지 않은 문제였음. 
  비트마스킹을 쓸 까 고민해봤는데, nCk의 조합을 구하는 문제에 2^n의 시간복잡도를 쓰면 비효율적이라 여겼기에 그냥 재귀함수로 구현함. 
  후에 복습하는 과정에서 Gosper's hack을 추가로 공부해봄. 
  Gosper's hack을 사용한 코드는 Algorithm/Optimization 에 저장함. 
*/

#include <bits/stdc++.h>
using namespace std;

int n;
int s[17][17];
int arr[17];
vector<int>v1, v2;
int sum1, sum2;
int ret;

int calcu(){
    v1.clear();
    v2.clear();
    sum1 = 0, sum2 = 0;
    for(int i=1; i<=n; i++){
        if(arr[i])v1.push_back(i);
        else v2.push_back(i);
    }
    
    for(int i=0; i<v1.size(); i++){
        for(int j=i+1; j<v1.size(); j++){
            int a = v1[i], b = v1[j];
            sum1 += s[a][b] + s[b][a];
        }
    }
    
    for(int i=0; i<v2.size(); i++){
        for(int j=i+1; j<v2.size(); j++){
            int a = v2[i], b = v2[j];
            sum2 += s[a][b] + s[b][a];
        }
    }
    
    return (int)abs(sum1 - sum2);
}

void combi(int cnt, int go){
    if(cnt == n/2){
        ret = min(ret, calcu());
        return;
    }
    
    for(int i=go+1; i<=n; i++){
        arr[i] = 1;
        combi(cnt+1, i);
        arr[i] = 0;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	
	for(int _t=1; _t<=t; _t++){
	    memset(arr, 0, sizeof(arr));
	    ret = 1e9;
	    cin >> n;
	    
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=n; j++){
	            cin >> s[i][j];
	        }
	    }
	    
	    combi(0, 0);
	    
	    cout << "#" << _t << " " << ret << "\n";
	}
    return 0;
}
