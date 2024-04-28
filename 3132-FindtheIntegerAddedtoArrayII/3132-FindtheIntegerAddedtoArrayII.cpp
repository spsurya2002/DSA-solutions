        }
        return {true, c};
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < nums1.size() - 1; i++) {
            for (int j = i + 1; j < nums1.size(); j++) {
                pair<bool, int> b = check(nums1, nums2, i, j);
[
