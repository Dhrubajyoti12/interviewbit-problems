#define MOD 1000007

using u64 = unsigned long long int;

int Solution::coinchange2(vector<int> &coins, int N) {
	sort(coins.begin(), coins.end());

	int size = coins.size();
    vector<int> dyn(N+1, 0); 	dyn[0] = 1;
    for(int coin : coins){
    	for(int i=coin ; i<=N ; ++i){
    		dyn[i] = (dyn[i-coin] + dyn[i]) % MOD;
    	}
    }
    return dyn[N];
}