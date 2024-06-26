CC := gcc
CFLAGS = -std=c99 -O0   // -O0是不做最佳化
TARGET = compiler       // 產生的執行檔的名字

all: $(TARGET)

$(TARGET): lexer.c compiler.c main.c
	$(CC) $(CFLAGS) $^ -o $@    // S^代表 lexer.c compiler.c main.c，$@代表$(TARGET)

clean:
	rm -f *.o *.exe
