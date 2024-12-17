class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }

        priority_queue<pair<char, int>> maxHeap;
        for (auto& [ch, count] : charCount) {
            maxHeap.push({ch, count});
        }

        string result = "";
        while (!maxHeap.empty()) {
            auto [currentChar, currentCount] = maxHeap.top();
            maxHeap.pop();
            
            int countToAdd = min(currentCount, repeatLimit);
            result.append(countToAdd, currentChar);
            currentCount -= countToAdd;

            if (currentCount > 0) {
                if (maxHeap.empty()) {
                    break; 
                }

                auto [nextChar, nextCount] = maxHeap.top();
                maxHeap.pop();
                
                result.push_back(nextChar);
                if (--nextCount > 0) {
                    maxHeap.push({nextChar, nextCount});
                }

                maxHeap.push({currentChar, currentCount});
            }
        }

        return result;
    }
};
