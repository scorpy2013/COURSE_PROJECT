//
// Created by alexscorpy on 25.11.2020.
//

#ifndef CURSE_CODE_GOST_ANALYSIS_H
#define CURSE_CODE_GOST_ANALYSIS_H

void GOST_Analysis() {
    uint8_t encrypted[BUFF_SIZE], decrypted[BUFF_SIZE];
    uint8_t key256b[32] = "this_is_a_pas_for_GOST_28147_89";

    uint8_t buffer[BUFF_SIZE], ch;
    size_t position;
    while ((ch = getchar()) != '\n' && position < BUFF_SIZE - 1)
        buffer[position++] = ch;
    buffer[position] = '\0';

    printf("Open message:\n");
    GOST_print_array(buffer, position);
    printf("%s\n", buffer);
    putchar('\n');

    position = GOST_28147(encrypted, 'E', key256b, buffer, position);
    printf("Encrypted message:\n");
    GOST_print_array(encrypted, position);
    printf("%s\n", encrypted);
    putchar('\n');

    printf("Decrypted message:\n");
    position = GOST_28147(decrypted, 'D', key256b, encrypted, position);
    GOST_print_array(decrypted, position);
    printf("%s\n", decrypted);
    putchar('\n');
}

#endif //CURSE_CODE_GOST_ANALYSIS_H
