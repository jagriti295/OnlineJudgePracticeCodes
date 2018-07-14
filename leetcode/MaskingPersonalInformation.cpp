class Solution {
public:
    string maskPII(string S) {
        int n = S.length(),i;
        for(i=0;i<n;i++){
            if(S[i]=='@')   break;
        }
        if(i<n){
            string res;
            res.push_back((S[0]>=65&&S[0]<=90?S[0]+32:S[0]));
            for(int j=0;j<5;j++)    res.push_back('*');
            for(int j=i-1;j<n;j++)    res.push_back((S[j]>=65&&S[j]<=90?S[j]+32:S[j]));
            return res;
        }
        else{
            int cnt=0;
            for(i=0;i<n;i++){
                if(S[i]>=48 && S[i]<=57){
                    cnt++;
                }
            }
            string res;
            if(cnt>10){
                res.resize(cnt+4);
                res[0]='+';
                res[cnt-9]='-';
                res[cnt-5]='-';
                res[cnt-1]='-';
                int ind=cnt+3;
                for(int j=n-1;j>=0;j--){
                    if(S[j]>=48 && S[j]<=57){
                        if(ind>=cnt)
                            res[ind--]=S[j];
                        else{
                            while(res[ind]=='+' || res[ind]=='-')   ind--;
                            if(res[ind]!='+' && res[ind]!='-'){
                                res[ind--]='*';
                            }
                        }
                    }
                }
            }  
            else{
                res.resize(12);
                for(int j=0;j<3;j++)    res[j]='*';
                res[3]='-';
                for(int j=4;j<7;j++)    res[j]='*';
                res[7]='-';
                int ind=11;
                for(int j=n-1;j>=0;j--){
                    if(S[j]>=48 && S[j]<=57){
                        res[ind--]=S[j];
                        if(ind==7)  break;
                    }
                }
            }    
            return res;
        }
    }
};
