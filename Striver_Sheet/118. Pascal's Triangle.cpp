class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;
        for(int i=0;i<numRows;i++){
            vector<int>row(i+1,1);
            for(int j=1;j<i;j++){
                row[j]=prev[j-1]+prev[j];
            }
            ans.push_back(row);
            prev=row;
        }
        return ans;
    }
};



/*
-> Initial Thought

The question was construction type so got confused in the postitioning since the 2D matrix array gets updated. i was able to construct the formula for posiitioning it was 0 indexed so i changed a bit but that was also possible

-> Mistake

i tried to make the matrixthen tried to increase the the size and insertion both at the same time with the formula

-> Solution

First was the inital 2D matrix making the we will ue two forlopp one for the size of the matrix other for the increasing array in each 1 to i with in the array. after the first for loop we willl make a vector that will increase it size time to the for loop and insert the v[i-1][j-1] + v[i-1][j] in thafterat array then that array will in incerted right afterthe the second forloop is finished ....... There is a DP approch too it updates the previous array to the updating array after the for loop

*/