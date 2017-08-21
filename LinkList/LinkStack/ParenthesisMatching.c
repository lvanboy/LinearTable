//测试字符串:#include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0;
#include <stdio.h>
#include "LinkList.h"
#include "LinkStack.h"
//算法核心
//遇到左括号入栈
//遇到右括号出栈
//其他字符后移
//当栈中没有符号,则合法
//否则非法

int IsLeft(char c){
	switch (c){
	case '<':
	case '(':
	case '[':
	case '{':
		return 1;
	}
	return 0;
}
int IsRight(char c){
	switch (c){
	case '>':
	case ')':
	case ']':
	case '}':
		return 1;
	}
	return 0;
}

int Isvalid(LinkStack *_stack,char *s){
	char *head = s;
	while (*head){
		if (IsLeft(*head)){
			Push(_stack, head);
		}
		else if (IsRight(*head)){
			Pop(_stack);
		}
		head++;
	}
	if (Get_Length(_stack)){
		return 0;
	}
	else{
		return 1;
	}
}

int main(){
	LinkStack *_stack = Create_LinkStack();
	//this is lack of a brace ,thus the result of the outlet is invalid
	char s[] = { "#include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0;" };
	if (Isvalid(_stack, s)){
		printf("valid!");
	}
	else{
		printf("invalid!");
	}
	getchar();
	return 0;
}
