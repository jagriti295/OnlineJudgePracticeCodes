class LLNode {
    //private:
    
    public:
    LLNode* next;
    int key, val;
    LLNode(int key, int val){
        this->next = NULL;
        this->key = key;
        this->val = val;
    }
};

class LL {
    public:
    LLNode* head;
    LL(){
        head = NULL;
    }
    
    LL(LLNode* head){
        this->head = head;
        //cout<<head<<" "<<head->val<<endl;
    }
    
    /*assignLLHead(LLNode* head){
        this->head = head;
    }*/
    
    void pushToFront(LLNode* node){
        if(!node)   return;
        node->next = head;
        head = node;
    }
    
    void deleteNode(LLNode* node){
        if(!node)   return; //error message or something
        LLNode* runner = head,*prev=NULL;
        /*cout<<"In delete node"<<endl;
        if(head)    cout<<head<<" "<<head->val<<endl;*/
        while(runner && runner!=node){
            prev=runner;
            runner=runner->next;
        }
        if(!runner)    return;  //message - not found
        else if(!prev){
            head = runner->next;
            delete runner;
        }
        else{
            prev->next = runner->next;
            delete runner;
        }
    }
    
    LLNode* getLastNode(){
        if(!head)   return NULL;
        /*cout<<"In get last node"<<endl;
        if(head)    cout<<head<<" "<<head->val<<endl;*/
        LLNode* node = head;
        while(node->next){
            //cout<<node->val<<" "<<node->next->val<<endl;
            node = node->next;
        }
        return node;
    }
    
    void deleteLastNode(){
        if(!head)   return;
        /*cout<<"In delete last node"<<endl;
        if(head)    cout<<head<<" "<<head->val<<endl;*/
        LLNode* node = head,*prev=NULL;
        while(node->next){
            prev = node;
            node = node->next;
        }
        if(node == head){
            head = NULL;
            delete node;
        }
        else{
            prev->next = NULL;
            delete node;
        }
    }
    
    void printList(){
        LLNode* node = head;
        while(node){
            cout<<node->val<<" ";
            node = node->next;
        }
        cout<<endl;
    }
    
};

class LRUCache {
    private:
    int capacity;
    int size;
    LL dq;
    map<int,LLNode*> m;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        dq.head = NULL;
    }
    
    int get(int key) {
        /*cout<<"In get"<<endl;
        if(dq.head)    cout<<dq.head<<" "<<(dq.head)->val<<endl;*/
        if(m.find(key)==m.end())    return -1;
        else {
            //cout<<(m[key])->val<<endl;
            LLNode* node = m[key];
            LLNode* node1 = new LLNode(key,node->val);
            dq.deleteNode(node);
            dq.pushToFront(node1);
            m[key] = node1;
            /*cout<<"In get 1"<<endl;
            if(dq.head)    cout<<dq.head<<" "<<(dq.head)->val<<endl;*/
            //dq.printList();
            /*cout<<"^^"<<size<<endl;
            cout << (m[key])->val <<endl;*/
            return (m[key])->val;
        }
    }
    
    void put(int key, int value) {
        //cout<<"ummm"<<endl;
        if(size<capacity && m.find(key)==m.end()){
            LLNode* node = new LLNode(key,value);
            dq.pushToFront(node);
            m[key] = node;
            size++;
            //cout << size <<endl;
        }
        else if(size<=capacity && m.find(key)!=m.end()){
            LLNode* node = m[key];
            LLNode* node1 = new LLNode(key,value);
            dq.deleteNode(node);
            dq.pushToFront(node1);
            m[key] = node1;
            //cout << size <<endl;
        }
        else{
            //cout<<"yay"<<endl;
            LLNode* lnode = dq.getLastNode();
            dq.deleteNode(lnode);
            m.erase(lnode->key);
            LLNode* node = new LLNode(key,value);
            dq.pushToFront(node);
            m[key] = node;
            //cout << size <<endl;
        }
        /*cout<<"In put"<<endl;
        if(dq.head)    cout<<dq.head<<" "<<(dq.head)->val<<endl;*/
        //dq.printList();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
