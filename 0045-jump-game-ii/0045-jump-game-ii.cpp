class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();

        if(size == 1) return 0;

        int curr = 0 , far = 0 , jumps = 0;

        for(int i = 0 ; i < size;  i++){
            far = max(far ,  nums[i] + i);

            if(i == curr){
                jumps++;
                curr = far;

                if(curr >= size-1) break;
            }
        }

        return jumps;
    }
};