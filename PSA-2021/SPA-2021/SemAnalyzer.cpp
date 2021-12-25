#include "stdafx.h"
#include "SemAnalyzer.h"
#include "Error.h"

bool Sem::checkSemantic(LT::LexTable& lexTable, IT::IdTable& idTable) 
{

	bool isMain = false;
	IT::IDDATATYPE typeOfFunction;
	for (int i = 0; i < lexTable.size; ++i)
	{
		switch (lexTable.table[i].lexema)
		{

		case LEX_LESS:
			if (idTable.table[lexTable.table[i - 1].idxTI].iddatatype != idTable.table[lexTable.table[i + 1].idxTI].iddatatype) {
				throw ERROR_THROW_IN(314, lexTable.table[i].sn, -1);
			}
			break;

		case LEX_MORE:
			if (idTable.table[lexTable.table[i - 1].idxTI].iddatatype != idTable.table[lexTable.table[i + 1].idxTI].iddatatype) {
				throw ERROR_THROW_IN(314, lexTable.table[i].sn, -1);
			}
			break;

		case LEX_MORE_OR_EQUALS:
			if (idTable.table[lexTable.table[i - 1].idxTI].iddatatype != idTable.table[lexTable.table[i + 1].idxTI].iddatatype) {
				throw ERROR_THROW_IN(314, lexTable.table[i].sn, -1);
			}
			break;

		case LEX_LESS_OR_EQUALS:
			if (idTable.table[lexTable.table[i - 1].idxTI].iddatatype != idTable.table[lexTable.table[i + 1].idxTI].iddatatype) {
				throw ERROR_THROW_IN(314, lexTable.table[i].sn, -1);
			}
			break;

		case LEX_FULL_EQUALS:
			if (idTable.table[lexTable.table[i - 1].idxTI].iddatatype != idTable.table[lexTable.table[i + 1].idxTI].iddatatype) {
				throw ERROR_THROW_IN(314, lexTable.table[i].sn, -1);
			}
			break;

		case LEX_NOT_FULL_EQUALS:
			if (idTable.table[lexTable.table[i - 1].idxTI].iddatatype != idTable.table[lexTable.table[i + 1].idxTI].iddatatype) {
				throw ERROR_THROW_IN(314, lexTable.table[i].sn, -1);
			}
			break;




		case LEX_RETURN:
			if (isMain && (idTable.table[lexTable.table[i + 1].idxTI].iddatatype != IT::IDDATATYPE::INT)) {
				throw ERROR_THROW_IN(300, lexTable.table[i].sn, -1);
			}
			else if (!isMain && (idTable.table[lexTable.table[i + 1].idxTI].iddatatype != typeOfFunction)) {
				throw ERROR_THROW_IN(301, lexTable.table[i].sn, -1);
			}
			break;

		case LEX_MAIN:
			isMain = true;
			break;

		case LEX_ID:
			if (idTable.table[lexTable.table[i].idxTI].idtype == IT::IDTYPE::F && lexTable.table[i + 1].lexema == LEX_EQUAL) {
				throw ERROR_THROW_IN(304, lexTable.table[i].sn, -1);
			}
			if (lexTable.table[i + 1].lexema == LEX_LEFTTHESIS && lexTable.table[i - 1].lexema != LEX_FUNCTION) {
				int parmsPassed = 0;
				int parmsRequired = 1;
				for (int j = i + 1; lexTable.table[j].lexema != LEX_RIGHTTHESIS; ++j) {
					if (lexTable.table[j].lexema == LEX_ID || lexTable.table[j].lexema == LEX_LITERAL) {
						++parmsPassed;
						IT::IDDATATYPE paramType = idTable.table[lexTable.table[j].idxTI].iddatatype;
						if (paramType != idTable.table[lexTable.table[i].idxTI + parmsPassed].iddatatype) {
							throw ERROR_THROW_IN(302, lexTable.table[i].sn, -1);
						}
					}
				}
				while (idTable.table[lexTable.table[i].idxTI + parmsRequired].idtype == IT::IDTYPE::P)
				{
					++parmsRequired;
				}
				if (parmsRequired - 1 != parmsPassed) throw ERROR_THROW_IN(302, lexTable.table[i].sn, -1);
			}
			if (idTable.table[lexTable.table[i].idxTI].idxfirstLE != i && lexTable.table[i - 2].lexema == LEX_DECLARE) {
				throw ERROR_THROW_IN(308, lexTable.table[i].sn, -1);
			}
			break;

		case LEX_FUNCTION:
			if ((i - 2 < 0) || lexTable.table[i - 2].lexema != LEX_DECLARE) {
				typeOfFunction = idTable.table[lexTable.table[i + 1].idxTI].iddatatype;
				isMain = false;
			}
			break;

		case LEX_EQUAL:
			if ((i - 1 >= 0) && idTable.table[lexTable.table[i].idxTI].idtype == IT::IDTYPE::F) {
				throw ERROR_THROW_IN(304, lexTable.table[i].sn, -1);
			}

			IT::IDDATATYPE typeOfIdentificator = idTable.table[lexTable.table[i - 1].idxTI].iddatatype;
			IT::IDTYPE Function = idTable.table[lexTable.table[i + 1].idxTI].idtype;
			for (int j = i; lexTable.table[j].lexema != LEX_SEMICOLON; ++j) {
				if ((lexTable.table[j].lexema == LEX_ID || lexTable.table[j].lexema == LEX_LITERAL) && idTable.table[lexTable.table[j].idxTI].iddatatype != typeOfIdentificator && Function != IT::IDTYPE::F) {
					throw ERROR_THROW_IN(305, lexTable.table[i].sn, -1);
				}
				else if (lexTable.table[i].lexema == LEX_ID && idTable.table[lexTable.table[i].idxTI].idtype != IT::IDTYPE::F && lexTable.table[i + 1].lexema == LEX_LEFTTHESIS) {
					throw ERROR_THROW_IN(306, lexTable.table[i].sn, -1);
				}
			}
			break;
		
		}
	}
	return true;
}
