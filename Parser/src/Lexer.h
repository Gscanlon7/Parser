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

	NullTerminator
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
	Token next();
private:
	void skip_comment();
	void skip_whitespace();
	void advance(uint32_t length);
	Token process_token();
	Token make_token(TokenType type, size_t length);
private:
	const char* m_CurrentCharacter;
	uint32_t m_CurrentLineNumber = 0;
	uint32_t m_CurrentColumnNumber = 0;
};
