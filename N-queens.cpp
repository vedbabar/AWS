#include<bits/stdc++.h>
using namespace std;

int N;
vector<vector<string>>ans;
bool valid(int row,int col,vector<string>&board){
    // check attack from top left diag
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q') return false;
    }
    // check attack from top right diag
    for(int i=row-1,j=col+1;i>=0 && j<N;i--,j++){
        if(board[i][j]=='Q') return false;
    }
    // check attack from top
    for(int i=row-1;i>=0;i--){
        if(board[i][col]=='Q') return false;
    }
    return true;
}
void solve(int row,vector<string>board){
    if(row>=N){
        ans.push_back(board);
        return;
    }
    // for the current row, try placing the queen in all columns and check if it is safe to place the queen there or not
    for(int col=0;col<N;col++){
        if(valid(row,col,board)){
            board[row][col]='Q';
            solve(row+1,board);
            board[row][col]='.';
        }
    }

}

int main(){
    int n;
    cout<<"Enter the size of the board: ";
    cin>>n;
    N=n;
    vector<string>board(n,string(n,'.'));
    // output all possible boards, for a given input n
    // we can use backtracking to solve this problem
    solve(0,board);
    cout<<"Total number of solutions: "<<ans.size()<<endl;
    for(auto &board:ans){
        for(auto &row:board){
            cout<<row<<endl;
        }
        cout<<endl;
        cout<<endl;
    }
}