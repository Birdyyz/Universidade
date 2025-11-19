from calculator_sin import parser
import sys

print(
"""
Interactive calculator, available commands:
    ! e - print the value of an expression e
    ? v - print the value of a variable v 
    v = e - assign value of expression e to variable v 
    * - dump the value of all variables
"""
)

"""
Instruction -> Var = EXP
            | ? Var
            | ! EXP
            | *
EXP -> EXP - Term 
    | EXP + Term 
    | Term
Term -> Term * Factor 
    | Term / Factor 
    | Factor 
Factor -> NUM 
    |(EXP) 
    | Var

"""
for linha in sys.studio:
    parser.sucess = True 
    result = parser.parse(linha)
    if parser.sucess:
        if result: print(result)

