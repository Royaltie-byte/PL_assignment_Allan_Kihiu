MAX_SIZE = 100

class ArrayList:
    def __init__(self):
        self.data = [0] * MAX_SIZE
        self.size = 0

# insert value at index
def insert_at(lst, index, value):
    if lst.size == MAX_SIZE:
        print("List is full!!")
        return
    if index < 0 or index > lst.size:
        print("Invalid index")
        return
    # shift right
    for i in range(lst.size, index, -1):
        lst.data[i] = lst.data[i-1]
    lst.data[index] = value
    lst.size += 1

# delete at index
def delete_at(lst, index):
    if lst.size == 0:
        print("List is empty!")
        return
    if index < 0 or index >= lst.size:
        print("Invalid index")
        return
    # shift left
    for i in range(index, lst.size - 1):
        lst.data[i] = lst.data[i+1]
    lst.size -= 1

# print list
def traverse(lst):
    if lst.size == 0:
        print("List is empty")
        return
    for i in range(lst.size):
        print("The data at", i, "is", lst.data[i])

# main
if __name__ == "__main__":
    lst = ArrayList()
    insert_at(lst, 0, 12)
    insert_at(lst, 0, 20)
    insert_at(lst, 0, 90)
    insert_at(lst, 0, 120)
    insert_at(lst, 4, 1000)

    traverse(lst)
    print("Size after insertions:", lst.size)

    delete_at(lst, 0)
    delete_at(lst, 3)

    print("Array after deletion")
    traverse(lst)
    print("Size after two deletions:", lst.size)
