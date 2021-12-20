# Note.
# Highly unoptimized code which really needs factoring, but work nonetheless


from math import floor, ceil

class Node:
    def __init__(self, literal = True, left = None, right = None, val = 0, parent = None, isLeftchild = True) -> None:
        self.literal = literal
        self.val = val
        self.left = left
        self.right = right
        self.parent = parent
        self.isLeftchild = isLeftchild

    def __str__(self):
        if self.literal:
            return str(self.val)
        return '[' + self.left.__str__() + ',' + self.right.__str__() + ']'

def FindLeftmost(node: Node):
    crawl = node
    while crawl.isLeftchild and crawl.parent != None:
        crawl = crawl.parent
    if crawl.parent == None: return None
    crawl = crawl.parent.left
    # print(crawl)
    while not crawl.literal and crawl != None:
        crawl = crawl.right
    return crawl

def FindRightmost(node: Node):
    crawl = node
    while not crawl.isLeftchild and crawl.parent != None:
        crawl = crawl.parent
    if crawl.parent == None: return None
    crawl = crawl.parent.right
    # print(crawl)
    while not crawl.literal and crawl != None:
        crawl = crawl.left
    return crawl

root = Node()

def Split(node: Node):
    if node.literal:
        if node.val >= 10:
            node.left = Node(val=floor(node.val/2), isLeftchild=True)
            node.right = Node(val=ceil(node.val/2), isLeftchild=False)
            node.literal = False
            node.val = 0
            return True
        return False

    if Split(node.left): return True
    elif Split(node.right): return True
    return False

def Fix(node: Node):
    if node.literal:
        return
    node.left.isLeftchild = True
    node.left.parent = node
    node.right.isLeftchild = False
    node.right.parent = node
    Fix(node.left)
    Fix(node.right)

def Exploding(node: Node, level = 0):
    global root
    if node.literal: return False
    elif level >= 4:
        # print(node)
        leftmostNode = FindLeftmost(node)
        if leftmostNode != None:
            leftmostNode.val += node.left.val
            # print(f'leftmostNode = {leftmostNode}')
                
        rightmostNode = FindRightmost(node)
        if rightmostNode != None:
            rightmostNode.val += node.right.val
            # print(f'rightmostNode = {rightmostNode}')

        node.left = None
        node.right = None
        node.val = 0
        node.literal = True
        # print(root)

        return True
    else:
        if node.left != None and Exploding(node.left, level+1): return True
        elif node.right != None and Exploding(node.right, level+1): return True
        return False

def Parsing(s, idx = 0, parent=None, isLeftchild=True):
    node = Node(literal=False, parent=parent, isLeftchild=isLeftchild)

    # left child
    idx += 1
    if s[idx] == '[':
        node.left, idx = Parsing(s, idx, node, True)
    else:
        next_idx = s.find(',', idx)
        val = int(s[idx: next_idx])
        node.left = Node(literal=True,val=val,parent=node,isLeftchild=True)
        idx = next_idx+1

    #right child
    if s[idx] == '[':
        node.right, idx = Parsing(s, idx, node, False)
    else:
        next_idx = s.find(']', idx)
        val = int(s[idx: next_idx])
        node.right = Node(literal=True,val=val,parent=node,isLeftchild=False)
        idx = next_idx+1

    idx += 1

    return node, idx

def CalculateSum(node: Node):
    if node.literal: return node.val
    return 3*CalculateSum(node.left) + 2*CalculateSum(node.right)

def part1():
    global root
    with open('Advent of Code/2021/d18.txt') as file:
        s = file.readline().strip()
        root, _ = Parsing(s)
        # print(root)
        
        for line in file:
            node, _ = Parsing(line.strip())
            # print(node)
            x = Node(literal=False,left=root,right=node)
            node.parent = x
            node.isLeftchild = False
            root.parent = x
            root.isLeftchild = True
            root = x
            # print(f'before\t= {root}')
            while True:
                Fix(root)
                if Exploding(root):
                    # print(f'explode\t: {root}')      
                    continue
                elif Split(root):
                    # print(f'split\t: {root}')
                    continue
                break
            # print(f'after\t= {root}')
            
    print(CalculateSum(root))

part1()

def part2():
    global root
    nodes = []
    with open('Advent of Code/2021/d18.txt') as file:        
        for line in file:
            nodes.append(line.strip())
    ans = 0
    for i in range(len(nodes)):
        for j in range(len(nodes)):
            if i == j: continue
            a, _ = Parsing(nodes[i])
            b, _ = Parsing(nodes[j])
            root = Node(literal=False,left=a,right=b)
            a.parent = root
            a.isLeftchild = False
            b.parent = root
            b.isLeftchild = True
            # print(f'before\t= {root}')
            while True:
                Fix(root)
                if Exploding(root):
                    # print(f'explode\t: {root}')      
                    continue
                elif Split(root):
                    # print(f'split\t: {root}')
                    continue
                break
            # print(f'after\t= {root}')
            ans = max(CalculateSum(root), ans)
    print(ans)


part2()