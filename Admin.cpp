#include"Admin.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"Student.h"
#include"Teacher.h"
#include<algorithm>
#include"ComputerRoom.h"
//默认构造
Admin::Admin()
{

}

//有参构造
Admin::Admin(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();  //初始化容器  获取文件中所有老师和学生的信息

	//获取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}

	ifs.close();
}



//显示管理员操作的界面
void Admin::openMenu()
{
	cout << "欢迎管理员： " << this->m_Name << "登录！" << endl;
	cout << "\t\t -----------------------------------------\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             1.添加账号                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             2.查看账号                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             3.查看机房                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             4.清空预约                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|             0.注销登录                 |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t -----------------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//初始化容器
void Admin::initVector()
{
	//读取学生文件
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	this->vStu.clear();
	this->vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为： " << vStu.size() << endl;
	ifs.close();

	//读取教师文件
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为： " << vTea.size() << endl;
	ifs.close();

}

//检测重复
bool Admin::checkRepeat(int id, int type)
{
	if (type == 1)  //学生
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

//添加账号
void Admin::addAccount()
{	
	string fileName;   //操作文件名

	ofstream ofs;
	string tip; //提示
	string errorTip;  //错误提示
	int select = 0;
	while (true)
	{
		cout << "请输入添加账号的类型：" << endl;
		cout << "1.添加学生" << endl;
		cout << "2.添加老师" << endl;


		
		cin >> select;

		if (select == 1)
		{	
			fileName = STUDENT_FILE;
			tip = "请输入学号：";
			
			errorTip = "学号重复,请重新输入";
			break;
		}
		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			tip = "请输入职工号：";
			errorTip = "职工号重复，请重新输入";
			break;
		}
		else
		{
			cout << "输入有误，请重新输入!" << endl;
			system("pause");
			system("cls");

			this->openMenu();
		}
	}

	ofs.open(fileName, ios::out | ios::app);

	string name;  //姓名
	string pwd;   //密码
	int id;       //学号or职工号
	
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
	

	
	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;

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
	
	//this->initVector(); //初始化容器
	
}

//打印学生
void printStudent(Student &s)
{
	cout << "学号： " << s.m_Id << "姓名： " << s.m_Name << " 密码： " << s.m_Pwd << endl;
}

//打印教师
void printTeacher(Teacher &t)
{
	cout << "职工号： " << t.m_EmpId << "姓名： " << t.m_Name << " 密码： " << t.m_Pwd << endl;
}

//查看账号
void Admin::showAccount()
{	
	while (true)
	{
		cout << "请选择查看内容： " << endl;
		cout << "1.查看所有学生" << endl;
		cout << "2.查看所有老师" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{	
			cout << "所有学生信息如下： " << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);
			break;
		}
		else if (select == 2)
		{	
			cout << "所有老师信息如下： " << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}

	system("pause");
	system("cls");
	
}

//查看机房信息
void Admin::showComputer()
{	
	cout << "机房信息如下： " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it!=vCom.end();it++)
	{
		cout << "机房编号： " << it->m_ComId << " 机房最大容量： " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Admin::clearOrder()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "预约已清空" << endl;
	

	system("pause");
	system("cls");
}



