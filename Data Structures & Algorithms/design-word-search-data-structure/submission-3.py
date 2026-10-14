class WordDictionary:

    def __init__(self):
        self.chars = dict()
        self.end = False

    def addWord(self, word: str) -> None:
        curr = self
        for letter in word: 
            if letter not in curr.chars:
                curr.chars[letter] = WordDictionary()
            curr=curr.chars[letter]
        curr.end = True
    def ssearch(self,sself, word: str) -> bool:
        curr = sself
        res = False
        for i in range(len(word)):
            if word[i]=='.':
                for _, temp in curr.chars.items():
                    if self.ssearch(temp, word[i+1:]):
                        return True
                return False
            else:
                if word[i] not in curr.chars:
                    return False
                curr = curr.chars[word[i]]
        return curr.end
    def search(self, word: str) -> bool:
        return self.ssearch(self, word)
