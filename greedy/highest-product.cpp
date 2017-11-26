#include <iostream>
#include <algorithm>

using namespace std;

int maxp3(vector<int> &A) {
    sort(A.begin(), A.end());
    int size = A.size();
    // if A has a negative part, we take 2 negatives.
    return max(A[0]*A[1]*A[size-1], A[size-1]*A[size-2]*A[size-3]);
}

//driver.
int main(void){

	return 0;
}