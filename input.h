#ifndef INPUT_H
#define INPUT_H

typedef enum numberType {INT = 0, UINT = 1, FLOAT = 2} numberType;
void readNumber(numberType type, void *num, char *message);

#endif // INPUT_H
