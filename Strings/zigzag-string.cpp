

string Solution::convert(string q, int rows) {
    if(rows<2)     return q;
    string res;
	// map[i] holds the char that will go to i'th row;
	vector< vector<char> > index_map(rows, vector<char>());

	int dir=1, cur_row = 0, size = q.size();
	for(int i=0 ; i<size ; ++i){
		index_map[cur_row].push_back(q[i]);
		if(!cur_row and dir==-1) 		dir=1;
		if(cur_row == rows-1 and dir==1) 	dir=-1;
		cur_row += dir;
	}

	size = index_map.size();
	for(int i=0,row_size ; i<size ; ++i){
		row_size = index_map[i].size();
		for(int j=0 ; j<row_size ; ++j)
			res += index_map[i][j];
	}
	
	return res;
}
