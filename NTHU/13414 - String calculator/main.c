#include <stdio.h>
#include <string.h>

char a[100005];
char b[100005];

int check_num(char *str) {
    int num = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') num *= 10, num += (str[i] - '0');
        else return -1;
    }
    return num;
}

int cstring_cmp(const void *a, const void *b) 
{ 
    char **ia = (char **)(&a);
    char **ib = (char **)(&b);
    return strcmp(*ia, *ib);
} 

int re_cstring_cmp(const void *a, const void *b) 
{ 
    char **ia = (char **)(&a);
    char **ib = (char **)(&b);
    if (strlen(*ia) != strlen(*ib)) return strlen(*ia) < strlen(*ib);
    else return strcmp(*ia, *ib);
} 

int main() {
    int n, len_a, len_b;
    char operation, c;
    scanf("%d", &n);
    
    for (int _ = 0; _ < n; _++) {
        scanf(" %s %c %s", a, &operation, b);

        len_a = strlen(a);
        len_b = strlen(b);

        if (operation == '+') {
            char result[25] = {'\0'};
            strcpy(result, a);
            strcpy(&result[len_a], b);
            printf("%s\n", result);
        } else if (operation == '-') {
            int flag = 0;
            for (int i = 0; i < len_a && len_a - i >= len_b; i++) {
                if (strncmp(&a[i], b, len_b) == 0) {
                    flag = 1;
                    for (int j = 0; j < i; j++) printf("%c", a[j]);
                    for (int j = i + len_b; j < len_a; j++) printf("%c", a[j]);
                    break;
                }
            }
            if (!flag) printf("error\n");
            else printf("\n");
        } else if (operation == '*') {
            int time = check_num(b);
            if (time == -1) printf("error");
            else for (int j = 0; j < time; j++) printf("%s", a);
            printf("\n");
        } else if (operation == '/') {
            int num = 0;
            for (int i = 0; i < len_a && len_a - i >= len_b; i++) {
                if (strncmp(&a[i], b, len_b) == 0) num++;
            }
            printf("%d\n", num);
        } else if (operation == '&') {
            char tmp[1024][20] = {'\0'};
            int num = 0;
            for (int i = 1; i <= len_a; i++) {
                for (int j = 0; j < len_a && j + i <= len_a; j++) {
                    for (int k = 0; k < len_b && k + i <= len_b; k++) {
                        if (strncmp(&a[j], &b[k], i) == 0) {
                            strncpy(tmp[num], &a[j], i);
                            num++;
                        }
                    }
                }
            }
            qsort(tmp, num, sizeof(tmp[0]), cstring_cmp);
            printf("%s", tmp[0]);
            for (int i = 1; i < num; i++) {
                if (strcmp(tmp[i], tmp[i-1]) != 0) {
                    printf(" %s", tmp[i]);
                }
            }
            printf("\n");
        } else if (operation == '@') {
            int start = 0;
            int end = 0;
            char tmp[1024][20] = {'\0'};
            int num = 0;
            if (len_a > len_b) continue;
            while (end < len_b) {
                while (b[end] != '_' && end != len_b) end++;
                for (int i = start; i < end && end - i >= len_a; i++) {
                    if (strncmp(&b[i], a, len_a) == 0) {
                        strncpy(tmp[num++], &b[start], end - start);
                        break;
                    }
                }
                start = end + 1;
                end = start;
            }
            qsort(tmp, num, sizeof(tmp[0]), re_cstring_cmp);
            for (int i = 0; i < num; i++) {
                if (i != 0) printf(" ");
                printf("%s", tmp[i]);
            }
            printf("\n");
        }
    }

    return 0;
}