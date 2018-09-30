/**
 * hashtable.h
 * Copyright Antonio Macovei
 */

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
		// Constructor
		Hashtable(int hmax, unsigned int (*h)(Tkey)) {
			HMAX = hmax;
			H = new std::list<struct elem_info<Tkey, Tvalue> >[hmax];
			hash = h;
		}

		// Destructor
		~Hashtable() {
			delete[] H;
		}

		/**
		 * Adds an element to the hashtable
		 *
		 * @param key The key of the element to be added
		 * @param value The value of the element to be added
		 */
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

		/**
		 * Adds an element to the hashtable
		 *
		 * @param key The key of the searched element
		 * @return the value found with the key
		 */
		Tvalue get(Tkey key) {
			unsigned int index = hash(key) % HMAX;
			for(auto it : H[index]) {
				if(it.key == key) {
					return it.value;
				}
			}
			return Tvalue();
		}

		/**
		 * Gets the hashtable size.
		 *
		 * @return Number of elements in the hashtable.
		 */
		int get_size() {
			return size;
		}

		/**
		 * Gets the hastable capacity.
		 *
		 * @return Number of buckets in the hashtable.
		 */
		int get_capacity() {
			return HMAX;
		}
};

#endif  // HASHTABLE_H__