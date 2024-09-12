class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin() ,words.end(), [](const string & a, const string &b){
            return  a.size() < b.size();
        });

        int size = words.size();

        vector<string>res;

        for(int i =0; i < size ; i++){
            for(int j = i+1 ; j < words.size() ; j++){
                if(words[j].find(words[i]) != string::npos){
                    res.emplace_back(words[i]);
                    break;
                }
            }
        }

        return res;

    }
};