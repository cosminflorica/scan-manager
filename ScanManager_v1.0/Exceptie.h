#pragma once
#ifndef EXCEPTIE_H
#define EXCEPTIE_H

class CExceptie
{
	char *M_errMessage;
	int M_errCode;
public:
	CExceptie(int code);
	CExceptie(int code, char *message);
	~CExceptie();
	char *getMessage();
	int getCode();
};

#endif