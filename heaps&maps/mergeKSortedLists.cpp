#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
using ln = ListNode;

struct Compare{
	bool operator()(ln* &l, ln* &r){
		return l->val > r->val;
	}
};


vector<ln*> klist;
int K;

void get_input(){
	int q; cin>>K;
	ln *head;

	for(int i=0 ; i<K ; ++i){
		cin>>q;
		head = new ln(0);
		ln* dummy = head;
		while(q!=-1){
			dummy->next = new ln(0);
			dummy = dummy->next;
			dummy->val = q;
			cin >> q;
		}
		klist.push_back(head->next);
	}
}

void printList(ln* q){
	if(!q) 	return;
	cout<<q->val;
	q = q->next;
	while(q){
		cout<<"-->"<<q->val;
		q = q->next;
	}
	cout<<endl;
}

ln* merge(){
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
	printList(head);
 	return head->next;
}


int main(){
	get_input();
	merge();

}