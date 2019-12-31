#include "stdio.h"
#include "ctype.h"
#include<stdlib.h>
#include<malloc.h> 
#include<string.h>
#define N 80
#define M 16
int main(){
char *p0, *t0, *p1, *t1, *p2, *t2, *p3, *t3 = "const";
int ci = 0, cf = 0, cc = 0, cs = 0, cb = 0;
printf("\n Input string:");
p0 = (char*)malloc(N * sizeof(char));
p1 = (char*)malloc(M * sizeof(char));
p2 = (char*)malloc(M * sizeof(char));
p3 = (char*)malloc(M * sizeof(char));
t0 = p3;
t1 = p1;
t2 = p2;
gets(p0);
while(*p0!=' '){
if(*p0 == *t3){
	p0++;
	t3++;
}
else{
	printf("\n This string isn't a const declaration!");
	exit(0);
}
}
while (*p0 != '!'){
	while(p1 < t1+M){
		*p1 = '\0';
		p1++;
	}
	p1 = t1;
while(p2<t2+M){
	*p2 = '\0';
	p2++;
	}
	p2 = t2;
	if(*(p0-1)== ' ' || *(p0-1)== ';'){
		if (*p0!='_' && (!isalpha(*p0))){
			printf("\n Const name is wrong. Exit!");
			break;
		}
		else if (*p0 == ' ' || isalpha(*p0)){
			do{
				*p1 = *p0;
				p0++;
				p1++;
				if(*p0 != '=' && *p0 != '_' && !isalnum(*p0)){
					printf("\n Const name is wrong. Exit! ");
					break;
				}
			}while(*p0!='=');
			p1 = t1;
			printf("\n Name:%s;\t",p1);
		}
	}
	else if(*(p0-1) == '='){
		if(!isdigit(*p0) && *p0 != ' ' && *p0 != '.'){
			printf("\n Const data is wrong. Exit!");
			break;
		}
		else if(*p0 == ' '){
			do{
				*p2 = *p0;
				p0++;
				p2++;
			}while(*p0 != ';');
		if(*(p0-1) != ' '){
			printf("\n String data is wrong. Exit!");
			break;
		}
		p2 = t2;
		if(strlen(p2) == 3){
			cc++;
			printf("Data: %s; \t Type:char !\n",p2);
		}
		else {
			cs++;
			printf("Data:%s;\t Type:string !\n",p2);
			}
		}
		if(*p0=='.')
			if(*(p0+1)==';'){
				printf("\n Float data is wrong. Exit!");
				break;
			}
		else if(isdigit(*(p0+1))){
			do{
				*p2 = *p0;
				p0++;
				p2++;
				if(!isdigit(*p0)&&*p0!=';'){
					printf("\n Float data is wrong. Exit!");
					break;
				}
			}while(*p0!=';');
			p2 = t2;
			cf++;
			printf("Data:%s;\t Type: float!\n", p2);
		}
		if(*p0 == '0'){
			*p2 = *p0;
			p0++;
			p2++;
		if(*p0==';'){
			ci++;
			printf("Data:%c ;\t Type: int !\n", *(p2-1));
		}
		else if(*p0=='.'){
			do{
				*p2 = *p0;
				p0++;
				p2++;
				if(!isdigit(*p0) && *p0!=';'){
					printf("\n Float data is wrong. Exit!");
					break;
				}
			}while(*p0!=';');
			p2 = t2;
			cf++;
			printf("Data:%s; \t Type:float !\n", p2);
			}
		}
	if(isdigit(*p0)&&(*p0!='0')){
		p3 = t0;
		p3 = "int";
		ci++;
		do{
			*p2 = *p0;
			p0++;
			p2++;
			if(!isdigit(*p0)&&*p0!=';'&&*p0!='.'){
				printf("\n Int data is wrong. Exit!");
				break;
			}
			else if(*p0=='.'){
				p3 = t0;
				p3 = "float";
				ci--;
				cf++;
			}
		}while(*p0!=';');
			p2 = t2;
			printf("Data:%s; \t Type:%s!\n", p2, p3);
		}
	}
	else 
		p0++;
	}
	printf("\n Total: \n\t int numbers: %d \n\t float numbers: %d", ci, cf);
	printf("\n\t string numbers: %d \n\t char numbers: %d",cs,cc);
	printf("\n\t bool numbers: %d",cb);
	return 0;
}