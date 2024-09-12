class Solution {
public:
    void solve(int index , vector<int> & nums, vector<int>temp , vector<vector<int>> &res){
        res.emplace_back(temp);

        for(int i=index;i<nums.size();i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;

        sort(nums.begin(),nums.end());

        solve(0 ,nums,temp,res);
        
        return res;
    }
};