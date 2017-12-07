using LN = ListNode;

class Solution{

  public:
  	ListNode* swapPairs(ListNode* head);
};

LN* _swap(LN* left){
	if(!left or !(left->next)) 	return left;

	LN* right = left->next;
	left->next = right->next;
	right->next = left;
	return right;
}

LN* Solution::swapPairs(LN* head){
	LN* root = new LN(-1270);
	root->next = head;
	
	LN* iter = root;
	while(iter){
		iter->next = _swap(iter->next);
		iter = iter->next;
		// iter may be null here.
		if(iter) 	iter = iter->next;
	}
	return root->next;
}