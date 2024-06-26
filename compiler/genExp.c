#include "rlib.h"

void E();
void T();
void F();

// === EBNF Grammar =====
// E=T ([+-] T)*           // *代表產生0次以上
// T=F ([*/] F)?           // ?代表0或1次
// F=[0-9] | (E)           // 產生0~9或(E)

int main(int argc, char * argv[]) {
    timeSeed();
    // E();
    int i;
    // 產生10次E()
    for (i=0; i<10; i++) {
        E();
        printf("\n");
    }
}

// E=T ([+-] T)*
void E() {
    T();
    while (randInt(10) < 3) {
       printf("%c", randChar("+-"));
       T();
    }
}

// T=F ([*/] F)?
void T() {
    F();
    if (randInt(10) < 7) {
        printf("%c", randChar("*/"));
        F();
    }
}

// F=[0-9] | (E)
void F() {
    if (randInt(10) < 8) {
        printf("%c", randChar("0123456789"));
    } else {
        printf("(");
        E();
        printf(")");
    }
}
