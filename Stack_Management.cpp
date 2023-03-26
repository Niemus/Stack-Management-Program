#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

// Структура Stack представляет собой элемент стека, содержащий информацию (info) и указатель на следующий элемент (next).
struct Stack {
    int info;
    Stack* next;
};

// Функция InStack создает новый элемент стека и помещает его на вершину стека.
Stack* InStack(Stack* p, int in) {
    return new Stack {in, p};
}

// Функция View осуществляет вывод содержимого стека на экран.
void View(Stack* p) {
    Stack* t = p;
    while (t != nullptr) {
        cout << t->info << endl;
        t = t->next;
    }
}

// Функция Del_All осуществляет удаление всех элементов стека, начиная с его вершины.
void Del_All(Stack** p) {
    while (*p != nullptr) {
        Stack* t = *p;
        *p = (*p)->next;
        delete t;
    }
}

// Функция DeleteMinEl удаляет все элементы стека, имеющие отрицательное значение info.
Stack* DeleteMinEl(Stack* p) {
    Stack* begin = p;
    while (begin != nullptr && begin->info < 0) {
        begin = begin->next;
    }
    if (begin == nullptr) {
        return p;
    }
    Stack* prev = begin;
    Stack* curr = begin->next;
    while (curr != nullptr) {
        if (curr->info < 0) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return begin;
}

// Функция Average вычисляет среднее значение элементов стека.
double Average(Stack* p) {
    int count = 0;
    double sum = 0;
    Stack* t = p;
    while (t != nullptr) {
        sum += t->info;
        count++;
        t = t->next;
    }
    return (count == 0) ? 0 :
    sum / count;
}

// Функция clearOut удаляет все элементы стека, кроме его вершины.
void clearOut(Stack*& stk) {
for (Stack* t = stk->next; stk->next != nullptr; t = stk->next) {
delete stk;
stk = t;
}
}

// Функция main предоставляет пользователю возможность выбора режима работы программы.
int main() {
int i, in, n, kod;
Stack* begin = nullptr;
while (true) {
cout << "\n\tCreate - 1.\n\tAdd - 2.\n\tView - 3.\n\tDel - 4.\n\tDelMinEl - 5.\n\tEXIT - 0. : ";
cin >> kod;
switch (kod) {
case 1:
case 2:
if (kod == 1 && begin != nullptr) {
cout << "Clear Memory!" << endl;
break;
}
cout << "Input kol = ";
cin >> n;
for (i = 1; i <= n; i++) {
in = rand() % 20;
begin = InStack(begin, in);
}
if (kod == 1) {
cout << "Create " << n << endl;
} else {
cout << "Add " << n << endl;
}
break;
case 3:
if (begin == nullptr) {
cout << "Stack is Empty!" << endl;
break;
}
cout << "--- Stack ---" << endl;
View(begin);
double avg = Average(begin);
cout << "--- New Stack ---" << endl;
begin->info = avg;
clearOut(begin);
View(begin);
break;
case 4:
if (begin == nullptr) {
cout << "Stack is Empty!" << endl;
break;
}
Del_All(&begin);
cout << "Memory Freed!" << endl;
break;
case 5:
if (begin == nullptr) {
cout << "Stack is Empty!" << endl;
break;
}
begin = DeleteMinEl(begin);
cout << "Negative Items Removed!" << endl;
break;
case 0:
if (begin != nullptr) {
Del_All(&begin);
}
return 0;
default:
cout << "Invalid Input!" << endl;
break;
}
}
}
