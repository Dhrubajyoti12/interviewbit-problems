unsigned int Solution::reverse(unsigned int A) {
    unsigned int res=0;
    // we have 2 pointers, i and j. 
    // i traverses A from right to left as j traverses 
    // the result number from left to right
    for(int i=0,j=31 ; i<32 ; --j,++i)
        if(A&(1<<i))    res |= 1<<j;
    // whenever A's i'th bit from the right is 1
    // we flip res's i'th bit from the left to 1.
    //               ^ namely its j'th bit from the right.
    return res;
}
