class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++){
                row[j]=prev[j-1]+prev[j];
            }
            ans.push_back(row);
            prev=row;
        }
        return ans;
    }
};
