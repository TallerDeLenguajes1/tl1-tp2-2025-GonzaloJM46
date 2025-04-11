#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct compu {
 int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
 int anio; // Año de fabricación (valor entre 2015 y 2024)
 int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
 char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
};

void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);

int main(){
    int aleatorio, total = 5;
    struct compu pcs[total];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
        "Pentium"};

    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        pcs[i].velocidad = (rand() % (3 - 1 + 1)) + 1;
        pcs[i].anio = (rand() % (2024 - 2015 + 1)) + 2015;
        pcs[i].cantidad_nucleos = (rand() % (8 - 1 + 1)) + 1;
        aleatorio = (rand() % (5 - 0 + 1)) + 0;
        pcs[i].tipo_cpu = tipos[aleatorio];
    }

    listarPCs(pcs, total);
    mostrarMasVieja(pcs, total);
    return 0;
}

void listarPCs(struct compu pcs[], int cantidad){
    for(int i = 0; i < cantidad; i++){
        printf("\nPC %d:", i + 1);
        printf("\n%d", pcs[i].velocidad);
        printf("\n%d", pcs[i].anio);
        printf("\n%d", pcs[i].cantidad_nucleos);
        printf("\n%s", pcs[i].tipo_cpu);
        printf("\n");
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad){
    int anio_viejo = 2026, i, mas_vieja;
    for(int i = 0; i < cantidad; i++){
        if(anio_viejo > pcs[i].anio){
            anio_viejo = pcs[i].anio;
            mas_vieja = i;
        }
    }
    printf("\nlas caracteristicas de la pc mas antigua son:");
    printf("\n%d", pcs[mas_vieja].velocidad);
    printf("\n%d", pcs[mas_vieja].anio);
    printf("\n%d", pcs[mas_vieja].cantidad_nucleos);
    printf("\n%s", pcs[mas_vieja].tipo_cpu);
}



