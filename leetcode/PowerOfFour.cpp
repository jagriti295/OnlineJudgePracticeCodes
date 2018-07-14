class Solution {
public:
    bool isPowerOfFour(int n) {
        double ans = log10(n)/log10(4);
        //cout<<log10(n)<<" "<<log10(3)<<endl;
        //cout<<ans<<endl;
        int cmp = ans;
        //cout<<cmp<<endl;
        if(cmp == ans)  return 1;
        return 0;
    }
};
