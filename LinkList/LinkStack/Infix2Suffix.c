#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "LinkStack.h"


//���˿հ�
//��ջ: �Ƿ���(���ȼ�����ջ��),������
//��ջ: ����������
//�ȳ����� :��ǰ�������ȼ�С��ջ��Ԫ��
//test:
//5 + 4=> 5 4 +
//1 + 2 * 3 = > 1 2 3 * +
//8 + (3 �C 1) * 5 = > 8 3 1 �C 5 * +

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
	//���������ַ���
	char *head = exp;
	
	int index = 0;
	char num = '0';
	while (*head){
		//num ���ַ�����  ,num�ĵ�ַ�ǲ�����head��,����ֻ��ֵ���
		//��ջ�õ�ַ,�Ƚ���ֵ,����copyһ��ֵ
		num = *head;
		//filter the blank
		if (num == ' '){
			head++;
			continue;
		}
		//�ַ�����ֱ�����
		if (num >= '0' && num <= '9'){
			suffix[index] = num;
			index++;
		}
		//�������
		else{
			//��һ������ֱ����ջ
			if (Get_Length(stack) == 0){
				Push(stack, head);
			}
			else{
				//���������� ,������������֮��ķ���ȫ������
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
				//������ֱ����ջ
				else if (num == '('){
					Push(stack, head);
				}
				//��ǰ�ַ�����ջ�� ,ֱ����ջ
				else if (Get_priority(num) >= Get_priority(*temp)){
					Push(stack, head);
				}
				//in turn , �ȳ�����
				else{
					char *top = (char *)Pop(stack);
					suffix[index] = *top;
					index++;
					Push(stack, head);
				}
			}
		}
	//�����������headͬ��++,��Ϊhead++ָ���ƶ�,�����������ջ������û��ֵ��.
	//	index++;
		head++;
	}
	//ջ�ڷ���ȫ������
	while (Get_Length(stack) > 0){
		char *top = (char *)Top(stack);
		suffix[index] = *top;
		index++;
		Pop(stack);
	}

	//�洢�ĺ�׺���ʽ
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
	printf("the result of 8 + ( 3 �C 1 ) * 5 is %f", result);
	getchar();
	return 0;
}