#include"orderFile.h"
#include<fstream>
#include"globalFile.h"
#include<string>
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;  //日期
	string interval; //时间段
	string stuId;  //学号
	string stuName; //姓名
	string roomId;  //房间号
	string status; //状态

	this->m_Size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{	
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;*/
		map<string, string>m;


		string key;
		string value;

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1);
			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1);
			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1);
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1);
			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1);
			m.insert(make_pair(key, value));
		}

		this->m_OrderData.insert(make_pair(this->m_Size, m));

		this->m_Size++;
	}

	ifs.close();

	/*for (map<int,map<string, string>>::iterator it = m_OrderData.begin(); it != m_OrderData.end(); it++)
	{
		cout << "key= " << it->first << " value=  " << endl;
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
		{
			cout << "key= " << mit->first << " value= " << mit->second << endl;
		}

	}*/
}

//更新预约
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		cout << "当前无预约记录" << endl;
		system("system");
		system("cls");
		return;
	}

	//更新预约信息文件
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out|ios::trunc);

	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_OrderData[i]["date"] << " ";
		ofs << "interval:" << this->m_OrderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_OrderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_OrderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_OrderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_OrderData[i]["status"] << endl;

	}
	ofs.close();

	
	ofs.close();
}