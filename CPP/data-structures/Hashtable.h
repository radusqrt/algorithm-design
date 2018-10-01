#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <list>

#define TRESHOLD 0.75

template <typename Tkey, typename Tvalue> struct elem_info {
	Tkey key;
	Tvalue value;
};

template <typename Tkey, typename Tvalue> class Hashtable {
private:
	std::list<struct elem_info<Tkey, Tvalue> > * H;  // pointer to buckets
	int HMAX;  // number of buckets
	unsigned int (*hash)(Tkey);  // pointer to hash function
	unsigned int size;  // number of elements in hashtable

public:
	Hashtable(int hmax, unsigned int (*h)(Tkey)) {
		HMAX = hmax;
		H = new std::list<struct elem_info<Tkey, Tvalue> >[hmax];
		hash = h;
	}

	~Hashtable() {
		delete[] H;
	}

	// Adds an element to the hashtable
	void put(Tkey key, Tvalue value) {
		unsigned int index = hash(key) % HMAX;
		bool found = false;
		for(auto it : H[index]) {
			if(it.key == key) {
				it.value = value;
				found = true;
			}
		}
		if(!found) {
			elem_info<Tkey, Tvalue> new_elem;
			new_elem.key = key;
			new_elem.value = value;
			H[index].push_back(new_elem);
		}
	}

	// Gets an element from the hashtable
	Tvalue get(Tkey key) {
		unsigned int index = hash(key) % HMAX;
		for(auto it : H[index]) {
			if(it.key == key) {
				return it.value;
			}
		}
		return Tvalue();
	}

	// Gets the hashtable size.
	int get_size() {
		return size;
	}

	// Gets the hastable capacity.
	int get_capacity() {
		return HMAX;
	}
};

#endif  // HASHTABLE_H__