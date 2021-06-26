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
	cout << "��ӭ��ʦ�� " << this->m_Name << "��¼��" << endl;
	cout << "\t\t -----------------------------------------\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             1.�鿴����ԤԼ             |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             2.���ԤԼ                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             0.ע����¼                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t -----------------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "�� ";
		cout << "ԤԼ����: ��" << of.m_OrderData[i]["date"];
		cout << " ʱ��: " << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ����: " << of.m_OrderData[i]["roomId"];
		string status = " ״̬: ";   //0 ȡ����ԤԼ   1 �����  2 ��ԤԼ  -1 ԤԼʧ��
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_OrderData[i]["status"] == "0")
		{
			status += "ԤԼ��ȡ��";
		}
		else if (of.m_OrderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵�ԤԼ��¼���£� " << endl;
	vector<int> v_ValidOrder;

	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{	
			v_ValidOrder.push_back(i);
			cout << index++ << "�� ";
			cout << "ԤԼ����: ��" << of.m_OrderData[i]["date"];
			cout << " ʱ��: " << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ����: " << of.m_OrderData[i]["roomId"];
			string status = " ״̬: �����";
			cout << status << endl;
		}
	}

	cout << "��ѡ��Ҫ��˵�ԤԼ��0������ " << endl;
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
				cout << "��������˽��";
				cout << "1- ͨ��" << endl;
				cout << "2- ��ͨ��" << endl;

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

				cout << "�����ԤԼ���" << endl;
				break;
			}
			
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}

