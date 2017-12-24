#include<list>

#define NOT_FOUND -1

struct item{
	int key; int value;
	item(int k, int v): key(k), value(v) {}
};

list<item> *lee;
unordered_map< int, list<item>::iterator > *hmap;
int cap;

LRUCache::LRUCache(int capacity) {
	cap = capacity;
	lee = new list<item>;
	hmap = new unordered_map<int, list<item>::iterator >;
}

int LRUCache::get(int key) {
	unordered_map<int, list<item>::iterator>::iterator saga = hmap->find(key); 
	// if key's not in the cache, return
	if(saga == hmap->end()) 	return NOT_FOUND;

	item found = *(saga->second);
	lee->erase(saga->second);
	lee->push_front(found);
	(*hmap)[key] = lee->begin();
	return found.value;
}

void LRUCache::set(int key, int value) {
	int saga = get(key);

	if(saga == NOT_FOUND){
		if(lee->size() == cap){		
			int last_key = lee->back().key;
			hmap->erase(last_key);
			lee->pop_back();
		}
		lee->push_front(item{key, value});
		(*hmap)[key] = lee->begin();
	}
	else{
		lee->front().value = value;
	}
}
