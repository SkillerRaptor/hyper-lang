/*
 * Copyright (c) 2020-2021, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Hyper/Generators/CGenerator.hpp"

#include "Hyper/Ast/Declarations/VariableDeclaration.hpp"
#include "Hyper/Ast/Expressions/BinaryExpression.hpp"
#include "Hyper/Ast/Expressions/IdentifierExpression.hpp"
#include "Hyper/Ast/Literals/NumericLiteral.hpp"
#include "Hyper/Ast/Statements/AssignStatement.hpp"
#include "Hyper/Ast/Statements/CompoundStatement.hpp"
#include "Hyper/Ast/Statements/IfStatement.hpp"
#include "Hyper/Ast/Statements/PrintStatement.hpp"

#include <iostream>

namespace Hyper
{
	CGenerator::CGenerator(std::string file)
		: Generator(std::move(file))
		, m_output_file(m_file + ".c")
	{
	}

	void CGenerator::generate_pre()
	{
		m_output_file << "#include <stdint.h>\n";
		m_output_file << "#include <stdio.h>\n";
		m_output_file << "\n";
		m_output_file << "int main()\n";

		enter_scope();
	}

	void CGenerator::generate_post()
	{
		leave_scope();
	}

	void CGenerator::visit(const AstNode &ast_node)
	{
		std::cerr << "Visit for " << ast_node.class_name() << "not implemented!";
	}

	void CGenerator::visit(const VariableDeclaration &variable_declaration)
	{
		const std::string type = [&variable_declaration]()
		{
			switch (variable_declaration.type())
			{
			case VariableDeclaration::Type::Int64:
				return "int64_t";
			default:
				// TODO(SkillerRaptor): Error handling
				std::abort();
			}
		}();
		const std::string string =
			type + " " + variable_declaration.identifier() + ";\n";
		m_output_file << m_indent << string;
	}

	void CGenerator::visit(const BinaryExpression &binary_expression)
	{
		const std::string operation = [&binary_expression]()
		{
			switch (binary_expression.operation())
			{
			case BinaryExpression::Operation::Addition:
				return "+";
			case BinaryExpression::Operation::Subtraction:
				return "-";
			case BinaryExpression::Operation::Multiplication:
				return "*";
			case BinaryExpression::Operation::Division:
				return "/";
			case BinaryExpression::Operation::Equal:
				return "==";
			case BinaryExpression::Operation::NotEqual:
				return "!=";
			case BinaryExpression::Operation::LessThan:
				return "<";
			case BinaryExpression::Operation::GreaterThan:
				return ">";
			case BinaryExpression::Operation::LessEqual:
				return "<=";
			case BinaryExpression::Operation::GreaterEqual:
				return ">=";
			default:
				// TODO(SkillerRaptor): Error handling
				std::abort();
			}
		}();

		binary_expression.left()->accept(*this);
		m_output_file << " " << operation << " ";
		binary_expression.right()->accept(*this);
	}

	void CGenerator::visit(const IdentifierExpression &identifier_expression)
	{
		m_output_file << identifier_expression.identifier();
	}

	void CGenerator::visit(const NumericLiteral &numeric_literal)
	{
		m_output_file << numeric_literal.value();
	}

	void CGenerator::visit(const AssignStatement &assign_statement)
	{
		m_output_file << m_indent << assign_statement.identifier() << " = ";
		assign_statement.expression()->accept(*this);
		m_output_file << ";\n";
	}
	
	void CGenerator::visit(const CompoundStatement &compound_statement)
	{
		compound_statement.left()->accept(*this);
		compound_statement.right()->accept(*this);
	}
	
	void CGenerator::visit(const IfStatement &if_statement)
	{
		m_output_file << m_indent << "if (";
		if_statement.condition()->accept(*this);
		m_output_file << ")\n";
		
		enter_scope();
		if_statement.true_branch()->accept(*this);
		leave_scope();
		
		if (if_statement.false_branch() != nullptr)
		{
			enter_scope();
			if_statement.false_branch()->accept(*this);
			leave_scope();
		}
	}

	void CGenerator::visit(const PrintStatement &print_statement)
	{
		m_output_file << m_indent << R"(println("%d\n", )";
		print_statement.expression()->accept(*this);
		m_output_file << ");\n";
	}

	void CGenerator::enter_scope()
	{
		m_output_file << m_indent << "{\n";
		m_indent += '\t';
	}

	void CGenerator::leave_scope()
	{
		m_indent.pop_back();
		m_output_file << m_indent << "}\n";
	}
} // namespace Hyper
