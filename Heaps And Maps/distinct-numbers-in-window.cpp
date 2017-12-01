inline bool map_contains(unordered_map<int, int> &chi, int query){
	return chi.find(query) != chi.end();
}

vector<int> Solution::dNums(vector<int> &vec, int window_size){
	unordered_map<int, int> chi; // value - quantitiy
	
	int i, size = vec.size();
	for(i=0 ; i<window_size ; ++i) 		chi[ vec[i] ]++;

	vector<int> res; 	res.push_back(chi.size());
	while(i < size){
		chi[ vec[i - window_size] ]--;
		if(chi[ vec[i - window_size] ] == 0)    chi.erase(vec[i - window_size]);
		chi[ vec[i] ]++;
		res.push_back(chi.size());
		++i;
	}
	return res;
}