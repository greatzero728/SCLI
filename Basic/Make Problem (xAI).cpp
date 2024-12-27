#include<bits/stdc++.h>

using namespace std;

const int NN = 10101;

char s[NN], id[NN];

int main() {
	puts("Please input the task ID:");
    string taskID;
    cin>>taskID;
    
    puts("Please input the row index in googlesheet:");
    string rowIndex;
    cin>>rowIndex;
    
    puts("Please input the contest ID:");
    string contestID;
    cin>>contestID;
    
    puts("Please input the index in the contest:");
    string indexInContest;
    cin>>indexInContest;
    
    int nn = 0;
    id[nn++] = '(';
    for(char c : rowIndex) id[nn++] = c;
    id[nn++] = '_';
    for(char c : contestID) id[nn++] = c;
    id[nn++] = '_';
    for(char c : indexInContest) id[nn++] = c;
    id[nn++] = ')';
    
    sprintf(s, "md \"%s\"", id), system(s);
    sprintf(s, "md \"%s\\Result\"", id), system(s);


	sprintf(s, "%s\\statement.txt", id), freopen(s, "w", stdout);
	sprintf(s, "%s\\hint.txt", id), freopen(s, "w", stdout);
    
	sprintf(s, "%s\\%s.cpp", id, taskID.c_str()), freopen(s, "w", stdout);
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
}