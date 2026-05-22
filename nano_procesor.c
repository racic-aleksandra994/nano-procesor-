#include <stdio.h>

int main() {
    int regA = 0;
    int regB = 0;
    int PC = 0;
    int trci = 1;

    // Novi kod: Učitaj 1, uradi NOT, odštampaj (mora da ispiše 0!)
    int memorija[] = {1, 1, 5, 4, 0}; 

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
