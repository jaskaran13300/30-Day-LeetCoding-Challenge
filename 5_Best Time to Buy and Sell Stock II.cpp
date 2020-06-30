class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit=0,a=0,b=0;
        int n=arr.size();
        if(n==0 || n==1){
            return 0;
        }
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]<arr[i+1]){
                a=arr[i];
                // i++;
                // while(arr[i]<=arr[i+1] && i+1<=n-1){
                //     i++;
                // }
                b=arr[i+1];
                profit=profit+(b-a);
                // i--;
            }
        }
        return profit;
    }
};
