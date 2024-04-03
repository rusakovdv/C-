#include <stdio.h>
#include <tuple>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

void printAllFile(FILE *in) {
    fseek(in, 0, SEEK_SET);
    while (!feof(in)) {
        putchar(getc(in));
    }
}

tuple<int, int> countPrintedAndEmptySymbols(FILE *in) {
    fseek(in, 0, SEEK_SET);
    int symbols = 0;
    int emptySymbols = 0;
    while (!feof(in)) {
        char chr = getc(in);
        if (chr <= 32)
            emptySymbols++;
        else
            symbols++;
    }

    return {symbols, emptySymbols};
}

void search(FILE *in, char* query) {
    fseek(in, 0, SEEK_SET);
    char *buffer = (char*) malloc(1024);
    FILE *out = fopen("../5-search.txt", "w");

    if(out == nullptr) {
        printf("Не удалось открыть выходной файл");
        return;
    }

    char* line;
    int i = 0;
    while((line = fgets(buffer, 1024,in))) {
        i++;
        if (strstr(line, query) != nullptr) {
            char* bufferLocal = (char*) malloc(20 + strlen(line));
            sprintf(bufferLocal, "LINE %d: %s", i, line);

            fputs(bufferLocal, out);
            free(bufferLocal);
        }
    }

    fclose(out);
    free(buffer);
}

void movePageNumbers() {
    char *line = (char*) malloc(1024);

    ifstream ifs("../test.txt");
    if (!ifs) {
        printf("Не удалось открыть файл test.txt");
        return;
    }

    ofstream ofs("../test-moved.txt");
    if (!ofs) {
        printf("Не удалось открыть файл test-moved.txt");
        return;
    }

    bool is_next_line_with_number = false;
    char *pageNumStr = new char[1024];
    while (ifs && ofs) {
        ifs.getline(line, 1024);
        if (strstr(line, "\f") != nullptr) {
            is_next_line_with_number = true;
        } else {
            if (is_next_line_with_number) {
                strcpy(pageNumStr, line);
            } else {
                if (strlen(pageNumStr) > 0) {
                    string str = string(pageNumStr);
                    replace(str.begin(), str.end(), '-', ' ');
                    ofs << str << endl << '\f';
                }
                ofs << line << endl;
                pageNumStr[0] = '\0';
            }
            is_next_line_with_number = false;
        }
    }
}

int main() {
    char name[50];
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);
    FILE *in = fopen(name, "r");
    if (in == nullptr) {
        printf("Файл %s не открыт", name);
        return 0;
    }

    printAllFile(in);

    auto symbolsCount = countPrintedAndEmptySymbols(in);
    printf("\n\nВ файле %d \"непустых\" символов и %d \"пустых\"\n", get<0>(symbolsCount), get<1>(symbolsCount));

    search(in, "ipsum");

    movePageNumbers();

    fclose(in);

    return 0;
}