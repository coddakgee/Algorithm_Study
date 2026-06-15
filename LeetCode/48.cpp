//90도 회전은 어떻게 하냐. BEFORE, AFTER를 만들었다. 

//BEFORE 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n/2; i++){
            for(int j=i; j<(n-1-i); j++){
                int tmp = matrix[i][j];
                int cnt = 0;
                int pi = i, pj = j; //prev
                int ni = n-1-pj, nj = pi; //next
                while(cnt<3){
                    matrix[pi][pj] = matrix[ni][nj];
                    pi = ni, pj = nj;
                    ni = n-1-pj, nj = pi;
                    cnt+=1;
                }
                matrix[pi][pj] = tmp;
            }
        }
    }
};

//AFTER 
//-> 시계 90도 : 전치 + 좌우반전
//-> 반시계 90도 : 전치 + 상하반전

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
