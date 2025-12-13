# Node structure
class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

# Linked list
class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

# insert at index
def insert_at(lst, index, value):
    if index < 0 or index > lst.size:
        print("Error: Invalid index.")
        return
    new_node = Node(value)
    if index == 0:  # insert at start
        new_node.next = lst.head
        lst.head = new_node
    else:  # insert middle/end
        current = lst.head
        for _ in range(index - 1):
            current = current.next
        new_node.next = current.next
        current.next = new_node
    lst.size += 1

# delete at index
def delete_at(lst, index):
    if lst.size == 0:
        print("Error: List is empty.")
        return
    if index < 0 or index >= lst.size:
        print("Error: Invalid index.")
        return
    if index == 0:  # delete first
        temp = lst.head
        lst.head = lst.head.next
    else:  # delete middle/end
        current = lst.head
        for _ in range(index - 1):
            current = current.next
        temp = current.next
        current.next = temp.next
    temp.next = None  # optional
    lst.size -= 1

# print list
def traverse(lst):
    current = lst.head
    if current is None:
        print("[empty]")
        return
    while current is not None:
        print(current.data, end=" ")
        current = current.next
    print()

# main
if __name__ == "__main__":
    lst = LinkedList()
    insert_at(lst, 0, 10)
    insert_at(lst, 1, 20)
    insert_at(lst, 1, 15)
    insert_at(lst, 3, 25)

    print("List after insertions: ", end="")
    traverse(lst)

    delete_at(lst, 1)
    print("List after deleting index 1: ", end="")
    traverse(lst)

    delete_at(lst, 0)
    print("List after deleting index 0: ", end="")
    traverse(lst)
