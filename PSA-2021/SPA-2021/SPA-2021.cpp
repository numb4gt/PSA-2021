#include "stdafx.h"
#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Log.h"
#include "IdTable.h"
#include "LexTable.h"
#include "LexAnalyzer.h"
#include "Greibach.h"
#include "MFST.h"
#include "PolishNatation.h"
#include "SemAnalyzer.h"
#include "CodGeneration.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getParm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		IT::IdTable idTable = IT::Create(in.size);
		LT::LexTable lexTable = LT::Create(in.size);
		Lex::Scan(lexTable, idTable, in, parm, log);
		Log::WriteLine(log, "1)Лексический анализ выполнен", "");
		MFST::Mfst mfst(lexTable, GRB::getGreibach(), parm.mfst);
		mfst.start(*log.stream);
		Log::WriteLine(log, "2)Синтаксический анализ выполнен", "");
		mfst.savededucation();
		mfst.printrules();
		Sem::checkSemantic(lexTable, idTable);
		Log::WriteLine(log, "3)Семантический анализ выполнен", "");
		PN::PolishNotation(lexTable, idTable);
		Log::WriteLine(log, "4)Польская нотация выполнена", "");
#ifdef _DEBUG
		Log::WriteLine(log, "\n                        Таблица идентификаторов\n", "");
		IT::ShowTable(idTable, log.stream);
		Log::WriteLine(log, "                             Таблица лексем", "");
		LT::ShowTable(lexTable, log.stream);
#endif		
		CodGeneration::Generation writeToOut = CodGeneration::Generation(lexTable, idTable, parm.out);
		writeToOut.start();
		Log::WriteLine(log, "\n5)Генерация кода выполнена", "");
#ifdef _DEBUG
		CodGeneration::Generation writeToASM = CodGeneration::Generation(lexTable, idTable, "../SPA-ASM/asm.asm");
		writeToASM.start();
#endif 
#ifndef _DEBUG
		system("start compile.bat");
#endif
		Log::Close(log);
	}
	catch (Error::ERROR err)
	{
		Log::WriteError(log, err);
		Log::Close(log);
	}
	system("pause");
	return 0;
}