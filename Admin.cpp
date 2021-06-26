#include"Admin.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"Student.h"
#include"Teacher.h"
#include<algorithm>
#include"ComputerRoom.h"
//Ĭ�Ϲ���
Admin::Admin()
{

}

//�вι���
Admin::Admin(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();  //��ʼ������  ��ȡ�ļ���������ʦ��ѧ������Ϣ

	//��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}

	ifs.close();
}



//��ʾ����Ա�����Ľ���
void Admin::openMenu()
{
	cout << "��ӭ����Ա�� " << this->m_Name << "��¼��" << endl;
	cout << "\t\t -----------------------------------------\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             1.����˺�                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             2.�鿴�˺�                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             3.�鿴����                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             4.���ԤԼ                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             0.ע����¼                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t -----------------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//��ʼ������
void Admin::initVector()
{
	//��ȡѧ���ļ�
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	this->vStu.clear();
	this->vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ�� " << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ�ļ�
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ�� " << vTea.size() << endl;
	ifs.close();

}

//����ظ�
bool Admin::checkRepeat(int id, int type)
{
	if (type == 1)  //ѧ��
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{	
			if (id == it->m_Id)
			{
				return true;
			}
			
		}
	}
	else if (type == 2)
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}

//����˺�
void Admin::addAccount()
{	
	string fileName;   //�����ļ���

	ofstream ofs;
	string tip; //��ʾ
	string errorTip;  //������ʾ
	int select = 0;
	while (true)
	{
		cout << "����������˺ŵ����ͣ�" << endl;
		cout << "1.���ѧ��" << endl;
		cout << "2.�����ʦ" << endl;


		
		cin >> select;

		if (select == 1)
		{	
			fileName = STUDENT_FILE;
			tip = "������ѧ�ţ�";
			
			errorTip = "ѧ���ظ�,����������";
			break;
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "������ְ���ţ�";
			errorTip = "ְ�����ظ�������������";
			break;
		}
		else
		{
			cout << "������������������!" << endl;
			system("pause");
			system("cls");

			this->openMenu();
		}
	}

	ofs.open(fileName, ios::out | ios::app);

	string name;  //����
	string pwd;   //����
	int id;       //ѧ��orְ����
	
	while (true)
	{	
		cout << tip;
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		
		}
		else
		{
			break;
		}
	}
	

	
	cout << "������������ " << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ�" << endl;

	if (select == 1)
	{
		Student s(id, name, pwd);
		this->vStu.push_back(s);
	}
	else if (select == 2)
	{
		Teacher t(id, name, pwd);
		this->vTea.push_back(t);
	}

	system("pause");
	system("cls");

	ofs.close();
	
	//this->initVector(); //��ʼ������
	
}

//��ӡѧ��
void printStudent(Student &s)
{
	cout << "ѧ�ţ� " << s.m_Id << "������ " << s.m_Name << " ���룺 " << s.m_Pwd << endl;
}

//��ӡ��ʦ
void printTeacher(Teacher &t)
{
	cout << "ְ���ţ� " << t.m_EmpId << "������ " << t.m_Name << " ���룺 " << t.m_Pwd << endl;
}

//�鿴�˺�
void Admin::showAccount()
{	
	while (true)
	{
		cout << "��ѡ��鿴���ݣ� " << endl;
		cout << "1.�鿴����ѧ��" << endl;
		cout << "2.�鿴������ʦ" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{	
			cout << "����ѧ����Ϣ���£� " << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);
			break;
		}
		else if (select == 2)
		{	
			cout << "������ʦ��Ϣ���£� " << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
		}
	}

	system("pause");
	system("cls");
	
}

//�鿴������Ϣ
void Admin::showComputer()
{	
	cout << "������Ϣ���£� " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it!=vCom.end();it++)
	{
		cout << "������ţ� " << it->m_ComId << " ������������� " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Admin::clearOrder()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "ԤԼ�����" << endl;
	

	system("pause");
	system("cls");
}



