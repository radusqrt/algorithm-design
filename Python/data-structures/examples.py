from Queue import Queue

# ----------------- Queue -----------------
q1 = Queue()

# put elements in queue
q1.enqueue(42)
q1.enqueue(256)
q1.enqueue(6)

# look at the top of the queue
print("Top element: ", q1.peek())

# use the top element
top = q1.dequeue()
print("Top element in variable: ", top)
print("Top element after using past top element: ", q1.peek())

print("Size of queue: ", q1.size())
# we can just dequeue elements without using
q1.dequeue()
q1.dequeue()
print("Is queue empty now: ", q1.is_empty())

