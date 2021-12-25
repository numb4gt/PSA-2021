#pragma once
#include "stdafx.h"
#include "LexTable.h"
#include "IdTable.h"


namespace PN {
	void PolishNotation(LT::LexTable &lexTable, IT::IdTable &idTable);
	void ConvertToPolishNotation(LT::LexTable &lexTable, IT::IdTable &idTable, int startIndex, LT::Entry* expression);
}