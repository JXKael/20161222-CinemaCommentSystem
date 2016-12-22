#include "Cinema.h"

Cinema::Cinema()
{
	this->id = paras->_no_data;
	this->name = paras->_no_data;		// 电影名字
	this->director = paras->_no_data;	// 导演
	this->language = ELanguage::No_data;
	this->year = 0;
	this->score = 0;
	this->type = new CinemaType();
}

Cinema::~Cinema()
{
}