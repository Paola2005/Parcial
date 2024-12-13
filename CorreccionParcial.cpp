#include<iostream>
using namespace std;

int main() 
{

    int A;
    cout << "\nCantidad de articulos a procesar: ";
    cin >> A;
    cin.ignore(); 
    char Articulos[A][40];

 
    int i = 0;
    while (i <= A - 1) {
        cout << "\nIngrese el nombre del articulo " << i + 1 << ": ";
        cin.getline(Articulos[i], 40);
        i++;
    }


    float Valores[A];
    i = 0;
    while (i <= A - 1) {
        cout << "\nIngrese el valor del articulo " << Articulos[i] << ": ";
        cin >> Valores[i];
        i++;
    }


    int E;
    cout << "\nCantidad de empleados a procesar: ";
    cin >> E;
    cin.ignore(); 
    char Empleados[E][40];


    int j = 0;
    while (j <= E - 1) {
        cout << "\nIngrese el nombre del empleado " << j + 1 << ": ";
        cin.getline(Empleados[j], 40);
        j++;
    }

    
    int Asignacion[A][E];
    for (int h = 0; h <= A - 1; h++) {
        cout << "\nPara el articulo " << Articulos[h] << ": ";
        for (int k = 0; k <= E - 1; k++) {
            cout << "\nCantidad asignada al empleado " << Empleados[k] << ": ";
            cin >> Asignacion[h][k];
        }
    }


    float ValorInventario[E] = {0};
    for (j = 0; j <= E - 1; j++) {
        for (i = 0; i <= A - 1; i++) {
            ValorInventario[j] += Asignacion[i][j] * Valores[i];
        }
    }

 
    cout << "\nValores del inventario asignado a cada empleado:\n";
    for (j = 0; j <= E - 1; j++) {
        cout << Empleados[j] << ": $" << ValorInventario[j] << endl;
    }

   
    int indiceMayor = 0;
    for (j = 1; j <= E - 1; j++) {
        if (ValorInventario[j] > ValorInventario[indiceMayor]) {
            indiceMayor = j;
        }
    }
    cout << "\nEmpleado con mayor inventario asignado:\n";
    cout << Empleados[indiceMayor] << ": $" << ValorInventario[indiceMayor] << endl;


    float ValorTotalInventario = 0;
    for (j = 0; j <= E - 1; j++) {
        ValorTotalInventario += ValorInventario[j];
    }
    float Umbral = 0.2 * ValorTotalInventario;


    cout << "\nEmpleados con inventario menor al 20% del total:\n";
    for (j = 0; j <= E - 1; j++) {
        if (ValorInventario[j] < Umbral) {
            cout << Empleados[j] << ": $" << ValorInventario[j] << endl;
        }
    }


    cout << "\nValor total de los inventarios: $" << ValorTotalInventario << endl;

    return 0;
}

