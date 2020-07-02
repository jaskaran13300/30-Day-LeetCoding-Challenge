# 1) Find middle point mid = (l + h)/2
# 2) If key is present at middle point, return mid.
# 3) Else If arr[l..mid] is sorted
#     a) If key to be searched lies in range from arr[l]
#        to arr[mid], recur for arr[l..mid].
#     b) Else recur for arr[mid+1..h]
# 4) Else (arr[mid+1..h] must be sorted)
#     a) If key to be searched lies in range from arr[mid+1]
#        to arr[h], recur for arr[mid+1..h].
#     b) Else recur for arr[l..mid]

class Solution:
    def help(self,nums,low,high,target):
        if low>high:
            return -1
        mid=int((high+low)/2)
        print(mid)
        if nums[mid]==target:
            return mid
        if nums[low]<=nums[mid]:
            if target >=nums[low] and target<=nums[mid]:
                return self.help(nums,low,mid-1,target)
            else:
                return self.help(nums,mid+1,high,target)
        # else:
        if target>=nums[mid] and target<=nums[high]:
            return self.help(nums,mid+1,high,target)
        else:
            return self.help(nums,low,mid-1,target)
    def search(self, nums: List[int], target: int) -> int:
        return self.help(nums,0,len(nums)-1,target)



// find pivot(Greatest) by bin search
// Another Solution
class Solution:
    def findPivot(self,nums,low,high):
        if high<low: # if array is empty
            return -1
        if low==high:
            return low
        mid=int((low+high)/2) 
        
        if nums[mid]>nums[mid+1]:
            return mid
        if nums[mid]<nums[mid-1]:
            return mid-1
        if nums[mid]<=nums[low]:
            return self.findPivot(nums,low,mid-1)
        # if nums[low]<=nums[mid]:
        return self.findPivot(nums,mid+1,high)
        
        
    def bs(self,nums,low,high,target):
        if high<low:
            return -1
        mid=int((low+high)/2)
        if nums[mid]==target:
            return mid
        if nums[mid]<target:
            return self.bs(nums,mid+1,high,target)
        # if nums[mid]>target:
        return self.bs(nums,low,mid-1,target)
        
        
    def search(self, nums: List[int], target: int) -> int:
        pivotIndex=self.findPivot(nums,0,len(nums)-1)
        print(pivotIndex)
        if pivotIndex==-1:
            ans=self.bs(nums,0,len(nums)-1,target)
        elif nums[pivotIndex]==target:
            ans=pivotIndex
        elif nums[0]<=target:
            ans=self.bs(nums,0,pivotIndex,target)
        elif(nums[0]>=target):
            ans=self.bs(nums,pivotIndex+1,len(nums)-1,target)
        return ans
        
        
