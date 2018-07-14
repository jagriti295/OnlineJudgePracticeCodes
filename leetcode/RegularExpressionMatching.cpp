class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.length()==0 && p.length()==0)  return 1;
        vector<vector<int> > dp(p.length()+1,vector<int>(s.length()+1,-1));
        return backtracking(s,p,0,0,s.length(),p.length(),dp);
    }
    bool isValid(string p,int i,int n){
        for(int k = i;k<n;k++){
            if(k==n-1 && p[k]!='*')  return 0;
            if(k<n-1 && p[k]!='*' && p[k+1]!='*')   return 0;
        }
        return 1;
    }
    bool backtracking(string s,string p,int i,int j,int m,int n,vector<vector<int> >& dp){
        if(dp[i][j]!=-1)   return dp[i][j]; 
        if(i==n && j==m)    return (dp[i][j] = 1);
        if(j==m && i<n-1 && isValid(p,i,n))    return (dp[i][j] = 1);
        if(i==n || j==m)    return (dp[i][j] = 0);
        if(i<n-1 && p[i]=='.' && p[i+1]=='*'){
            dp[i][j] = (backtracking(s,p,i,j+1,m,n,dp) || backtracking(s,p,i+2,j,m,n,dp));
        }   
        else if(i<n-1 && p[i]!='.' && p[i+1]=='*'){
            if(p[i]==s[j])  return (dp[i][j] = (backtracking(s,p,i,j+1,m,n,dp) || backtracking(s,p,i+2,j,m,n,dp)));
            else    return (dp[i][j] = backtracking(s,p,i+2,j,m,n,dp));
        }
        else if((i<n-1 && p[i]=='.' && p[i+1]!='*') || (i==n-1 && p[i]=='.'))  return (dp[i][j] = backtracking(s,p,i+1,j+1,m,n,dp));
        else if(p[i]!='.'){
            if(p[i]==s[j])  return (dp[i][j] = backtracking(s,p,i+1,j+1,m,n,dp));
            else    return (dp[i][j] = 0);
        }
        return dp[i][j];
    }
};
