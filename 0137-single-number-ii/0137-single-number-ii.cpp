class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0 ;

        for(int i = 0; i  < 32; i++){
            int sum = 0 ;

            for(auto t : nums){
                sum += (t >> i & 1);
            }

            sum %=3;
            res |= (sum << i);
        }

        return res;
    }
};