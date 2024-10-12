struct HuffmanCode {
	HuffmanCode() {}
	~HuffmanCode() {delete top;}
	
	struct node {
		node(char chr, int cnt) : chr(chr), cnt(cnt), ls(NULL), rs(NULL) {}
		~node() {delete ls, rs;}
		char chr; int cnt;
		node *ls, *rs;
	} *top;
	struct cmp {
		bool operator() (node *l, node *r) {
			return l->cnt > r->cnt;
		}
	};
	
	void print(node *root, string str) {
		if(root == NULL) return;
		if(root->chr == '$') {
			print(root->ls, str + "0");
			print(root->rs, str + "1");
		}
		if(root->chr != '$') {
			cout<<root->chr<<" : "<<str<<endl;
			print(root->ls, str + "0");
			print(root->rs, str + "1");
		}
	}
	
	void build(vector<char> &chr, vector<int> &cnt, int size) {
		node *ls, *rs;
		priority_queue<node*, vector<node*>, cmp> pq;
		
		for(int i = 0; i < size; i++) {
			pq.push(new node(chr[i], cnt[i]));
		}
		
		while(pq.size() != 1) {
			ls = pq.top(), pq.pop();
			rs = pq.top(), pq.pop();
			
			top = new node('$', ls->cnt + rs->cnt);
			top->ls = ls, top->rs = rs, pq.push(top);
		}
		print(pq.top(), "");
	}
};