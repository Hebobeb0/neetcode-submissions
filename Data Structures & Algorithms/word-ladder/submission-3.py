from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        m = len(beginWord)
        used = set()
        words = set(wordList)
        if endWord not in words:
            return 0
        q = deque([(beginWord, 1)])
        while len(q):
            curr, long = q.popleft()
            if curr == endWord:
                return long 
            for i in range(m):
                for j in range(26):
                    temp = curr[:i] + chr(ord('a')+j) + curr[i+1:]
                    if temp != curr and temp in words and temp not in used:
                        used.add(temp)
                        q.append((temp,long+1))
        return 0
                        