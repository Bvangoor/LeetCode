class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int val = 0;
        for (int i=0, size=citations.size(); i<size; ++i) {
            if (citations[i] >= (size-i)) {
                val = size - i;
                break;
            }
        }
        return val;
    }
};
