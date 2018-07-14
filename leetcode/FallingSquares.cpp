#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define pb push_back

vector<int> arr;
vector<int> res,st(8000),lazy(8000);

class Solution {
public:
    
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        res.clear();
        st.clear();
        st.resize(8000);
        lazy.clear();
        lazy.resize(8000);
        arr.clear();
        int n=positions.size();
        int l,r,val,mx=0;
        for(int i=0;i<n;i++){
            arr.pb(positions[i].f);
            arr.pb(positions[i].f+positions[i].s-1);
        }
        sort(arr.begin(),arr.end());
        arr.resize(unique(arr.begin(),arr.end())-arr.begin());
        for(int i=0;i<arr.size();i++){
            //cout<<arr[i]<<endl;
        }
        for(int i=0;i<n;i++){
            l=lower_bound(arr.begin(),arr.end(),positions[i].f)-arr.begin();
            r=lower_bound(arr.begin(),arr.end(),positions[i].f+positions[i].s-1)-arr.begin();
            //cout<<l<<" "<<r<<endl;
            val=getMax(l,r,0,2*n-1,1);
            //cout<<val<<endl;
            val+=positions[i].s;
            update(l,r,0,2*n-1,1,val);
            mx=max(mx,val);
            //cout<<mx<<endl;
            //printArr(2*n);
            res.pb(mx);
        }
        return res;
    }
    
    void printArr(int n){
        cout<<n<<endl;
        for(int i=1;i<2*n;i++)  cout<<st[i]<<" ";
        cout<<endl;
        for(int i=1;i<2*n;i++)  cout<<lazy[i]<<" ";
        cout<<endl;
    }
    
    void push(int id){
        st[id]=lazy[id];
        lazy[2*id]=lazy[2*id+1]=lazy[id];
        lazy[id]=0;
    }
    
    int getMax(int l,int r,int s,int e,int id){
        if(lazy[id] && s==e){
            st[id]=lazy[id];
            lazy[id]=0;
        }
        else if(lazy[id])   push(id);
        if(s>e || r<s || l>e)   return 0;
        if(l<=s && e<=r)    return st[id];
        int m=(s+e)/2;
        return max(getMax(l,r,s,m,2*id),getMax(l,r,m+1,e,2*id+1));
    }
    
    void update(int l,int r,int s,int e,int id,int val){
        if(lazy[id] && s==e){
            st[id]=lazy[id];
            lazy[id]=0;
        }
        else if(lazy[id])   push(id);
        if(s>e || r<s || l>e)   return;
        if(l<=s && e<=r){
            st[id]=val;
            if(s!=e){
                lazy[2*id]=val;
                lazy[2*id+1]=val;
            }
            return;
        }
        int m=(s+e)/2;
        update(l,r,s,m,2*id,val);
        update(l,r,m+1,e,2*id+1,val);
        st[id]=max(st[2*id],st[2*id+1]);
    }
    
};
