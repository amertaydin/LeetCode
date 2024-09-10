// https://leetcode.com/problems/reconstruct-itinerary/description/

// Time Complexity: O(n logn)

// Space Complexity: O (n)

#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        map<string, priority_queue<string, vector<string>, greater<string>>> graph;

        for (const auto &ticket : tickets)
        {
            string from = ticket[0];
            string to = ticket[1];
            graph[from].push(to);
        }

        vector<string> itinerary;
        dfs("JFK", graph, itinerary);

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }

    void dfs(const string &current, map<string, priority_queue<string, vector<string>, greater<string>>> &graph, vector<string> &itinerary)
    {

        while (!graph[current].empty())
        {
            string nextAirport = graph[current].top();
            graph[current].pop();
            dfs(nextAirport, graph, itinerary);
        }
        itinerary.push_back(current);
    }
};