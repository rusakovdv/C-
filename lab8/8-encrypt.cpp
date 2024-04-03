#include <string>
#include <cstring>
#include <fstream>

using namespace std;


int main(int argc, char **argv) {
    char* inFileName = argv[1];
    char* outFileName = argv[2];
    char* password = argv[3];

    if (argc < 4) {
        printf("Параметров недостаточно");
    }
    else {
        fstream fout(outFileName, ios::app);
        fstream fin(inFileName, ios::in);
        char ch;
        int i = 0;
        while (fin) {
            ch = fin.get();
            ch = ch ^ password[i];
            fout.put(ch);
            i = (i + 1) % strlen(password);
        }
    }

    return 0;
}