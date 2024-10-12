#include<bits/stdc++.h>

using namespace std;

char s[22], a[11];

int main() {
	puts("Please input number of Problems (5/e/E):");
    
	int k = 200, n;
	while(--k) {
    	sprintf(s, "%d\\in.txt", k);
    	if(fopen(s, "r")) break;
    }
	k++;
    
	scanf("%s", a);
	if(isdigit(a[0])) n = atoi(a);
	else if(islower(a[0])) n = a[0] - 'a' + 1;
	else n = a[0] - 'A' + 1;
    
	sprintf(s, "md %d", k);
	sprintf(s, "md %d\\Hint", k), system(s);
	sprintf(s, "%d\\Hint\\Hint.txt", k), freopen(s, "w", stdout);
	sprintf(s, "md %d\\Problem", k), system(s);
	sprintf(s, "%d\\Problem\\Problem.txt", k), freopen(s, "w", stdout);
	sprintf(s, "md %d\\Standing", k), system(s);
    
	sprintf(s, "%d\\in.txt", k), freopen(s, "w", stdout);
	sprintf(s, "%d\\out.txt", k), freopen(s, "w", stdout);
	sprintf(s, "%d\\test.txt", k), freopen(s, "w", stdout);
    
	sprintf(s, "%d\\Run.bat", k), freopen(s, "w", stdout);
	puts("\"MakeTest\"");
	puts("\"Test\"");
	puts("\"Trivial\"");
    
	sprintf(s, "%d\\Rand.cpp", k), freopen(s, "w", stdout);
	puts("#include<bits/stdc++.h>");
	puts("");
	puts("using namespace std;");
	puts("");
	puts("string s, t;");
	puts("char u[19990728];");
	puts("");
	puts("int main() {");
	puts("	for(int i = 77; i--; ) {");
	puts("    	system(\"run.bat\");");
	puts("    	s.clear(), t.clear();");
	puts("    	freopen(\"out.txt\", \"r\", stdin);");
	puts("    	while(gets(u)) s += u;");
	puts("    	freopen(\"test.txt\", \"r\", stdin);");
	puts("    	while(gets(u)) t += u;");
	puts("    	while(s != t) puts(\"\\a\\n\\nWrong Answer\"), exit(0);");
	puts("    }");
	puts("	puts(\"\\a\\n\\nAccepted\");");
	puts("	return 0;");
	puts("}");
    
	sprintf(s, "%d\\Test.cpp", k), freopen(s, "w", stdout);
	sprintf(s, "%d\\Trivial.cpp", k), freopen(s, "w", stdout);
	puts("#include<bits/stdc++.h>");
	puts("#define y second");
	puts("#define x first");
	puts("");
	puts("using namespace std;");
	puts("using INT = long long;");
	puts("using pii = pair<int, int>;");
	puts("");
	puts("int main() {");
	puts("#ifndef ONLINE_JUDGE");
	puts("	freopen(\"in.txt\", \"r\", stdin);");
	puts("	freopen(\"test.txt\", \"w\", stdout);");
	puts("#endif");
	puts("    ");
	puts("    ");
	puts("	return 0;");
	puts("}");
    
	sprintf(s, "%d\\MakeTest.cpp", k), freopen(s, "w", stdout);
	puts("#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())");
	puts("#include<bits/stdc++.h>");
	puts("#define y second");
	puts("#define x first");
	puts("");
	puts("using namespace std;");
	puts("using INT = long long;");
	puts("using pii = pair<int, int>;");
	puts("");
	puts("int main() {");
	puts("	freopen(\"in.txt\", \"w\", stdout);");
	puts("    ");
	puts("	srand(time(0));");
	puts("    ");
	puts("	return 0;");
	puts("}");
    
	for(int i = 0; i < n; i++) {
    	sprintf(s, "%d\\(%c).cpp", k, 'A' + i);
    	freopen(s, "w", stdout);
    	puts("#include<bits/stdc++.h>");
    	puts("#define y second");
    	puts("#define x first");
    	puts("");
    	puts("using namespace std;");
    	puts("using INT = long long;");
    	puts("using pii = pair<int, int>;");
    	puts("");
    	puts("int main() {");
    	puts("#ifndef ONLINE_JUDGE");
    	puts("	freopen(\"in.txt\", \"r\", stdin);");
    	puts("    //freopen(\"out.txt\", \"w\", stdout);");
    	puts("#endif");
    	puts("    ");
    	puts("    ");
    	puts("	return 0;");
    	puts("}");
    }
	return 0;
}
