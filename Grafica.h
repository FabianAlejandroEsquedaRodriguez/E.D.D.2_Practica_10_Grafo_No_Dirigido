/* Máximo número de vértices que maneja la clase Gráfica. */
#define MAX 20

#include <iostream>
#include <fstream>

using namespace std;

/* Función auxiliar que obtiene el valor más pequeño de dos dados como
➥parámetros. La utiliza el método de Kruskal. */
int Minimo (int Val1, int Val2)
{
    int Min= Val1;
    if (Val2 < Min)
        Min= Val2;
    return Min;
}

/* Función auxiliar que obtiene el valor más grande de dos dados como
➥parámetros. La utiliza el método de Kruskal. */
int Maximo (int Val1, int Val2)
{
    int Max= Val1;
    if (Val2 > Max)
        Max= Val2;
    return Max;
}

/* Definición de la plantilla de la clase Grafica. Se incluyen como
➥atributos la matriz de adyacencia (MatAdy), el total de vértices
➥(NumVer) y sus nombres (Vertices). */
template <class T>
class Grafica
{
private:
    T MatAdy[MAX][MAX];
    int NumVer, Vertices[MAX];

public:
    /* Método constructor y métodos auxiliares para leer la 
    información relacionada a la gráfica e imprimir los resultados obtenidos
    al aplicar los demás métodos. */
    Grafica();
    void Lee();
    void Imprime();

    /* Métodos que calculan el árbol abarcador de costo mínimo. */
    void Prim();
    void Kruskal();

    void respaldar_MatAdy();
};

/* Declaración del método constructor. Inicializa el número de vértices
➥en cero y la matriz de distancias con un valor arbitrario muy grande
➥(999), excepto en la diagonal principal, donde el costo es cero. */
template <class T>
Grafica<T>::Grafica()
{
    int Ind1, Ind2;

    for (Ind1= 0; Ind1 < MAX; Ind1++)
        for (Ind2= 0; Ind2 < MAX; Ind2++)
            if (Ind1 != Ind2)
                MatAdy[Ind1][Ind2]= 999;
            else
                MatAdy[Ind1][Ind2]= 0;
    NumVer= 0;
}

/* Método que lee del teclado la información de la gráfica. En esta
➥solución el nombre de los vértices sólo pueden ser valores enteros. */
template <class T>
void Grafica<T>::Lee()
{
    int Aristas, Costo, Ind1, Origen, Destino;

    cout<<"\nINGRESE EL TOTAL DE VERTICES (NODOS) DE LA GRAFICA: ";
    cin>>NumVer;

    for (Ind1= 0; Ind1 < NumVer; Ind1++)
    {
        cout<<"\nNOMBRE DEL VERTICE #"<<Ind1+1<<": ";
        cin>>Vertices[Ind1];
    }

    cout<<"\n\nINGRESE EL TOTAL DE ARISTAS DE LA GRAFICA: ";
    cin>>Aristas;

    system("cls");

    Ind1= 0;

    while (Ind1 < Aristas)
    {
        cout<<"INGRESE DATOS DE LAS CIUDADES (VERTICES) Y DE LAS CARRETERAS (ARISTAS)\n\n\n";

        cout<<"ARISTA #"<<Ind1+1<<endl<<endl;

        cout<<"\nVERTICE ORIGEN: ";
        cin>>Origen;
        cout<<"\nVERTICE DESTINO: ";
        cin>>Destino;
        cout<<"\nCOSTO DE IR DE "<<Origen<<" A "<<Destino<<": ";
        cin>>Costo;

        MatAdy[Origen - 1][Destino - 1]= Costo; 
        MatAdy[Destino - 1][Origen - 1]= Costo;

        Ind1++;

        cout<<"\n\n\n";
        system("pause"); system("cls");
    }

}

//Metodo para imprimir las matrices, segun su metodo
template<class T>
void Grafica<T>::Imprime()
{
    int Ind1, Ind2;
    system("color F0");

    cout<<"\tMATRIZ DE ADYACENCIA O COSTOS: \n\n";
    for (Ind1= 0; Ind1 < NumVer; Ind1++)
    {
        cout<<Vertices[Ind1]<< ": ";
        for (Ind2= 0; Ind2 < NumVer; Ind2++)
            cout<<MatAdy[Ind1][Ind2] << "\t";
        cout<<endl;
    }

}

/* Este método encuentra el árbol abarcador de costo mínimo de una
➥gráfica. En el arreglo VerAux se almacenan los vértices con menor costo
➥que van formando el árbol abarcador. */
template <class T>
void Grafica<T>::Prim()
{
    int MCosto[MAX], VerAux[MAX], Ind1, Ind2, VerMen, MenCos;

    /* Inicializa el subconjunto de vértices VerAux con el valor del
    ➥primer vértice. */
    for (Ind1= 0; Ind1<NumVer; Ind1++)
    {
        MCosto[Ind1]= MatAdy[0][Ind1];
        VerAux[Ind1]= 0;        
    }

    fstream archivoPrim("Prim.txt", ios::out);//Creando el archivo logico
    //Se va a ir guardando en el archivo
    archivoPrim<<"LA RED MINIMA DE CARRETERAS REQUERIDAS PARA UNIR TODAS LAS CIUDADES ES:\n\n";
    archivoPrim<<"\tARCOS Y COSTOS DEL ARBOL ABARCADOR DE COSTO MINIMO - PRIM\n\n";
    archivoPrim<<"\nVertice | Vertice | Costo \n";

    cout<<"\tARCOS Y COSTOS DEL ARBOL ABARCADOR DE COSTO MINIMO - PRIM\n\n";
    cout<<"\nVertice | Vertice | Costo \n";


    /* Encuentra el vértice VerMen en (Vertices - VerAux) tal que el
    ➥costo de ir de dicho vértice a uno de VerAux sea mínimo. */
    for (Ind1= 0; Ind1 < NumVer - 1; Ind1++)
    {
        MenCos= MCosto[1];
        VerMen= 1;
        for (Ind2= 2; Ind2 < NumVer; Ind2++)
            if (MCosto[Ind2] < MenCos)
            {
                MenCos= MCosto[Ind2];
                VerMen= Ind2;
            }
            cout<<"\n   "<<Vertices[VerMen]<<"\t     "<<Vertices[VerAux[VerMen]]<<"\t      "<<MatAdy[VerMen][VerAux[VerMen]];

            //Se va a ir guardando en el archivo
            archivoPrim<<"\n   "<<Vertices[VerMen]<<"\t     "<<Vertices[VerAux[VerMen]]<<"\t      "<<MatAdy[VerMen][VerAux[VerMen]];

            /* Se agrega el vértice VerMen a VerAux y se redefinen los
            ➥costos asociados. */
            MCosto[VerMen]= 1000;
            for (Ind2= 1; Ind2 < NumVer; Ind2++)
                if ((MatAdy[VerMen][Ind2] < MCosto[Ind2]) && MCosto[Ind2] < 1000)
                {
                    MCosto[Ind2]= MatAdy[VerMen][Ind2];
                    VerAux[Ind2]= VerMen;
                }
    }
    cout<<"\n\n";
}


/* Este método encuentra el árbol abarcador de costo mínimo de una
➥gráfica. */
template <class T>
void Grafica<T>::Kruskal()
{
    /* El arreglo auxiliar ArisCosto[][] almacena en cada renglón los
    ➥datos de una arista: vértices adyacentes y costo. El arreglo
    ➥Partic[] almacena particiones de Vertices. Inicialmente
    ➥Partic= {{1},{2},...,{NumVer}}. */
    int ArisCosto[2*MAX][3], Partic[MAX], Ind1, Ind2, Ver1, Ver2, TotAris, Menor, Mayor, Band;

    fstream archivoKruskal("Kruskal.txt", ios::out);//Creando archivo logico
    //Se va a ir guardando en el archivo
    archivoKruskal<<"LA RED MINIMA DE CARRETERAS REQUERIDAS PARA UNIR TODAS LAS CIUDADES ES:\n\n";        
    archivoKruskal<<"\t\tARBOL ABARCADOR DE COSTOS MINIMOS - KRUSKAL"<<endl<<endl;

    /* Inicializa Partic[]. */
    for (Ind1= 0; Ind1 < NumVer; Ind1++)
        Partic[Ind1]= Ind1;

    /* Inicializa ArisCosto[][]. */
    Ver1= 0; 
    Ver2= 0; 
    TotAris= 0;

    for (Ind1= 0; Ind1 < NumVer; Ind1++)
        for (Ind2= Ind1; Ind2 < NumVer; Ind2++)
            if (MatAdy[Ind1][Ind2] != 0 && MatAdy[Ind1][Ind2] != 999)
            {
                ArisCosto[Ver1][Ver2++]= Ind1;
                ArisCosto[Ver1][Ver2++]= Ind2;
                ArisCosto[Ver1++][Ver2]= MatAdy[Ind1][Ind2];
                Ver2= 0;
                TotAris++;
            }

    /* Ciclo en el cual se seleccionan aristas y se agregan los vértices
    ➥mientras existan vértices en Partic que se encuentren en distintas
    ➥particiones. */
    Band= 0;

    while (Band != 1)
    {
        /* Se selecciona la arista de menor costo. */
        Menor= 999;
        for (Ind1= 0; Ind1 < TotAris; Ind1++)
            if (ArisCosto[Ind1][2] < Menor)
            {
                Ver1= ArisCosto[Ind1][0]; 
                Ver2= ArisCosto[Ind1][1];
                Menor= ArisCosto[Ind1][2];
                Ind2= Ind1;
            }
        
        /* Se elimina la arista de menor costo de la matriz ArisCosto. */
        ArisCosto[Ind2][2]= 999;
        /* Se verifica que la arista (Ver1, Ver2) una dos vértices que
        ➥pertenecen a particiones diferentes. */


        if (Partic[Ver1] != Partic[Ver2])
        {
            cout<<"\nDel Vertice/Ciudad: "<<Vertices[Ver1]<<", Al Vertice/Ciudad: "
            <<Vertices[Ver2] <<" -> Costo/Distancia: "<<MatAdy[Ver1][Ver2]<<"\n\n";

            archivoKruskal<<"\nDel Vertice/Ciudad: "<<Vertices[Ver1]<<", Al Vertice/Ciudad: "
            <<Vertices[Ver2] <<" -> Costo/Distancia: "<<MatAdy[Ver1][Ver2]<<"\n\n";

            Mayor= Maximo(Partic[Ver1], Partic[Ver2]);
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
                if (Ind1 == Ver1 || Ind1 == Ver2 || Partic[Ind1] == Mayor)
                    Partic[Ind1]= Minimo(Partic[Ver1], Partic[Ver2]);
        }

        /* Ciclo para determinar si quedan vértices en particiones
        ➥diferentes. */
        Ind1= 0;

        while (Ind1 < NumVer && !Band)
        {
            if (Partic[Ind1] != 0)
                Band= 1;
        Ind1++;
        }

        /* Si existen particiones en Partic se debe seguir con el
        proceso. */
        Band= !Band;
    }
}


template <class T>
void Grafica<T>::respaldar_MatAdy()
{
    int Ind1, Ind2;

    fstream archivoMatAdy("matriz_adyacencia.txt", ios::out);

    if(!archivoMatAdy)
    {
        cerr<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        exit(0);
    }

    archivoMatAdy<<"\tMATRIZ DE ADYACENCIA O COSTOS: \n\n";
    for (Ind1= 0; Ind1 < NumVer; Ind1++)
    {
        archivoMatAdy<<Vertices[Ind1]<< ": ";
        for (Ind2= 0; Ind2 < NumVer; Ind2++)
            archivoMatAdy<<MatAdy[Ind1][Ind2] << "\t";
        archivoMatAdy<<endl;
    }
}
