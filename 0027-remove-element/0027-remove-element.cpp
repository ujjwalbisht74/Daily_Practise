class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j =0;

        for(int x : nums){
            if(x != val){
                nums[j++] = x;
            }
        }

        return j;
    }
};