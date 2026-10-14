class PrefixTree:
    def __init__(self):
        self.chars = dict([(chr(ord('a')+i),  None) for i in range(26)])
        self.end = False

    def insert(self, word: str) -> None:
        curr = self
        for l in word:
            if curr.chars[l] == None:
                curr.chars[l] = PrefixTree()
            curr = curr.chars[l]
        curr.end = True

    def search(self, word: str) -> bool:
        curr = self
        for l in word:
            if curr.chars[l] == None:
                return False
            curr = curr.chars[l]
        return curr.end

    def startsWith(self, prefix: str) -> bool:
        curr = self
        for l in prefix:
            if curr.chars[l] == None:
                return False
            curr=curr.chars[l]
        return True
        