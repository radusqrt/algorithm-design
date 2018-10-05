/*
	Deque.h
	Copyright Antonio Macovei
*/

#ifndef DEQUE_H_
#define DEQUE_H_

#include "DoublyLinkedList.h"

template<typename T>
class Deque {
	private:
		DoublyLinkedList<T> deque;

	public:
		void push_front(T data) {
			deque.add_first(data);
		}

		void push_back(T data) {
			deque.add_last(data);
		}

		void pop_front() {
			deque.remove_first();
		}

		void pop_back() {
			deque.remove_last();
		}

		T front() {
			if (!deque.is_empty())
				return deque.get_head()->data;
		}

		T back() {
			if (!deque.is_empty())
				return deque.get_tail()->data;
		}

		int size() {
			return deque.size();
		}

		bool empty() {
			return deque.is_empty();
		}
};
#endif  // DEQUE_H_