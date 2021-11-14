/*
 * Copyright (c) 2020-2021, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "Hyper/Ast/Statements/AssignStatement.hpp"

#include "Hyper/Ast/Expressions/Expression.hpp"
#include "Hyper/Generators/Generator.hpp"
#include "Hyper/Logger.hpp"

namespace Hyper
{
	AssignStatement::AssignStatement(
		std::string identifier,
		ExpressionPtr expression)
		: m_identifier(std::move(identifier))
		, m_expression(std::move(expression))
	{
	}

	void AssignStatement::accept(Generator &generator) const
	{
		generator.visit(*this);
	}

	void AssignStatement::dump(const std::string &prefix, bool last) const
	{
		AstNode::print_prefix(prefix, last);

		Logger::raw("(identifier={})\n", m_identifier);

		AstNode::print_next_node(*m_expression, prefix, last, true);
	}

	AstNode::Category AssignStatement::class_category() const noexcept
	{
		return AstNode::Category::AssignStatement;
	}

	std::string_view AssignStatement::class_name() const noexcept
	{
		return "AssignStatement";
	}

	std::string AssignStatement::identifier() const
	{
		return m_identifier;
	}

	const ExpressionPtr &AssignStatement::expression() const
	{
		return m_expression;
	}
} // namespace Hyper
