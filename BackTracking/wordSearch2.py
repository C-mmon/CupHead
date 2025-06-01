class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEnd = False
        self.word = None  # Store the word when it's completed


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        root = self.root
        for char in word:
            root = root.children.setdefault(char, TrieNode())
        root.isEnd = True
        root.word = word


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.num_words = len(words)
        if self.num_words == 0:
            return []

        res, trie = [], Trie()
        for word in words:
            trie.insert(word)

        self.rows, self.cols = len(board), len(board[0])
        self.board = board

        for i in range(self.rows):
            for j in range(self.cols):
                self.dfs(i, j, trie.root, res)

        return res

    def dfs(self, i, j, node, res):
        if i < 0 or i >= self.rows or j < 0 or j >= self.cols:
            return

        char = self.board[i][j]
        if char == '#' or char not in node.children:
            return

        next_node = node.children[char]

        if next_node.isEnd:
            res.append(next_node.word)
            next_node.isEnd = False  # prevent duplicates
            self.num_words -= 1
            if self.num_words == 0:
                return

        self.board[i][j] = '#'  # mark visited

        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            self.dfs(i + dx, j + dy, next_node, res)

        self.board[i][j] = char  # unmark
