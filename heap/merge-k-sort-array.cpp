class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // Min-heap: {value, {arrayIndex, elementIndex}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> minHeap;

        // Push the first element of each array into the heap
        for (int arrayIndex = 0; arrayIndex < K; arrayIndex++) {
            if (!arr[arrayIndex].empty()) {
                minHeap.push({arr[arrayIndex][0], {arrayIndex, 0}});
            }
        }

        vector<int> mergedArray;

        // Extract min and push next element from the same array
        while (!minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop();

            int value = current.first;
            int arrayIndex = current.second.first;
            int elementIndex = current.second.second;

            mergedArray.push_back(value);

            // Push the next element from the same array, if it exists
            if (elementIndex + 1 < arr[arrayIndex].size()) {
                minHeap.push({arr[arrayIndex][elementIndex + 1], {arrayIndex, elementIndex + 1}});
            }
        }

        return mergedArray;
    }
};
