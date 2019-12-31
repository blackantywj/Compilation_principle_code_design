#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define  N 80
#define  M 16

void check_const();
void measure_iden();
void measure_string();
void measure_digit();
void measure_char();


char cha;

int ci=0,cf=0,cc=0,cs=0,const_name_error_flag=0;

char *p0,*t0,*p1,*t1, *p2,*str,*const_detection="const",*digi,*flo;

void main()
{

 printf("Please input string: \n");


 p0=(char *)malloc(N*sizeof(char));
 p1=(char *)malloc(M*sizeof(char));
 p2=(char *)malloc(M*sizeof(char));
 
 gets(p0);
 printf("\n");
 check_const();
 
/* 开始处理输入串 p0  */
 while(*(p0)==' '||*(p0)==',')  /*从串p0中取标识符，并将其作为常量名存放到串p1中 */
  {
  p0++;
  if(*(p0)==' '||*(p0)==',')
   continue;
  else
  {
  measure_iden();      //*p0=="="
  if(!isdigit(*p0) && *p0 != '\"' && *p0 != '\'')//注意'和"做字符表示时用\'和\"
  {
   system("cls");
   printf("\n Const data is wrong . Exit !");
   exit(0);
  }
  else if(*p0=='\"')   /* 处理字符串常量 */
  { 
   p0++;
   measure_string();
  }
  else if(isdigit(*p0))  /* 处理数字 */
  {
   measure_digit();
  }
  else if(*p0=='\'') //处理字符常量
  {
   p0++;
   measure_char();
  }
  const_name_error_flag=0;
 }
 }
 if(*p0!=';')
 {
  system("cls");
  printf("\n This centence is wrong . Exit !");
  exit(0);
 }
 else
 {
  printf("int_num=%d;  char_num=%d; string_num=%d; float_num=%d.\n",ci,cc,cs,cf);
 }
}


/*    检查输入串是否以"'const"开头   */
void check_const()
{
 while(*p0!=' ') 
 {
  if(*p0==*const_detection)
  {
   p0++;
   const_detection++;
  }
  else
  {
   printf("It is not a constant declaration statement! \nPlease input a string again!\n");
   exit(0);
  }
 }
}


void measure_iden()
{
 if (*p0!='_' && (!isalpha(*p0)))
 {
	const_name_error_flag = 1; //变量名出错
  t1=p1;
  while(*p0!='=')
  {
   *p1=*p0;
   p0++;
   p1++;
  }
  *p1='\0';
//  printf("%s\n",p0);
  p0++;
 }
 else if (*p0=='_'||isalpha(*p0))
 {
  t1=p1;
  while(*p0!='=')
  {
   *p1=*p0;
   p0++;
   p1++;
  }
  *p1='\0';
//  printf("%s\n",p0);
  p0++;
 }
 printf("%s",t1);
}

void measure_string()
{
 str=p2; 
 while(*(p0)!='\"')
 {
  *p2=*p0;
  if(*(p0)==';')//丢了个分号，直接输出String  data is wrong. Exit
  {
   system("cls");
   printf("\n String  data is wrong. Exit !");
   exit(0);
 }
  p0++;
  p2++;
 }
 if(const_name_error_flag!=1){
 *p2='\0';
 p0++;
 cs++;
 printf("(string,\"%s\")\n",str);
 }
 else{
 p0++;
 printf("(Wrong! It is not a identifier!)\n");
 }
}

void measure_digit()
{
 char *jud;
 int mark=0;
 int zero_start_flag = 0;
 jud=p0;
 if(isdigit(*(jud+1)) && *jud == '0'){
	while(*p0!=','&&*p0!=';')
		 p0++;
	printf("(Wrong! The integer can't be started with '0'.)\n");
	zero_start_flag = 1;
 }
 for(;*(jud)!=','&&*(jud)!=';';jud++)
 {
  if(*jud=='.')
  {
   mark=1;
   break;
  }
 }

 if(const_name_error_flag == 1){
	 while(*p0!=','&&*p0!=';')
		 p0++;
	 printf("(Wrong! It is not a identifier!)\n");
 }
 if(mark==0 && !const_name_error_flag && !zero_start_flag)
 {
  digi=p2;
  while(*p0!=','&&*p0!=';')
  {

   *p2=*p0;
   p0++;
   p2++;
  }
  *p2='\0';
  ci++;
  printf("(integer,%s)\n",digi);
 }
 if(mark==1 && !const_name_error_flag && !zero_start_flag)
 {
  flo=p2;
  while(*p0!=','&&*p0!=';')
  {
   *p2=*p0;
   p0++;
   p2++;
  }
  *p2='\0';
  cf++;
  printf("(float,%s)\n",flo);
 }
}

void measure_char() 
{  
	char *jud;  
	jud=p0;  
	if(const_name_error_flag != 0){   
		//system("cls");
		p0=p0+2;
		printf("(Wrong! It is not a identifier!)");
		//exit(0);
	}
	else if(*(jud+1)=='\''&&*(jud)!='\''){
		cha=*p0;
		p0=p0+2;
		cc++;
		printf("(char,'%c')\n",cha);
	}
	if(*(jud+1)!='\''){
		 while(*p0!=','&&*p0!=';')
				p0++;
		 printf("(Wrong! There are  more than one char in ''.)\n");
	}
}
