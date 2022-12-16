
// Time: O(NlogN)
// Space: O(N)
struct Transaction {
    string name;
    int time;
    int amount;
    string city;
    Transaction(string t) {
        istringstream ss(t);
        getline(ss, name, ',');
        string token;
        getline(ss, token, ',');
        time = stoi(token);
        getline(ss, token, ',');
        amount = stoi(token);
        ss >> city;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& A) {
        unordered_map<string, vector<int>> m;
        vector<Transaction> B;
        unordered_set<int> invalid;
        for (int i = 0; i < A.size(); ++i) {
            auto t = Transaction(A[i]);
            if (t.amount > 1000) invalid.insert(i);
            m[t.name].push_back(i);
            B.push_back(t);
        }
        for (auto &[p, ids] : m) {
            sort(begin(ids), end(ids), [&](int a, int b) { return B[a].time < B[b].time; });
            int i = 0, j = 0, k = 0, N = ids.size();
            unordered_map<string, int> cities;
            while (j < N) {
                while (B[ids[j]].time - B[ids[i]].time > 60) {
                    auto &c = B[ids[i++]];
                    if (--cities[c.city] == 0) cities.erase(c.city);
                }
                if (B[ids[j]].time - B[ids[i]].time <= 60) {
                    auto &c = B[ids[j++]];
                    cities[c.city]++;
                    if (cities.size() > 1) {
                        for (k = max(k, i); k < j; ++k) invalid.insert(ids[k]);
                    }
                }
            }
        }
        vector<string> ans;
        for (int i : invalid) ans.push_back(A[i]);
        return ans;
    }
};