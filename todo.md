Todo:

# We can recognize the next tokens :

- file extension rcz
- keyword “if”
- indentifiers: “a1” and “a2”
- constants: 12
- symbols: “(”, “)” and “;”
- operators “=” et “+”
- operator cmp “==”
- operator increment “++”
- operator range “:=”

advance(lexer);
peek(lexer);
peek_next(lexer);
match(lexer);
skip_whitespace(lexer);
scan_identifier(lexer);
scan_number(lexer);
