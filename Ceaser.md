# The Cryptolang Programming Language

## Arithmetic operators

- [ ] the sum operator : **+**
- [ ] the difference operator : **-**
- [ ] the multiply operator : **\***
- [ ] the division operator : **/**
- [ ] the modulo operator : **%**
- [ ] the post-increment operator : **++{}**
- [ ] the later-increment operator : **{}++**

## Bitwise operators

- [ ] the not operator : **!**
- [ ] the and operator : **&**
- [ ] the nand operator : **~**
- [ ] the or operator : **|**
- [ ] the nor operator : **#**
- [ ] the xor operator : **^**
- [ ] the shift right operator : **>>**
- [ ] the shift left operator : **<<**
- [ ] the rotate left operator : **<<<**
- [ ] the rotate right operator : **>>>**

## Relational operators

- [ ] the equal operator : **==**
- [ ] the not equal operator : **!=**
- [ ] the greater than operator : **>**
- [ ] the less than operator : **<**
- [ ] the greater than or equal operator : **>=**
- [ ] the less than or equal operator : **<=**

## Assignment operators

- [ ] the assignment operator : **=**
- [ ] the sum assignment operator : **+=**
- [ ] the subtract assignment operator : **-=**
- [ ] the multiplication assignment operator : **\*=**
- [ ] the division assignment operator : **/=**
- [ ] the modulo assignment operator : **%=**

## Type System Keywords

- [ ] the bit type : **bit**
- [ ] the bits type : **bits**
- [ ] the byte type : **byte**
- [ ] the word type : **word**
- [ ] the polynomial ring type : **poly**
- [ ] the lattice type : **lattice**
- [ ] the finite field type : **field**
- [ ] the elliptic curve group type : **group**
- [ ] the type definition keyword : **type**
- [ ] the structure definition keyword : **struct**

## Quantum Computing Keywords

- [ ] the quantum bit type : **qubit**
- [ ] the quantum register type : **qureg**
- [ ] the quantum circuit keyword : **qcircuit**
- [ ] the quantum gate keyword : **qgate**
- [ ] the measure quantum state keyword : **measure**
- [ ] the superposition keyword : **superpose**

## Conditional Keywords

- [ ] the if keyword : **if**
- [ ] the else keyword : **else**
- [ ] the elif keyword : **elif**
- [ ] the try keyword : **try**
- [ ] the catch keyword : **catch**
- [ ] the finally keyword : **finally**
- [ ] the match keyword : **match**
- [ ] the case keyword : **case**

## Loop Keywords

- [ ] the for keyword : **for**
- [ ] the while keyword : **while**
- [ ] the doWhile keyword : **dowhile**

## Function Definition Keywords

- [ ] the pure function keyword : **apply**
- [ ] the bijective transformation keyword : **transform**
- [ ] the permutation operation keyword : **permute**
- [ ] the crypto round function keyword : **round**
- [ ] the constant-time guard keyword : **with**
- [ ] the compile-time check keyword : **assert**
- [ ] the verifier hint keyword : **assume**
- [ ] the function return keyword : **return**
- [ ] the lazy sequence keyword : **yield**

## Cryptographic Operation Keywords

- [ ] the modular addition keyword : **add_mod**
- [ ] the modular multiplication keyword : **mul_mod**
- [ ] the modular exponentiation keyword : **exp_mod**
- [ ] the modular inverse keyword : **inv_mod**
- [ ] the cryptographic sampling keyword : **sample**
- [ ] the polynomial compression keyword : **compress**
- [ ] the polynomial decompression keyword : **decompress**
- [ ] the hash function keyword : **hash**

## Verification & Security Attributes

- [ ] the verifiable attribute : **@verifiable**
- [ ] the constant-time attribute : **@constant_time**
- [ ] the pure attribute : **@pure**
- [ ] the leak-free attribute : **@leak_free**
- [ ] the theorem prover keyword : **prove**
- [ ] the loop invariant keyword : **invariant**
- [ ] the precondition keyword : **requires**

## Memory & Side-Channel Protection Keywords

- [ ] the secret data keyword : **secret**
- [ ] the public data keyword : **pub**
- [ ] the secure zeroize keyword : **zeroize**
- [ ] the compile-time constant keyword : **constant**
- [ ] the volatile memory keyword : **volatile**
- [ ] the memory alignment keyword : **aligned**

## Module System Keywords

- [ ] the mod keyword : **mod**
- [ ] the import keyword : **import**
- [ ] the export keyword : **export**
- [ ] the qualified use keyword : **use**
- [ ] the rename import keyword : **as**
- [ ] the opaque type keyword : **opaque**

## Built-in Literals & Constants

- [ ] the boolean true literal : **true**
- [ ] the boolean false literal : **false**
- [ ] the hexadecimal literal prefix : **0x**
- [ ] the binary literal prefix : **0b**
- [ ] the sized bits literal : **bits**
- [ ] the point at infinity literal : **INF**

## Complete Operator Precedence (Highest to Lowest)

| Precedence | Operators                    | Associativity |
| :--------- | :--------------------------- | :------------ | ---- |
| 1          | `!` `~` `#`                  | Right         |
| 2          | `<<` `>>` `<<<` `>>>`        | Left          |
| 3          | `&`                          | Left          |
| 4          | `^`                          | Left          |
| 5          | \`                           | \`            | Left |
| 6          | `==` `!=` `<` `>` `<=` `>=`  | Left          |
| 7          | `and` (logical and)          | Left          |
| 8          | `or` (logical or)            | Left          |
| 9          | `=` `+=` `-=` `*=` `/=` `%=` | Right         |

## Complete Keyword Summary (85 total)

**Operators:** `+` `-` `*` `/` `%` `!` `&` `~` `|` `#` `^` `>>` `<<` `<<<` `>>>` `==` `!=` `>` `<` `>=` `<=` `=` `+=` `-=` `*=` `/=` `%=`

**Types:** `bit` `bits` `byte` `word` `poly` `lattice` `field` `group` `type` `struct`

**Quantum:** `qubit` `qureg` `qcircuit` `qgate` `measure` `superpose`

**Conditionals:** `if` `else` `elif` `try` `catch` `finally` `match` `case`

**Loops:** `for` `while` `dowhile`

**Functions:** `apply` `transform` `permute` `round` `with` `assert` `assume` `return` `yield`

**Crypto Ops:** `add_mod` `mul_mod` `exp_mod` `inv_mod` `sample` `compress` `decompress` `hash`

**Verification:** `@verifiable` `@constant_time` `@pure` `@leak_free` `prove` `invariant` `requires`

**Security:** `secret` `public` `zeroize` `constant` `volatile` `aligned`

**Modules:** `mod` `import` `export` `use` `as` `opaque`

**Literals:** `true` `false` `infinity`
