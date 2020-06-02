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
   | (assignment|fnExpression ',')* expression
   ;

assignment
   : identifier=IDENTIFIER '=' expression
   ;

fnExpression
   : fnDeclaration '=' expression
   ;

fnDeclaration
   : identifier=IDENTIFIER '(' param_name=IDENTIFIER ')'
   ;

expression
   : expression op=('*'|'/') expression       # MulDiv
   | expression op=('+'|'-') expression       # AddSub
   | NUMBER                                   # Number
   | IDENTIFIER                               # Identifier
   | identifier=IDENTIFIER '(' expression ')' # FunctionCall
   | '(' expression ')'                       # InnerExpr
   ;
