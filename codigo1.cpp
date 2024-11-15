#include <iostream>
using namespace std;

const int MAX_COORDENADAS = 100;

struct Coordenada {
    int x;
    int y;
};

void determinarCuadrante(int x, int y) {
    if (x > 0 && y > 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el primer cuadrante (+,+)" << endl;
    } else if (x < 0 && y > 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el segundo cuadrante (-,+)" << endl;
    } else if (x < 0 && y < 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el tercer cuadrante (-,-)" << endl;
    } else if (x > 0 && y < 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el cuarto cuadrante (+,-)" << endl;
    } else if (x == 0 && y == 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el origen" << endl;
    } else if (x == 0){
        cout << "La coordenada (" << x << ", " << y << ") se encuentra sobre el eje Y." << endl;
    } else if (y == 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra sobre el eje X." << endl;
    }
}

void verificarLinea(Coordenada coordenadas[], int numCoordenadas) {
    if (numCoordenadas < 2) {
        cout << "Se necesitan al menos dos coordenadas para determinar una recta" << endl;
        return;
    }

    int x1 = coordenadas[0].x;
    int y1 = coordenadas[0].y;
    int x2 = coordenadas[1].x;
    int y2 = coordenadas[1].y;

    float m = (float)(y2 - y1) / (x2 - x1);
    float b = y1 - m * x1;

    bool enMismaLinea = true;
    for (int i = 2; i < numCoordenadas; ++i) {
        int xi = coordenadas[i].x;
        int yi = coordenadas[i].y;
        if (yi != m * xi + b) {
            enMismaLinea = false;
            break;
        }
    }

    if (enMismaLinea) {
        cout << "Todas las coordenadas se encuentran en la misma recta" << endl;
        cout << "La ecuacion de la recta es: y = " << m << "x + " << b << endl;
    } else {
        cout << "Las coordenadas no se encuentran en la misma recta" << endl;
    }
}

int main() {
    Coordenada coordenadas[MAX_COORDENADAS];
    int numCoordenadas = 0;
    char continuar;

    do {
        if (numCoordenadas >= MAX_COORDENADAS) {
            cout << "Se ha alcanzado el numero maximo de coordenadas." << endl;
            break;
        }

        cout << "Ingrese las coordenadas X e Y (separadas por un espacio): ";
        cin >> coordenadas[numCoordenadas].x >> coordenadas[numCoordenadas].y;
        determinarCuadrante(coordenadas[numCoordenadas].x, coordenadas[numCoordenadas].y);
        numCoordenadas++;

        cout << "Desea ingresar otra coordenada? (y/n): ";
        cin >> continuar;
    } while (continuar == 'y' || continuar == 'Y');

    verificarLinea(coordenadas, numCoordenadas);

    return 0;
}
