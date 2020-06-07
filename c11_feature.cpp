#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <set>
#include <tuple>
#include <memory>

using namespace std;

bool comp(const int& lhs, const int& rhs) {
   return (lhs > rhs);
}

int sum(const initializer_list<int>& list) {
  int total = 0;
  for (auto& e : list) {
    total += e;
  }

  return total;
}

int main() {
   array<int, 3> a1{ {1, 2, 3} }; // double-braces required in C++11 prior to the CWG 1270 revision
                                        // (not needed in C++11 after the revision and in C++14 and beyond)
   array<int, 3> a2 = {1, 2, 3};	
   
   auto comp1 = [](const int& lhs, const int& rhs){return lhs > rhs;};
   cout << comp1(a1.at(1), a1.at(2)) << endl;
   
   auto comp2 = [&](){return a1.at(2) > a1.at(1);};
   cout << comp2() << endl;

   sort(a1.begin(), a1.end(), comp);
   
   cout << a1.at(0) << endl; // " " << a1.at(3) << endl;
   
   cout << *(a2.data()+1) << endl;

   vector<int> v = {1, 3, 5, 7};
   v.emplace(v.begin()+1, 2);
   v.erase(v.begin()+2, v.end());

   set<int> s = {1, 3, 5, 3};
   vector<int> vv(s.begin(), s.end());
   for (auto i : vv)
       cout << i << " ";
  cout << endl;

  // Initializer lists
  initializer_list<int> l = {1, 3, 5, 3};
  cout << sum(l) << endl;

  // static assert
  constexpr int x = 0;
  constexpr int y = x;
  static_assert(x == y, "x != y");

  auto playerProfile = make_tuple(51, "Frans Nielsen", "NYI");
  cout << get<0>(playerProfile) << " " << get<1>(playerProfile) << " " << get<2>(playerProfile) << endl;

  // With tuples...
  string playerName;
  tie(ignore, playerName, ignore) = make_tuple(91, "John Tavares", "NYI");
  // With pairs...
  string yes, no;
  tie(yes, no) = make_pair("yes", "no");

  // Smart pointer
  unique_ptr<int[]> s1 = make_unique<int[]>(3);
  s1[2] = 2;
  cout << s1[0] << " " << s1[2] << endl;
  shared_ptr<int> s2 = make_shared<int>();
  *s2 = 2;
  decltype(s2) s22 = s2;
  *s22 = 1;
  cout << *s2 << endl;
  decltype(s1) s11 = move(s1);
  s11[2] = 3;
  s1 = move(s11);
  cout << s1[0] << " " << s1[2] << endl;
}
