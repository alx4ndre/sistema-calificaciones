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