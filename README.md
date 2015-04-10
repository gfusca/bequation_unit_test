# bequation_unit_test
Unit test example based on boolean equation parser using GTest and GMock

usage: bool_eval \<bool_expression\> \<arg1=value_1\> \<arg2=value_2\> \<...\> \<argn=value_n\>

Example

Execution:

$ bool_eval "AND(AND(x,y),OR(c,d),OR(e,f))" "x=True" "y=True" "c=False" "d=True" "e=False" "f=True"

Result:
Expression: And(And(True, True), Or(False, True), Or(False, True))=1
