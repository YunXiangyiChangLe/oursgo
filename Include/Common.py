from Include.TACh import TACOP


def commonop2string(op: TACOP) -> str:
    if op == TACOP.ADD:
        return "add"
    elif op == TACOP.SUB:
        return "sub"
    elif op == TACOP.MUL:
        return "mul"
    elif op == TACOP.DIV:
        return "div"
    else:
        return "oopp"