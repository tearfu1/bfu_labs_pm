#include <iostream>

int main()
{
    char a_str[1000];
    char b_str[1000];
    int ans[1001] = {0};
    std::cin >> a_str >> b_str;

    if (strlen(b_str) > strlen(a_str)) {
        char temp[1000];
        strcpy_s(temp, a_str);
        strcpy_s(a_str, b_str);
        strcpy_s(b_str, temp);
    }

    for (int i = 0; i < strlen(a_str); ++i) {
        int k = 1000 - i - 1;
        ans[k + 1] += a_str[strlen(a_str)-i-1] - 48;
        if (i < strlen(b_str)) {
            int summ = ans[k + 1] + (b_str[strlen(b_str) - i - 1] - 48);
            if (summ > 9) {
                ans[k + 1] = summ % 10;
                ans[k] += 1;
            }
            else {
                ans[k + 1] = summ % 10;
            }
        }
    }

   /* for (int i = 0; i < strlen(a_str); ++i) {
        int k = 1000 - i - 1;
        ans[k + 1] += a_str[strlen(a_str) - i - 1] - 48;
        if (i < strlen(b_str)) {
            int summ = ans[k + 1] + (b_str[strlen(b_str) - i - 1] - 48);
            if (summ > 9) {
                ans[k + 1] = summ % 10;
                ans[k] += 1;
            }
            else {
                ans[k + 1] = summ % 10;
            }
        }*/

    bool flag = true;
    for (int i = 0; i < 1001; ++i) {
        if (ans[i]==0 && flag) {
            continue;
        }
        else {
            flag = false;
            std::cout << ans[i];
        }
    }
    return 0;
}

