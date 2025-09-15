class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if not nums:
            return 0
        
        write_index = 0
        for read_index in range(len(nums)):
            if nums[read_index] != val:
                nums[write_index] = nums[read_index]
                write_index += 1
        return write_index
from typing import List