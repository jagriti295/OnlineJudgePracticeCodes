class Solution {
public:
    int jump(vector<int>& nums) {
        int i,n,j,ind=1;
        n = nums.size();
        vector<int> jumps(n,-1);
        jumps[0] = 0;
        for(i=0;i<n-1;i++){
            for(;ind<n && ind<=nums[i]+i;ind++){
                jumps[ind] = jumps[i] + 1;
            }
        }
        if(jumps[i]==-1)   return -1;
        return jumps[n-1];
    }
};
