class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ## Create a dictionary to store both number and index
        hash_map = {}

        for i in range(len(nums)):
            ## Target - number will give us required number
            complement = target - nums[i]

            ## if required number is in the dictionary, we return it
            if complement in hash_map:
                ## return current number's index and the index of complement
                return [i, hash_map[complement]]
            ## if not in the dictionary, add with its index
            hash_map[nums[i]] = i