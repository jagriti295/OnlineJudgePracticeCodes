class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)  return s;
        string rs;
        int elems = 2*numRows-2;
        int cols,n=s.length();
        int i,j,ind=0,pind,fac = 1+numRows-2;
        cols = fac*(n/elems);
        int cnt=0;
        //cout<<"***"<<n/elems<<" "<<n<<" "<<elems<<endl;
        for(i=0;i<numRows;i++){
            ind = i;
            for(j=0;j<=n/elems;j++){
                //cout<<ind<<endl;
                if(i==0 || i==numRows-1){
                    //cout<<"hi"<<endl;
                    if(ind>=n)  continue;
                    //cout<<s[ind];
                    rs.push_back(s[ind]);
                    ind+=elems;
                }
                else{
                    //cout<<"hey"<<endl;
                    if(ind>=n)  continue;
                    //cout<<s[ind];
                    rs.push_back(s[ind]);
                    //cout<<"bye"<<endl;
                    //cout<<ind + 2*(numRows-i-1)<<endl;
                    if(ind + 2*(numRows-i-1)>=n)  continue;
                    rs.push_back(s[ind + 2*(numRows-i-1)]);
                    
                    //cout<<s[ind + 2*(numRows-i-1)];
                    ind+=elems;
                }
            }
        }
        return rs;
    }
};
