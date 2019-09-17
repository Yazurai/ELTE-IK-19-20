void readNumber(numberType type, void *num, char *message) {
    bool inputSuccess = false;
    while(!inputSuccess) {
        while(getchar() != '\n') {
            continue;
        }

        printf("%s", message);

        int check;
        if(type == INT) {
            check = scanf(" %d", num);
        } else {
            check = scanf(" %f", num);
        }

        if(check != 0) {
            inputSuccess = (type != UINT) || (num >= 0);
        } else {
            printf("Wrong format!\n");
        }
    }
}
