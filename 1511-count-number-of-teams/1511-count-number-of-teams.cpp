class Solution {
public:
    int numTeams(vector<int>& rating) {
        int maxRating = 0;
        for (int r : rating) {
            maxRating = max(maxRating, r);
        }

        vector<int> leftBIT(maxRating + 1, 0);
        vector<int> rightBIT(maxRating + 1, 0);

        for (int r : rating) {
            updateBIT(rightBIT, r, 1);
        }

        int teams = 0;
        for (int currentRating : rating) {
            updateBIT(rightBIT, currentRating, -1);

            int smaller_left = getPrefixSum(leftBIT, currentRating - 1);
            int smaller_right = getPrefixSum(rightBIT, currentRating - 1);
            int larger_left = getPrefixSum(leftBIT, maxRating) -
                                    getPrefixSum(leftBIT, currentRating);
            int larger_right = getPrefixSum(rightBIT, maxRating) -
                                     getPrefixSum(rightBIT, currentRating);

            teams += (smaller_left * larger_right);
            teams += (larger_left * smaller_right);

            updateBIT(leftBIT, currentRating, 1);
        }

        return teams;
    }

private:
    void updateBIT(vector<int>& BIT, int index, int value) {
        while (index < BIT.size()) {
            BIT[index] += value;
            index +=
                index & (-index);  
        }
    }

    int getPrefixSum(vector<int>& BIT, int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & (-index);  
        }
        return sum;
    }
};