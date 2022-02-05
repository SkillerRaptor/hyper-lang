/*
 * Copyright (c) 2020-present, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "hyper/ast/expression.hpp"

namespace hyper
{
	Expression::Expression(SourceRange source_range)
		: AstNode(source_range)
	{
	}
} // namespace hyper
