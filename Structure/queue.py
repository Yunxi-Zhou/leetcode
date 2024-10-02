class Queue:
    def __init__(self):
        self.items = []
    
    def is_empty(self):
        return len(self.items) == 0

    def enqueue(self, item):
        # add to the end of the queue
        self.items.append(item)
    
    def dequeue(self):
        # remove: remove the head of the queue
        if not self.is_empty():
            return self.items.pop(0)
        raise IndexError("dequeue from empty queue")
    
    def peek(self):
        if not self.is_empty():
            return self.items[0]
        raise IndexError("peek from empty queue")
    
    def size(self):
        return len(self.items)
    
    def __str__(self):
        return "Queue: " + str(self.items)
    
if __name__ == "__main__":
    queue = Queue()
    
    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    
    print(queue)
    
    print("Dequeued: ", queue.dequeue())
    print(queue)
    
    # check the head elements
    print("Peek: ", queue.peek())
    
    # size
    print("Size: ", queue.size())
    
    # check if it is empty
    print("Is empty: ", queue.is_empty())