#include <iostream>

using namespace std;

template <typename T>
class shared_ptr {
   T* ptr;
   int* ref_cnt;
   public:
      shared_ptr(T* p) { 
	 ptr = p; 
	 ref_cnt = new int; 
	 *ref_cnt = 0; 
      }
      shared_ptr(shared_ptr& sp) { 
	 ptr = sp.getPtr(); 
	 ref_cnt = sp.getRefCnt(); 
	 (*ref_cnt)++;
      }
      T& operator * () { return *ptr; }
      T* operator -> () { return ptr; }
      T* getPtr() { return ptr; }
      int* getRefCnt() { return ref_cnt; }
      ~shared_ptr() { 
	 if (*ref_cnt == 0) {
             delete ref_cnt;
	     delete ptr;
	     cout << "Destruct raw ptr" << endl;
         }
	 else {
             (*ref_cnt)--;
	     cout << "Destructor " << *ref_cnt << endl;
	 }
      }
};      
  
struct KV {
   int key;
   int val;
};

int main() {
   shared_ptr<int> a(new int);
   *a = 11;
   cout << "End1 " << *a << endl;
   shared_ptr<int> b = a;
   *b = 12;
   cout << "End2 " << *a << endl;
   if (true) {
       shared_ptr<int> c = a;
       *c = 13;
   }
   cout << "End3 " << *a << endl;
   shared_ptr<int> e = a;
   if (true) {
       shared_ptr<int> d = b;
       *d = 14;
   }
   cout << "End4 " << *a << endl;
   shared_ptr<KV> f(new KV{1, 2});
   cout << "End5 " << f->key << " " << f->val << endl;
   shared_ptr<KV> g = f;
   g->key = 12;
   g->val = 21;
   cout << "End6 " << f->key << " " << f->val << endl;
}
