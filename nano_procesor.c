#include <stdio.h>

int main() {
    // 1. Komponente procesora (Registri i Program Counter)
    int regA = 0;
    int regB = 0;
    int PC = 0; // Program Counter - pokazuje gde smo u memoriji
    int trci = 1;

    // 2. Memorija sa tvojim programom iz sveske
    // Kodovi: 1 = LOAD_A, 2 = LOAD_B, 3 = ADD, 4 = PRINT, 0 = HALT
    int memorija[] = {1, 5, 2, 3, 3, 4, 0}; 

    printf("--- NANO PROCESOR POKRENUT ---\n");

    // 3. Ciklus izvršavanja (Fetch - Decode - Execute)
    while (trci) {
        int instrukcija = memorija[PC]; // FETCH (Učitaj instrukciju)

        switch (instrukcija) { // DECODE & EXECUTE (Dekodiraj i Izvrši)
            case 1: // LOAD A <vrednost>
                PC++; // Pomeri PC da uzme podatak koji sledi nakon instrukcije
                regA = memorija[PC];
                printf("[PC: %d] LOAD A %d (RegA = %d)\n", PC-1, regA, regA);
                break;
                
            case 2: // LOAD B <vrednost>
                PC++; // Pomeri PC da uzme podatak koji sledi nakon instrukcije
                regB = memorija[PC];
                printf("[PC: %d] LOAD B %d (RegB = %d)\n", PC-1, regB, regB);
                break;
                
            case 3: // ADD
                printf("[PC: %d] ADD (%d + %d)\n", PC, regA, regB);
                regA = regA + regB; // Rezultat ide nazad u regA
                break;
                
            case 4: // PRINT
                printf("[PC: %d] PRINT -> IZLAZ = %d\n", PC, regA);
                break;
                
            case 0: // HALT
                printf("[PC: %d] HALT (Kraj programa)\n", PC);
                trci = 0;
                break;
                
            default:
                printf("Nepoznata instrukcija na poziciji %d!\n", PC);
                trci = 0;
                break;
        }
        PC++; // Pomeri na sledeću instrukciju
    }

    printf("--- PROCESOR JE USPEŠNO STAO ---\n");
    return 0;
}
