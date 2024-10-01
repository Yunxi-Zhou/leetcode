
#define binary tree node
class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.value = key

class BinaryTree:
    def __init__(self):
        self.root = None
        
    def insert(self, root, key):
        # if root is empty, create a new node
        if root is None:
            return Node(key)
        else:
            if key < root.value:
                root.left = self.insert(root.left, key)
            else:
                root.right = self.insert(root.right, key)
        return root
    
    # Inorder traversal: left -> root -> right 中序
    def inorder_traversal(self, root):
        if root:
            self.inorder_traversal(root.left)
            print(root.value, end=" ")
            self.inorder_traversal(root.right)
    
    # Preorder traversal: root -> left -> right 前序
    def preorder_traversal(self, root):
        if root:
            print(root.value, end=" ")
            self.preorder_traversal(root.left)
            self.preorder_traversal(root.right)
    
    # Postorder traversal: left -> right -> root hou xu
    def postorder_traversal(self, root):
        if root:
            self.postorder_traversal(root.left)
            self.postorder_traversal(root.right)
            print(root.value, end=" ")
            
    # add a new node to the tree
    def add(self, key):
        self.root = self.insert(self.root, key)
    
    def maxDepth(self, root):
        left = 0;
        right = 0;
        if root:
            if root.left:
                left += 1
            if root.right:
                right += 1
        return max(left,right)

# main
if __name__ == "__main__":
    tree = BinaryTree()
    
    # insert the node
    tree.add(2)
    tree.add(5)
    tree.add(3)
    tree.add(4)
    
    # inorder
    print('Inorder traversal:', end=' ')
    tree.inorder_traversal(tree.root)
    print()
    
    #preorder
    print('Preorder traversal:', end=' ')
    tree.preorder_traversal(tree.root)
    print()
    #postorder
    print('Postorder traversal:', end=' ')
    tree.postorder_traversal(tree.root)
    print(tree.maxDepth(tree.root))
    print()