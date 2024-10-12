//       0  1
//       2  3
// 4  5  6  7  8  9 10 11
//12 13 14 15 16 17 18 19
//  U   20 21
// LFRB 22 23
//  D

int r_[8][12] = {
	{0,2,3,1, 4,6,7,10, 5,7,9,11},
	{4,12,13,5, 2,11,22,14, 0,19,20,6},
	{6,14,15,7, 3,5,20,16, 2,13,21,8},
	{8,16,17,9, 1,7,21,18, 3,15,23,10},
	{10,18,19,11, 0,9,23,12, 1,17,22,4},
	{20,22,23,21, 13,19,17,15, 1,17,22,4},
	{2,0,1,3, 6,7,15,14, 5,13,12,4},
	{23,22,20,21, 18,10,11,9, 17,16,8,9}
}, rot[6][24], id[24][24] = {
	{10,11,18,19, 9,17,23,22, 12,4,0,1, 8,16,21,20, 13,5,2,3, 15,14,7,6}
}, rev[24] = {1,0,3,2, 9,8,7,6, 5,4,11,10, 17,16,15,14, 13,12,19,18, 21,20,23,22};

void rote(int *a, int *b, int *c) {
	int i = 0;
	while(i < 4) b[c[i]] = a[c[i + 8]], i++;
	while(i < 12) b[c[i]] = a[c[i - 4]], i++;
}
void change(int i, int j) {
	rote(id[i], id[j], r_[6]), rote(id[i], id[j], r_[7]);
}
void init() {
	int i = 6, j, k = 24;
	while(k--) id[3][k] = k;
	while(i--) {
		j = 24; while(j--) rot[i][j] = j;
		j = 11; while(j--) rot[i][r_[i][j]] = r_[i][j + 1];
		for(j = 3; j < 12; j += 4) rot[i][r_[i][j]] = r_[i][j - 3];
	}
	for(i = 0; i < 4; i += 3) change(i, i + 1), change(i + 1, i + 2);
	while(i--) for(j = i + 6; j < 24; j += 6) {
		k = 24; while(k--) id[j][rot[0][k]] = id[j - 6][rot[5][k]];
	}
}