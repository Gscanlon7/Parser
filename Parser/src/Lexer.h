#pragma once
#include <stdint.h>
class Lexer {

public:
	Lexer() {}
	~Lexer() {}
public:
	Token advance();
	void skip_whitespace();
private:
	char* current;
};

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