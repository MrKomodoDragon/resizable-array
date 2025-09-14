#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *arr;
    int used;
    int size;
} List;

List init_list(int size) {
    List list;
    list.arr = malloc(size * sizeof(int));
    list.size = size;
    list.used = 0;
    return list;
}

void insert_element(List* list, int element) {
    if (list->used >= list->size) {
        printf("List is too big, resizing\n");
        list->arr = realloc(list->arr, list->size * 2 * sizeof(int));
        list->size  *= 2;
        list->arr[list->used++] = element;
        return;
    }
   list->arr[list->used++] = element; 
}

void print_list(List* list) {
    printf("List contents: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d, ", list->arr[i]);
    }
}

int main() {
    List list = init_list(5);
    for (int i = 1; i < 10; i++) {
        insert_element(&list, i);
    }
    print_list(&list);
}