/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// sayilar ters

// 1 2 3
// 1 0 0 1
// 2 2 3 1

ListNode* helpMe_NIGGA(ListNode* uzun, ListNode* kisa, int maxLen){
    ListNode* res = new ListNode(0);
    ListNode* cur = res;
    for(int i=1 ; i<maxLen ; ++i){
        cur->next = new ListNode(0);
        cur = cur->next;
    }
    
    ListNode *pu=uzun, *pk=kisa;
    
    cur=res;// kasapca topla, be italian
    while(pu or pk){
        if(pu)      cur->val += pu->val,  pu = pu->next;
        if(pk)      cur->val += pk->val,  pk = pk->next;
        cur = cur->next;
    }
    
    cur=res;// toplami duzle.
    while(cur->next!=NULL){
        cur->next->val += cur->val/10;
        cur->val = cur->val%10;
        cur = cur->next;
    }
    
    if(cur->val > 9){
        cur->next = new ListNode(cur->val/10);
        cur->val = cur->val%10;
    }
    
    return res;
}

ListNode* Solution::addTwoNumbers(ListNode* top, ListNode* btm) {
    int lenTop=0, lenBtm=0;
    ListNode *ctop=top, *cbtm=btm;
    
    while(ctop!=NULL){
        ctop = ctop->next;
        ++lenTop;
    }// we have top's len
    while(cbtm!=NULL){
        cbtm = cbtm->next;
        ++lenBtm;
    }// we have btm's len SURPRIZE.
    if(lenTop>lenBtm)   return helpMe_NIGGA(top, btm, lenTop);
    else                return helpMe_NIGGA(btm, top, lenBtm);
    
}
