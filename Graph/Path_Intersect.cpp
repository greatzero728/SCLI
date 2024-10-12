void merge(int &A, int &B, int a, int b) {
	if(!~A || !~a) return;
	int u, v, x, y, w = lc.lca(A, B);
	u = lc.lca(A, a), v = lc.lca(B, a), x = dep[u] < dep[v] ? v : u;
	u = lc.lca(A, b), v = lc.lca(B, b), y = dep[u] < dep[v] ? v : u;
	if(dep[x] < dep[w] && dep[y] < dep[w]) A = B = -1;
	else if(x == y && lc.lca(a, b) ^ x) A = B = -1;
	else A = dep[x] < dep[w] ? w : x, B = dep[y] < dep[w] ? w : y;
}