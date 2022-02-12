/*
 * Copyright (c) 2020-present, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "hyper/token.hpp"

namespace hyper
{
	Token::Token(std::string value, Token::Type type, SourceRange source_range)
		: m_value(value)
		, m_type(type)
		, m_source_range(source_range)
	{
	}

	std::string_view Token::type_string() const noexcept
	{
		return token_type_to_string(m_type);
	}

	DataType Token::data_type() const noexcept
	{
		switch (m_type)
		{
		case Token::Type::Bool:
			return DataType("bool", DataType::Kind::Bool, m_source_range);
		case Token::Type::Int8:
			return DataType("i8", DataType::Kind::Int8, m_source_range);
		case Token::Type::Int16:
			return DataType("i16", DataType::Kind::Int16, m_source_range);
		case Token::Type::Int32:
			return DataType("i32", DataType::Kind::Int32, m_source_range);
		case Token::Type::Int64:
			return DataType("i64", DataType::Kind::Int64, m_source_range);
		case Token::Type::Uint8:
			return DataType("u8", DataType::Kind::Uint8, m_source_range);
		case Token::Type::Uint16:
			return DataType("u16", DataType::Kind::Uint16, m_source_range);
		case Token::Type::Uint32:
			return DataType("u32", DataType::Kind::Uint32, m_source_range);
		case Token::Type::Uint64:
			return DataType("u64", DataType::Kind::Uint64, m_source_range);
		case Token::Type::ISize:
			return DataType("isize", DataType::Kind::ISize, m_source_range);
		case Token::Type::USize:
			return DataType("usize", DataType::Kind::USize, m_source_range);
		case Token::Type::Float32:
			return DataType("f32", DataType::Kind::Float32, m_source_range);
		case Token::Type::Float64:
			return DataType("f64", DataType::Kind::Float64, m_source_range);
		case Token::Type::String:
			return DataType("string", DataType::Kind::String, m_source_range);
		case Token::Type::Void:
			return DataType("void", DataType::Kind::Void, m_source_range);
		case Token::Type::Identifier:
			return DataType(m_value, DataType::Kind::UserDefined, m_source_range);
		default:
			return {};
		}
	}

	size_t Token::line_number() const noexcept
	{
		return m_source_range.start.line;
	}

	size_t Token::line_column() const noexcept
	{
		return m_source_range.start.column;
	}

	size_t Token::length() const noexcept
	{
		return m_value.length();
	}

	Position Token::start_position() const noexcept
	{
		return m_source_range.start;
	}

	Position Token::end_position() const noexcept
	{
		return m_source_range.end;
	}

	std::string Token::value() const
	{
		return m_value;
	}

	Token::Type Token::type() const noexcept
	{
		return m_type;
	}

	SourceRange Token::source_range() const noexcept
	{
		return m_source_range;
	}
} // namespace hyper