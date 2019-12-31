#include<stdio.h>
#include<string.h>
#include<ctype.h>

char prog[80], token[80];
char ch;
int syn, p, m, n, sum;
char* rwtab[6] = { "begin", "if", "then", "while", "do", "end" };
int scaner(void);
int scaner() {
	m = 0;
	sum = 0;
	for (n = 0; n <= 8; n++)
		token[n] = '\0';
	ch = prog[p++];
	while (isspace(ch))
		ch = prog[p++];
	if (isalpha(ch)) {
		while (isalnum(ch)) {
			token[m++] = ch;
			ch = prog[p++];
		}
		token[m++] = '\0';
		p--;
		syn = 10;
		for (n = 0; n<6; n++)
			if (strcmp(token, rwtab[n]) == 0) {
				syn = n + 1;
				break;
			}
	}
	else if (isdigit(ch)) {
		while (isdigit(ch)) {
			sum = sum * 10 + ch - '0';
			ch = prog[p++];
		}
		p--;
		syn = 11;
	}
	else
		switch (ch) {
		case '<':m = 0; token[m++] = ch;
			ch = prog[p++];
			if (ch == '>') {
				syn = 21;
				token[m++] = ch;
			}
			else if (ch == '=') {
				syn = 22;
				token[m + 1] = ch;
			}
			else {
				syn = 20;
				p--;
			}
			break;
		case '>': m = 0;
			token[m++] = ch;
			ch = prog[p++];
			if (ch == '=') {
				syn = 24;
				token[m++] = ch;
			}
			else {
				syn = 24;
				p--;
			}
			break;
		case ':': m = 0;
			token[m++] = ch;
			ch = prog[p++];
			if (ch == '=') {
				syn = 18;
				token[m++] = ch;
			}
			else {
				syn = 18;
				p--;
			}
			break;
		case '+':syn = 13; token[0] = ch; break;
		case '-':syn = 14; token[0] = ch; break;
		case '*':syn = 15; token[0] = ch; break;
		case '/':syn = 16; token[0] = ch; break;
		case '=':syn = 25; token[0] = ch; break;
		case ';':syn = 26; token[0] = ch; break;
		case '(':syn = 27; token[0] = ch; break;
		case ')':syn = 28; token[0] = ch; break;
		case '#':syn = 0; token[0] = ch; break;
		default:syn = -1;
		}
	return syn;
}
int main() {
	p = 0;
	printf("\nplease input string: \n");
	do {
		ch = getchar();
		prog[p++] = ch;
	} while (ch != '#');
	p = 0;
	do {
		scaner();
		switch (syn) {
		case 11:printf("(%d, %d)", syn, sum); break;
		case -1:printf("error!\n"); break;
		default:printf("(%d, %s)", syn, token);
		}
	} while (syn != 0);
	return 0;
}
