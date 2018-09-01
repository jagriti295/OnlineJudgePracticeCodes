class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //string s;
        vector<string> board(n,string(n,'.'));
        vector<vector<string> > res;
        //printBoard(board,n,res);
        solveNQueensUtil(n,board,res,0);
        return res;
    }
    
    void printBoard(vector<string>& board,int n,vector<vector<string> >& res){
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }*/
        res.push_back(board);
    }
    
    bool horizontal(vector<string>& board,int p,int q){
        for(int j=q-1;j>=0;j--){
            if(board[p][j]=='Q')    return true;
        }
        return false;
    }
    
    bool vertical(vector<string>& board,int p,int q){
        for(int i=p-1;i>=0;i--){
            if(board[i][q]=='Q')    return true;
        }
        return false;
    }
    
    bool diagonal(vector<string>& board,int p,int q,int n){
        int i=p-1,j=q-1;
        for(int i=p-1,j=q-1;i>=0 && j>=0;--i,--j){
            if(board[i][j]=='Q')    return true;
        }
        for(int i=p-1,j=q+1;i>=0 && j<n;--i,++j){
            if(board[i][j]=='Q')    return true;
        }
        return false;
    }
    
    void solveNQueensUtil(int n,vector<string>& board,vector<vector<string> >& res,int p){
        if(p==n){
            printBoard(board,n,res);
            return;
        }
        for(int q=0;q<n;q++){
            if(!horizontal(board,p,q) && !vertical(board,p,q) && !diagonal(board,p,q,n)){
                board[p][q]='Q';
                solveNQueensUtil(n,board,res,p+1);
                board[p][q]='.';
            }
        }
    }
};
