

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account_info
{
	char name[128];
	float money;
	account_info* next;
};

void DepositMoney();//存钱
void DrawMoney();//取钱
void AddAccount();//新增储户
void DeleteAcount();//删除储户
void DisplayAccountInfo();//展示系统储户信息
void Menu(); // 每次刷新显示菜单项
void returnMenu(); // 返回菜单

account_info *accountInfo; //储户信息
int main()
{
	accountInfo = (account_info*)malloc(sizeof(account_info)); //第一个带头结点
	accountInfo->next = NULL;
	while (1)
	{
		Menu();
		printf("请输入1-6之间的选项：");
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
			printf("输入错误，请重新输入!!!\n"); getchar();
			break;
		}
	}
	
	return 0;
}

void DepositMoney()
{
	printf("请输入需要存储金额储户姓名:");
	char name[128];
	scanf("%s", name);

	account_info* p = accountInfo;
	while (p->next != NULL)
	{
		if (strcmp(p->next->name, name) == 0)
		{
			printf("当前储户姓名:%s, 储蓄金额:%2f\n", p->next->name, p->next->money);

			printf("请输入当前需要增加的储蓄金额:");
			float addMoney;
			scanf("%f", &addMoney);
			p->next->money += addMoney;

			printf("储户姓名:%s, 储蓄金额:%2f", p->next->name, p->next->money);

			returnMenu();
			return;
		}
		p = p->next;
	}
	printf("无该储户信息, 存钱失败！！！");
	returnMenu();
}

void DrawMoney()
{

	printf("请输入需要存储金额储户姓名:");
	char name[128];
	scanf("%s", name);

	account_info* p = accountInfo;
	while (p->next != NULL)
	{
		if (strcmp(p->next->name, name) == 0)
		{
			printf("当前储户姓名:%s, 储蓄金额:%2f\n", p->next->name, p->next->money);

			printf("请输入当前需要存取的储蓄金额:");
			float drawMoney;
			scanf("%f", &drawMoney);
			if (p->next->money >= drawMoney)
			{
				p->next->money -= drawMoney;
			}
			else
			{
				printf("取钱失败，当前金额不足!!!\n");
			}

			printf("储户姓名:%s, 剩余储蓄金额:%2f", p->next->name, p->next->money);
			returnMenu();

			return;
		}
		p = p->next;
	}
	printf("无该储户信息, 取钱失败！！！");
	returnMenu();
}

void AddAccount()
{
	printf("请输入增加储户姓名:");
	char name[128];
	scanf("%s", name);
	printf("请输入储户(%s)存储金额:", name);
	float money;
	scanf("%f", &money);

	account_info *node = (account_info*)malloc(sizeof(account_info)); //新增结点
	node->money = money;
	strcpy(node->name, name);

	//将结点插入
	node->next = accountInfo->next;
	accountInfo->next = node;
	printf("储户开户成功");
	returnMenu();
}

void DeleteAcount()
{
	printf("请输入需要删除储户姓名:");
	char name[128];
	scanf("%s", name);
	
	account_info* p = accountInfo;
	while (p->next != NULL)
	{
		if (strcmp(p->next->name, name) == 0)
		{
			account_info* d = p->next;
			p->next = d->next;
			free(d); //删除结点，并释放删除结点的空间

			printf("删除成功");
			returnMenu();
			return;
		}
		p = p->next;
	}
	printf("无该储户信息, 删除失败！！！");
	returnMenu();
}

void DisplayAccountInfo()
{
	int num = 0; //记录人数
	printf("姓名, 储蓄金额\n");
	account_info* p = accountInfo;
	while (p->next != NULL)
	{
		printf("%s, %2f\n", p->next->name, p->next->money);
		p = p->next;
		num++;
	}
	printf("共 %d人", num);
	returnMenu();
}

void Menu()
{
	system("cls");
	printf("|****活期储蓄账目管理系统*****|\n");
	printf("|****    1    储户开户   *****|\n");
	printf("|****    2    储户销户   *****|\n");
	printf("|****    3    存    入   *****|\n");
	printf("|****    4    支    出   *****|\n");
	printf("|****    5    查询储户   *****|\n");
	printf("|****    6    退    出   *****|\n");
	printf("|*****************************|\n");
}

void returnMenu()
{
	printf("\n按任意键返回菜单!!!\n");
	getchar(); getchar();
}
