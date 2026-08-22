class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers) 
        L,R = 0,n-1
        temp = numbers[L]+numbers[R]
        while (temp != target):
            if temp>target:
                R -=1
            if temp < target:
                L+=1
            temp = numbers[L]+numbers[R]
        return [L+1,R+1]
        