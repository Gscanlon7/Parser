#include "Lexer.h"

Lexer::Lexer(const char* file) : m_CurrentCharacter((char*)file) {}

void Lexer::skip_whitespace() {
	const char current = *m_CurrentCharacter;
	while (current == ' ' || current == '\t' || current == '\r' || current == '\n' || current == '\0') {
		if (current == '\n') {
			m_CurrentLineNumber++;
			m_CurrentColumnNumber = 0;
			break;
		}
		m_CurrentCharacter++;
		m_CurrentColumnNumber++;
	}
}

static TokenType process_token(const char c) {
	switch (c) {
		case '[': return { TokenType::LeftBracket };
		case ']': return { TokenType::RightBracket };
		case '{': return { TokenType::LeftBrace };
		case '}': return { TokenType::RightBrace };
		case '(': return { TokenType::LeftParentheses };
		case ')': return { TokenType::RightParentheses };
		case '<': return { TokenType::LeftAngleBracket };
		case '>': return { TokenType::RightAngleBracket };
		case ';': return { TokenType::Semicolon };
	}
}

Token Lexer::make_token(const TokenType& token) {
	uint32_t length = 0;

	switch (token) {
		case TokenType::LeftBracket:
		case TokenType::RightBracket:
		case TokenType::LeftBrace:
		case TokenType::RightBrace:
		case TokenType::LeftParentheses:
		case TokenType::RightParentheses:
		case TokenType::LeftAngleBracket:
		case TokenType::RightAngleBracket:
		case TokenType::Semicolon:
		case TokenType::Colon:
		case TokenType::ForwardSlash:
		case TokenType::BackSlash:
		case TokenType::Hyphen:
		case TokenType::Underscore:
		case TokenType::Pipe:
		case TokenType::Astricks:
		case TokenType::Tilda:
		case TokenType::SingleQuote:
		case TokenType::DoubleQuote:
		case TokenType::ExclamationMark:
		case TokenType::QuestionMark:
		case TokenType::Period:
		case TokenType::Comma:
		case TokenType::Equal:
		case TokenType::Plus:
		case TokenType::At:
		case TokenType::Pound:
		case TokenType::DollarSign:
		case TokenType::Percentage:
		case TokenType::Caret:
		case TokenType::Ampersand:
		case TokenType::Grave: length = 1; break;
	}

	return { token, m_CurrentLineNumber, m_CurrentColumnNumber + length };
}

Token Lexer::advance_ptr() {
	m_CurrentCharacter++;
	return make_token(process_token(*m_CurrentCharacter));
}