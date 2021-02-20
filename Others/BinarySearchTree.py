###
# Implementation of Binary Search Tree (BST) insert and search functionality.
###

class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BST(object):
    def __init__(self, root):
        self.root = Node(root)
    
    def insert(self, new_val):
        self.insertItem(self.root, new_val)
        
    def insertItem(self, root, new_val):
        node = Node(new_val)
        if new_val > root.value: 
            if root.right == None:
                root.right = node
            else:
                self.insertItem(root.right, new_val)
                
        elif new_val < root.value:
            if root.left == None:
                root.left = node
            else:
                self.insertItem(root.left, new_val)

    def search(self, find_val):
        return self.searchItem(self.root, find_val)
        
    def searchItem(self, root, find_val):
        # This condition becomes true when find_val is not in the tree and root becomes a None value
        if root == None:
            return False
        
        elementSearchStatus = False
        
        if root.value == find_val:
            #print("root.value == {}".format(root.value))
            elementSearchStatus = True
        elif find_val > root.value:
            #print("find_val > root.value")
            elementSearchStatus = self.searchItem(root.right, find_val)
        elif find_val < root.value:
            #print("find_val < root.value")
            elementSearchStatus = self.searchItem(root.left, find_val)
        return elementSearchStatus
    
# Set up tree
tree = BST(4)

# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)


# Check search
# Should be True
print tree.search(4)
# Should be False
print tree.search(6)