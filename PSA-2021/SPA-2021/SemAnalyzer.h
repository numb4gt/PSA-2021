#pragma once
#include "stdafx.h"
#include "LexTable.h"
#include "IdTable.h"

namespace Sem {
	bool checkSemantic(LT::LexTable& lexTable, IT::IdTable& idTable);
}