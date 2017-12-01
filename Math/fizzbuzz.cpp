vector<string> Solution::fizzBuzz(int A) {
    vector<string> ans;
    for(int i=1 ; i<=A ; ++i){
        string dummy = "";
        if(i%3 and i%5)     dummy=to_string(i);
        if(i%3==0)  dummy += "Fizz";
        if(i%5==0)  dummy += "Buzz";
        ans.push_back(dummy);
    }
    return ans;
}
