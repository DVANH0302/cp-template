import sys
input = sys.stdin.readline

class Node:
    def __init__(self, isWord = False):
        self.children = {}
        self.isWord = isWord

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, s):
        cur = self.root

        for c in s:
            if c not in cur.children:
                cur.children[c] = Node()
            cur = cur.children[c]
        cur.isWord = True

    def find(self, s):
        cur = self.root

        for c in s:
            if c not in cur.children:
                return False

            cur = cur.children[c]
            if cur.isWord:
                return True
        return False


def main():
    q    = int(input())
    allowed = set()
    not_allowed = set()
    a_trie = Trie()
    na_trie = Trie()
    sa_trie = Trie()
    sna_trie = Trie()
    for _ in range(q):
        t,s = list(input().rstrip().split())

        if t == '1':
            allowed.add(s)
        elif t == '2':
            not_allowed.add(s)
        elif t == '3':
            a_trie.insert(s)
        elif t == '4':
            na_trie.insert(s)
        elif t == '5':
            sa_trie.insert(s[::-1])
        elif t == '6':
            sna_trie.insert(s[::-1])
        elif t == '7':
            if (s in not_allowed or na_trie.find(s) or sna_trie.find(s[::-1])):
                print("NO")
            else:
                print("YES")

        
if __name__ == '__main__':
    main()