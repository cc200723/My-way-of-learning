

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account_info
{
	char name[128];
	float money;
	account_info* next;
};

void DepositMoney();//��Ǯ
void DrawMoney();//ȡǮ
void AddAccount();//��������
void DeleteAcount();//ɾ������
void DisplayAccountInfo();//չʾϵͳ������Ϣ
void Menu(); // ÿ��ˢ����ʾ�˵���
void returnMenu(); // ���ز˵�

account_info *accountInfo; //������Ϣ
int main()
{
	accountInfo = (account_info*)malloc(sizeof(account_info)); //��һ����ͷ���
	accountInfo->next = NULL;
	while (1)
	{
		Menu();
		printf("������1-6֮���ѡ�");
		int op;
		scanf("%d", &op);
		system("cls");
		switch (op)
		{
		case 1:AddAccount();  break;
		case 2:DeleteAcount(); break;
		case 3:DepositMoney(); break;
		case 4:DrawMoney(); break;
		case 5:DisplayAccountInfo(); break;
		case 6:return 0;
		default:
			printf("�����������������!!!\n"); getchar();
			break;
		}
	}
	
	return 0;
}

void DepositMoney()
{
	printf("��������Ҫ�洢��������:");
	char name[128];
	scanf("%s", name);

	account_info* p = accountInfo;
	while (p->next != NULL)
	{
		if (strcmp(p->next->name, name) == 0)
		{
			printf("��ǰ��������:%s, ������:%2f\n", p->next->name, p->next->money);

			printf("�����뵱ǰ��Ҫ���ӵĴ�����:");
			float addMoney;
			scanf("%f", &addMoney);
			p->next->money += addMoney;

			printf("��������:%s, ������:%2f", p->next->name, p->next->money);

			returnMenu();
			return;
		}
		p = p->next;
	}
	printf("�޸ô�����Ϣ, ��Ǯʧ�ܣ�����");
	returnMenu();
}

void DrawMoney()
{

	printf("��������Ҫ�洢��������:");
	char name[128];
	scanf("%s", name);

	account_info* p = accountInfo;
	while (p->next != NULL)
	{
		if (strcmp(p->next->name, name) == 0)
		{
			printf("��ǰ��������:%s, ������:%2f\n", p->next->name, p->next->money);

			printf("�����뵱ǰ��Ҫ��ȡ�Ĵ�����:");
			float drawMoney;
			scanf("%f", &drawMoney);
			if (p->next->money >= drawMoney)
			{
				p->next->money -= drawMoney;
			}
			else
			{
				printf("ȡǮʧ�ܣ���ǰ����!!!\n");
			}

			printf("��������:%s, ʣ�ഢ����:%2f", p->next->name, p->next->money);
			returnMenu();

			return;
		}
		p = p->next;
	}
	printf("�޸ô�����Ϣ, ȡǮʧ�ܣ�����");
	returnMenu();
}

void AddAccount()
{
	printf("���������Ӵ�������:");
	char name[128];
	scanf("%s", name);
	printf("�����봢��(%s)�洢���:", name);
	float money;
	scanf("%f", &money);

	account_info *node = (account_info*)malloc(sizeof(account_info)); //�������
	node->money = money;
	strcpy(node->name, name);

	//��������
	node->next = accountInfo->next;
	accountInfo->next = node;
	printf("���������ɹ�");
	returnMenu();
}

void DeleteAcount()
{
	printf("��������Ҫɾ����������:");
	char name[128];
	scanf("%s", name);
	
	account_info* p = accountInfo;
	while (p->next != NULL)
	{
		if (strcmp(p->next->name, name) == 0)
		{
			account_info* d = p->next;
			p->next = d->next;
			free(d); //ɾ����㣬���ͷ�ɾ�����Ŀռ�

			printf("ɾ���ɹ�");
			returnMenu();
			return;
		}
		p = p->next;
	}
	printf("�޸ô�����Ϣ, ɾ��ʧ�ܣ�����");
	returnMenu();
}

void DisplayAccountInfo()
{
	int num = 0; //��¼����
	printf("����, ������\n");
	account_info* p = accountInfo;
	while (p->next != NULL)
	{
		printf("%s, %2f\n", p->next->name, p->next->money);
		p = p->next;
		num++;
	}
	printf("�� %d��", num);
	returnMenu();
}

void Menu()
{
	system("cls");
	printf("|****���ڴ�����Ŀ����ϵͳ*****|\n");
	printf("|****    1    ��������   *****|\n");
	printf("|****    2    ��������   *****|\n");
	printf("|****    3    ��    ��   *****|\n");
	printf("|****    4    ֧    ��   *****|\n");
	printf("|****    5    ��ѯ����   *****|\n");
	printf("|****    6    ��    ��   *****|\n");
	printf("|*****************************|\n");
}

void returnMenu()
{
	printf("\n����������ز˵�!!!\n");
	getchar(); getchar();
}
