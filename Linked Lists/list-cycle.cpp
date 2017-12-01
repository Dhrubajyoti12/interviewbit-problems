/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *hizli=A,*yavas=A;
    int loopvar=0;
    while(hizli!=NULL and yavas!=NULL and yavas->next!=NULL){
        hizli = hizli->next;
        yavas = yavas->next->next;
        if(hizli == yavas && ++loopvar)     break;
    }
    if(!loopvar)    return NULL;
    yavas=A;
    while(hizli!=yavas){
        hizli=hizli->next;
        yavas=yavas->next;
    }
    return yavas;
}