#include <iostream>
#include <limits>

// Funció per trobar el valor màxim i mínim en una matriu
void trobarMaximMinim(int** matriu, int files, int columnes, int& maxim, int& minim) {
    maxim = std::numeric_limits<int>::min(); // Inicialitzem amb el valor més petit possible
    minim = std::numeric_limits<int>::max(); // Inicialitzem amb el valor més gran possible

    for (int i = 0; i < files; ++i) {
        for (int j = 0; j < columnes; ++j) {
            if (matriu[i][j] > maxim) {
                maxim = matriu[i][j];
            }
            if (matriu[i][j] < minim) {
                minim = matriu[i][j];
            }
        }
    }
}
int main() {
    // Demana a l'usuari les dimensions de la matriu
    int files, columnes;
    std::cout << "Introdueix el nombre de files: ";
    std::cin >> files;
    std::cout << "Introdueix el nombre de columnes: ";
    std::cin >> columnes;

    // Crea la matriu dinàmicament
    int** matriu = new int* [files];
    for (int i = 0; i < files; ++i) {
        matriu[i] = new int[columnes];
    }

    // Demana a l'usuari les puntuacions i omple la matriu
    for (int i = 0; i < files; ++i) {
        for (int j = 0; j < columnes; ++j) {
            std::cout << "Introdueix la puntuacio per la fila " << i + 1 << " i la columna " << j + 1 << ": ";
            std::cin >> matriu[i][j];
        }
    }
    // Troba el valor màxim i mínim
    int maxim, minim;
    trobarMaximMinim(matriu, files, columnes, maxim, minim);

    // Mostra els resultats
    std::cout << "\nEl valor maxim es: " << maxim << std::endl;
    std::cout << "El valor minim es: " << minim << std::endl;

    // Allibera la memòria
    for (int i = 0; i < files; ++i) {
        delete[] matriu[i];
    }
    delete[] matriu;

    return 0;
}