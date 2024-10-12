int zeller(int y, int m, int d) {
	if(m < 3) y--, m += 12;
	int c = y / 100; y %= 100;
	int w = ((c >> 2) - (c << 1) + y + (y >> 2) + 13 * (m + 1) / 5 + d - 1) % 7;
	return w < 0 ? w + 7 : w;
} //sunday = 0;

int getId(int y, int m, int d) {
	if(m < 3) y--, m += 12;
	return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m + 3) / 5 + d - 398;
} //getId(1, 1, 1) = 1

int date_int(int y, int m, int d) {
	return 1461 * (y + 4800 + (m - 14) / 12) / 4 +
			367 * (m - 2 - (m - 14) / 12 * 12) / 12 -
			3 * ((y + 4900 + (m - 14) / 12) / 100) / 4 + d - 32075;
} // date_int(-4713, 11, 25) = 1

void int_date(int k, int &y, int &m, int &d) {
	int x = k + 68569, n = 4 * x / 146097;
	x -= (146097 * n + 3) / 4;
	int i = (4000 * (x + 1)) / 1461001;
	x -= 1461 * i / 4 - 31;
	int j = 80 * x / 2447;
	d = x - 2447 * j / 80, x = j / 11, m = j + 2 - 12 * x;
	y = 100 * (n - 49) + i + x;
} //int_date(1, y, m, d) -> y = -4713, m = 11, d = 25