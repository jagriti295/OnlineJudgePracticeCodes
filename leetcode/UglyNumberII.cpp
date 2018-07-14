class Solution {
public:
    int nthUglyNumber(int n) {
        long long tmp;
        set<int> sets;
        priority_queue<long long> pq;
        pq.push(-1);
        sets.insert(-1);
        for(int i=0;i<n;i++){
            tmp=pq.top();
            pq.pop();
            //cout<<tmp<<" ";
            if(sets.find(2*tmp)==sets.end()){
                pq.push(2*tmp);
                sets.insert(2*tmp);
            }
            if(sets.find(3*tmp)==sets.end()){
                pq.push(3*tmp);
                sets.insert(3*tmp);
            }
            if(sets.find(5*tmp)==sets.end()){
                pq.push(5*tmp);
                sets.insert(5*tmp);
            }
            //pq.push(3*tmp);
            //pq.push(5*tmp);
        }
        //cout<<endl;
        return -tmp;
    }
};
