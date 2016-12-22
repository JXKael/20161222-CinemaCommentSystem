#include <string>
using namespace std;

#ifndef PARAMETER_STRING_H
#define PARAMETER_STRING_H

class ParameterString
{
private:
	// 单例模式访问
	ParameterString();
	// 静态实例
	static ParameterString *instance;
public:
	static ParameterString *Instance()
	{
		if (!instance)
			instance = new ParameterString();

		return instance;
	}
	inline ~ParameterString() { delete instance; }		// 析构函数


// 参数数据，在此处添加定义的字符串
public:
	string _no_data = "no data";
};

#define _NO_DATA "no data"

#endif