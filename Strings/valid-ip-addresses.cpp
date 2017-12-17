#define BLOCK_NUMBER 4
#define MAX_BLOCK_SIZE 3

// size will always be in range [1,3]
bool valid(const string &block){
	// if block starts with zero, it must be the only element in block
	if(block[0]=='0') 	return block.size() == 1;
	
	int num = stof(block);
	return num < 256;
}

//                     inp: input string |  rem: remaining parts
vector<string> restore(const string &inp, int base_index, int rem){
	int size = inp.size();
	// handle base case
	if(!rem){
		vector<string> cur;
		string tail = inp.substr(base_index);
		if(valid(tail))  cur.push_back(tail);
		return cur;
	}

	string block;
	vector<string> result;
	for(int i=0 ; i<MAX_BLOCK_SIZE and i<size ; ++i){
		block.push_back(inp[base_index + i]);
		bool rest_size_ok = rem <= (size - base_index - i - 1)
		                 and rem*3 >= (size - base_index - i - 1);
		if(valid(block) and rest_size_ok){
		    // restore rest & add "block." to the beginning of every
		    // solution
			vector<string> rest = restore(inp, base_index+i+1, rem-1);
			for(int i=0 ; i<rest.size() ; ++i)
				result.push_back(block + "." + rest[i]);
		}
	}
	return result;
}

vector<string> Solution::restoreIpAddresses(string inp){
    if(inp.size() > 12) 	return vector<string>();
	return restore(inp, 0, BLOCK_NUMBER-1);
}
/*
0100110
  0.10.0.110
  0.100.1.10
  0.100.11.0
12345
  1.2.3.45
  1.2.34.5
  1.23.4.5
  12.3.4.5
19216811 
  1.92.168.11
  19.2.168.11
  19.21.68.11
  19.216.8.11
  19.216.81.1
  192.1.68.11
  192.16.8.11
  192.168.1.1
falanfilansnfdsjgfkmf
*/