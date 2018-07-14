class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int cx,dy;
        vector<vector<int> > grid(N,vector<int>(N,1));
        vector<vector<int> > l(N,vector<int>(N,N)), r(N,vector<int>(N,-1)), t(N,vector<int>(N,N)), b(N,vector<int>(N,-1));
        for(int i=0;i<mines.size();i++){
            cx = mines[i][0];
            dy = mines[i][1];
            grid[cx][dy]=0;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]){
                    if(i>0)
                        t[i][j]=min(i,t[i-1][j]);
                    else    t[i][j]=0;
                    if(j>0)
                        l[i][j]=min(j,l[i][j-1]);
                    else    l[i][j]=0;
                }
            }
        }
        for(int i=N-1;i>=0;i--){
            for(int j=N-1;j>=0;j--){
                if(grid[i][j]){
                    if(i!=N-1)
                        b[i][j]=max(i,b[i+1][j]);
                    else    b[i][j]=N-1;
                    if(j!=N-1)
                        r[i][j]=max(j,r[i][j+1]);
                    else    r[i][j]=N-1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]){
                    ans=max(ans,min(i-t[i][j]+1,min(j-l[i][j]+1,min(r[i][j]-j+1,b[i][j]-i+1))));
                    //cout<<j-l[i][j]+1<<" "<<r[i][j]-j+1<<" "<<i-t[i][j]+1<<" "<<b[i][j]-i+1<<endl;
                    //cout<<"***"<<ans<<endl;
                }
            }
        }
        return ans;
        //return -1;
    }
};
