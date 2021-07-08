import java.util.Stack;

/**
 * https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
 */
public class InfixToPostfix {

    private int precedence(char c) {
        switch (c) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default:
                return -1;
        }
    }

    public String infixToPostfix(String expression) {
        StringBuilder builder = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);

            if (Character.isLetterOrDigit(c)) {
                builder.append(c);
            } else if (c == '(') {
                stack.push(c);
            } else if (c == ')') {
                while (!stack.empty() && stack.peek() != '(')
                    builder.append(stack.pop());

                // discard the '(' encountered at the last step
                stack.pop();
            } else {
                while (!stack.empty() && precedence(c) < precedence(stack.peek()))
                    builder.append(stack.pop());

                stack.push(c);
            }
        }

        while (!stack.empty()) {
            if (stack.peek() == '(')
                return "Invalid arguments";
            builder.append(stack.pop());
        }

        return builder.toString();
    }

    public static void main(String[] args) {
        InfixToPostfix obj = new InfixToPostfix();
        String expr = "a+b*(c^d-e)^(f+g*h)-i";
        System.out.println(obj.infixToPostfix(expr));
    }
}
