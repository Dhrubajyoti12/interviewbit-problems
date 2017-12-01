/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
inline void removeNext(ListNode* &cur){
    ListNode* ikiOn = cur->next->next;
    delete cur->next;
    cur->next = ikiOn;
}

ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode *cur = head;
    int cval, nval;
    while(cur->next!=NULL){
        cval = cur->val;
        nval = cur->next->val;
        if(cval == nval)    removeNext(cur);
        else                cur = cur->next;
    }
    
    return head;
}
