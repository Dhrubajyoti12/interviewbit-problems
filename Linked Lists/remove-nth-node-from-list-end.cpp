/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using ln = ListNode;

int get_length(ln* node){
    int res=0;
    while(node)     ++res, node = node->next;
    return res;
}

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
   if(!head)   return NULL;
    
    int len = get_length(head);
    if(n > len)     n = len;
    int index = len - n;
    
    ln* newHead = new ln(-1270);
    newHead->next = head;
    ln* dummy = newHead;
    for(int i=0 ; i<index ; ++i)    dummy = dummy->next;
    
    ln* sil = dummy->next;
    dummy->next = dummy->next->next;
    delete sil;
    return newHead->next;
    
}
