#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "LinkStack.h"
float addition(float left, float right){
	return left + right;
}

float subtract(float left, float right){
	return left - right;
}

float multiple(float left, float right){
	return left * right;
}

float divide(float left, float right){
	if (right == 0){
		return 0.0;
	}
	return left / right;
}
float Match_Sign(char sign,float left,float right){
	switch (sign){
	case '+':
		return addition(left, right);
		
	case '-':
		return subtract(left, right);
		
	case '*':
		return multiple(left, right);

	case '/':
		return  divide(left, right);
	}
	return 0;
}

int isNum(char c){
	if (c >= '0' && c <= '9'){
		return 1;
	}
	return 0;
}

float Char2Interge(char c){
	float f = (float)c - '0';
	return f;
}

int Suffix2Result(LinkStack *stack,char *suffix){
	char *head = suffix;
	float left = 0;
	float right = 0;
	float result = 0;
	//����һЩ��Ч��ַ,�����������
	float _num[12] = { 0 };
	float _temp[12] = {0};
	float *num = (float *)&_num;
	float *temp = (float *)&_temp;

	while (*head){
		if(isNum(*head)){
			//������ָ��,����һ��������,ÿ��push�ĵ�ַ����,����ͨ��ָ��,�����ַ�ƶ�(������Ч�ĵ�ַ)
			 *num= Char2Interge(*head);
			Push(stack, num);
			num++;
		}
		else{
			right = *((float *)Pop(stack));
			left = *((float *)Pop(stack));
	
			//����Ҳ������ͬ��
			*temp= Match_Sign(*head, left, right);
			Push(stack, temp);
			temp++;
		}
		head++;
	}

	result = *((float *)Pop(stack));
	
	return result;
}