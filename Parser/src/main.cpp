#include <iostream>
#include "Lexer.h"

int main() {
	const char* file = R"(


#comment

int /address/ name << 6;
int /address/ name[size] << 8;

for (8) {

}

for (int i :: 8) {

}
for (int i << 6 : 8 : ++)

int foo(int x, int y) {}

int x << 4;
int y << 9;

int l << foo << x, y;

int> r << .l;

int k << *r;

)";


const char* str = R"(
[
     ]
{ 
}
(   
  )
;
//yo muth   eee   e {}{{ef)*&*
\\
+_-
$
'
  ~
\'
\"
?
.
,
@
#
'
%
'
'
 '
100 abcd
)";

	Lexer lexer{str};
	Token token{};
	while (token.type != TokenType::NullTerminator) {
		token = lexer.next();
		std::cout << "TYPE: " << (uint32_t)token.type << ", LINE: " << token.line << ", COL: " << token.col << std::endl;
	}

	return 0;
}