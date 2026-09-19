#include "Lexer.h"

Lexer::Lexer() {

}

void Lexer::skip_whitespace() {
	while (*current == ' ' || *current == '\t' || *current == '\r' || *current == '\n' || *current == '\0')
		current++;
}

Token Lexer::advance_ptr() {
	current++;
	return {};
}