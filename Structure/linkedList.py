class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # set the initial node of linked list

# Node: data -> next
# LinkedList: Node -> Node -> Node

class LinkedList:
    def __init__(self):
        self.head = None # set head node as Empty
        
    def append(self, data):
        new_node = Node(data)
        # check if the list is empty
        if self.head == None:
            self.head = new_node
            return
        # while loop until the last node,and append the data 
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node
        
    def print_list(self):
        #while loop print every node data
        current_node = self.head
        while current_node:
            print(current_node.data, end = ' -> ')
            current_node = current_node.next
        print('None')
        
    def delete_node(self, key):
        #case 1: delete the head node
        current_node = self.head
        
        if current_node and current_node.data == key:
            self.head = current_node.next
            current_node = None
            return
        
        #case 2: find the location of the delete node
        prev = None
        while current_node and current_node != key:
            prev = current_node
            current_node = current_node.next
            
        #case 2.1: None of delete node in the linked list
        if current_node is None:
            print('Error, try to input the correct value')
            return

        #delete the node 
        prev.next = current_node.next
        current_node = None
    
    def insert_after_node(self, prev_node, data):
        # case 1: check prev node
        if not prev_node:
            print('Error, try to insert valid prev node')
            return
        # case 2: insert the node
        new_node = Node(data)
        new_node.next = prev_node.next # pre -> current -> next, let new -> current
        prev_node.next = new_node
    
    def length(self):
        count = 0
        current_node = self.head
        while current_node:
            count += 1
            current_node = current_node.next
        return count

linked = LinkedList()

linked.append(1)
linked.append(2)
linked.append(3)
linked.append(4)
linked.delete_node(1)

linked.print_list()

linked.insert_after_node(linked.head, 4)

linked.print_list()

linked.length()


        