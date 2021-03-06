#include"Teacher.h"
#include"orderFile.h"
#include<vector>
#
Teacher::Teacher()
{

}

Teacher::Teacher(int empId, string name, string pwd)
{	
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::openMenu()
{
	cout << "欢迎教师： " << this->m_Name << "登录！" << endl;
	cout << "\t\t -----------------------------------------\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             1.查看所有预约             |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             2.审核预约                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             0.注销登录                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t -----------------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、 ";
		cout << "预约日期: 周" << of.m_OrderData[i]["date"];
		cout << " 时段: " << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 机房: " << of.m_OrderData[i]["roomId"];
		string status = " 状态: ";   //0 取消的预约   1 审核中  2 已预约  -1 预约失败
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_OrderData[i]["status"] == "0")
		{
			status += "预约已取消";
		}
		else if (of.m_OrderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的预约记录如下： " << endl;
	vector<int> v_ValidOrder;

	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{	
			v_ValidOrder.push_back(i);
			cout << index++ << "、 ";
			cout << "预约日期: 周" << of.m_OrderData[i]["date"];
			cout << " 时段: " << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房: " << of.m_OrderData[i]["roomId"];
			string status = " 状态: 审核中";
			cout << status << endl;
		}
	}

	cout << "请选择要审核的预约：0代表返回 " << endl;
	int select = 0;
	int valid = 0;
	
	while (true)
	{
		cin >> select;
		if (select >= 0 && select << v_ValidOrder.size())
		{	
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果";
				cout << "1- 通过" << endl;
				cout << "2- 不通过" << endl;

				cin >> valid;

				if (valid == 1)
				{
					of.m_OrderData[v_ValidOrder[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_OrderData[v_ValidOrder[select - 1]]["status"] = "-1";
				}
				of.updateOrder();

				cout << "已完成预约审核" << endl;
				break;
			}
			
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}

