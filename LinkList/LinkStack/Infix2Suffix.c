#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "LinkStack.h"


//过滤空白
//入栈: 是符号(优先级大于栈顶),左括号
//出栈: 遇到右括号
//先出后入 :当前符号优先级小于栈顶元素
//test:
//5 + 4=> 5 4 +
//1 + 2 * 3 = > 1 2 3 * +
//8 + (3 – 1) * 5 = > 8 3 1 – 5 * +

int Suffix2Result(LinkStack *stack,char *suffix);
int Get_priority(char sign){
	switch (sign)
	{

	case '+':
	case '-':
		return 1;
		break;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
	
}
char suffix[1024] = { 0 };
char *Infix2Suffix(LinkStack *stack ,char *exp){
	//遍历整个字符串
	char *head = exp;
	
	int index = 0;
	char num = '0';
	while (*head){
		//num 是字符变量  ,num的地址是不等于head的,他们只是值相等
		//入栈用地址,比较用值,这里copy一份值
		num = *head;
		//filter the blank
		if (num == ' '){
			head++;
			continue;
		}
		//字符数字直接输出
		if (num >= '0' && num <= '9'){
			suffix[index] = num;
			index++;
		}
		//符号情况
		else{
			//第一个符号直接入栈
			if (Get_Length(stack) == 0){
				Push(stack, head);
			}
			else{
				//遇到右括号 ,把它和左括号之间的符号全部弹出
				char *temp = (char *)Top(stack);
				if (num == ')'){
					
					while (*temp != '('){
						char *top = (char *)Pop(stack);
						suffix[index] = *top;
						index++;
						temp = (char *)Top(stack);
					}
					Pop(stack);
				}
				//左括号直接入栈
				else if (num == '('){
					Push(stack, head);
				}
				//当前字符大于栈顶 ,直接入栈
				else if (Get_priority(num) >= Get_priority(*temp)){
					Push(stack, head);
				}
				//in turn , 先出后入
				else{
					char *top = (char *)Pop(stack);
					suffix[index] = *top;
					index++;
					Push(stack, head);
				}
			}
		}
	//不能在这里和head同步++,因为head++指针移动,里面包含了入栈操作是没有值的.
	//	index++;
		head++;
	}
	//栈内符号全部弹出
	while (Get_Length(stack) > 0){
		char *top = (char *)Top(stack);
		suffix[index] = *top;
		index++;
		Pop(stack);
	}

	//存储的后缀表达式
	for (int i = 0; i < index; i++){
		printf(" %c", suffix[i]);
	}
	printf("\n");
	return suffix;
}

int main(){
	LinkStack *stack = Create_LinkStack();
	char *suffix = NULL;
	float result = 0;
	suffix = Infix2Suffix(stack, "8 + ( 3 - 1 ) * 5");
	result = Suffix2Result(stack, suffix);
	printf("the result of 8 + ( 3 – 1 ) * 5 is %f", result);
	getchar();
	return 0;
}