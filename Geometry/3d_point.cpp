struct point {
	DO x, y, z;
	point(DO x = 0, DO y = 0, DO z = 0) : x(x), y(y), z(z) {}
	point operator + (point a) {return point(x + a.x, y + a.y, z + a.z);}
	point operator - (point a) {return point(x - a.x, y - a.y, z - a.z);}
	point operator * (DO a) {return point(x * a, y * a, z * a);}
	point operator / (DO a) {return point(x / a, y / a, z / a);}
	point operator ^ (point a) {return point(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x);}
	point norm() {DO s = nor(); return s < eps ? *this : point(x / s, y / s, z / s);}
	DO nor() {return sqrt(*this * *this);}
	DO operator * (point a) {return x * a.x + y * a.y + z * a.z;}
	bool operator < (const point &a) const {
		return fabs(x - a.x) > eps ? x < a.x : fabs(y - a.y) < eps ? y < a.y : z < a.z;
	}
	bool operator > (const point &a) const {
		return fabs(x - a.x) > eps ? x > a.x : fabs(y - a.y) > eps ? y > a.y : z > a.z;
	}
	bool operator != (const point &a) const {
		return fabs(x - a.x) > eps || fabs(y - a.y) > eps || fabs(z - a.z) > eps;
	}
	bool operator == (const point &a) const {
		return fabs(x - a.x) < eps && fabs(y - a.y) < eps && fabs(z - a.z) < eps;
	}
	void input() {scanf("%lf %lf %lf", &x, &y, &z);}
	void print() {printf("%lf %lf %lf", x, y, z);}
};

int sgn(DO a) {return a < -eps ? -1 : a > eps;}
DO area(point a, point b, point c) {
	return (b - a ^ c - a).nor() / 2;
}
DO volume(point a, point b, point c, point d) {
	return fabs((b - a ^ c - a) * (d - a) / 6);
}