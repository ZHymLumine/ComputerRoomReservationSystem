#pragma once
#include"Identity.h"
#include<iostream>
#include<vector>
#include"Student.h"
#include"Teacher.h"
#include"ComputerRoom.h"
using namespace std;

class Admin : public Identity
{
public:
	//默认构造
	Admin();

	//有参构造
	Admin(string name, string pwd);

	//显示管理员操作的界面
	virtual void openMenu();

	//添加账号
	void addAccount();

	//查看账号
	void showAccount();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void clearOrder();

	//初始化容器
	void initVector();

	//检测重复
	bool checkRepeat(int id, int type);

	//学生容器
	vector<Student> vStu;

	//老师容器
	vector<Teacher> vTea;

	//机房容器
	vector<ComputerRoom> vCom;
};