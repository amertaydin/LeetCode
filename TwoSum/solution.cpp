class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int complement;
        map<int, int>hash_map;

        for (int i = 0; i < nums.size(); i++) {
            // If complement is present in map, we return it
            complement = target - nums[i];
            if (hash_map.count(complement)) {
                return {hash_map[complement], i};
            } else {
                hash_map[nums[i]] = i;
            }
        }

        return {};
    }
};