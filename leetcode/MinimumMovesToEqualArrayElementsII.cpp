class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long lsum=0,rsum=0,ans=1e18;
        //for(int i=0;i<n;i++)    cout<<nums[i]<<" ";
        //cout<<endl;
        for(int i=n-1;i>=0;i--){
            rsum = rsum + nums[i];
            //cout<<"**"<<rsum<<endl;
        }
        for(int i=0;i<n;i++){
            rsum = rsum - nums[i];
            //cout<<lsum<<" "<<rsum<<endl;
            //cout<<"----"<<i<<" "<<(long long)i*nums[i] - lsum<<" "<<rsum - (long long)(n-i-1)*nums[i]<<endl;
            ans = min(ans,abs((long long)i*nums[i] - lsum + rsum - (long long)(n-i-1)*nums[i]));
            lsum = lsum + nums[i];
        }
        return ans;
    }
};
