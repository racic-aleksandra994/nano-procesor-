#include <stdio.h>

int main() {
    int regA = 0;
    int regB = 0;
    int PC = 0;
    int trci = 1;

    // Učitaj 5, učitaj 3, oduzmi ih (6), odštampaj (4), ugasi se (0)
    int memorija[] = {1, 5, 2, 3, 6, 4, 0}; 

    printf("--- NANO PROCESOR POKRENUT ---\n");

    while (trci) {
        int instrukcija = memorija[PC]; 

        switch (instrukcija) { 
            case 1: 
                PC++;
                regA = memorija[PC];
                printf("[PC: %d] LOAD A %d\n", PC-1, regA);
                break;
            case 2: 
                PC++;
                regB = memorija[PC];
                printf("[PC: %d] LOAD B %d\n", PC-1, regB);
                break;
            case 3: 
                printf("[PC: %d] ADD (%d + %d)\n", PC, regA, regB);
                regA = regA + regB;
                break;
            case 4: 
                printf("[PC: %d] PRINT -> IZLAZ = %d\n", PC, regA);
                break;
            case 5: 
                printf("[PC: %d] NOT za Registar A (Prethodno: %d)\n", PC, regA);
                regA = !regA; 
                break;
            case 6: 
                printf("[PC: %d] SUB (%d - %d)\n", PC, regA, regB);
                regA = regA - regB;
                break;
            case 0: 
                printf("[PC: %d] HALT\n", PC);
                trci = 0;
                break;
        }
        PC++; 
    }
    printf("--- PROCESOR JE USPEŠNO STAO ---\n");
    return 0;
}
