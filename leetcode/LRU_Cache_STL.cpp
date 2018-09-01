class LRUCache {
    int capacity,size;
    list<pair<int,int> > dq;
    map<int,list<pair<int,int> >::iterator> m;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())    return -1;
        else{
            int v = m[key]->second;
            dq.erase(m[key]);
            dq.push_front(make_pair(key,v));
            m[key] = dq.begin();
            return v;
        }
    }
    
    void put(int key, int value) {
        if(dq.size()<=capacity && m.find(key)!=m.end()){
            dq.erase(m[key]);
            //size--;
        }
        else if(dq.size()==capacity){
            pair<int,int> p = dq.back();
            m.erase(p.first);
            dq.pop_back();
            //size--;
        }
        dq.push_front(make_pair(key,value));
        m[key] = dq.begin();
        //size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
