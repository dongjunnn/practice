# https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/?envType=daily-question&envId=2026-01-20

class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        res = []
        for n in nums:
            if n % 2 == 0:
                res.append(-1)
            else:
                t = n + 1
                lowbit = t & -t
                res.append(n - (lowbit >> 1))
        return res



"""
Gemini's Logic Explanation:
1. Condition: ans | (ans + 1) == n
   - The operation x | (x + 1) always sets the lowest zero bit to 1. 
   - This means the result 'n' must always end in 1 (odd).
   - If 'n' is even, it's impossible. Return -1.

2. Strategy for Odd Numbers:
   - An odd number 'n' has a continuous block of trailing 1s (e.g., 23 is 10111).
   - We can form 'n' by taking 'ans' and flipping any ONE of those trailing 1s to 0.
   - To find the MINIMUM 'ans', we must remove the largest possible value.
   - Therefore, we identify the Most Significant Bit (left-most) of the trailing 1s and subtract it.

3. The Bitwise Trick:
   - Calculate t = n + 1. This clears all trailing 1s and sets the bit immediately to their left.
     (e.g., n=23 [10111] -> t=24 [11000])
   - isolate = t & -t. This finds that newly set bit (the pivot).
     (e.g., 24 & -24 = 8 [01000])
   - (isolate >> 1) gives us the bit we actually wanted to remove.
     (e.g., 8 >> 1 = 4 [00100])
   - Result = n - 4 = 19.
"""
