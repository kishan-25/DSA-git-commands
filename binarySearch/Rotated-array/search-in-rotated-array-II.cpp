class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int start = 0, end = arr.size()-1;
        int mid = start + (end - start)/2;
        if(arr.size() >= 3)
        {
            while(arr[start] == arr[mid] && arr[mid] == arr[end])
            {
                start = start + 1;
                end = end - 1;
            }
        }
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(arr[mid] == target)
                return true;
            
          
            // ab find krne pdega ki konse hisa sorted h
            if(arr[start] <= arr[mid])
            {
                // ab check krenge ki konse part me lie krte h target element 
                if(target >= arr[start] && target < arr[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else
            {
                if(target > arr[mid] && target <= arr[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};