/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> v=binaryMatrix.dimensions();
        int row=v[0];
        int col=v[1];
        int ans=-1;
        int i=0,j=col-1;
        while(i<row && j>=0){
            if(binaryMatrix.get(i,j)==1){
                ans=j;
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
