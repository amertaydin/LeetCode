// Time Complexity O(nlogn+Wlogp) nlogn for sorting and W logp for traversing words and checking set members

// Space complexity O (n + p) for set and vector

#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] >= b[0];
    }

    vector<int> topStudents(vector<string> &positive_feedback,
                            vector<string> &negative_feedback,
                            vector<string> &report, vector<int> &student_id,
                            int k)
    {
        set<string> pos(positive_feedback.begin(), positive_feedback.end());
        set<string> neg(negative_feedback.begin(), negative_feedback.end());

        vector<vector<int>> scores;
        for (int i = 0; i < report.size(); i++)
        {
            int score = 0;
            stringstream s(report[i]);
            string word;
            while (s >> word)
            {
                // find negative comment
                if (neg.find(word) != neg.end())
                {
                    score -= 1;
                }

                if (pos.find(word) != pos.end())
                {
                    score += 3;
                }
            }
            scores.push_back({score, student_id[i]});
        }

        sort(scores.begin(), scores.end(), comp);

        vector<int> result;
        for (int i = 0; i < k && i < scores.size(); i++)
        {
            result.push_back(scores[i][1]); // getting id
        }

        return result;
    }
};