/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using ln = ListNode;

struct Compare{
	bool operator()(ln* &l, ln* &r){
		return l->val > r->val;
	}
};

ln* merge(int K, vector<ln*> &klist){
    priority_queue<ln*, vector<ln*>, Compare> pq;
	for(int i=0 ; i<K ; ++i) 	pq.push(klist[i]);

	ln *head = new ln(-12721);
	ln *iter = head; 
	while(pq.size()){
		ln* q = pq.top(); 	pq.pop();
		iter->next = q;
		iter = iter->next;
		q = q->next;
		if(q) 	pq.push(q);
	}
 	return head->next;

}

ListNode* Solution::mergeKLists(vector<ListNode*> &klist) {
    for(int i=0 ; i<klist.size() ; ++i){
        if(!klist[i]){
            klist[i] = klist.back();
            klist.pop_back();
        }
    }
    return merge(klist.size(), klist);
}
