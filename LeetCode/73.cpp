/*
BEFORE, AFTER가 있다. 
BEFORE에서는 0인 좌표를 모두 저장했다가 마지막에 row, col을 모두 0으로 바꿔주는 코드고,
AFTER에서는 맨 앞 row, col에 그 정보를 저장하고, 1부터 순회하면서 채워주는 코드이다. 
*/

//BEFORE
class Solution {
private:
    int n, m;
    struct cordi{
        int y,x;
    };
    vector<cordi>v;

    void make_zeroes(int y, int x, vector<vector<int>>& k){
        for(int i=0; i<n; i++){
            k[i][x] = 0;
        }
        for(int j=0; j<m; j++){
            k[y][j] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0)v.push_back({i,j});
            }
        }

        for(auto a : v){
            make_zeroes(a.y, a.x, matrix);
        }
        return;
    }
};




//AFTER
class Solution {
private:
    int n, m;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        bool first_row_zero = false;
        bool first_col_zero = false;

        for(int i=0; i<m; i++){
            if(matrix[0][i] == 0){
                first_row_zero = true;
                break;
            }
        }

        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0){
                first_col_zero = true;
                break;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0, matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)matrix[i][j] = 0;
            }
        }

        if(first_row_zero){
            for(int i=0; i<m; i++)matrix[0][i] = 0;
        }

        if(first_col_zero){
            for(int i=0; i<n; i++)matrix[i][0] = 0;
        }
    }
};
