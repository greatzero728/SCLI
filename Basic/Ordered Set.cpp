#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using sot = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	sot s;
	s.insert(1), s.insert(1), s.insert(2), s.insert(3);
	cout<<s.order_of_key(3)<<endl;
	// the number of elements in the s less than 3
	cout<<*s.find_by_order(0)<<endl;
	// print the 0-th smallest number in the s (0-based)
}