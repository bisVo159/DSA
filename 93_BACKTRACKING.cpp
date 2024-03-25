#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row,int col,vector<vector<int>>&board,int value){
    for(int i=0;i<board.size();i++){
        //row check
        if(board[row][i]==value)
            return false;
        //column check
        if(board[i][col]==value)
            return false;
            //3*3 matrix check
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==value)
            return false;
        }
        return true;
    }

bool solve(vector<vector<int>>&board){
    int n=board[0].size();
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            //cell empty
            if(board[row][col]==0){
                for(int val=1;val<=n;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col]=val;
                        //recurrsive call
                        bool aageSolutionPossible=solve(board);
                        if(aageSolutionPossible)
                        return true;
                        else{
                            //backtrack
                            board[row][col]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solveSudoku(vector<vector<int>>&sudoku){
    solve(sudoku);
    return sudoku;
}

int main(){
    // ----->SUDOKU SOLVER<-----
    vector<vector<int>>sudoku={{7,0,9,0,0,0,0,6,4},
                                                    {0,0,0,0,0,1,3,0,0},
                                                    {3,4,0,9,0,0,0,0,0},
                                                    {0,5,0,0,0,9,0,1,3},
                                                    {0,0,7,4,0,0,0,0,0},
                                                    {0,0,0,6,0,5,4,2,0},
                                                    {4,2,0,5,9,0,6,8,1},
                                                    {0,0,6,1,2,0,0,0,0},
                                                    {5,7,1,8,3,0,9,4,0}};
    vector<vector<int>>ans=solveSudoku(sudoku);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}