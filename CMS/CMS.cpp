#include<iostream>
#include<string>
using namespace std;

//通信录最大储存人数
#define Max 1000 //最大人数


//定义一个联系人结构体
struct Contacts
{
	string cName;		//姓名
	int cGender = 1;	//性别
	int cAge = 0;		//年龄
	string cPhone;		//电话号码
	string cAdd;		//住址
};

//定义一个通信录结构体
struct AddressBooks
{
	Contacts contactsArry[Max];	//通信录联系人信息数组
	int aCount = 0;					//通信录中人员的个数
};

//显示主菜单
void showMenu()
{
	cout << "********************************" << endl;
	cout << "***** 通 信 录 管 理 系 统 *****" << endl;
	cout << "********************************" << endl;
	cout << "*****    1、添加联系人     *****" << endl;
	cout << "*****    2、显示联系人     *****" << endl;
	cout << "*****    3、删除联系人     *****" << endl;
	cout << "*****    4、查找联系人     *****" << endl;
	cout << "*****    5、修改联系人     *****" << endl;
	cout << "*****    6、清空联系人     *****" << endl;
	cout << "*****    0、退出通信录     *****" << endl;
	cout << "********************************" << endl;
	cout << "***********Version1.0***********" << endl;
	cout << "********************************" << endl;
}

//添加联系人
void AddContacts(AddressBooks* abs)
{
	//判断是否满员
	if (abs->aCount == Max)
	{
		cout << "通信录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->contactsArry[abs->aCount].cName = name;

		//性别
		int gender;
		cout << "请输入性别： " << endl;
		cout << "1 ---- 男 " << endl;
		cout << "2 ---- 女 " << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[abs->aCount].cGender = gender;
				break;
			}
			cout << "输入有误请重新输入！" << endl;
		}

		//年龄
		int age;
		cout << "请输入年龄： " << endl;
		cin >> age;
		abs->contactsArry[abs->aCount].cAge = age;

		//电话
		string phone;
		cout << "请输入电话： " << endl;
		cin >> phone;
		abs->contactsArry[abs->aCount].cPhone = phone;

		//地址
		string add;
		cout << "请输入地址： " << endl;
		cin >> add;
		abs->contactsArry[abs->aCount].cAdd = add;

		//个数加一
		abs->aCount += 1;
		cout << "添加成功！" << endl;
		system("pause");
		//清屏
		system("cls");
	}

}

//显示联系人
void ShowContacts(AddressBooks* abs)
{
	if (abs->aCount == 0)
	{
		cout << "无联系人，请先添加一下吧!" << endl;
	}
	else
	{
		//显示所有联系人
		for (int i = 0; i < abs->aCount; i++)
		{
			cout << "姓名：" << abs->contactsArry[i].cName << " 性别：" << (abs->contactsArry[i].cGender != 2 ? "男" : "女") << " 年龄：" << abs->contactsArry[i].cAge << " 电话：" << abs->contactsArry[i].cPhone << " 住址：" << abs->contactsArry[i].cAdd << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测某人是否存在
int IsExit(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->aCount; i++)
	{
		if (abs->contactsArry[i].cName == name)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void DeleteContacts(AddressBooks* abs)
{
	//记录用户输入的姓名
	string name;
	cout << "请输入您要删除的用户姓名：" << endl;
	cin >> name;
	//判断联系人是否存在
	int index = IsExit(abs, name);
	//存在
	if (index > -1)
	{
		for (int i = index; i < abs->aCount - 1; i++)
		{
			//往前移位操作
			Contacts temp = abs->contactsArry[i];
			abs->contactsArry[i] = abs->contactsArry[i + 1];
			abs->contactsArry[i + 1] = temp;
		}
		//减少一个记录
		abs->aCount--;
		cout << "删除成功！" << endl;
	}
	else//不存在
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void GetContacts(AddressBooks* abs)
{
	//记录用户输入的姓名
	string name;
	cout << "请输入您要查找的用户姓名" << endl;
	cin >> name;
	//判断联系人是否存在
	int index = IsExit(abs, name);
	if (index > -1)
	{
		//存在
		cout << "姓名：" << abs->contactsArry[index].cName << endl;
		cout << "性别：" << abs->contactsArry[index].cGender << endl;
		cout << "年龄：" << abs->contactsArry[index].cAge << endl;
		cout << "电话：" << abs->contactsArry[index].cPhone << endl;
		cout << "住址：" << abs->contactsArry[index].cAdd << endl;
	}
	else
	{
		//不存在
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");

}

//修改联系人
void ModefyContacts(AddressBooks* abs)
{
	//记录用户输入的姓名
	string name;
	cout << "请输入您要修改的用户姓名" << endl;
	cin >> name;
	//判断联系人是否存在
	int index = IsExit(abs, name);
	if (index > -1)
	{
		//存在
		//姓名
		string name;
		cout << "请输入修改后的姓名： " << endl;
		cin >> name;
		abs->contactsArry[index].cName = name;

		//性别
		int gender;
		cout << "请输入修改后的性别： " << endl;
		cout << "1 ---- 男 " << endl;
		cout << "2 ---- 女 " << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs->contactsArry[index].cGender = gender;
				break;
			}
			cout << "输入有误请重新输入！" << endl;
		}

		//年龄
		int age;
		cout << "请输入修改后的年龄： " << endl;
		cin >> age;
		abs->contactsArry[index].cAge = age;

		//电话
		string phone;
		cout << "请输入修改后的电话： " << endl;
		cin >> phone;
		abs->contactsArry[index].cPhone = phone;

		//地址
		string add;
		cout << "请输入修改后的地址： " << endl;
		cin >> add;
		abs->contactsArry[index].cAdd = add;
		cout << "修改成功!" << endl;
	}
	else
	{
		//不存在
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//清空联系人
void ClearContacts(AddressBooks* abs)
{
	string choose = "N";
	cout << "您确定要清空通信录吗？(Y 确认/N 取消)" << endl;

	while (true)
	{
		cin >> choose;
		if (choose == "Y" || choose == "N")
		{
			break;
		}
		else
		{
			cout << "输入有误请重新输入!!" << endl;
		}
	}

	if (choose == "Y")
	{
		abs->aCount = 0;
		cout << "清空成功!!" << endl;
	}
	else
	{
		cout << "操作已取消!!" << endl;
	}
	system("pause");
	system("cls");
}


int main()
{
	//记录用户输入的信息
	int select = 0;
	//定义一个通信录结构体
	AddressBooks abs;
	//设置当前人数为零
	abs.aCount = 0;

	while (true)
	{
		//显示主菜单
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1://1、添加联系人
			AddContacts(&abs);	//地址传递
			break;
		case 2://2、显示联系人
			ShowContacts(&abs); //地址传递
			break;
		case 3://3、删除联系人
			DeleteContacts(&abs);
			break;
		case 4://4、查找联系人
			GetContacts(&abs);
			break;
		case 5://5、修改联系人
			ModefyContacts(&abs);
			break;
		case 6://6、清空联系人
			ClearContacts(&abs);
			break;
		case 0://0、退出通信录
			cout << "欢迎下次使用，再见！" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}


	system("pause");//按任意键继续
	return 0;
}