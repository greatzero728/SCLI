struct MultiSet {
	PQ in, out;
	void c() {while(!out.empty() && in.top() == out.top()) in.pop(), out.pop();}
	bool empty() {return c(), in.empty();}
	int top() {return c(), in.top();}
	void insert(int x) {in.push(x);}
	void erase(int x) {out.push(x);}
	void clear() {in = out = PQ();}
};