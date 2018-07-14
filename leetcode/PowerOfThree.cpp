class Solution {
public:
    bool isPowerOfThree(int n) {
        double ans = log10(n)/log10(3);
        //cout<<log10(n)<<" "<<log10(3)<<endl;
        //cout<<ans<<endl;
        int cmp = ans;
        //cout<<cmp<<endl;
        if(cmp == ans)  return 1;
        return 0;
    }
};
