#include <iostream>

using namespace std;

template <typename T>
class stack {
public:
	T *arr;
	int top;
	size_t capacity;
	size_t size;

	stack (size_t capacity) {
	    this->capacity = capacity;
	    arr = new T[capacity];
	    top = -1;
	    size = 0;
	}

    void push(T data) {
        if (size < capacity) {
            arr[++top] = data;
            ++size;
        } else {
            T *arr2 = new T[capacity * 2];
            for (int i = 0; i < capacity; ++i) {
                arr2[i] = arr[i];
            }
            arr2[++top] = data;
            ++size;
            capacity *= 2;
            
            delete []arr;
            arr = arr2;
        }
    }

	void pop() {
	    if (is_empty()) {
	        cout << "Stack is empty" << endl;
	        return;
	    }
	    --top;
	    --size;
	}
	
	T peek() {
	    if (is_empty()) {
	        exit(-1);
	    }
	    return arr[top];
	}

	bool is_empty() {
	    if (size != 0) {
	        return false;
	    }
	    return true;
	}
	
	~stack() {
	    delete []arr;
	}
};

int main()
{
	return 0;
}
