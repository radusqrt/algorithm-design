/** Circular Queue */
#define DEFAULT_SIZE 100

#include <iostream>
#include <climits>

template <typename T>
class Queue {
private:
    T *container;
    int numElems;
    int size;
    int head, tail;

public:
    /** Constructor */
    Queue() {
        container = new T[DEFAULT_SIZE];
        numElems = 0;
        this->size = DEFAULT_SIZE;
        head = tail = 0;
    }

    /** 2nd Constructor */
    Queue(int size) {
        container = new T[size];
        numElems = 0;
        this->size = size;
        head = tail = 0;
    }

    /** Destructor */
    ~Queue() {
        delete[] container;
    }

    /** Assignment operator */
    Queue &operator=(const Queue &copy) {
        this->container = new T[copy.size];

        for (int i = 0; i < copy.size; i++) {
            this->container[i] = copy.container[i];
        }

        this->size = copy.size;
        this->numElems = copy.numElems;
        this->head = copy.head;
        this->tail = copy.tail;

        return *this;
    }

    /** Copy Constructor */
    Queue(const Queue &copy) {
        this->container = new T[copy.size];

        for (int i = 0; i < copy.size; i++) {
            this->container[i] = copy.container[i];
        }

        this->size = copy.size;
        this->numElems = copy.numElems;
        this->head = copy.head;
        this->tail = copy.tail;
    }

    /**  Insert an element into the circular queue */
    void enQueue(T x) {
        if (isFull()) {
            std::cout << "Can't enqueue, queue is full!\n";
            return;
        }

        container[tail] = x;
        tail = (tail + 1) % size;
        numElems++;
    }

    /** Delete an element from the circular queue */
    void deQueue() {
        if (isEmpty()) {
            std::cout << "Can't dequeue, queue is empty!\n";
            return;
        }

        numElems--;
        head = (head + 1) % size;
    }

    /** Get the front item from the queue */
    int front() {
        if (isEmpty()) {
            return INT_MIN;
        }

        return container[head];
    }

    /** Checks whether the circular queue is empty or not */
    bool isEmpty() {
        return !numElems;
    }

    /** Checks whether the circular queue is full or not */
    bool isFull() {
        return numElems == size;
    }

    /** Overloading << operator */
    template <typename U>
    friend std::ostream& operator<< (std::ostream& stream, Queue<U> &obj);

};

template <typename T>
std::ostream& operator<< (std::ostream& stream, Queue<T> &obj) {
    for (int i = 0; i < obj.numElems; i++) {
        T front = obj.front();
        stream << front << " ";
        obj.deQueue();
        obj.enQueue(front);
    }
    stream << std::endl;

    return stream;
}

int main() {
    /** Checking functionality of Circular Queue */
    Queue<int> q(4);

    /** Checking isEmpty */
    if (q.isEmpty()) {
        std::cout << "Queue is empty\n";
    }

    /** Checking deQueue for empty queue */
    q.deQueue();

    /** Checking enQueue */
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(-4);
    q.enQueue(23);

    /** Checking operator<< overloading */
    std::cout << q;

    /** Checking enQueue for full queue */
    q.enQueue(2);

    /** Checking isFull */
    if (q.isFull()) {
        std::cout << "Queue is full\n";
    }

    /** Checking deQueue */
    q.deQueue();

    std::cout << q;

    /** Checking front */
    std::cout << q.front() << std::endl;

    /** Checking Copy Constructor */
    Queue<int> p = q;
    std::cout << p;

    /** Checking operator= overloading */
    Queue<int> r;
    
    r = p;

    std::cout << r;

    q.enQueue(2);
    r = q;
    std::cout << r;

    return 0;
}
