#include <stdio.h>

int main() {
    int num_estudiantes;
    int num_asignaturas = 3;

    printf("--- GESTOR DE CALIFICACIONES ---\n");
    printf("Ingrese la cantidad de estudiantes en el grupo: ");
    scanf("%d", &num_estudiantes);

    
    float notas[num_estudiantes][num_asignaturas];