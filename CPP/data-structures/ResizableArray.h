/*
	ResizableArray.h
	Copyright Antonio Macovei
*/

#ifndef RESIZABLEARRAY_H_
#define RESIZABLEARRAY_H_

template <typename T>
class ResizableArray {
	private:
		int defaultCapacity = 1;

		int numElements;
		int maxCapacity;
		T *data;

		void resizeArray() {
			maxCapacity = maxCapacity + 1;
			T *temp;
			temp = new T[maxCapacity];
			for (int i = 0; i < numElements; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
		}

		// Shift elements one position to the right
		void shift_elements_right(int start) {
			for (int i = numElements; i > start; i--) {
				data[i] = data[i - 1];
			}
		}

		// Shift elements one position to the left
		void shift_elements_left(int stop) {
			for (int i = satop; i < numElements; i++) {
				data[i] = data[i + 1];
			}
		}

	public:
		// Constructor
		ResizableArray() {
		    numElements = 0;
		    maxCapacity = defaultCapacity;

		    data = new T[maxCapacity];
		}

		// Destructor
		~ResizableArray() {
		    delete[] data;
		}

		/**
		 * Adds the specified element at the end of the array.
		 *
		 * @param element Element to be added at the end of the array.
		 */
		void add_last(T element) {
		    if (numElements == maxCapacity) {
				resizeArray();
			}
			data[numElements] = element;
			numElements++;
		}

		/**
		 * Adds the specified element at the beginning of the array.
		 *
		 * @param element Elment to be added at the beginning of the array.
		 */
		void add_first(T element) {
		    if (numElements == maxCapacity) {
				resizeArray();
			}
			numElements++;
			shift_elements_right(0);
			data[0] = element;
		}

		/**
		 * Removes and returns the last element of the array.
		 *
		 * @return Value of the last element stored in the array.
		 */
		void remove_last() {
			if (numElements == 0) return;
			numElements--;
		}

		/**
		 * Removes and returns the first element of the array.
		 *
		 * @return Value of the first element stored in the array.
		 */
		void remove_first() {
			if (numElements == 0) return;
		    shift_elements_left(0);
			numElements--;
		}

		/**
		 * Checks if the array contains any elements.
		 *
		 * @return True if the array contains no elements, False otherwise.
		 */
		bool is_empty() {
		    if (numElements == 0)
				return true;
			return false;
		}

		/**
		 * Returns the number of elements in the array.
		 *
		 * @return The number of elements stored in the array.
		 */
		int size() {
		    return numElements;
		}

		// Getters
		T *get_data() {
		    return data;
		}
};
#endif  // RESIZABLEARRAY_H_