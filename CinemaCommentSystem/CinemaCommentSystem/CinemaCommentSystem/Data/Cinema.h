﻿#ifndef CINEMA_H
#define CINEMA_H

#include <string>
#include "ELanguage.h"
#include "CinemaType.h"
#include "ParameterString.h"

namespace ccs 
{
	class Cinema {
	public:
		Cinema();			// 默认构造函数
		Cinema(string id, string name, string director, ELanguage language, int year, CinemaType type);// 构造函数，不包括分数
		~Cinema();			// 析构函数

	private:
		string id;			// 编号
		string name;		// 电影名字
		string director;	// 导演
		ELanguage language;	// 语言
		int year;			// 年份
		float score;		// 评分
		int scoreNum;		// 评分人数
		CinemaType *type;	// 类别

		// Get function
	public:
		inline string GetId() { return this->id; }
		inline string GetName() { return this->name; }
		inline string GetDirector() { return this->director; }
		inline ELanguage GetLanguage() { return this->language; }
		inline int GetYear() { return this->year; }
		inline float GetScore() { return this->score; }
		inline CinemaType *GetType() { return this->type; }
	};
}

#endif