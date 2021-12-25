#pragma once
#include "stdafx.h"
#include "LexTable.h"
#include "IdTable.h"

namespace CodGeneration
{
	struct Generation
	{
		LT::LexTable lexTable;
		IT::IdTable idTable;
		std::ofstream out;
		Generation(LT::LexTable lexT, IT::IdTable idT, std::string outFile);
		void start();

	private:
		void head();
		void constants();
		void data();
		void code();
		void end();
	};
}