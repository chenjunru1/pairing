#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<iomanip>
#include<iostream>
using namespace std;
void float1();//С������
void intadd();//�����Ӽ�����
void intmul();//�����˷�����
void intdiv();//������������
void fractionadd();//�����Ӽ�����
void fractionmul();//�����˳�����
int mainmenu();
int menu();
void mix();//������㣬�������źͻ��������
int rightnum = 0;//ÿ����Ŀ��ֵһ�֣�����ѧ���÷����
int wrongnum = 0;
int score = 0;

//С���Ӽ�

void float1()
{
	int num, n = 0;					//������㷶Χ����Ŀ����
	printf("ѡ��Ӽ�����ķ�Χ��\n");
	scanf_s("%d", &num);
	printf("������Ŀ������\n");
	scanf_s("%d", &n);
	std::ofstream ofile;
	ofile.open(".\\test-float.txt");
	for (int i = 0; i < n; i++)
	{
		int a, b, f1,f2;
		float c = 1.0,f3=0.1,f4=0.1;
		srand((int)time(0));
		a = -num + rand() % (2 * num + 1);//���㷶ΧΪ-num��num
		srand(i);
		b = -(num)+rand() % (2 * num + 1);
		srand((int)time(0));
		f1 = 1 + rand() % 9;
		srand(i);
		f2 = 1 + rand() % 9;
		f3 = f3 * f1;
		f4 = f4 * f1;
		float num1, num2, num3=1.0;
		num1 = a*1.0+f3;
		num2 = b*1.0+f4;
		if (num1 >= 0.0 && num2 >= 0.0)
		{
			printf("����㣺\n\t\t %.1f + %.1f = ", num1, num2);
			ofile << num1 << "+" << num2 << "=" << num1+num2 << endl;
		}
		if (num1 >= 0.0 && num2 < 0.0)
		{
			num3 = -num2;
			printf("����㣺\n\t\t %.1f - %.1f = ", num1, num3);
			ofile << num1 << "-" << num3 <<"=" << num1 + num2 << endl;
		}
		if (num1 < 0.0 && num2 >= 0.0)
		{
			printf("����㣺\n\t\t %.1f + %.1f = ", num1, num2);
			ofile << num1 << "+" << num2 << "=" << num1 + num2 << endl;
		}
		if (num1 < 0.0 && num2 < 0.0)
		{
			num3=-num2;
			printf("����㣺\n\t\t %.1f -%.1f = ", num1, num3);
			ofile << num1 << "-" << num3 << "=" << num1 + num2 << endl;
		}
		cin >> c;
		float d = (num1 + num2) * 1.0;
		if (d == c)
		{
			printf("�ش���ȷ!\n");
			rightnum++;
		}
		else
		{
			printf("�ش����!\n");
			cout << "ǰ���ļ��鿴��ȷ��" << endl;
			wrongnum++;
		}
	}
	ofile.close();
}
int gcd(int m, int n) //շת����������Լ��
{
	if (n == 0) //û�пո�
		return m;
	else
		return gcd(n, m % n);
}
//�����ӷ�
void intadd()
{
	int num,n=0;					//������㷶Χ����Ŀ����
	printf("ѡ��Ӽ�����ķ�Χ��\n");
	scanf_s("%d", &num);
	printf("������Ŀ������\n");
	scanf_s("%d", &n);
	std::ofstream ofile;
	ofile.open(".\\test-intadd.txt");
	for (int i = 0; i < n; i++)
	{
		int a, b, c,d,e;
		srand((int)time(0));
		a = -num + rand() % (2 * num + 1);//���㷶ΧΪ-num��num
		srand(i);
		b = -(num) + rand() % (2 * num+1);
		if (a>=0&&b>=0)
			printf("����㣺\n\t\t %d + %d = ", a, b);
		if (a >= 0 && b < 0)
		{	
			e = -b;
			printf("����㣺\n\t\t %d - %d = ", a, e);
		}
		if(a<0&&b>=0)
			printf("����㣺\n\t\t %d + %d = ", a, b);
		if (a < 0 && b < 0) 
		{
			e = -b;
			printf("����㣺\n\t\t %d - %d = ", a, e);
		}
		d = a + b;
		ofile << a << '+' << b << '=' << d << endl;
		scanf_s("%d", &c);
		if (a + b == c)
		{
			printf("�ش���ȷ!\n");
			rightnum++;
		}
		else
		{
			printf("�ش����!\n");
			cout << "ǰ���ļ��鿴��ȷ��" << endl;
			wrongnum++;
		}
	}
	ofile.close();
}
//�����˷�
void intmul()
{
	int num, n = 0;					//������㷶Χ����Ŀ����
	printf("ѡ��˳�����ķ�Χ��\n");
	scanf_s("%d", &num);
	printf("������Ŀ������\n");
	scanf_s("%d", &n);
	std::ofstream ofile;
	ofile.open(".\\test-intmul.txt");
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		srand((int)time(0));
		a = -num + rand() % (2 * num + 1);//���㷶ΧΪ-num��num
		srand(i);
		b = 1 + rand() % (num - 1);
		printf("����㣺\n\t\t %d �� %d = ", a, b);
		d = a * b;
		ofile << a << "��" << b << '=' << d << endl;
		scanf_s("%d", &c);
		if (c == d)
		{
			printf("�ش���ȷ!\n");
			rightnum++;
		}
		else
		{
			printf("�ش����!\n");
			cout << "ǰ���ļ��鿴��ȷ��" << endl;
			wrongnum++;
		}
	}
	ofile.close();
}
//��������
void intdiv()
{
	int num, n = 0;					//������㷶Χ����Ŀ����
	printf("ѡ��˳�����ķ�Χ��\n");
	scanf_s("%d", &num);
	printf("������Ŀ������\n");
	scanf_s("%d", &n);
	std::ofstream ofile;
	ofile.open(".\\test-intdiv.txt");
	int a, b,d, m, p;
	for (int i = 0; i < n; i++)
	{
		srand((int)time(0));
		a = -num + rand() % (2 * num + 1);//���㷶ΧΪ-num��num
		srand(i);
		b = 1 + rand() % (num - 1);
		m = a, p = b;
		gcd(m, p);
		a = a / gcd(m, p);
		b = b / gcd(m, p);
		if (a == 0 || b == 1&&a>=b)
		{
			printf("����㣺\n\t\t %d �� %d = ", m, p);
			cin >> d;
			ofile << a << "��" << b << '=' << a << endl;
			if (d == a)
			{
				printf("�ش���ȷ!\n");
				rightnum++;
			}
			else
			{
				printf("�ش����!\n");
				cout << "ǰ���ļ��鿴��ȷ��" << endl;
				wrongnum++;
			}
		}
		else
		{
			n++;
			continue;
		}
	}
	ofile.close();
}

//��������

void fractionmul()
{
	int n, ran;
	cout << "�����ĸ��С��Χ:" << endl;
	cin >> ran;
	cout << "����������Ŀ������" << endl;
	cin >> n;
	std::ofstream ofile;
	ofile.open(".\\test-fractionmul.txt");
	int a, b, d, e, f, g, m, p;
	for (int i = 0; i < n; i++) 
	{
		f = 0, g = 0;
		int op;
		string s;
		int c;
		srand((int)time(0));
		a = 1+rand() % ran;//���㷶ΧΪ-num��num
		srand(i);
		b = 1 + rand() % ran;
		srand(i + 1);
		d = 1+rand() % ran;
		srand(i + 2);
		e = 1 + rand() % ran;
		srand(i + 3);
		op = 1+rand() % 2;
		switch (op)
		{

		case 1:
			f = a * d, g = b * e, g = b * e;
			m = f, p = g;
			f = f / gcd(m, p);
			g = g / gcd(m, p);
			int a1, b1, d1, e1;
			a1 = a, b1 = b;
			d1 = d, e1 = e;
			a = a / gcd(a1, b1);
			b = b / gcd(a1, b1);
			d = d / gcd(d1, e1);
			e = e / gcd(d1, e1);
			if (f == 0 || g == 1)
			{
				printf("������𰸣�\n\t\t %d/%d��%d/%d = ", a, b, d, e);
				ofile << a <<'/'<<b<< "��" << d <<'/'<<e<< '=' << f << endl;
				cin >> c;
				if (c == f)
				{
					cout << "�ش���ȷ!" << endl;
					rightnum++;

				}
				else
				{
					cout << "�ش����!" << endl;
					cout << "ǰ���ļ��鿴��ȷ��" << endl;
					wrongnum++;

				}
			}
			else
			{
				printf("������𰸣�\n\t\t %d/%d��%d/%d = ", a, b, d, e);
				ofile << a << '/' << b << "��" << d << '/' << e << '=' << f<<'/'<<g << endl;
				int num1, num2;
				char ch;
				cin >> num1 >> ch >> num2;
				if (num1 == f && num2 == g)
				{
					cout << "�ش���ȷ!" << endl;
					rightnum++;

				}
				else
				{
					cout << "�ش����!" << endl;
					cout << "ǰ���ļ��鿴��ȷ��" << endl;
					wrongnum++;

				}

			}
			break;

		case 2:
			f = a * e, g = b * d;
			m = f, p = g;
			f = f / gcd(m, p);
			g = g / gcd(m, p);
			int a2, b2, d2, e2;
			a2 = a, b2 = b;
			d2 = d, e2 = e;
			a = a / gcd(a2, b2);
			b = b / gcd(a2, b2);
			d = d / gcd(d2, e2);
			e = e / gcd(d2, e2);
			if (f == 0 || g == 1)
			{
				printf("������𰸣�\n\t\t %d/%d��%d/%d = ", a, b, d, e);
				ofile << a << '/' << b << "��" << d << '/' << e << '=' << f << endl;
				cin >> c;
				if (c == f)
				{
					cout << "�ش���ȷ!" << endl;
					rightnum++;

				}
				else
				{
					cout << "�ش����!" << endl;
					cout << "ǰ���ļ��鿴��ȷ��" << endl;
					wrongnum++;
				}
			}
			else
			{
				printf("������𰸣�\n\t\t %d/%d��%d/%d = ", a, b, d, e);
				ofile << a << '/' << b << "��"<< d << '/' << e << '=' << f << '/' << g << endl;
				int num1, num2;
				char ch;
				cin >> num1 >> ch>> num2;
				if (num1==f && num2 == g)
				{
					cout << "�ش���ȷ!" << endl;
					rightnum++;

				}
				else
				{
					cout << "�ش����!" << endl;
					cout << "ǰ���ļ��鿴��ȷ��"<<endl;
					wrongnum++;
				}
			}break;
			
		}
	}
	ofile.close();
}

//�����Ӽ�����
void fractionadd()
{
	int n,num0;
	cout << "�����ĸ��Χ" << endl;
	cin >> num0;
	cout << "����������Ŀ������" << endl;
	cin >> n;
	std::ofstream ofile;
	ofile.open(".\\test-fractionadd.txt");
	int a, b, d, e, f, g, m, p;
	for (int i = 0; i < n; i++)
	{
		f = 0, g = 0;
		int op;
		int c;
		//scanf_s("%d/%d %c %d/%d", &a, &b, &op, &d, &e);
		srand((int)time(0));
		a = 1 + rand() % num0;//���㷶ΧΪ-num��num
		srand(i);
		b = 1 + rand() % num0;
		srand(i + 1);
		d = 1 + rand() % num0;
		srand(i + 2);
		e = 1 + rand() % num0;
		srand(i + 3);
		op = 1 + rand() % 2;
		//cin >> a >> b >> op >> d >> e;
		switch (op)
		{
		case 1:
			f = a * e + b * d, g = b * e;
			m = f, p = g;
			f = f / gcd(m, p);
			g = g / gcd(m, p);
			int a1, b1,d1,e1;
			a1 = a, b1 = b;
			d1 = d, e1 = e;
			a = a / gcd(a1, b1);
			b = b / gcd(a1, b1);
			d = d / gcd(d1, e1);
			e = e / gcd(d1, e1);
			if (f == 0 || g == 1)
			{
				printf("������𰸣�\n\t\t %d/%d+%d/%d = ", a, b, d, e);
				ofile << a << '/' << b << '+' << d << '/' << e <<'='<< f<<endl;
				cin >> c;
				if (c == f)
				{
					cout << "�ش���ȷ!" << endl;
					rightnum++;

				}
				else
				{
					cout << "�ش����!" << endl;
					cout << "ǰ���ļ��鿴��ȷ��" << endl;
					wrongnum++;

				}
			}
			else
			{
				printf("������𰸣�\n\t\t %d/%d+%d/%d = ", a, b, d, e);
				ofile << a << '/' << b << '+' << d << '/' << e << '=' <<f<<'/'<<g<<endl;
				int num1, num2;
				char ch;
				cin >> num1 >> ch >> num2;
				if (num1 == f && num2 == g)
				{
					cout << "�ش���ȷ!" << endl;
					rightnum++;

				}
				else
				{
					cout << "�ش����!" << endl;
					cout << "ǰ���ļ��鿴��ȷ��" << endl;
					wrongnum++;

				}
			}
			break;

		case 2:
			f = a * e - b * d, g = b * e;
			if (f >= 0) {
				m = f, p = g;
				f = f / gcd(m, p);
				g = g / gcd(m, p);
			}
			else
			{
				m = -f, p = g;
				f = f / gcd(m, p);
				g = g / gcd(m, p);
			}
			int a2, b2, d2, e2;
			a2 = a, b2 = b;
			d2 = d, e2 = e;
			a = a / gcd(a2, b2);
			b = b / gcd(a2, b2);
			d = d / gcd(d2, e2);
			e = e / gcd(d2, e2);
			if (f == 0 || g == 1)
			{
				printf("������𰸣�\n\t\t %d/%d-%d/%d = ", a, b, d, e);
				ofile << a << '/' << b << '-' << d << '/' << e << '= ' << f << endl;
				cin >> c;
				if (c == f)
				{
					cout << "�ش���ȷ!" << endl;
					rightnum++;

				}
				else
				{
					cout << "�ش����!" << endl;
					cout << "ǰ���ļ��鿴��ȷ��" << endl;
					wrongnum++;
				}

			}

			else
			{
				printf("������𰸣�\n\t\t %d/%d-%d/%d = ", a, b, d, e);
				ofile << a << '/' << b << '+' << d << '/' << e << '= ' << f << '/' << g << endl;
				int num1, num2;
				char ch;
				cin >> num1 >> ch >> num2;
				if (num1 == f && num2 == g)
				{
					cout << "�ش���ȷ!" << endl;
					rightnum++;

				}
				else
				{
					cout << "�ش����!" << endl;
					cout << "ǰ���ļ��鿴��ȷ��" << endl;
					wrongnum++;

				}

			}
			break;
		}		
	}
	ofile.close();
}
int mainmenu()
{
	int choise;
	printf("\t  1.�����Ӽ�����\n\n");
	printf("\t  2.�����˷�����\n\n");
	printf("\t  3.������������\n\n");
	printf("\t  4.С���Ӽ�����\n\n");
	printf("\t  5.�����Ӽ�����\n\n");
	printf("\t  6.�����˳�����\n\n");
	printf("\t  7.�˳�������ϰ\n\n");
	printf("\t  ��������Ӧ�����ѡ����Ŀ����\n");
	cin >> choise;
	//system("cls");
	switch (choise)
	{
	case 1:intadd(); system("pause"); system("cls"); menu();  break;
	case 2:intmul(); system("pause"); system("cls"); menu();  break;
	case 3:intdiv(); system("pause"); system("cls"); menu();  break;
	case 4:float1(); system("pause");system("pause");  system("cls"); menu(); break;
	case 5:fractionadd(); system("pause"); system("cls"); menu(); break;
	case 6:fractionmul(); system("pause"); system("cls"); menu(); break;
	case 7:return 1; break;
	default:printf("����ȷ�������!\n"); mainmenu(); break;
	}
}
int menu()
{
	int con;
	printf("\n\t1.�����������㣿\n");
	printf("\n\t2.�˳�������ϰ��\n");
	cin >> con;
	switch (con)
	{
	case 1:
		system("cls");
		mainmenu();	
		break;
	case 2:
		return 1;
		break;
	default:
		printf("����ȷ�������!\n");
		return 1;
		break;
	}
}
int main()
{
		int mainmenu();
		if (mainmenu() == 1)
		{
			printf("���ܹ������ %d ����\n��ȷ���� %d ��\n�������� %d ��\n", rightnum + wrongnum, rightnum, wrongnum);
			score = rightnum;
			printf("��������ϰ�÷�Ϊ%d\n", score);
			system("pause");
		}
	}
