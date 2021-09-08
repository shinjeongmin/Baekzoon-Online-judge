import sys
input = sys.stdin.readline
# 5639번 재귀횟수 제한을 늘려야 런타임 에러 해결
sys.setrecursionlimit(20000)

class Node:
    def __init__(self, item, left, right):
        self.item=item
        self.left=left
        self.right=right

def postorder(node):
    if node.left!=0:
        postorder(tree[node.left])
    if node.right!=0:
        postorder(tree[node.right])
    print(node.item)

def addtree(node,item):
    global tree
    # 자식 노드가 없을 떄
    if node.item>item and node.left==0:
        node.left=item
        tree[item]=Node(item=item,left=0,right=0)
    elif node.item<item and node.right==0:
        node.right=item
        tree[item]=Node(item=item,left=0,right=0)
    #자식 노드가 있을 때 (재귀)
    elif node.item>item and node.left!=0:
        addtree(tree[node.left],item)
    elif node.item<item and node.right!=0:
        addtree(tree[node.right],item)

if __name__=="__main__":
    tree={}
    # sec=int(input())
    # root=sec
    # tree[sec]=Node(item=sec,left=0,right=0)
    # while True:
    #     fir=sec
    #     sec=input()
    #     if sec=='\n':
    #         break
    #     addtree(tree[root],int(sec))

    # 출력방식 - 예외처리식
    c=False
    count=0
    while count<= 10000:
        try:
            i=int(input())
            if not c:
                root=int(i)
                tree[root]=Node(item=root,left=0,right=0)
                c=True
                continue
            addtree(tree[root],int(i))
        except:break
        count+=1
    postorder(tree[root])