class Solution {
private:
    int arr[10];
    void init(){
        for(int i=1; i<=9; i++)arr[i] = 0;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            init();
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')continue;
                int a = board[i][j] - '0';
                if(++arr[a] > 1)return false;
            }
        }

        for(int j=0; j<9; j++){
            init();
            for(int i=0; i<9; i++){
                if(board[i][j] == '.')continue;
                int a = board[i][j] - '0';
                if(++arr[a] > 1)return false;
            }
        }

        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                init();
                for(int x=0; x<3; x++){
                    for(int y=0; y<3; y++){
                        if(board[i+x][j+y] == '.')continue;
                        int a = board[i+x][j+y] - '0';
                        if(++arr[a] > 1)return false;
                    }
                }
            }
        }

        return true;
    }
};
