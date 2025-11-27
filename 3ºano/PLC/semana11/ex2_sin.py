import ply.yacc as yacc
from calc_lex import lexer, tokens, literals


def p_gramatica(p):
    """
    PAR : '(' INST ')' 
    INST : READ VAR 
          | IF '(' '>' VAR VAR ')'
          | WRITE VAR 
          | WHILE '(' '>' VAR NUM ')'

        
    """



"""
STOR
def p_program(t):
    r"Program : Statements"
    t[0] = "\n".join("pushi 0 for i in range 26" + t[1])

def p_stmts_0(t):
    r"Statements : Statements Statement"
    t[0] = t[1]

def p_stmts_1(t):
    r"Statements: "
    t[0] = []


def p_stmt_read(t):
    r"Statements : '(' READ VAR ')'"
    idx = ord(t[3]) - ord("a")
    t[0] = [f"pushs "var {t[3]}":" , "writes", "read","atoi", f"storeg(idx)"]

def p_stmt_write(t):
    r"Statement : '(' WRITE VAR ')'"
    idx = ord(t[3]) - ord("a")
    t[0] = [f"pushs "var {t[3]}":" , "writes" , f"pushg(idx)","writei"]

def p_stmt_assign(t):
    r"Statement : '(' '=' VAR Exp ')'
    idx = ord(t[3]) - ord("a")
    t[0] = t[4] + [f"storeg (idx)"]


def p_stmt_if(t):
    r"Statement : '(' IF Cond Block Block ')'"

def_stmt_while(t):
    r"Statemenet : '(' WHILE Cond Block ')'"


def p_block_0(t):
    r"Block : Statement

def p_block_1(t):
    r"Block : '(' Statement ')'"

def p_exp_sum(t):
    r"Exp : '(' '+' Exp Term ')'"
    t[0] = t[3] + t[4] + ["add"]

def p_exp_sub(t):
    r"Exp : '(' '-' Exp Term ')'"
    t[0] = t[3] + t[4] + ["add"]

def p_factor_fact(t):
    r"Term : Factor"

def p_factor_num(t):
    r"Factor : NUM"
    t[0] = t[1]
r"Factor : NUM"

def p_factor_var(t):


"""