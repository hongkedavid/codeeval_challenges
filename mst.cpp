#include <iostream>
#include <queue> 
#include <map>
#include <vector>
#include <set>
using namespace std;

struct Edge {
    int x;
    int y;
    int cost;
};

class cost_comparator {
    public:
       cost_comparator() {}
       bool operator() (const Edge& lhs, const Edge& rhs) {
	    return (lhs.cost > rhs.cost);
       }
};

int mst(int n, vector<vector<int>>& G) {
    priority_queue<Edge, vector<Edge>, cost_comparator> eq;
    for (int i = 0; i < G.size(); i++) {
         Edge e = {G[i][0], G[i][1], G[i][2]};
         eq.push(e);
    }
    int curr_set_num = n;
    int curr_cost = -1;
    map<int, int> node_ptr; //map<int, set<int>*> node_ptr;
    for (int i = 0; i < n; i++) {
	node_ptr[i] = i; //node_ptr[i] = new set<int>(); 
	//node_ptr[i]->insert(i);
    }
    while (!eq.empty()) {
	 Edge e = eq.top();
	 cout << e.x << " " << e.y << " " << e.cost << " " << curr_set_num << "\n";
	 curr_cost = e.cost;
         if (node_ptr[e.x] != node_ptr[e.y]) {
	     //node_ptr[e.y]->insert(node_ptr[e.x]->begin(), node_ptr[e.x]->end());
	     //node_ptr[e.x]->clear();
	     node_ptr[e.x] = node_ptr[e.y];
	     curr_set_num--;
	 }
	 if (curr_set_num <= 1)
	     break;	 
	 eq.pop();
    }
    if (curr_set_num > 1)
	return -1;
    else
        return curr_cost;
}

int main() {    
    vector<vector<int>> G;
    vector<int> a;
    a.push_back(1); a.push_back(0); a.push_back(2);
    G.push_back(a); a.clear();
    a.push_back(1); a.push_back(2); a.push_back(4);
    G.push_back(a); a.clear();
    a.push_back(0); a.push_back(2); a.push_back(3);
    G.push_back(a); a.clear();
    cout << mst(3, G) << "\n";
    return 0;
}
