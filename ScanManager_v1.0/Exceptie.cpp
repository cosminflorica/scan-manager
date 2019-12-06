#include "Exceptie.h"

#include<stdio.h>
#include<string.h>

CExceptie::CExceptie(int code)
{
	M_errCode = code;
	M_errMessage = _strdup("");
}

CExceptie::CExceptie(int code, char * message)
{
	M_errCode = code;
	M_errMessage = _strdup(message);
}

CExceptie::~CExceptie()
{
	if (M_errMessage)
	{
		delete M_errMessage;
		M_errMessage = NULL;
	}
}

char * CExceptie::getMessage()
{
	return M_errMessage;
}

int CExceptie::getCode()
{
	return M_errCode;
}
