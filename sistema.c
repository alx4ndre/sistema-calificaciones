#include <stdio.h>

int main() {
    int num_estudiantes;
    int num_asignaturas = 3;

    printf("--- GESTOR DE CALIFICACIONES ---\n");
    printf("Ingrese la cantidad de estudiantes en el grupo: ");
    scanf("%d", &num_estudiantes);

    
    float notas[num_estudiantes][num_asignaturas];

 
    for(int i = 0; i < num_estudiantes; i++) {
        printf("\n>> Estudiante %d <<\n", i + 1);
        for(int j = 0; j < num_asignaturas; j++) {
            do {
                printf("Ingrese la calificacion para la Asignatura %d (0 a 10): ", j + 1);
                scanf("%f", &notas[i][j]);
                if(notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Error: La calificacion es invalida. Intente de nuevo.\n");
                }
            } while(notas[i][j] < 0 || notas[i][j] > 10);
        }
    }   
    
    float prom_estudiante[num_estudiantes];
    float prom_asignatura[3] = {0, 0, 0};

    for(int i = 0; i < num_estudiantes; i++) {
        float suma_estudiante = 0;
        for(int j = 0; j < num_asignaturas; j++) {
            suma_estudiante += notas[i][j];
            prom_asignatura[j] += notas[i][j];
        }
        prom_estudiante[i] = suma_estudiante / num_asignaturas;
    }

    for(int j = 0; j < num_asignaturas; j++) {
        prom_asignatura[j] = prom_asignatura[j] / num_estudiantes;
    }