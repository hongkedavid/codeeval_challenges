/*
We are testing Nurobots on an open field.
There are bots and packages scattered across the field.
Each bot tries to drive to a package to pick it up. Only one bot per package. 
We’ve decided to have the bots behave with the following simple rule: 
    drive towards the closest package that another bot will not get to first.

Implement a method that given a bot, returns the package it goes to.

Assume equal number of bots as packages.
Assume all bots know the exact locations of all other bots and packages.
Assume bots move only up, down, left, right at the same constant speed and immediate turning.
Assume no ties - no two bots are the same distance to the same package, and no two packages are the same distance to the same bot.
Assume no collisions - Nurobots can just pass through each other.

Input: vector<vector<int>> bot; vector<vector<int>> pkg;
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct BotPkg {
    int bot_id;
    int pkg_id;
    int cost;
};

class comp {
    public: 
       comp() {}
       bool operator() (const BotPkg& lhs, const BotPkg& rhs) {
           return (lhs.cost > rhs.cost);
       }
};

int botPackage(int bid, vector<vector<int>>& bot, vector<vector<int>>& pkg) {
    priority_queue<BotPkg, vector<BotPkg>, comp> pq;
    for (int i = 0; i < bot.size(); i++) {
        for (int j = 0; j < pkg.size(); j++) {
            int c = abs(bot[i][0]-pkg[j][0]) + abs(bot[i][1]-pkg[j][1]);
            pq.push({i, j, c});
        }
    }
    vector<bool> bot_selected(bot.size(), false);
    vector<bool> pkg_selected(pkg.size(), false);
    while (!pq.empty()) {
        BotPkg curr = pq.top();
        if (!bot_selected[curr.bot_id] && !pkg_selected[curr.pkg_id]) {
            if (curr.bot_id == bid)
                return curr.pkg_id;
            else {
                bot_selected[curr.bot_id] = true;
                pkg_selected[curr.pkg_id] = true;
            }
        }
        pq.pop();
    }
}

/*
N----P
-----N
N-P-P-
*/

int main() {
    vector<vector<int>> bot = {{0, 0}, {1, 5}, {2, 0}};
    vector<vector<int>> pkg = {{0, 5}, {2, 2}, {2, 4}};
    cout << botPackage(0, bot, pkg) << endl;
    return 0;
}
