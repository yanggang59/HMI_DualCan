/*INIParser.h
*/

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

//INI文件结点存储结构
class ININode
{
public:
	ININode(string root, string key, float value)
	{
		this->root = root;
		this->key = key;
		this->value = value;
	}
	string root;
	string key;
	float value;
};

//键值对结构体
class SubNode
{
public:
	void InsertElement(string key, float value)
	{
		sub_node.insert(pair<string, float>(key, value));
	}
	map<string, float> sub_node;
};

//INI文件操作类
class INIParser
{
public:
    INIParser();
	~INIParser();

public:
	int ReadINI(string path);													//读取INI文件
	float GetValue(string root, string key);									//由根结点和键获取值
	vector<ININode>::size_type GetSize(){ return map_ini.size(); }				//获取INI文件的结点数
	vector<ININode>::size_type SetValue(string root, string key, float value);	//设置根结点和键获取值
	int WriteINI(string path);			//写入INI文件
	void Clear(){ map_ini.clear(); }	//清空
	void Travel();						//遍历打印INI文件
private:
	map<string, SubNode> map_ini;		//INI文件内容的存储变量
};