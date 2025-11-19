import ply.yacc as yacc
from calculator_lex import tokens, literals
#tokens literais aparecem entre aspas
def p_gramatica(p):
    """
    Instruction : Var "=" EXP
                | "?" Var
                | "!" EXP
                | "*"
    EXP : EXP "-" Term 
        | EXP "+" Term 
        | Term
    Term : Term "*" Factor 
        | Term "/" Factor 
        | Factor 
    Factor : NUM 
        | "(" EXP ")"
        | Var

    """
    # isto e a mesma coisa, so partimos a gramatica em varias funcoes diferentes
    #para podermos dizer coisas diferentes para cada regra
    # podemos dividir ou podemos ter tudo numa so funcao
def p_inst_assign(p):
    r'Instruction : Var "=" EXP'
def p_inst_var(p):
    r'Instruction: "?" Var'
def p_inst_exp(p):
    r'Instruction: "!" EXP'
def p_innt_mult(p):
    r'Instruction: "*"'

#falta aqui exp
def p_exp_term(p):
    r'EXP: Term'
def p_term_mul(p):
    r'Term: Term "*" Factor'
def p_term_div(p):
    r'Term: Term "/" Factor'
def p_term_factor(p):
    r'Term: Term'
def p_factor_num(p):
    r'Factor: NUM'
def p_factor_paren(p):
    r'Factor: "(" EXP ")"'
def P_factor_Var(p):
    r'Factor: Var'

        
def p_error(p):
    print('Erro sintático: ', p)
    parser.success = False

# Build the parser
parser = yacc.yacc()

# Adicionar estado ao parser
parser.success = True
