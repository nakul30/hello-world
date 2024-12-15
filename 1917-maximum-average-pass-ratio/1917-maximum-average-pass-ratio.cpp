class Solution {
public:
  double calculate_gain(int passes, int total) {
    return (double)(passes + 1) / (total + 1) - (double)passes / total;
  }

  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<pair<double, pair<int, int>>> pq;  // Min-heap for gain calculation

    for (int i = 0; i < classes.size(); i++) {
      pq.push({calculate_gain(classes[i][0], classes[i][1]), {classes[i][0], classes[i][1]}});
    }

    while (extraStudents--) {
      auto topClass = pq.top();
      pq.pop();
      int passes = topClass.second.first;
      int total = topClass.second.second;

      pq.push({calculate_gain(passes + 1, total + 1), {passes + 1, total + 1}});
    }

    double ans = 0;
    while (!pq.empty()) {
      pair<int, int> second = pq.top().second;
      ans += (double)second.first / second.second;
      pq.pop();
    }
    return ans / classes.size();
  }
};