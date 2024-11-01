#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

// Функція для визначення пріоритету операторів
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0; // Для неоператорів
}

// Функція для виконання математичної операції
int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/':
        if (operand2 == 0) throw invalid_argument("Ділення на нуль.");
        return operand1 / operand2;
    default:
        throw invalid_argument("Невірна операція");
    }
}

// Функція для перетворення інфіксного виразу в постфіксну (обернену польську) нотацію
string infixToPostfix(const string& expression) {
    stack<char> operators;  // Стек для зберігання операторів
    string postfix;         // Змінна для зберігання постфіксного виразу
    for (char token : expression) {
        // Якщо токен - пробіл, пропускаємо його
        if (isspace(token)) continue;

        // Якщо токен - цифра, додаємо його до постфіксного виразу
        if (isdigit(token)) {
            postfix += token;
        }
        else if (token == '(') {
            operators.push(token); // Додаємо '(' в стек
        }
        else if (token == ')') {
            // Витягуємо з стеку до появи '('
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop(); // Видаляємо '('
        }
        else {
            // Оператор: перевірка пріоритету перед додаванням у стек
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token); // Додаємо оператор до стеку
        }
    }

    // Витягуємо всі залишені оператори
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

// Функція для оцінки постфіксного виразу
int evaluatePostfix(const string& expression) {
    stack<int> operands; // Стек для зберігання операндів
    for (char token : expression) {
        if (isdigit(token)) {
            operands.push(token - '0'); // Перетворення символу в цифру та додавання до стеку
        }
        else {
            // Витягуємо два операнди для виконання операції
            if (operands.size() < 2) throw invalid_argument("Невірний постфіксний вираз");

            int operand2 = operands.top(); operands.pop();
            int operand1 = operands.top(); operands.pop();
            int result = performOperation(token, operand1, operand2); // Виконуємо операцію
            operands.push(result); // Результат повертаємо в стек
        }
    }
    if (operands.size() != 1) throw invalid_argument("Невірний постфіксний вираз");
    return operands.top(); // Остаточний результат
}

// Основна функція для виконання калькулятора
int main() {
    string infixExpression;
    cout << "Введіть інфіксний вираз: ";
    getline(cin, infixExpression);

    try {
        string postfixExpression = infixToPostfix(infixExpression);
        cout << "Постфіксний вираз: " << postfixExpression << endl;

        int result = evaluatePostfix(postfixExpression);
        cout << "Результат: " << result << endl;
    }
    catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }
    return 0;
}
