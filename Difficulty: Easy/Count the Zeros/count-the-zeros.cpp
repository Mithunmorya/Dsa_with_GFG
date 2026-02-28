// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        // code here
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int firstidx = -1;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            if(arr[mid]==0){
                firstidx = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        if(firstidx==-1)
        return 0;
        else
        return n-firstidx;
        
    }
};