# Unit Test Boolean Equation Example
Unit test example based on boolean equation parser using c++, GTest and GMock

## Compilation
1. cmake .
2. make


## Usage

`bool_eval \<bool_expression\> \<arg1=value_1\> \<arg2=value_2\> \<...\> \<argn=value_n\>`

## Example

Execution:

`./bool_eval "AND(AND(x,y),OR(c,d),OR(e,f))" "x=True" "y=True" "c=False" "d=True" "e=False" "f=True"`

Result:

`Expression: And(And(True, True), Or(False, True), Or(False, True))=1`

## Test run

Run test cases:

For running the test cases do `ctest .` or `make test`

Verbose visualization:

`ctest -VV`
