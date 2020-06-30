// max sub array sum may be in left or right or left part + right part
// max of all three will be ans
// comp O(NlogN)
class Solution {
public:
    int findCrossSubArray(vector<int>& nums, int left, int right) {
        int mid = left + (right - left) / 2;
        
        int leftMaxSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftMaxSum = max(leftMaxSum, sum);
        }
        
        int rightMaxSum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightMaxSum = max(rightMaxSum, sum);
        }
        
        int maxCrossSum = leftMaxSum + rightMaxSum;
        return maxCrossSum;
    }

    int findMaxSubArraySum(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];

        int mid = left + (right - left) / 2;

        int leftSubArraySum = findMaxSubArraySum(nums, left, mid);
        int rightSubArraySum = findMaxSubArraySum(nums, mid + 1, right);

        int crossSubArraySum = findCrossSubArray(nums, left, right);
        
        return max({leftSubArraySum, rightSubArraySum, crossSubArraySum});
    }

    int maxSubArray(vector<int>& nums) {
        int left = 0;
        int right = (int)nums.size() - 1;
        return findMaxSubArraySum(nums, left, right);
    }
};




// kadane algo
// O(n)

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSoFar=nums[0]
        currSum=nums[0]
        for i in range(1,len(nums)):
            currSum=max(nums[i],currSum+nums[i])
            maxSoFar=max(maxSoFar,currSum)
        return maxSoFar
