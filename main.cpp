#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t read_number(FILE* file) {
    uint32_t number;
    fread(&number, sizeof(uint32_t), 1, file);
    return ntohl(number);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: ./add-nbo <file1> <file2>\n");
        return 1;
    }

    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    uint32_t number1 = read_number(file1);
    uint32_t number2 = read_number(file2);

    fclose(file1);
    fclose(file2);

    uint32_t sum = number1 + number2;
    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", number1, number1, number2, number2, sum, sum);

    return 0;
}

