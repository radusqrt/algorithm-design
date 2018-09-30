/*
	DoublyLinkedList.h
	Copyright Antonio Macovei
*/

#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

template <typename T>
struct Node {
	T data;
	Node<T> *next;
	Node<T> *prev;

	explicit Node(T data) {
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

template <typename T>
class DoublyLinkedList {
	private:
		Node<T> *head;
		Node<T> *tail;
		int numElements;

		// Returns the pos'th node in the list.
		Node<T> *goToPos(int pos) {
		    int count = 0;
		    Node<T> *it = head;

		    while (count != pos) {
		        it = it->next;
		        count++;
		    }
		    return it;
		}

	public:
		// Constructor
		DoublyLinkedList() {
			head = nullptr;
			tail = nullptr;
			numElements = 0;
		}

		// Destructor
		~DoublyLinkedList() {
			while (head != nullptr) {
				Node<T> *temp = head;
				head = head->next;
				delete temp;
			}
		}

		/**
		 * Adds a new node at the beginning of the list.
		 *
		 * @param data Data to be added at the end of the list.
		 */
		void add_first(T data) {
			if (head == nullptr) {
				head = new Node<T>(data);
				head->next = nullptr;
				head->prev = nullptr;
				tail = head;
			} else {
				Node<T> *new_node;
				new_node = new Node<T>(data);
				new_node->next = head;
				new_node->prev = nullptr;
				head->prev = new_node;
				head = new_node;
			}
			numElements++;
		}

		/**
		 * Adds a new node at the end of the list.
		 *
		 * @param data Data to be added at the end of the list.
		 */
		void add_last(T data) {
			if (head == nullptr) {
				head = new Node<T>(data);
				head->next = nullptr;
				head->prev = nullptr;
				tail = head;
			} else {
				Node<T> *new_node;
				new_node = new Node<T>(data);
				new_node->next = nullptr;
				new_node->prev = tail;
				tail->next = new_node;
				tail = new_node;
			}
			numElements++;
		}

		/**
		* Removes the last node of the list.
		*/
		void remove_last() {
			if (numElements == 0) return;
			if (numElements == 1) {
				delete tail;
				tail = nullptr;
				head = nullptr;
				numElements = 0;
			} else {
				Node<T> *new_tail = tail->prev;
				tail->prev->next = nullptr;
				delete tail;
				tail = new_tail;
				numElements--;
			}
		}

		/**
		 * Removes the first node of the list.
		 */
		void remove_first() {
			if (numElements == 0) return;
			if (numElements == 1) {
				delete head;
				tail = nullptr;
				head = nullptr;
				numElements = 0;
			} else {
				Node<T> *new_head = head->next;
				head->next->prev = nullptr;
				delete head;
				head = new_head;
				numElements--;
			}
		}

		/**
		 * Check if the list contains any elements.
		 *
		 * @return True if the list contains no elements, False otherwise.
		 */
		bool is_empty() {
			if (numElements == 0)
				return true;
			return false;
		}

		/**
		 * Get the number of nodes in the list.
		 *
		 * @return The number of nodes stored in the list.
		 */
		int size() {
			return numElements;
		}

		// Getters & Setters
		Node<T> *get_head() {
			return head;
		}

		Node<T> *get_tail() {
			return tail;
		}
};
#endif  // DOUBLYLINKEDLIST_H_