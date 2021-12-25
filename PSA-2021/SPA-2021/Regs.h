#pragma once

#define REG_DECLARE "new"
#define REG_STRING "pstring"
#define REG_INTEGER "pint"
#define REG_LINTEGER "plong"
#define REG_BOOL "pbool"
#define REG_FUNCTION "function"
#define REG_RETURN "return"
#define REG_PRINT "output"
#define REG_MAIN "main"
#define REG_ID "[a-z]+"
#define REG_BOOL_LIT "(true)|(false)"
#define REG_INTEGER_LIT "([1-9]+[0-9]*)|0o?|([1-7]+[0-7]*o)"
#define REG_STRING_LIT "'(.)*'"
#define REG_SEMICOLON ";"
#define REG_EQUAL "="
#define REG_COMMA ","
#define REG_MREQUAL "\\{"
#define REG_LSEQUAL "\\}"
#define REG_LEFTTHESIS "\\("
#define REG_RIGHTTHESIS "\\)"
#define REG_PLUS "\\+"
#define REG_OST "\\%"
#define REG_MINUS "\\-"
#define REG_STAR "\\*"
#define REG_DIRSLASH "/"
#define REG_IF "if"
#define REG_ELSE "else"
#define REG_MORE ">"
#define REG_LESS "<"
#define REG_MORE_OR_EQUALS "$"      //>=
#define REG_LESS_OR_EQUALS "#"    //<=
#define REG_FULL_EQUALS "~"   //==
#define REG_NOT_FULL_EQUALS "&"   //!=