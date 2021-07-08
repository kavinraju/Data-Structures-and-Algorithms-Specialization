import java.util.Stack;

public class PostfixEvaluation {

    public int evaluatePostfixForSingleDigit(String expression) {

        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (Character.isDigit(c)) {
                stack.push(c - '0');
            } else {
                int val1 = stack.pop();
                int val2 = stack.pop();

                switch (c) {
                    case '+':
                        stack.push(val2 + val1);
                        break;
                    case '-':
                        stack.push(val2 - val1);
                        break;
                    case '*':
                        stack.push(val2 * val1);
                        break;
                    case '/':
                        stack.push(val2 / val1);
                        break;
                }
            }
        }
        return stack.pop();
    }

    public int evaluatePostfixForMultipleDigit(String expression) {

        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);

            if (c == ' ')
                continue;
            else if (Character.isDigit(c)) {
                int result = 0;
                while (Character.isDigit(c)) {
                    int val = c - '0';
                    result = (result * 10) + val;
                    i++;
                    c = expression.charAt(i);
                }
                i--;
                stack.push(result);
            } else {
                int val1 = stack.pop();
                int val2 = stack.pop();

                switch (c) {
                    case '+':
                        stack.push(val2 + val1);
                        break;
                    case '-':
                        stack.push(val2 - val1);
                        break;
                    case '*':
                        stack.push(val2 * val1);
                        break;
                    case '/':
                        stack.push(val2 / val1);
                        break;
                }
            }
        }
        return stack.pop();
    }

    public static void main(String[] args) {
        PostfixEvaluation obj = new PostfixEvaluation();
        String expr = "231*+9-";
        System.out.println("Postfix " + expr + " evaluated to " + obj.evaluatePostfixForSingleDigit(expr));

        expr = "100 200 + 2 / 5 * 7 +";
        System.out.println("Postfix " + expr + " evaluated to " + obj.evaluatePostfixForMultipleDigit(expr));
    }
}
