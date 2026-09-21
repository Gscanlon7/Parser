#pragma once
#include <stdint.h>

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
	Grave
};

class Token {
public:

public:
	TokenType type;
	uint32_t start;
	uint32_t end;
};

class Lexer {

public:
	Lexer(const char* file);
	~Lexer() {}
public:
	Token advance_ptr();
	void skip_whitespace();
private:
	Token make_token(const TokenType& token);
private:
	char* m_CurrentCharacter;
	uint32_t m_CurrentLineNumber = 0;
	uint32_t m_CurrentColumnNumber = 0;
};
