#include <iostream>
#include <vector>
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