class Solution {
public:
    int give_row(vector<vector<int>>& matrix, int target) {
        int rows;
        rows = matrix.size();
        for (int i=0;i<rows;i++) {
            if (target<matrix[i][0])
                return (i-1);
        }
        return (rows-1);
    }
    
    bool check_element(vector<int>& nums, int target) {
        int len=nums.size();
        if(len==0)
            return false;
        for (int i=0;i<len;i++) {
            if (nums[i]==target)
                return true;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int no_of_rows_check, len, column;
        len = matrix.size();
        if (len==0)
            return false;
        no_of_rows_check = give_row(matrix, target);
        //cout<<"no of rows check : "<<no_of_rows_check<<"\n";
        if (no_of_rows_check==-1)
            return false;
        for (int i=0;i<=no_of_rows_check;i++) {
            column = matrix[i].size();
            if(matrix[i][0]<=target && target<=matrix[i][column-1]) {
                 if(check_element(matrix[i], target))
                    return true;
            }
        }
        return false;
    }
};
