class PrefixTree:
    def __init__(self):
        self.chars = dict()
        self.end = False

    def insert(self, word: str) -> None:
        curr = self
        for l in word:
            if l not in curr.chars:
                curr.chars[l] = PrefixTree()
            curr = curr.chars[l]
        curr.end = True

    def search(self, word: str) -> bool:
        curr = self
        for l in word:
            if l not in curr.chars:
                return False
            curr = curr.chars[l]
        return curr.end

    def startsWith(self, prefix: str) -> bool:
        curr = self
        for l in prefix:
            if l not in curr.chars:
                return False
            curr=curr.chars[l]
        return True
        