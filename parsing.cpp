#include<iostream>
#include<string.h>
#include<stack>
#include<stdio.h>
using namespace std;
int main()
{
	stack<char>letter;//����һ����ĸջ
	stack<char>symbol;//����һ�������ջ
	char ch;
	char n = 'A', x, y, z;
	int tem;
	char input[200];
	int p = 0;
	int i;
	int x1, z1;
	do {
		ch = getchar();
		input[p++] = ch;
	} while (ch != '\n');//���븳ֵ���
	for (i = 0; i <= p; i++)
	{
		ch = input[i];
		if (ch <= 'z' && ch >= 'a')//�����ȡ������ĸ������ĸջ
		{
			letter.push(ch);
		}
		if (ch == ':' || ch == '=' || ch == '(')//�����ȡ���ǡ�������=������"���������ջ
			symbol.push(ch);
		while (ch == '+' || ch == '-')
		{
			if (symbol.top() == '=' || symbol.top() == '(')//�����ȡ���ǡ�+�����ߡ�-"�������ջ��Ԫ��Ϊ��=�����ߡ�����ʱ����+�����ߡ�-���������ջ
			{
				symbol.push(ch);
				break;
			}
			else//�����ȡ���ǡ�+�����ߡ�-"�������ջ��Ԫ�ز�Ϊ��=�����ߡ�����ʱ��������
			{
				z = letter.top();
				letter.pop();
				x = letter.top();
				letter.pop();
				y = symbol.top();
				symbol.pop();
				tem = (int)n;
				tem += 1;
				n = (char)tem;
				letter.push(n);
				if ((z >= 'a' && z <= 'z') && (x >= 'a' && x <= 'z'))
				{
					printf("T%d:=%c%c%c     (%c,%c,%c,T%d)", tem - 65, x, y, z, y, x, z, tem - 65);
				}
				if ((z >= 'A' && z <= 'Z') && (x >= 'a' && x <= 'z'))
				{
					z1 = int(z);
					printf("T%d:=%c%cT%d     (%c,%c,T%d,T%d)", tem - 65, x, y, z1 - 65, y, x, z1 - 65, tem - 65);
				}
				if ((x >= 'A' && x <= 'Z') && (z >= 'a' && z <= 'z'))
				{
					x1 = int(x);
					printf("T%d:=T%d%c%c     (%c,T%d,%c,T%d)", tem - 65, x1 - 65, y, z, y, x1 - 65, z, tem - 65);
				}
				if ((z >= 'A' && z <= 'Z') && (x >= 'A' && x <= 'Z'))
				{
					x1 = int(x);
					z1 = int(z);
					printf("T%d:=T%d%cT%d     (%c,T%d,T%d,T%d)", tem - 65, x1 - 65, y, z1 - 65, y, x1 - 65, z1 - 65, tem - 65);
				}
				printf("\n");
			}
		}
		while (ch == '*' || ch == '/')
		{
			if (symbol.top() == '=' || symbol.top() == '(' || symbol.top() == '+' || symbol.top() == '-')//�����ȡ���ǡ�*�����ߡ�/���������ջ��Ԫ��Ϊ��=�����ߡ���"���ߡ�+�����ߡ�-��ʱ����*�����ߡ�/���������ջ
			{
				symbol.push(ch);
				break;
			}
			else//�����ȡ���ǡ�*�����ߡ�/���������ջ��Ԫ�ز�Ϊ��=�����ߡ���"���ߡ�+�����ߡ�-��ʱ����*�����ߡ�/����������
			{
				z = letter.top();
				letter.pop();
				x = letter.top();
				letter.pop();
				y = symbol.top();
				symbol.pop();
				tem = (int)n;
				tem += 1;
				n = (char)tem;
				letter.push(n);
				if ((z >= 'a' && z <= 'z') && (x >= 'a' && x <= 'z'))
				{
					printf("T%d:=%c%c%c     (%c,%c,%c,T%d)", tem - 65, x, y, z, y, x, z, tem - 65);
				}
				if ((z >= 'A' && z <= 'Z') && (x >= 'a' && x <= 'z'))
				{
					z1 = int(z);
					printf("T%d:=%c%cT%d     (%c,%c,T%d,T%d)", tem - 65, x, y, z1 - 65, y, x, z1 - 65, tem - 65);
				}
				if ((x >= 'A' && x <= 'Z') && (z >= 'a' && z <= 'z'))
				{
					x1 = int(x);
					printf("T%d:=T%d%c%c     (%c,T%d,%c,T%d)", tem - 65, x1 - 65, y, z, y, x1 - 65, z, tem - 65);
				}
				if ((z >= 'A' && z <= 'Z') && (x >= 'A' && x <= 'Z'))
				{
					x1 = int(x);
					z1 = int(z);
					printf("T%d:=T%d%cT%d     (%c,T%d,T%d,T%d)", tem - 65, x1 - 65, y, z1 - 65, y, x1 - 65, z1 - 65, tem - 65);
				}
				printf("\n");
			}
		}
		if (ch == ')')//�����ȡ���ǡ�������������
		{
			z = letter.top();
			letter.pop();
			x = letter.top();
			letter.pop();
			y = symbol.top();
			symbol.pop();
			tem = (int)n;
			tem += 1;
			n = (char)tem;
			letter.push(n);
			if ((z >= 'a' && z <= 'z') && (x >= 'a' && x <= 'z'))
			{
				printf("T%d:=%c%c%c     (%c,%c,%c,T%d)", tem - 65, x, y, z, y, x, z, tem - 65);
			}
			if ((z >= 'A' && z <= 'Z') && (x >= 'a' && x <= 'z'))
			{
				z1 = int(z);
				printf("T%d:=%c%cT%d     (%c,%c,T%d,T%d)", tem - 65, x, y, z1 - 65, y, x, z1 - 65, tem - 65);
			}
			if ((x >= 'A' && x <= 'Z') && (z >= 'a' && z <= 'z'))
			{
				x1 = int(x);
				printf("T%d:=T%d%c%c     (%c,T%d,%c,T%d)", tem - 65, x1 - 65, y, z, y, x1 - 65, z, tem - 65);
			}
			if ((z >= 'A' && z <= 'Z') && (x >= 'A' && x <= 'Z'))
			{
				x1 = int(x);
				z1 = int(z);
				printf("T%d:=T%d%cT%d     (%c,T%d,T%d,T%d)", tem - 65, x1 - 65, y, z1 - 65, y, x1 - 65, z1 - 65, tem - 65);
			}
			printf("\n");
			symbol.pop();
		}
		while (ch == '\n')
		{
			if (symbol.top() == '=')//�����ȡ���ǡ�\n���������ջ��Ԫ��Ϊ��=��ʱ��������
			{
				y = letter.top();
				tem = (int)y;
				letter.pop();
				x = letter.top();
				printf("%c:=T%d     (:=,T%d,-,%c)", x, tem - 65, tem - 65, x);
				printf("\n");
				break;
			}
			else//�����ȡ���ǡ�\n���������ջ��Ԫ�ز�Ϊ��=��ʱ��������
			{
				z = letter.top();
				letter.pop();
				x = letter.top();
				letter.pop();
				y = symbol.top();
				symbol.pop();
				tem = (int)n;
				tem += 1;
				n = (char)tem;
				letter.push(n);
				if ((z >= 'a' && z <= 'z') && (x >= 'a' && x <= 'z'))
				{
					printf("T%d:=%c%c%c     (%c,%c,%c,T%d)", tem - 65, x, y, z, y, x, z, tem - 65);
				}
				if ((z >= 'A' && z <= 'Z') && (x >= 'a' && x <= 'z'))
				{
					z1 = int(z);
					printf("T%d:=%c%cT%d     (%c,%c,T%d,T%d)", tem - 65, x, y, z1 - 65, y, x, z1 - 65, tem - 65);
				}
				if ((x >= 'A' && x <= 'Z') && (z >= 'a' && z <= 'z'))
				{
					x1 = int(x);
					printf("T%d:=T%d%c%c     (%c,T%d,%c,T%d)", tem - 65, x1 - 65, y, z, y, x1 - 65, z, tem - 65);
				}
				if ((z >= 'A' && z <= 'Z') && (x >= 'A' && x <= 'Z'))
				{
					x1 = int(x);
					z1 = int(z);
					printf("T%d:=T%d%cT%d     (%c,T%d,T%d,T%d)", tem - 65, x1 - 65, y, z1 - 65, y, x1 - 65, z1 - 65, tem - 65);
				}
				printf("\n");
			}
		}
	}
}


