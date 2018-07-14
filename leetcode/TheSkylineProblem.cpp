#define pb push_back
#define mp make_pair
#define f first
#define s second

vector<int> arr;
vector<int> st(80000),lazy(80000);
vector<pair<int, int>> res;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        arr.clear();
        st.clear();
        st.resize(80000);
        lazy.clear();
        lazy.resize(80000);
        res.clear();
        int n=buildings.size(),l,r,val;
        for(int i=0;i<n;i++){
            arr.pb(buildings[i][0]);
            arr.pb(buildings[i][1]);
            arr.pb(buildings[i][1]-1);
        }
        sort(arr.begin(),arr.end());
        arr.resize(unique(arr.begin(),arr.end())-arr.begin());
        for(int i=0;i<n;i++){
            l=lower_bound(arr.begin(),arr.end(),buildings[i][0])-arr.begin();
            r=lower_bound(arr.begin(),arr.end(),buildings[i][1]-1)-arr.begin();
            val=buildings[i][2];
            updateMax(l,r,0,arr.size()-1,val,1);
            //printArr(4*arr.size());
        }
        for(int i=0;i<arr.size();i++){
            int h=getHeights(i,i,0,arr.size()-1,1);
            if(res.size()>0 && res[res.size()-1].s==h) continue;
            res.pb(mp(arr[i],h));
        }
        return res;
    }
    void printArr(int n){
        for(int i=1;i<n;i++){
            cout<<st[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<n;i++){
            cout<<lazy[i]<<" ";
        }
        cout<<endl;
    }
    
    void push(int id,int s,int e){
        //cout<<"hi "<<id<<" "<<st[id]<<" "<<lazy[id]<<endl;
        if(lazy[id]){
            if(s==e){
                st[id]=max(st[id],lazy[id]);
                lazy[id]=0;
            }
            else{
                st[id]=max(st[id],lazy[id]);
                lazy[2*id]=max(lazy[2*id],lazy[id]);
                lazy[2*id+1]=max(lazy[2*id+1],lazy[id]);
                //lazy[2*id]=lazy[2*id+1]=lazy[id];
                lazy[id]=0;
            }
        } 
    }
    
    void updateMax(int l,int r,int s,int e,int val,int id){
        if(s>e) return;
        push(id,s,e);
        if(l>e || r<s)  return;
        if(l<=s && e<=r){
            st[id]=max(st[id],val);
            if(s!=e){
                lazy[2*id]=max(lazy[2*id],val);
                lazy[2*id+1]=max(lazy[2*id+1],val);
            }
            return;
        }
        int m=(s+e)/2;
        updateMax(l,r,s,m,val,2*id);
        updateMax(l,r,m+1,e,val,2*id+1);
        st[id]=max(st[2*id],st[2*id+1]);
    }
    
    int getHeights(int l,int r,int s,int e,int id){
        if(s>e) return -1;
        push(id,s,e);
        if(l>e || r<s)  return -1;
        if(l<=s && e<=r)    return st[id];
        int m=(s+e)/2;
        return max(getHeights(l,r,s,m,2*id),getHeights(l,r,m+1,e,2*id+1));
    }
};
