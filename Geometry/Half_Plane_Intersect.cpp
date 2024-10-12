using line = pair<point, point>;

bool is_in(line c, line a, line b) {
	DO s = a.x - b.x ^ b.y - b.x, t = b.y - b.x ^ a.y - b.x, m;
	return fabs(m = s + t) > eps && (a.x * (t / m) + a.y * (s / m) - c.y ^ c.x - c.y) > eps;
}
vector<line> half(vector<line> L) {
	int n = L.size(), i = n;
	vector<DO> a(n); vector<int> I(n); vector<line> b; deque<line> q;
	while(i--) a[I[i] = i] = (L[i].y - L[i].x).al();
	sort(I.begin(), I.end(), [&](int u, int v) {
		return fabs(a[u] - a[v]) > eps ? a[u] < a[v] : (L[v].y - L[u].y ^ L[u].x - L[u].y) < -eps;});
	b.push_back(L[I[++i]]);
	while(++i < n) if(fabs(a[I[i]] - a[I[i - 1]]) > eps) b.push_back(L[I[i]]);
	for(line L : b) {
		while(q.size() > 1 && !is_in(L, q[q.size() - 2], q.back())) q.pop_back();
		while(q.size() > 1 && !is_in(L, q[0], q[1])) q.pop_front();
		q.push_back(L);
	}
	while(q.size() > 2 && !is_in(q[0], q[q.size() - 2], q.back())) q.pop_back();
	while(q.size() > 2 && !is_in(q.back(), q[0], q[1])) q.pop_front();
	return vector<line>(q.begin(), q.end());
}