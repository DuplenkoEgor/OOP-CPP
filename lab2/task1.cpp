#include <iostream>

struct SimvolStr {
    char str[256];
};

SimvolStr operator-(SimvolStr S1, const SimvolStr& S2) {
    int len2 = 0;
    SimvolStr S3;

    while (S2.str[len2] != '\0') {
        len2++;
    }

    for (int i = 0; i < len2; i++) {
        char letter_to_remove = S2.str[i];

        int pos = -1;
        for (int j = 0; S1.str[j] != '\0'; j++) {
            if (S1.str[j] == letter_to_remove) {
                pos = j;
                break;
            }
        }

        if (pos != -1) {
            int k = pos;
            while (S1.str[k] != '\0') {
                S1.str[k] = S1.str[k + 1];
                k++;
            }
        }
    }

    int k = 0;
    for (; S1.str[k] != '\0'; k++) {
        S3.str[k] = S1.str[k];
    }
    S3.str[k] = '\0';

    return S3;
}

int main() {
    SimvolStr s1 = {"aabkkk"};
    SimvolStr s2 = {"kbka"};

    SimvolStr res = s1 - s2;

    std::cout << res.str << '\n';
    return 0;
}