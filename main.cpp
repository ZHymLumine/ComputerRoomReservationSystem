#include<iostream>
#include"ComputerRoom.h"
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Admin.h"
#include<fstream>
#include"globalFile.h"
using namespace std;

//管理员菜单
void adminMenu(Identity *&admin)
{
	while (true)
	{	
		//调用管理员子菜单
		admin->openMenu();

		//将父类指针 转为子类指针，调用子类里其他接口
		Admin* man = (Admin*)admin;

		int select = 0;
		cin >> select;

		if (select == 1)  //添加账号
		{
			//cout << "添加账号" << endl;
			man->addAccount();
		}
		else if (select == 2)  //查看账号
		{
			//cout << "查看账号" << endl;
			man->showAccount();
		}
		else if (select == 3)  //查看机房
		{
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)  //清空预约
		{
			//cout << "清空预约" << endl;
			man->clearOrder();
		}
		else
		{	
			//注销
			delete admin;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生菜单
void StudentMenu(Identity*& student)
{
	while (true)
	{
		//调用学生子菜单
		student->openMenu();

		//将父类指针 转为子类指针，调用子类里其他接口
		Student* man = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1) 
		{
			man->applyOrder(); //申请预约
		}
		else if (select == 2)  
		{
			man->showMyOrder(); //查看我的预约
		}
		else if (select == 3) 
		{
			man->showAllOrder(); //查看所有预约
		}
		else if (select == 4)  
		{
			man->cancelOrder(); //取消预约
		}
		else
		{
			//注销
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//老师菜单
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用学生子菜单
		teacher->openMenu();

		//将父类指针 转为子类指针，调用子类里其他接口
		Teacher* man = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			man->showAllOrder(); //查看所有预约
		}
		else if (select == 2)
		{
			man->validOrder(); //审核预约
		}
		else
		{
			//注销
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LogIn(string fileName, int type)
{	
	//父类指针，用于指向子类对象
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);
	//文件不存在的情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	
	//用于接收用户输入的信息
	int id = 0;
	string name;
	string pwd;

	if (type == 1)  //学生登录
	{
		cout << "请输入你的学号： " << endl;
		cin >> id;
	}
	else if (type == 2)  //教师登录
	{
		cout << "请输入你的职工号： " << endl;
		cin >> id;
	}

	cout << "请输入用户名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生登录
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs>>fPwd)
		{	
			if (id == fId && name == fName && pwd == fPwd)  //比较输入的信息与从文件中读取的信息
			{
				cout << "学生验证登陆成功!" << endl;
				//登录成功后，按任意键进入学生界面
				system("pause");
				system("cls");

				person = new Student(id, name, pwd);
				//进入学生子菜单
				StudentMenu(person);
				return;

			}
		}
	}
	else if (type == 2)
	{
		//教师登录
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{	
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登陆成功!" << endl;
				//登录成功后，按任意键进入教师界面
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				//进入教师子菜单
				TeacherMenu(person);
				return;

			}
		}
	}
	else if (type == 3)
	{
		//管理员登录
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)  //比较输入的信息与从文件中读取的信息
			{
				cout << "管理员验证登陆成功!" << endl;
				//登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");

				person = new Admin(name, pwd);
				//进入管理员子菜单
				adminMenu(person);
				
				return;

			}
		}
	}
	

	cout << "验证登录失败！" << endl;


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

		cout << "请输入您的选择： " << endl;
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
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}