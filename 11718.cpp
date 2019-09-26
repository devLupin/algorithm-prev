#include<cstdio>
#include<cstring>
int main()
{	
	char s[101]; scanf("%s", s);
	for (int i = 0, c = 1; i < strlen(s); i++,c++) {
		if (!(c % 10) && c != 1) printf("%c\n",s[i]);
		else printf("%c", s[i]);
	}
}