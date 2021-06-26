#pragma once
#include<iostream>
using namespace std;

//身份抽象类
class Identity
{
public:
	//显示功能菜单
	virtual void openMenu() = 0;


	string m_Name;  //用户名
	string m_Pwd;  //密码
};