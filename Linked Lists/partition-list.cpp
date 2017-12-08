/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using LN = ListNode;

ListNode* Solution::partition(ListNode* list, int pivot) {
	LN* sml = new LN(-1270); // sml for list with small elements
	LN* big = new LN(-1270); // big for list with small elements

	LN* iter_sml = sml;  // iterator for small list
	LN* iter_big = big;  // iterator for big list
	LN* iter_org = list; // iterator for original list

	while(iter_org){
		if(iter_org->val < pivot){
			iter_sml->next = new LN(iter_org->val);
			iter_sml = iter_sml->next;
		}
		else{
			iter_big->next = new LN(iter_org->val);
			iter_big = iter_big->next;
		}
		iter_org = iter_org->next;
	}
	iter_sml->next = big->next;
	return sml->next;
}
