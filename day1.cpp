#include <stdio.h>
#include <string.h>

int solve_captcha(const char *s) {
    int length = strlen(s), i, sum = 0;

    for (i = 0; i < length - 1; ++i) {
        if (s[i] == s[i + 1]) {
            sum += s[i] - '0';
        }
    }

    if (s[length - 1] == s[0]) {
        sum += s[length - 1] - '0';
    }

    return sum;
}

int solve_captcha_follow_up(const char *s) {
    int length = strlen(s), half_length = length / 2, i, sum = 0;

    for (i = 0; i < length; ++i) {
        if (s[i] == s[(i + half_length) % length]) {
            sum += s[i] - '0';
        }
    }

    return sum;
}

int main() {
    printf("%d\n", solve_captcha("1122"));
    printf("%d\n", solve_captcha("1111"));
    printf("%d\n", solve_captcha("1234"));
    printf("%d\n", solve_captcha("91212129"));

    printf("%d\n", solve_captcha_follow_up("1212"));
    printf("%d\n", solve_captcha_follow_up("1221"));
    printf("%d\n", solve_captcha_follow_up("123425"));
    printf("%d\n", solve_captcha_follow_up("123123"));
    printf("%d\n", solve_captcha_follow_up("12131415"));

    char s[3000];
    freopen("inputs/day1.in", "r", stdin);
    scanf("%s", s);
    printf("%d\n", solve_captcha(s));
    printf("%d\n", solve_captcha_follow_up(s));
    return 0;
}