#pragma once
# include <iostream>
# include<string>
# include<iomanip>
using namespace std;

class StuInfo 
{
private:
	char sno[20];//ѧ��
	char sname[20];//����
	char cname[20];//�༶
	char sex[4];//�Ա�
	int age;
	char tel[15];//�绰
public:
	StuInfo()
	{}
	StuInfo(char *sno1, char *sname, char *cname,char *sex,int age,char *tel);
	
	void setSno(char *sno );
	void setSname(char *sname);
	void setCname(char *cname);
	void setSex(char *sex);
	void setAge(int age);
	void setTel(char *tel);
	void Show();
	char * getSno();
};