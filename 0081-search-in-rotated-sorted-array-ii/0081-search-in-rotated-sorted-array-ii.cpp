class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high =  nums.size()-1;

        while(low <= high){
            int mid = low +  (high - low)/2;

            if(nums[mid] == target){
                return true;
            }

            if(nums[low] == nums[high]){
                high--;
                continue;
            }

            if(nums[mid] >= nums[low]){
                if(nums[low] <= target && nums[mid] >= target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(nums[mid] <= target && nums[high] >= target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        } 

        return false;
    }
};