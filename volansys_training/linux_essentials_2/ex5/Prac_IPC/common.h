#define MAX_LINE 80
#define MY_MQ_ID 111

typedef struct {
    long type;
    float fval;
    unsigned int uival;
    char strval[MAX_LINE]; 
} MY_TYPE_T;