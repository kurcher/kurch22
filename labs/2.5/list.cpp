#include <iostream>  // Підключає бібліотеку для вводу/виводу

// Визначаємо структуру вузла для однозв'язного списку
struct Node {
    int data;   // Дані, які зберігає вузол
    Node* next; // Вказівник на наступний вузол
};

// Функція для додавання елементу на початок списку
inline void addToFront(Node** head, int value) {
    Node* newNode = new Node; // Створюємо новий вузол
    newNode->data = value;    // Записуємо дані у вузол
    newNode->next = *head;    // Встановлюємо вказівник "next" на поточну голову списку
    *head = newNode;          // Робимо новий вузол головою списку
}

// Функція для додавання елементу в кінець списку
inline void addToEnd(Node** head, int value) {
    Node* newNode = new Node;  // Створюємо новий вузол
    newNode->data = value;     // Записуємо дані у вузол
    newNode->next = nullptr;   // Встановлюємо вказівник "next" як nullptr, оскільки це буде останній елемент

    if (*head == nullptr) {    // Якщо список порожній, новий вузол стає головою
        *head = newNode;
    }
    else {                   // Інакше проходимо по списку до останнього вузла
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;  // Переходимо до наступного вузла
        }
        current->next = newNode;      // Встановлюємо новий вузол як наступний після останнього
    }
}

// Функція для видалення елементу з початку списку
inline void removeFromFront(Node** head) {
    if (*head != nullptr) {         // Перевіряємо, чи список не порожній
        Node* temp = *head;         // Тимчасово зберігаємо поточну голову
        *head = (*head)->next;      // Змінюємо голову на наступний вузол
        delete temp;                // Звільняємо пам'ять від видаленого вузла
    }
}

// Функція для видалення елементу з кінця списку
inline void removeFromEnd(Node** head) {
    if (*head == nullptr) return;   // Якщо список порожній, нічого не робимо

    if ((*head)->next == nullptr) { // Якщо в списку лише один вузол
        delete* head;               // Видаляємо його
        *head = nullptr;            // Робимо список порожнім
    }
    else {                        // Інакше шукаємо передостанній вузол
        Node* current = *head;
        while (current->next->next != nullptr) {
            current = current->next;  // Переходимо до наступного вузла
        }
        delete current->next;         // Видаляємо останній вузол
        current->next = nullptr;      // Останній вузол тепер вказує на nullptr
    }
}

// Функція для пошуку елементу в списку за значенням
inline Node* searchElement(Node* head, int value) {
    Node* current = head;          // Починаємо з голови списку
    while (current != nullptr) {   // Перебираємо список
        if (current->data == value) {  // Якщо знаходимо значення
            return current;            // Повертаємо вказівник на цей вузол
        }
        current = current->next;       // Переходимо до наступного вузла
    }
    return nullptr;                 // Якщо значення не знайдено, повертаємо nullptr
}

// Функція для перевертання списку
inline void reverseList(Node** head) {
    Node* prev = nullptr;           // Вказівник на попередній вузол (спочатку nullptr)
    Node* current = *head;          // Поточний вузол починається з голови списку
    Node* next = nullptr;           // Тимчасовий вказівник для збереження наступного вузла

    while (current != nullptr) {    // Проходимо по всіх елементах списку
        next = current->next;       // Зберігаємо наступний вузол
        current->next = prev;       // Міняємо напрямок: поточний вузол тепер вказує на попередній
        prev = current;             // Оновлюємо попередній вузол
        current = next;             // Переходимо до наступного вузла
    }
    *head = prev;                   // Нова голова списку - це попередній останній вузол
}

// Функція для сортування списку методом "бульбашки"
inline void sortList(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) return; // Якщо список порожній або має 1 елемент, не потрібно сортувати

    bool swapped;
    do {
        swapped = false;            // Позначаємо, чи були заміни під час ітерації
        Node* current = *head;
        while (current != nullptr && current->next != nullptr) {
            if (current->data > current->next->data) {  // Якщо поточний вузол більший за наступний
                std::swap(current->data, current->next->data);  // Міняємо їх місцями
                swapped = true;      // Відмічаємо, що була заміна
            }
            current = current->next; // Переходимо до наступного вузла
        }
    } while (swapped);  // Продовжуємо, поки відбуваються заміни
}

// Функція для виведення всіх елементів списку
inline void printList(Node* head) {
    Node* current = head;           // Починаємо з голови списку
    while (current != nullptr) {    // Перебираємо всі вузли
        std::cout << current->data << " -> ";  // Виводимо дані вузла
        current = current->next;    // Переходимо до наступного вузла
    }
    std::cout << "null" << std::endl;  // Виводимо кінцевий символ для позначення кінця списку
}

// Функція для очищення списку і звільнення пам'яті
inline void clearList(Node** head) {
    while (*head != nullptr) {  // Видаляємо всі вузли, поки список не стане порожнім
        removeFromFront(head);  // Видаляємо вузли з початку
    }
}

// Структура для двозв'язного вузла в кільцевому списку
struct DoublyNode {
    int data;                // Дані, які зберігає вузол
    DoublyNode* prev;        // Вказівник на попередній вузол
    DoublyNode* next;        // Вказівник на наступний вузол
};

// Функція для перетворення однозв'язного списку в двозв'язний кільцевий список
inline DoublyNode* toTwoWayList(Node* head) {
    if (!head) return nullptr;  // Якщо однозв'язний список порожній, повертаємо nullptr

    DoublyNode* newHead = new DoublyNode;  // Створюємо новий вузол для двозв'язного списку
    newHead->data = head->data;            // Копіюємо дані з однозв'язного списку
    newHead->prev = nullptr;               // Початковий вузол не має попереднього
    DoublyNode* prevNode = newHead;        // Встановлюємо поточний вузол як попередній

    head = head->next;                     // Переходимо до наступного вузла однозв'язного списку
    while (head != nullptr) {              // Проходимо всі вузли однозв'язного списку
        DoublyNode* newNode = new DoublyNode;  // Створюємо новий вузол для двозв'язного списку
        newNode->data = head->data;            // Копіюємо дані
        newNode->prev = prevNode;              // Зв'язуємо з попереднім вузлом
        prevNode->next = newNode;              // Встановлюємо зв'язок наступного
        prevNode = newNode;                    // Оновлюємо поточний попередній вузол
        head = head->next;                     // Переходимо до наступного вузла однозв'язного списку
    }

    // Закриваємо кільцевий список: останній вузол вказує на голову
    prevNode->next = newHead;
    newHead->prev = prevNode;

    return newHead;  // Повертаємо вказівник на початок двозв'язного кільцевого списку
}

// Головна програма для демонстрації функцій
int main() {
    Node* head = nullptr;  // Ініціалізація голови однозв'язного списку

    // Додаємо елементи до списку
    addToFront(&head, 10);
    addToFront(&head, 20);
    addToFront(&head, 30);
    addToEnd(&head, 40);
    addToEnd(&head, 50);

    // Виводимо список після додавання елементів
    std::cout << "List after adding elements: ";
    printList(head);

    // Видаляємо елемент з початку
    removeFromFront(&head);
    std::cout << "List after removing from front: ";
    printList(head);

    // Видаляємо елемент з кінця
    removeFromEnd(&head);
    std::cout << "List after removing from end: ";
    printList(head);

    // Шукаємо елемент зі значенням 20
    Node* foundNode = searchElement(head, 20);
    if (foundNode) {
        std::cout << "Element 20 found!" << std::endl;
    }
    else {
        std::cout << "Element 20 not found!" << std::endl;
    }

    // Перевертаємо список
    reverseList(&head);
    std::cout << "List after reversing: ";
    printList(head);

    // Сортуємо список
    sortList(&head);
    std::cout << "List after sorting: ";
    printList(head);

    // Конвертуємо список у двозв'язний кільцевий
    DoublyNode* twoWayHead = toTwoWayList(head);
    std::cout << "Converted to two-way circular linked list, first node: " << twoWayHead->data << std::endl;

    // Очищаємо список
    clearList(&head);
    std::cout << "List after clearing: ";
    printList(head);

    return 0;  // Кінець програми
}

