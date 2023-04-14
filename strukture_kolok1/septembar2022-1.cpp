bool isOperation(char c) {
	return (c == '+' or c == '-' or c == '*' or c == '/');
}

double calc(char op, double op1, double op2) {
	if (op == '+')
		return op1 + op2;
	else if (op == '-')
		return op1 - op2;
	else if (op == '*')
		return op1 * op2;
	else if (op == '/')
		return op1 / op2;
}

double calcPrefix(const char* exp) {
	DStack<char> operations;
	DStack<double> operands;
	bool operation = false;
	for (int i = 0; exp[i] != '\0'; i++) {
		if (isOperation(exp[i])) {
			operations.push(exp[i]);
			operation = true;
		}
		else if (operands.isEmpty() or operation) {
			operands.push(exp[i] - 48);
			operation = false;
		}
		else {
			char op = operations.pop();
			double op1 = operands.pop();
			double op2 = exp[i] - 48;
			operands.push(calc(op, op1, op2));
			operation = false;
		}
	}
	if (not operations.isEmpty()) {
		double op2 = operands.pop();
		double op1 = operands.pop();
		return calc(operations.pop(), op1, op2);
	}
	return operands.pop();
}