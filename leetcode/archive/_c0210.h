//
// Created by fangding on 2020-01-31.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0), bfs;
        for (auto p : prerequisites) {
            if (p[0] == p[1]) {
                continue;
            }
            graph[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                bfs.push_back(i);
            }
        }
        for (int i = 0; i < bfs.size(); ++i) {
            for (auto g : graph[bfs[i]]) {
                --indegree[g];
                if (0 == indegree[g]) {
                    bfs.push_back(g);
                }
            }
        }
        if (bfs.size() != numCourses) {
            bfs.clear();
        }
        return bfs;
    }

    void _print(vector<int>& vec) {
        for (auto v : vec) {
            cout << v << ",";
        }
        cout << endl;
    }
};


void func() {
    Solution solution;
    int numCourses = 2;
    vector<vector<int>> prerequisites;
    vector<int> tmp{1,0};
    prerequisites.push_back(tmp);
    vector<int> res = solution.findOrder(numCourses, prerequisites);
    solution._print(res);
}

