#pragma once
# include <iostream>
# include<string>
# include "StuInfo.h"
# include<stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <vector>
# include <windows.h>
# include<conio.h>
#include<fstream>
# include<iomanip>
# define FileName "D:\\student.txt"

using namespace std;
class Controller
{
public:
	void ShowCopy();//��ʾ��Ȩ
	bool Login();//�û���¼
	void menu();//���˵�
	void initData();//��ʼ������
	void addStuinfo();//���ѧ����Ϣ
	void showStuinfo(StuInfo stu);//��ʾ����ѧ����Ϣ
	void SearchStuinfo();//��ʾ���ѧ����Ϣ
	bool Save(StuInfo stu);//���浽�ļ�
	void ViewInfo();//���ѧ����Ϣ
	void UpdateStuinfo();//�޸�ѧ����Ϣ
	void DeleteStuinfo();//ɾ��ѧ����Ϣ
	bool reWrite();//����д���ļ�
};