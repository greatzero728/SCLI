#include<bits/stdc++.h>

using namespace std;

const int NN = 10101;

char s[NN], id[NN];

int main() {
	puts("Please input the id of problem.");
    
	gets(id + 1);
	id[0] = '(', id[strlen(id + 1) + 1] = ')';
    
	sprintf(s, "md \"%s\"", id), system(s);
    sprintf(s, "md \"%s\\Source\"", id), system(s);
//	sprintf(s, "md \"%s\\Hint\"", id), system(s);
//	sprintf(s, "md \"%s\\Problem\"", id), system(s);
//	sprintf(s, "md \"%s\\test\"", id), system(s);
    
	sprintf(s, "%s\\Run.bat", id), freopen(s, "w", stdout);
//	puts("ren *.a *.out.txt");
//	puts("ren * *.txt");
    
	puts("\"MakeTest\"");
	printf("\"%s\"\n", id);
	puts("\"Trivial\"");


	sprintf(s, "%s\\in.txt", id), freopen(s, "w", stdout);
	sprintf(s, "%s\\product[en].txt", id), freopen(s, "w", stdout);
    sprintf(s, "%s\\product[ru].txt", id), freopen(s, "w", stdout);
	sprintf(s, "%s\\out.txt", id), freopen(s, "w", stdout);
	sprintf(s, "%s\\test.txt", id), freopen(s, "w", stdout);
//	sprintf(s, "%s\\Hint\\Hint.txt", id), freopen(s, "w", stdout);
//	sprintf(s, "%s\\Problem\\Problem.txt", id), freopen(s, "w", stdout);
    
	sprintf(s, "%s\\Rand.cpp", id), freopen(s, "w", stdout);
	puts("#include <bits/stdc++.h>");
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
    
    
	sprintf(s, "%s\\%s.cpp", id, id), freopen(s, "w", stdout);
	puts("#include <bits/stdc++.h>");
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
	puts("#endif");
	puts("    ");
	puts("    ");
	puts("    return 0;");
	puts("}");
    
	sprintf(s, "%s\\Trivial.cpp", id), freopen(s, "w", stdout);
//	puts("#include<bits/stdc++.h>");
//	puts("#define y second");
//	puts("#define x first");
//	puts("");
//	puts("using namespace std;");
//	puts("using INT = long long;");
//	puts("using pii = pair<int, int>;");
//	puts("");
//	puts("int main() {");
//	puts("#ifndef ONLINE_JUDGE");
//	puts("	freopen(\"in.txt\", \"r\", stdin);");
//	puts("	freopen(\"test.txt\", \"w\", stdout);");
//	puts("#endif");
//	puts("    ");
//	puts("    ");
//	puts("	return 0;");
//	puts("}");
    
	sprintf(s, "%s\\MakeTest.cpp", id), freopen(s, "w", stdout);
	puts("#define rnd (((((INT)rand() << 15) | rand()) << 15) | rand())");
	puts("#include <bits/stdc++.h>");
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
	return 0;
}
