# c++ string 类型功能不是很强大就选择用 py 实现
# 因为浮点数带个 '.' 不能直接调用 isdigit 函数，就只实现了 '/' 表示整除的四则运算

expression = "(15 - 5) * 10 / 2 + 1 * 3" 
# 使用一个测试用例 (15 - 5) * 10 / 2 + 1 * 3
# 正确结果应该是 53


priority = {'+' : 1, '-' : 1, '*' : 2, '/' : 2,'(' : 0}
i = 0
n = len(expression)
sufix = []
ops = []
while i < n:
    if expression[i].isspace():
        i += 1
        continue
    if expression[i].isdigit():
        num = ""
        while(i < n and expression[i].isdigit()):
            num += expression[i]
            i += 1
        sufix.append(num)
        continue
    if expression[i] == '(':
        ops.append(expression[i])
    elif expression[i] == ')':
        while(ops and ops[-1] != '('):
            sufix.append(ops[-1])
            ops.pop()
        ops.pop()
    else:
        while(ops and priority[ops[-1]] >= priority[expression[i]]):
            sufix.append(ops[-1])
            ops.pop()
        ops.append(expression[i])
    i += 1

while(len(ops) > 0):
    sufix.append(ops[-1])
    ops.pop()

def applyOP(num1,num2,OP):
    res = 0
    if OP == '+':
        res = int(num1) + int(num2)
    elif OP == '-':
        res = int(num1) - int(num2)
    elif OP == '*':
        res = int(num1) * int(num2)
    elif OP == '/':
        res = int(num1) // int(num2)
    return str(res)

calc = []
for cur in sufix:
    # 由于isdigit()函数的限制，只能处理整数
    if cur.isdigit(): 
        calc.append(cur)
    else:
        num1 = calc[-1]
        calc.pop()
        num2 = calc[-1]
        calc.pop()
        calc.append(applyOP(num2,num1,cur))

print(f"expression:{expression}")
if calc:
    print(f"result:{calc[0]}")
else:
    print("expression error!")

     
