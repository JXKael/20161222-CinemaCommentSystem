#include <string>
using namespace std;

#ifndef PARAMETER_STRING_H
#define PARAMETER_STRING_H

class ParameterString
{
private:
	// 单例模式访问
	ParameterString(){ this->instance = new ParameterString(); }
	// 静态实例
	ParameterString static *instance;
public:
	inline ParameterString static *Instance(){ return ParameterString::instance; }
	~ParameterString();		// 析构函数


// 参数数据
public:
	string _no_data = "no data";
};

#define para ParameterString
#define paras para::Instance()

#endif