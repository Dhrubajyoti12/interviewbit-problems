
string Solution::convertToTitle(int A) {
    string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans, rev;
    while(A){
        ans += table[(A-1)%26];
        A= (A-1)/26;
    }
    for(int i=ans.length()-1 ; i>-1 ; --i)
        rev+= ans[i];
    return rev;
}