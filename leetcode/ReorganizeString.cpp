class Solution {
public:
    string reorganizeString(string S) {
        string res;
        vector<pair<int,int> > cnt(26,make_pair(0,0));
        int n = S.length(),i,j;
        for(i=0;i<n;i++){
            cnt[S[i]-97].first++;
            cnt[S[i]-97].second = S[i]-97;
        }
        for(i=0;i<26;i++){
            if(cnt[i].first>(n+1)/2)  return res;
        }
        sort(cnt.begin(),cnt.end());
        res.resize(n);
        j = 0;
        for(i=25;i>=0;i--){
            while(cnt[i].first){
                res[j] = cnt[i].second+97;
                j+=2;
                if(j>=n)    j=1;
                cnt[i].first--;
            }
        }
        return res;
    }
};
