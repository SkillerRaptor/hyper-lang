/*
 * Copyright (c) 2020-present, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "hyper/validators/type_validator.hpp"

namespace hyper
{
	TypeValidator::TypeValidator(
		const Diagnostics &diagnostics,
		const std::vector<Symbol> &symbols)
		: m_diagnostics(diagnostics)
		, m_symbols(symbols)
	{
	}

	void TypeValidator::visit_function_declaration(
		const FunctionDeclaration *function_declaration)
	{
		m_current_function = find_symbol(function_declaration->identifier());
	}

	void TypeValidator::visit_variable_declaration_post(
		const VariableDeclaration *variable_declaration)
	{
		if (!variable_declaration->expression())
		{
			return;
		}

		if (!match_data_type(variable_declaration->type()))
		{
			m_diagnostics.error(
				variable_declaration->expression()->source_range(),
				Diagnostics::ErrorCode::E0006,
				m_current_data_type.value(),
				variable_declaration->type().value());
		}
	}

	void TypeValidator::visit_call_expression_post(
		const CallExpression *call_expression)
	{
		m_current_data_type = find_data_type(call_expression->identifier());
	}

	void TypeValidator::visit_cast_expression_post(
		const CastExpression *cast_expression)
	{
		m_current_data_type = cast_expression->type();
	}

	void TypeValidator::visit_bool_literal(const BoolLiteral *bool_literal)
	{
		const DataType data_type(
			"bool", DataType::Kind::Bool, bool_literal->source_range());
		m_current_data_type = data_type;
	}

	void TypeValidator::visit_floating_literal(
		const FloatingLiteral *floating_literal)
	{
		const DataType data_type(
			"f32", DataType::Kind::Float32, floating_literal->source_range());
		m_current_data_type = data_type;
	}

	void TypeValidator::visit_integer_literal(
		const IntegerLiteral *integer_literal)
	{
		const DataType data_type(
			"i32", DataType::Kind::Int32, integer_literal->source_range());
		m_current_data_type = data_type;
	}

	void TypeValidator::visit_string_literal(const StringLiteral *string_literal)
	{
		const DataType data_type(
			"string", DataType::Kind::String, string_literal->source_range());
		m_current_data_type = data_type;
	}

	bool TypeValidator::match_data_type(const DataType &data_type) const noexcept
	{
		if (m_current_data_type.kind() == DataType::Kind::UserDefined)
		{
			return m_current_data_type.value() == data_type.value();
		}

		return m_current_data_type.kind() == data_type.kind();
	}

	DataType TypeValidator::find_data_type(
		const Identifier &identifier) const noexcept
	{
		return find_symbol(identifier).data_type;
	}

	Symbol TypeValidator::find_symbol(const Identifier &identifier) const noexcept
	{
		for (const Symbol &symbol : m_symbols)
		{
			if (symbol.name == identifier.value)
			{
				return symbol;
			}
		}

		return {};
	}
} // namespace hyper