#include <iostream>
#include "Lexer.h"
Lexer::Lexer(const char* file) : m_CurrentCharacter(file) {}

static 	bool is_white_space(char c) {
	return (c == ' ' ||
		    c == '\t' ||
		    c == '\r' ||
		    c == '\n');
}
void Lexer::skip_whitespace() {

	while ((*m_CurrentCharacter == '/' && m_CurrentCharacter[1] == '/') || is_white_space(*m_CurrentCharacter)) {

		if (!is_white_space(*m_CurrentCharacter)) {
			while (*(++m_CurrentCharacter) != '\n');

			m_CurrentLineNumber++;
			m_CurrentColumnNumber = 0;
		}
		else if (*m_CurrentCharacter == '\n') {
			m_CurrentLineNumber++;
			m_CurrentColumnNumber = 0;
		}
		else {
			m_CurrentColumnNumber++;
		}

		m_CurrentCharacter++;
	}
}

 Token Lexer::process_token() {
	switch (*m_CurrentCharacter) {
		case '<':  
			if (m_CurrentCharacter[1] == '<')
				return make_token(TokenType::DoubleLeftAngularBracket, 2);
			if (m_CurrentCharacter[1] == '=')								 
				return make_token(TokenType::LessThanEqual, 2);			 
			return make_token(TokenType::LeftAngleBracket, 1);			 
		case '>':  
			if (m_CurrentCharacter[1] == '>')
				return make_token(TokenType::DoubleRightAngularBracket, 2);	
			if (m_CurrentCharacter[1] == '=')
				return make_token(TokenType::GreaterThanEqual, 2);				
			return make_token(TokenType::RightAngleBracket, 1);			
		case ':':
			if (m_CurrentCharacter[1] == ':')
				return make_token(TokenType::DoubleColon, 2);	
			return make_token(TokenType::Colon, 1);		
		case '|':															 
			if (m_CurrentCharacter[1] == '=')								 
				return make_token(TokenType::PipeEqual, 2);	
			if (m_CurrentCharacter[1] == '|')					
				return make_token(TokenType::DoublePipe, 2);	
			return make_token(TokenType::Pipe, 1);			
		case '&':
			if (m_CurrentCharacter[1] == '=')
				return make_token(TokenType::AmpersandEqual, 2);	
			if (m_CurrentCharacter[1] == '&')						
				return make_token(TokenType::DoubleAmpersand, 2);	
			return make_token(TokenType::Ampersand, 1);		
		case '!':
			if (m_CurrentCharacter[1] == '=')
				return make_token(TokenType::NotEqual, 2);			
			return make_token(TokenType::ExclamationMark, 1);	
		case '=':
			if (m_CurrentCharacter[1] == '=')
				return make_token(TokenType::DoubleEqual, 2);	
			return make_token(TokenType::Equal, 1);		
		case '+':
			if (m_CurrentCharacter[1] == '+')
				return make_token(TokenType::DoublePlus, 2);	
			if (m_CurrentCharacter[1] == '=')
				return make_token(TokenType::PlusEqual, 2);	
			return make_token(TokenType::Plus, 1);				
		case '-':  
			if (m_CurrentCharacter[1] == '-')
				return make_token(TokenType::DoubleMinus, 2);	
			if (m_CurrentCharacter[1] == '=')								 
				return make_token(TokenType::MinusEqual, 2);	
			return make_token(TokenType::Hyphen, 1);		
		case '*':
			if (m_CurrentCharacter[1] == '=')
				return make_token(TokenType::MultEqual, 2);	
			return make_token(TokenType::Astricks, 1);		
		case '/':  
			if (m_CurrentCharacter[1] == '=')
				return make_token(TokenType::DivEqual, 2);		
			return make_token(TokenType::ForwardSlash, 1);	

		case '[':  return make_token(TokenType::LeftBracket, 1);
		case ']':  return make_token(TokenType::RightBracket, 1);
		case '{':  return make_token(TokenType::LeftBrace, 1);
		case '}':  return make_token(TokenType::RightBrace, 1);
		case '(':  return make_token(TokenType::LeftParentheses, 1);
		case ')':  return make_token(TokenType::RightParentheses, 1);
		case ';':  return make_token(TokenType::Semicolon, 1);
		case '\\': return make_token(TokenType::BackSlash, 1);
		case '_':  return make_token(TokenType::Underscore, 1);
		case '~':  return make_token(TokenType::Tilda, 1);
		case '\'': return make_token(TokenType::SingleQuote, 1);
		case '\"': return make_token(TokenType::DoubleQuote, 1);
		case '?':  return make_token(TokenType::QuestionMark, 1);
		case '.':  return make_token(TokenType::Period, 1);
		case ',':  return make_token(TokenType::Comma, 1);
		case '@':  return make_token(TokenType::At, 1);
		case '#':  return make_token(TokenType::Pound, 1);
		case '$':  return make_token(TokenType::DollarSign, 1);
		case '%':  return make_token(TokenType::Percentage, 1);
		case '^':  return make_token(TokenType::Caret, 1);
		case '`':  return make_token(TokenType::Grave, 1);
		case '\0': return make_token(TokenType::NullTerminator, 1);
	}
}

Token Lexer::make_token(TokenType type, size_t length) {
	return { type, { m_CurrentCharacter, length }, m_CurrentLineNumber, m_CurrentColumnNumber };
}

Token Lexer::advance() {
	skip_whitespace();

	Token token = process_token();
	m_CurrentCharacter += token.position.length();
	m_CurrentColumnNumber += token.position.length();

	return token;
}