class Solution {
public:
    int countSeniors(vector<string>& details) {
        int size = details.size();

        int count = 0;

        for(string  & str : details){
            if(str.substr(str.size()-4,2) > "60"){
                count++;
            }
        }

        return count;
    }
};