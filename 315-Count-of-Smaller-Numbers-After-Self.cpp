class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        vector<pair<int, int>> num_idx;

        for (int i = 0; i < n; i++) {
            num_idx.push_back({nums[i], i});
        }

        mergeSort(num_idx, result, 0, n - 1);

        return result;
    }

    void mergeSort(vector<pair<int, int>>& num_idx, vector<int>& result, int left, int right) {
        if (left >= right) return;  

        int mid = left + (right - left) / 2;
        mergeSort(num_idx, result, left, mid);
        mergeSort(num_idx, result, mid + 1, right);
        merge(num_idx, result, left, mid, right);
    }

    void merge(vector<pair<int, int>>& num_idx, vector<int>& result, int left, int mid, int right) {
        vector<pair<int, int>> temp;
        int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
            if (num_idx[i].first > num_idx[j].first) {
                result[num_idx[i].second] += (right - j + 1);
                temp.push_back(num_idx[i++]);
            } else {
                temp.push_back(num_idx[j++]);
            }
        }

        while (i <= mid) temp.push_back(num_idx[i++]);
        while (j <= right) temp.push_back(num_idx[j++]);

        for (int i = left; i <= right; i++) {
            num_idx[i] = temp[i - left];
        }
    }
};
