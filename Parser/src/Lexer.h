#pragma once
#include <stdint.h>
#include <string>

enum class TokenType {
	LeftBracket,
	RightBracket,
	LeftBrace,
	RightBrace,
	LeftParentheses,
	RightParentheses,
	LeftAngleBracket,
	RightAngleBracket,
	Semicolon,
	Colon,
	ForwardSlash,
	BackSlash,
	Hyphen,
	Underscore,
	Pipe,
	Astricks,
	Tilda,
	SingleQuote,
	DoubleQuote,
	ExclamationMark,
	QuestionMark,
	Period,
	Comma,
	Equal,
	Plus,
	At,
	Pound,
	DollarSign,
	Percentage,
	Caret,
	Ampersand,
	Grave,

	DoubleLeftAngularBracket,
	DoubleRightAngularBracket,
	DoublePlus,
	DoubleMinus,
	DoubleEqual,
	PlusEqual,
	MinusEqual,
	MultEqual,
	DivEqual,
	DoubleAmpersand,
	AmpersandEqual,
	DoublePipe,
	PipeEqual,
	DoubleColon,
	GreaterThanEqual,
	LessThanEqual,
	NotEqual,

	Int,
	Float,
	Double,
	Char,


};

class Token {
public:

public:
	TokenType type{};
	std::string_view position{};
	uint32_t line = 0;
	uint32_t col = 0;
};

class Lexer {

public:
	Lexer(const char* file);
	~Lexer() {}
public:
	Token advance_ptr();
	void skip_whitespace();
private:
	void process_token(Token& token);
	Token make_token(const TokenType& type, size_t length);
private:
	const char* m_CurrentCharacter;
	uint32_t m_CurrentLineNumber = 0;
	uint32_t m_CurrentColumnNumber = 0;
};
