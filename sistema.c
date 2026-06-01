#include <stdio.h>

int main() {
    int num_estudiantes;
    int num_asignaturas = 3;

    printf("--- SISTEMA DE CALIFICACIONES ---\n");
    printf("Ingrese el numero de estudiantes: ");
    scanf("%d", &num_estudiantes);

    float notas[num_estudiantes][num_asignaturas];

    for(int i = 0; i < num_estudiantes; i++) {
        printf("\n-- Estudiante %d --\n", i + 1);
        for(int j = 0; j < num_asignaturas; j++) {
            do {
                printf("Ingrese la calificacion para la Asignatura %d (0 a 10): ", j + 1);
                scanf("%f", &notas[i][j]);
                if(notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Error: La calificacion debe estar entre 0 y 10. Intente de nuevo.\n");
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

    float max_estudiante[num_estudiantes], min_estudiante[num_estudiantes];
    float max_asignatura[3] = {0,0,0}, min_asignatura[3] = {10,10,10};

    for(int i = 0; i < num_estudiantes; i++) {
        max_estudiante[i] = notas[i][0];
        min_estudiante[i] = notas[i][0];
        for(int j = 0; j < num_asignaturas; j++) {
            if(notas[i][j] > max_estudiante[i]) max_estudiante[i] = notas[i][j];
            if(notas[i][j] < min_estudiante[i]) min_estudiante[i] = notas[i][j];
            
            if(notas[i][j] > max_asignatura[j]) max_asignatura[j] = notas[i][j];
            if(notas[i][j] < min_asignatura[j]) min_asignatura[j] = notas[i][j];
        }
    }

    int aprobados[3] = {0, 0, 0};
    int reprobados[3] = {0, 0, 0};

    for(int i = 0; i < num_estudiantes; i++) {
        for(int j = 0; j < num_asignaturas; j++) {
            if(notas[i][j] >= 6.0) {
                aprobados[j]++;
            } else {
                reprobados[j]++;
            }
        }
    }

    printf("\n================ RESULTADOS POR ESTUDIANTE ================\n");
    for(int i = 0; i < num_estudiantes; i++) {
        printf("Estudiante %d -> Promedio: %.2f | Max: %.2f | Min: %.2f\n", 
               i + 1, prom_estudiante[i], max_estudiante[i], min_estudiante[i]);
    }

    printf("\n================ RESULTADOS POR ASIGNATURA ================\n");
    for(int j = 0; j < num_asignaturas; j++) {
        printf("Asignatura %d:\n", j + 1);
        printf("  - Promedio: %.2f\n", prom_asignatura[j]);
        printf("  - Calificacion Maxima: %.2f\n", max_asignatura[j]);
        printf("  - Calificacion Minima: %.2f\n", min_asignatura[j]);
        printf("  - Estudiantes Aprobados: %d\n", aprobados[j]);
        printf("  - Estudiantes Reprobados: %d\n", reprobados[j]);
    }

    return 0;
}