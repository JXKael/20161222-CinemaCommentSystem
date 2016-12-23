#include "Cinema.h"

Cinema::Cinema()
{
	// ParameterString * paras = ParameterString::Instance();
	this->id = _NO_DATA;
	this->name = _NO_DATA;
	this->director = _NO_DATA;
	this->language = ELanguage::No_data;
	this->year = 0;
	this->score = 0;
	this->scoreNum = 0;
	this->type = new CinemaType();
}

Cinema::~Cinema()
{
	delete this->type;
}