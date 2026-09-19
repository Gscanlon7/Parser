#include "Lexer.h"

void Lexer::skip_whitespace() {
	while (*current != ' ' && *current != '\t' && *current != '\r' && *current != '\n' && *current != '\0')
		current++;
}

Token Lexer::advance() {
	current++;
	return;
}