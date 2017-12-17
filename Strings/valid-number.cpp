#define INVALID -1270

// Returns true iff q[i] is plus or minus
bool pm(const string &q, int i){
	return i < q.size() and (q[i]=='+' or q[i]=='-');
}

// Returns true iff q[i] is a digit
bool digit(const string &q, int i){
	return  '0'<=q[i] and q[i]<='9'; 
}

// Iterates over the adjacent digits from q[i].
// Returns the first non-digit index. May return q.size()
// Return INVALID if q[i] is not a digit.
int digits(const string &q, int i){
	int size = q.size();
	// invalid cases
	if( !(i<size and digit(q, i)) ) 	return INVALID;
	// iterate over digits
	while(digit(q, i) and i<size) 	++i;
	
	return i;
}

// Returns invalid if there is no decimal from q[i].
// Returns the first non-decimal index.
int decimals(const string &q, int i){
	if(pm(q, i)) 	++i;
	int size = q.size();
	if( !(i<size and q[i] == '.') ) 	return INVALID;
	return digits(q, i+1);
}

// Returns the first non-integer index.
int integer(const string &q, int i){
	if(pm(q, i)) 	++i;
	return digits(q, i);
}

// Returns the first non-floating index.
int floating(const string &q, int i){
	int new_index = integer(q, i);
	if(new_index == INVALID) 	return INVALID;
	return decimals(q, new_index);
}

// Returns the first non numeric index.
int num(const string &q, int i){
	int index_decimals = decimals(q, i);
	int index_floating = floating(q, i);
	int index_integer = integer(q, i);
	// Return invalid if q doesn't contain a number from q[i]
	if ( index_decimals == INVALID 
	 and index_floating == INVALID 
	 and index_integer == INVALID)
		return INVALID;

	if(index_decimals != INVALID) 	return index_decimals;
	if(index_floating != INVALID) 	return index_floating;
	
	return index_integer;
}

// Strips white spaces from both ends of string.
string strip(const string &A){
	int size = A.size();
	int lo = 0, hi = size-1;
	while(A[lo]==' ' and lo<size) 	++lo;
	while(A[hi]==' ' and hi>-1) 	--hi;

	string res;
	while(lo <= hi){
		res.push_back(A[lo++]);
	}

	return res;
}

int Solution::isNumber(const string &raw) {
	string A = strip(raw);

	int index_num = num(A, 0);
	// chech if its a whole number or invalid
	if(index_num == INVALID) 	return 0;
	if(index_num == A.size()) 	return 1;

	// its either exponential or INVALID
	if(A[index_num] != 'e') 	return 0;
	int index_integer = integer(A, index_num+1);
	if(index_integer == INVALID) 	return 0;
	if(index_integer == A.size()) 	return 1;
	
	// else it has more invalid characters
	return 0;

}

/*
			CFG FOR A VALID NUMBER

{valid}    -->		{num} | {num}e{integer}
{num} 	   --> 		{integer} | {floating} | {decimals} 

{floating} -->  	{integer}{decimals}
{integer}  -->      {pm}{digits}
{decimals} -->  	{pm}.{digits}

{digits}   -->  	{digit}NULL | {digit}{digits}
{digit}    -->  	0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 
{pm} 	   -->  	+ | - | NULL
*/
