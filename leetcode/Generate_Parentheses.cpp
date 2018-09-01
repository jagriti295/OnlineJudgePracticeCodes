class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string v;
        vector<string> res;
        generateParenthesisUtil(n,0,v,0,0,res);
        return res;
    }
    void appendToVec(string v,vector<string>& res){
        /*string a="";
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            a+=v[i];
        }
        cout<<endl;*/
        res.push_back(v);
        //cout<<v<<endl;
    }
    void generateParenthesisUtil(int n,int open,string v,int ocount,int ccount,vector<string>& res){
        if(ocount==n && ccount==n){
            appendToVec(v,res);
            return;
        }
        //if(ocount>=n || ccount>=n)  return;
        if(ocount<n){
            v.push_back('(');
            generateParenthesisUtil(n,open+1,v,ocount+1,ccount,res);
            v.pop_back();
        }
       
        
        if(open>=1 && ccount<n){
            v.push_back(')');
            generateParenthesisUtil(n,open-1,v,ocount,ccount+1,res);
            v.pop_back();
        }
        
    }
};
