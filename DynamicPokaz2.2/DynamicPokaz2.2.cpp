#include <iostream>

int main() {
    int M, N;
    std::cout << "розмір масиву A ";
    std::cin >> M;
    std::cout << "розмір масиву B ";
    std::cin >> N;

    int* A = new int[M];
    int* B = new int[N];
    int* C = new int[M + N];
    int index = 0;

    std::cout << "елементи масиву A ";
    for (int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    std::cout << "елементи масиву B ";
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for (int i = 0; i < M; i++) {
        bool foundInB = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                foundInB = true;
                break;
            }
        }
        bool alreadyInC = false;
        for (int k = 0; k < index; k++) {
            if (C[k] == A[i]) {
                alreadyInC = true;
                break;
            }
        }
        if (!foundInB && !alreadyInC) {
            C[index++] = A[i];
        }
    }
    for (int i = 0; i < N; i++) {
        bool foundInA = false;
        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                foundInA = true;
                break;
            }
        }
        bool alreadyInC = false;
        for (int k = 0; k < index; k++) {
            if (C[k] == B[i]) {
                alreadyInC = true;
                break;
            }
        }
        if (!foundInA && !alreadyInC) {
            C[index++] = B[i];
        }
    }

    std::cout << "третій масив - елементи, які є лише в одному з масивів A або B ";
    for (int i = 0; i < index; i++) {
        std::cout << C[i] << " ";
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
