#include<iostream>
#include"ComputerRoom.h"
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Admin.h"
#include<fstream>
#include"globalFile.h"
using namespace std;

//����Ա�˵�
void adminMenu(Identity *&admin)
{
	while (true)
	{	
		//���ù���Ա�Ӳ˵�
		admin->openMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Admin* man = (Admin*)admin;

		int select = 0;
		cin >> select;

		if (select == 1)  //����˺�
		{
			//cout << "����˺�" << endl;
			man->addAccount();
		}
		else if (select == 2)  //�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showAccount();
		}
		else if (select == 3)  //�鿴����
		{
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)  //���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			man->clearOrder();
		}
		else
		{	
			//ע��
			delete admin;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ���˵�
void StudentMenu(Identity*& student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->openMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Student* man = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1) 
		{
			man->applyOrder(); //����ԤԼ
		}
		else if (select == 2)  
		{
			man->showMyOrder(); //�鿴�ҵ�ԤԼ
		}
		else if (select == 3) 
		{
			man->showAllOrder(); //�鿴����ԤԼ
		}
		else if (select == 4)  
		{
			man->cancelOrder(); //ȡ��ԤԼ
		}
		else
		{
			//ע��
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��ʦ�˵�
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		teacher->openMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Teacher* man = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			man->showAllOrder(); //�鿴����ԤԼ
		}
		else if (select == 2)
		{
			man->validOrder(); //���ԤԼ
		}
		else
		{
			//ע��
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LogIn(string fileName, int type)
{	
	//����ָ�룬����ָ���������
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);
	//�ļ������ڵ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	
	//���ڽ����û��������Ϣ
	int id = 0;
	string name;
	string pwd;

	if (type == 1)  //ѧ����¼
	{
		cout << "���������ѧ�ţ� " << endl;
		cin >> id;
	}
	else if (type == 2)  //��ʦ��¼
	{
		cout << "���������ְ���ţ� " << endl;
		cin >> id;
	}

	cout << "�������û����� " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����¼
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs>>fPwd)
		{	
			if (id == fId && name == fName && pwd == fPwd)  //�Ƚ��������Ϣ����ļ��ж�ȡ����Ϣ
			{
				cout << "ѧ����֤��½�ɹ�!" << endl;
				//��¼�ɹ��󣬰����������ѧ������
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�
				StudentMenu(person);
				return;

			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{	
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��½�ɹ�!" << endl;
				//��¼�ɹ��󣬰�����������ʦ����
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
				TeacherMenu(person);
				return;

			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)  //�Ƚ��������Ϣ����ļ��ж�ȡ����Ϣ
			{
				cout << "����Ա��֤��½�ɹ�!" << endl;
				//��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");

				person = new Admin(name, pwd);
				//�������Ա�Ӳ˵�
				adminMenu(person);
				
				return;

			}
		}
	}
	

	cout << "��֤��¼ʧ�ܣ�" << endl;


	system("pause");
	system("cls");
}


int main()
{	
	ComputerRoom cr;
	int select = 0;

	while (true)
	{
		cr.showMenu();

		cout << "����������ѡ�� " << endl;
		cin >> select;

		switch (select)
		{
		case 1:
			LogIn(STUDENT_FILE, 1);
			break;
		case 2:
			LogIn(TEACHER_FILE, 2);
			break;
		case 3:
			LogIn(ADMIN_FILE, 3);
			break;
		case 0:
			cr.exitSystem();
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}