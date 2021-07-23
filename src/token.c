/*
 * Copyright (c) 2020-2021, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "token.h"

const char* token_type_to_string(int type)
{
	switch (type)
	{
	case TOKEN_TYPE_EOF:
		return "TOKEN_TYPE_EOF";
	case TOKEN_TYPE_PLUS:
		return "TOKEN_TYPE_PLUS";
	case TOKEN_TYPE_MINUS:
		return "TOKEN_TYPE_MINUS";
	case TOKEN_TYPE_STAR:
		return "TOKEN_TYPE_STAR";
	case TOKEN_TYPE_SLASH:
		return "TOKEN_TYPE_SLASH";
	case TOKEN_TYPE_PLUS_EQUAL:
		return "TOKEN_TYPE_PLUS_EQUAL";
	case TOKEN_TYPE_MINUS_EQUAL:
		return "TOKEN_TYPE_MINUS_EQUAL";
	case TOKEN_TYPE_STAR_EQUAL:
		return "TOKEN_TYPE_STAR_EQUAL";
	case TOKEN_TYPE_SLASH_EQUAL:
		return "TOKEN_TYPE_SLASH_EQUAL";
	case TOKEN_TYPE_MODULAR:
		return "TOKEN_TYPE_MODULAR";
	case TOKEN_TYPE_MODULAR_EQUAL:
		return "TOKEN_TYPE_MODULAR_EQUAL";
	case TOKEN_TYPE_EQUAL:
		return "TOKEN_TYPE_EQUAL";
	case TOKEN_TYPE_NOT_EQUAL:
		return "TOKEN_TYPE_NOT_EQUAL";
	case TOKEN_TYPE_LESS_THAN:
		return "TOKEN_TYPE_LESS_THAN";
	case TOKEN_TYPE_GREATER_THAN:
		return "TOKEN_TYPE_GREATER_THAN";
	case TOKEN_TYPE_LESS_EQUAL:
		return "TOKEN_TYPE_LESS_EQUAL";
	case TOKEN_TYPE_GREATER_EQUAL:
		return "TOKEN_TYPE_GREATER_EQUAL";
	case TOKEN_TYPE_LOGICAL_AND:
		return "TOKEN_TYPE_LOGICAL_AND";
	case TOKEN_TYPE_LOGICAL_OR:
		return "TOKEN_TYPE_LOGICAL_OR";
	case TOKEN_TYPE_LOGICAL_NOT:
		return "TOKEN_TYPE_LOGICAL_NOT";
	case TOKEN_TYPE_INCREMENT:
		return "TOKEN_TYPE_INCREMENT";
	case TOKEN_TYPE_DECREMENT:
		return "TOKEN_TYPE_DECREMENT";
	case TOKEN_TYPE_SEMICOLON:
		return "TOKEN_TYPE_SEMICOLON";
	case TOKEN_TYPE_ASSIGN:
		return "TOKEN_TYPE_ASSIGN";
	case TOKEN_TYPE_IDENTIFIER:
		return "TOKEN_TYPE_IDENTIFIER";
	case TOKEN_TYPE_COLON:
		return "TOKEN_TYPE_COLON";
	case TOKEN_TYPE_COMMA:
		return "TOKEN_TYPE_COMMA";
	case TOKEN_TYPE_DOT:
		return "TOKEN_TYPE_DOT";
	case TOKEN_TYPE_LEFT_ARROW:
		return "TOKEN_TYPE_LEFT_ARROW";
	case TOKEN_TYPE_RIGHT_ARROW:
		return "TOKEN_TYPE_RIGHT_ARROW";
	case TOKEN_TYPE_LEFT_BRACE:
		return "TOKEN_TYPE_LEFT_BRACE";
	case TOKEN_TYPE_RIGHT_BRACE:
		return "TOKEN_TYPE_RIGHT_BRACE";
	case TOKEN_TYPE_LEFT_PARENTHESIS:
		return "TOKEN_TYPE_LEFT_PARENTHESIS";
	case TOKEN_TYPE_RIGHT_PARENTHESIS:
		return "TOKEN_TYPE_RIGHT_PARENTHESIS";
	case TOKEN_TYPE_LEFT_BRACKET:
		return "TOKEN_TYPE_LEFT_BRACKET";
	case TOKEN_TYPE_RIGHT_BRACKET:
		return "TOKEN_TYPE_RIGHT_BRACKET";
	case TOKEN_TYPE_LEFT_SHIFT:
		return "TOKEN_TYPE_LEFT_SHIFT";
	case TOKEN_TYPE_RIGHT_SHIFT:
		return "TOKEN_TYPE_RIGHT_SHIFT";
	case TOKEN_TYPE_BITWISE_AND:
		return "TOKEN_TYPE_BITWISE_AND";
	case TOKEN_TYPE_BITWISE_OR:
		return "TOKEN_TYPE_BITWISE_OR";
	case TOKEN_TYPE_BITWISE_XOR:
		return "TOKEN_TYPE_BITWISE_XOR";
	case TOKEN_TYPE_BITWISE_NOT:
		return "TOKEN_TYPE_BITWISE_NOT";
	case TOKEN_TYPE_BITWISE_AND_EQUAL:
		return "TOKEN_TYPE_BITWISE_AND_EQUAL";
	case TOKEN_TYPE_BITWISE_OR_EQUAL:
		return "TOKEN_TYPE_BITWISE_OR_EQUAL";
	case TOKEN_TYPE_BITWISE_XOR_EQUAL:
		return "TOKEN_TYPE_BITWISE_XOR_EQUAL";
	case TOKEN_TYPE_BITWISE_NOT_EQUAL:
		return "TOKEN_TYPE_BITWISE_NOT_EQUAL";
	case TOKEN_TYPE_FUNCTION:
		return "TOKEN_TYPE_FUNCTION";
	case TOKEN_TYPE_VIRTUAL:
		return "TOKEN_TYPE_VIRTUAL";
	case TOKEN_TYPE_OVERRIDE:
		return "TOKEN_TYPE_OVERRIDE";
	case TOKEN_TYPE_IF:
		return "TOKEN_TYPE_IF";
	case TOKEN_TYPE_ELSE:
		return "TOKEN_TYPE_ELSE";
	case TOKEN_TYPE_DO:
		return "TOKEN_TYPE_DO";
	case TOKEN_TYPE_WHILE:
		return "TOKEN_TYPE_WHILE";
	case TOKEN_TYPE_FOR:
		return "TOKEN_TYPE_FOR";
	case TOKEN_TYPE_OF:
		return "TOKEN_TYPE_OF";
	case TOKEN_TYPE_RETURN:
		return "TOKEN_TYPE_RETURN";
	case TOKEN_TYPE_BREAK:
		return "TOKEN_TYPE_BREAK";
	case TOKEN_TYPE_BREAKALL:
		return "TOKEN_TYPE_BREAKALL";
	case TOKEN_TYPE_CONTINUE:
		return "TOKEN_TYPE_CONTINUE";
	case TOKEN_TYPE_IMPORT:
		return "TOKEN_TYPE_IMPORT";
	case TOKEN_TYPE_EXPORT:
		return "TOKEN_TYPE_EXPORT";
	case TOKEN_TYPE_PACKAGE:
		return "TOKEN_TYPE_PACKAGE";
	case TOKEN_TYPE_MUTABLE:
		return "TOKEN_TYPE_MUTABLE";
	case TOKEN_TYPE_ENUM:
		return "TOKEN_TYPE_ENUM";
	case TOKEN_TYPE_UNION:
		return "TOKEN_TYPE_UNION";
	case TOKEN_TYPE_STRUCT:
		return "TOKEN_TYPE_STRUCT";
	case TOKEN_TYPE_VOID:
		return "TOKEN_TYPE_VOID";
	case TOKEN_TYPE_BOOL:
		return "TOKEN_TYPE_BOOL";
	case TOKEN_TYPE_FLOAT:
		return "TOKEN_TYPE_FLOAT";
	case TOKEN_TYPE_DOUBLE:
		return "TOKEN_TYPE_DOUBLE";
	case TOKEN_TYPE_INT:
		return "TOKEN_TYPE_INT";
	case TOKEN_TYPE_INT8:
		return "TOKEN_TYPE_INT8";
	case TOKEN_TYPE_INT16:
		return "TOKEN_TYPE_INT16";
	case TOKEN_TYPE_INT32:
		return "TOKEN_TYPE_INT32";
	case TOKEN_TYPE_INT64:
		return "TOKEN_TYPE_INT64";
	case TOKEN_TYPE_UINT:
		return "TOKEN_TYPE_UINT";
	case TOKEN_TYPE_UINT8:
		return "TOKEN_TYPE_UINT8";
	case TOKEN_TYPE_UINT16:
		return "TOKEN_TYPE_UINT16";
	case TOKEN_TYPE_UINT32:
		return "TOKEN_TYPE_UINT32";
	case TOKEN_TYPE_UINT64:
		return "TOKEN_TYPE_UINT64";
	case TOKEN_TYPE_STRING:
		return "TOKEN_TYPE_STRING";
	case TOKEN_TYPE_INT_LITERAL:
		return "TOKEN_TYPE_INT_LITERAL";
	case TOKEN_TYPE_STRING_LITERAL:
		return "TOKEN_TYPE_STRING_LITERAL";
	case TOKEN_TYPE_PRINT:
		return "TOKEN_TYPE_PRINT";
	default:
		break;
	}
	
	return "undefined token type";
}
