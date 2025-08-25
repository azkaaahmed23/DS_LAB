#include<stdio.h>
#include<ctype.h>
#define MAX 100

int st[MAX];
int top=-1;

void push (int st[],int val);
int pop(int st[]);
int evalpfexp(char exp[]);

int main()
{
	int val;
	char exp[100];
	printf("\n Enter any postfix expression: ");
	fgets(exp,sizeof(exp),stdin);
	val=evalpfexp(exp);
	printf("\n Value of the postfix expression = %d\n",val);
	return 0;
}

int evalpfexp(char exp[])
{
	int i=0,op1,op2,value;
	while(exp[i]!='\0' && exp[i]!='\n')
	{
		if (isdigit(exp[i]))
		{
			int digit=exp[i]-'0';
			push(st,digit);
		}
		else if (exp[i]!=' ' && exp[i]!='\t')
		{
			op2=pop(st);
			op1=pop(st);
			switch(exp[i])
			{
				case '+':
					value=op1+op2;
					break;
				case '-':
					value=op1-op2;
					break;
				case '/':
					value=op1/op2;
					break;
				case '*':
					value=op1*op2;
					break;
				case '%':
					value=op1%op2;
					break;
				default: 
					printf("\n Invalid operator : %c",exp[i]);
					return 0;
			}
			push(st,value);
		}
		i++;
	}
	return pop(st);
}

void push (int st[], int val)
{
	if (top==MAX-1)
		printf("\n STACK OVERFLOW");
	else
		st[++top]=val;
}

int pop (int st[])
{
	if (top==-1)
	{
		printf("\n STACK UNDERFLOW");
		return -1;
	}
	return st[top--];
}
