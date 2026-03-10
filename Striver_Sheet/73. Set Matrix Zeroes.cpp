class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool zerocheck=false;
        for(int row=0;row<n;row++){
            if(matrix[row][0]==0) zerocheck=true;
            for(int col=1;col<m;col++){
                if(matrix[row][col]==0){
                    matrix[row][0]=0;
                    matrix[0][col]=0;
                }
            }
        }
        for(int row=n-1;row>=0;row--){
            for(int col=m-1;col>=1;col--){
                if(matrix[row][0]==0 || matrix[0][col]==0){
                    matrix[row][col]=0;
                }
            }
            if(zerocheck){
            matrix[row][0]=0;
        }
        }
        
        
    }
};

/*

-> Initial Thought

It was really confusing at first but turns out. It really is reasonable, secnd i had a thought of modifiing the current matrix itself is great. then the logic of marking the pointer was much more reachable.
 but need to clarify how to think and implement that in the future.

 
-> Mistake

I didn't thought of what will happen if the given marker 0 is being affected. I only thought of how to make 0 in all row and colum of that one or two zero positions
 
-> Solution

There are 2 loop process here, one is to state the row and column to be zero'd by marking the v[row][0]and v[0][col] here. and we will be makignna bool check for first colum because we don't want to hinder the already marker position, that is a separate matter we can disucs at last. for the second loop after we markered the row and colmn to be zerod we will process the zero making from bottom -> top and right -> left, we are doing in reverse order becasue we don't want to affect the marker we added at the begining.

-> Look

When matrix borders are used as markers, process the matrix backwards so markers are not overwritten too early.
 
 */

