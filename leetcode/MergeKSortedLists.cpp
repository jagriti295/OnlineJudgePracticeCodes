/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define f first
#define s second

struct myCom{
    bool operator()(pair<ListNode*,int>& a,pair<ListNode*,int>& b){
        if((a.f)->val>(b.f)->val)   return 1;
        return 0;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //vector<ListNode*> lis(lists);
        ListNode* res=NULL,*last;
        pair<ListNode*,int> p;
        int k = lists.size(),i;
        priority_queue<pair<ListNode*,int>,vector<pair<ListNode*,int> >,myCom > pq;
        for(i=0;i<k;i++){
            if(!lists[i]) continue;
            pq.push({lists[i],i});
            lists[i]=lists[i]->next;
        }
        while(!pq.empty()){
            p=pq.top();
            pq.pop();
            //cout<<(p.f)->val<<" "<<p.s<<endl;
            if(!res){
                res=p.f;
                last=res;
            }
            else{
                last->next=p.f;
                last=last->next;
            }
            if(lists[p.s]){
                pq.push({lists[p.s],p.s});
                lists[p.s]=lists[p.s]->next;
            }    
            
        }
        /*while(lists[2]){
            cout<<lists[2]->val<<" ";
            lists[2]=lists[2]->next;
        }
        cout<<endl;*/
        return res;
    }
};
