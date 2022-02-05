/*
 * Copyright (c) 2020-present, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "hyper/ast/expressions/binary_expression.hpp"

namespace hyper
{
	BinaryExpression::BinaryExpression(
		SourceRange source_range,
		Operation operation,
		ExpressionPtr left,
		ExpressionPtr right)
		: Expression(source_range)
		, m_operation(operation)
		, m_left(std::move(left))
		, m_right(std::move(right))
	{
	}

	void BinaryExpression::validate_scope(
		const ScopeValidator &scope_validator) const
	{
		(void) scope_validator;
	}

	void BinaryExpression::validate_type(
		const TypeValidator &type_validator) const
	{
		(void) type_validator;
	}
} // namespace hyper
