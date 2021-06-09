#include "Grafica.h"

/* Aplicación del concepto de gráficas para encontrar el conjunto mínimo de
➥carreteras, con el menor costo asociado, que una un grupo de ciudades. */

/*
Equipo #3:

-> Domínguez Martínez Edder Emmanuel
-> Esqueda Rodríguez, Fabián Alejandro.
-> Godoy Rodríguez, Berenice.
-> Gómez Jiménez, Ángel Armando.
-> Gómez Ramírez, Eduardo Fabián.

Sección: D05
Calendario: 2021-A
*/

int main(void)
{
    system("cls");

    Grafica<int> Caminos;
    size_t opc;

    do
    {
        system("color F1");

        cout<<"MENU - SECRETARIA DE COMUNICACIONES Y TRANSPORTE"<<endl<<endl;
        cout<<"(0) INGRESAR DATOS E IMPRIMIR MATRIZ DE ADYACENCIAS"<<endl;
        cout<<"(1) KRUSKAL"<<endl;
        cout<<"(2) PRIM"<<endl;
        cout<<"(3) SALIR"<<endl<<endl;

        cout<<"DIGITA UNA OPCION: ";
        cin>>opc;

        system("cls");

        switch(opc)
        {
            system("color F4");

            case 0: cout<<"INGRESE DATOS DE LAS CIUDADES (VERTICES) Y DE LAS CARRETERAS (ARISTAS)\n\n";

                    Caminos.Lee();
                    Caminos.Imprime();//Imprime la matriz de adyacencias o costos

                    Caminos.respaldar_MatAdy();

                    cout<<"\n\n";
                    system("pause"); system("cls");
                    break;

            case 1: cout<<"LA RED MINIMA DE CARRETERAS REQUERIDAS PARA UNIR TODAS LAS CIUDADES ES:\n\n";
                    
                    cout<<"\t\tARBOL ABARCADOR DE COSTOS MINIMOS - KRUSKAL"<<endl<<endl;
                    Caminos.Kruskal();
                    
                    cout<<"\n\n";
                    system("pause"); system("cls");
                    break;

            case 2: cout<<"LA RED MINIMA DE CARRETERAS REQUERIDAS PARA UNIR TODAS LAS CIUDADES ES:\n\n";
                    
                    Caminos.Prim();

                    cout<<"\n\n";
                    system("pause"); system("cls");
                    break;

            case 3: cout<<"\t\t\tSALIENDO DEL PROGRAMA..."<<endl<<endl;
                    break;

        }

    } while (opc != 3);
    
    
    // cout<<"\n\nLa red minima de carreteras requerida para unir todas las ciudades es:\n";
    
    // Caminos.Kruskal();
    // Caminos.Prim();

    return 0;
}