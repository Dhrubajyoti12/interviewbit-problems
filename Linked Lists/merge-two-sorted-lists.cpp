/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using ln = ListNode;

ListNode* Solution::mergeTwoLists(ListNode* ust, ListNode* alt) {
    ln *jevap = new ln(-1270);
    ln *dummy = jevap;
    while(ust or alt){
        if(!ust or (alt and alt->val < ust->val)){
            dummy->next = alt;
            alt = alt->next;
        } else{
            dummy->next = ust;
            ust = ust->next;
        }
        dummy = dummy->next;
        dummy->next = NULL;
    }
    return jevap->next;
    
    
}