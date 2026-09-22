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

 Token& Lexer::process_token(Token& token) {
	switch (*m_CurrentCharacter) {
		case '<':  
			if (m_CurrentCharacter[1] == '<')
				token = make_token({ TokenType::DoubleLeftAngularBracket	}, 2);		break;
			if (m_CurrentCharacter[1] == '=')
				token = make_token({ TokenType::LessThanEqual				}, 2);		break;
			token     = make_token({ TokenType::LeftAngleBracket				}, 1);	break;
		case '>':  
			if (m_CurrentCharacter[1] == '>')
				token = make_token({ TokenType::DoubleRightAngularBracket	}, 2);		break;
			if (m_CurrentCharacter[1] == '=')
				token = make_token({ TokenType::GreaterThanEqual			}, 2);		break;
			token     = make_token({ TokenType::RightAngleBracket			}, 1);		break;
		case ':':
			if (m_CurrentCharacter[1] == ':')
				token = make_token({ TokenType::DoubleColon					}, 2);	    break;
			token     = make_token({ TokenType::Colon						}, 1);	    break;
		case '|':
			if (m_CurrentCharacter[1] == '=')
				token = make_token({ TokenType::PipeEqual					}, 2);	    break;
			if (m_CurrentCharacter[1] == '|')
				token = make_token({ TokenType::DoublePipe					}, 2);	    break;
			token	  = make_token({ TokenType::Pipe						}, 1);	    break;
		case '&':
			if (m_CurrentCharacter[1] == '=')
				token = make_token({ TokenType::AmpersandEqual				}, 2);	    break;
			if (m_CurrentCharacter[1] == '&')
				token = make_token({ TokenType::DoubleAmpersand				}, 2);	    break;
			token     = make_token({ TokenType::Ampersand				    }, 1);	    break;
		case '!':
			if (m_CurrentCharacter[1] == '=')
				token = make_token({ TokenType::NotEqual					}, 2);	    break;
			token	  = make_token({ TokenType::ExclamationMark				}, 1);	    break;
		case '=':
			if (m_CurrentCharacter[1] == '=')
				token = make_token({ TokenType::DoubleEqual					}, 2);	    break;
			token	  = make_token({ TokenType::Equal						}, 1);	    break;
		case '+':
			if (m_CurrentCharacter[1] == '+')
				token = make_token({ TokenType::DoublePlus					}, 2);	    break;
			if (m_CurrentCharacter[1] == '=')
				token = make_token({ TokenType::PlusEqual					}, 2);	    break;
			token     = make_token({ TokenType::Plus						}, 1);	    break;
		case '-':  
			if (m_CurrentCharacter[1] == '-')
				token = make_token({ TokenType::DoubleMinus					}, 2);	    break;
			if (m_CurrentCharacter[1] == '=')
				token = make_token({ TokenType::MinusEqual					}, 2);	    break;
			token     = make_token({ TokenType::Hyphen						}, 1);	    break;
		case '*':
			if (m_CurrentCharacter[1] == '=')
				token = make_token({ TokenType::MultEqual					}, 2);	    break;
			token     = make_token({ TokenType::Astricks					}, 1);	    break;
		case '/':  
			if (m_CurrentCharacter[1] == '/')
				token = make_token({ TokenType::Comment						}, 2);	    break;
			if (m_CurrentCharacter[1] == '=')
				token = make_token({ TokenType::DivEqual					}, 2);	    break;
			token	  = make_token({ TokenType::ForwardSlash				}, 1);		break;

		case '[':  token = make_token({ TokenType::LeftBracket				}, 1);		break;
		case ']':  token = make_token({ TokenType::RightBracket				}, 1);		break;
		case '{':  token = make_token({ TokenType::LeftBrace				}, 1);		break;
		case '}':  token = make_token({ TokenType::RightBrace				}, 1);		break;
		case '(':  token = make_token({ TokenType::LeftParentheses			}, 1);		break;
		case ')':  token = make_token({ TokenType::RightParentheses			}, 1);		break;
		case ';':  token = make_token({ TokenType::Semicolon				}, 1);		break;
		case '\\': token = make_token({ TokenType::BackSlash				}, 1);	    break;
		case '_':  token = make_token({ TokenType::Underscore				}, 1);	    break;
		case '~':  token = make_token({ TokenType::Tilda					}, 1);	    break;
		case '\'': token = make_token({ TokenType::SingleQuote				}, 1);	    break;
		case '\"': token = make_token({ TokenType::DoubleQuote				}, 1);	    break;
		case '?':  token = make_token({ TokenType::QuestionMark				}, 1);	    break;
		case '.':  token = make_token({ TokenType::Period					}, 1);	    break;
		case ',':  token = make_token({ TokenType::Comma					}, 1);	    break;
		case '@':  token = make_token({ TokenType::At						}, 1);	    break;
		case '#':  token = make_token({ TokenType::Pound					}, 1);	    break;
		case '$':  token = make_token({ TokenType::DollarSign				}, 1);	    break;
		case '%':  token = make_token({ TokenType::Percentage				}, 1);	    break;
		case '^':  token = make_token({ TokenType::Caret					}, 1);	    break;
		case '`':  token = make_token({ TokenType::Grave					}, 1);	    break;
	}
}

Token Lexer::make_token(const TokenType& type, size_t length) {
	return { type, { m_CurrentCharacter, length }, m_CurrentLineNumber, m_CurrentColumnNumber };
}

Token Lexer::advance_ptr() {
	m_CurrentCharacter++;
	Token token{};
	process_token(token);

	return token;
}