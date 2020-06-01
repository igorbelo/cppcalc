grammar Fasd;

// Tokens
MUL: '*';
DIV: '/';
ADD: '+';
SUB: '-';
NUMBER: [0-9]+;
WHITESPACE: [ \r\n\t]+ -> skip;
IDENTIFIER: [a-zA-Z]+;

// Rules
start 
   : expression EOF
   | (assignment ',')* expression
   ;

assignment
   : identifier=IDENTIFIER '=' expression
   ;

expression
   : expression op=('*'|'/') expression # MulDiv
   | expression op=('+'|'-') expression # AddSub
   | NUMBER                             # Number
   | IDENTIFIER                         # Identifier
   | '(' expression ')'                 # InnerExpr
   ;
