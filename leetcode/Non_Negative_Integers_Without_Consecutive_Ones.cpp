class Solution {
public:
    int findIntegers(int num) {
        int count = 0,i,k;
        int dp[33][2]={0};
        bool equal = true;
        for(i=31;i>=0;i--){
            if(num>>i & 1)  break;
        }
        k = i;
        for(i=30;i>=0;i--){
            if((num>>i & 1) && (num>>(i+1) & 1)) break;
        }
        int j = i;
        
        //findIntegersUtil(num,count,small,i,0);
        dp[k+1][0] = 1;
        for(i=k;i>=0;i--){
            dp[i][0] = dp[i+1][0] + dp[i+1][1];
            if(i>j && !(num>>i&1) && !(num>>(i+1)&1)){
                dp[i][1] = max(dp[i+1][0]-1,0);
            } //dp[i][1] = max(dp[i+1][0]-1,0);
            else    dp[i][1] = dp[i+1][0];
        }
        return dp[0][0]+dp[0][1];
    }
    
    /*void findIntegersUtil(int num,int& count,bool small,int i,int last){
        if(i == -1){
            count++;
            return;
        }
        if(!(num>>i & 1)){
            if(!small)  findIntegersUtil(num,count,small,i-1,0);
            else{
                findIntegersUtil(num,count,small,i-1,0);
                if(!last)   findIntegersUtil(num,count,small,i-1,1);
            }
        }
        else if(num>>i & 1){
            if(!last)   findIntegersUtil(num,count,small,i-1,1);
            findIntegersUtil(num,count,true,i-1,0);
        }
    }*/
    
};
