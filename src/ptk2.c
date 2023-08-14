#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MaxEl 10001
#define Undefined (int)INFINITY

typedef int keytype;
typedef int valuetype;
typedef int address;

typedef struct {
    keytype Key;
    valuetype Value;
} eltype;

typedef struct {
    eltype Elements[MaxEl];
} HashMap;

void CreateEmpty(HashMap *M) {
    int i;
    for (i = 0; i < MaxEl; i++) {
        M->Elements[i].Key = Undefined;
        M->Elements[i].Value = Undefined;
    }
}

address Hash(keytype K) {
    return (K > 0 ? (K % MaxEl) : -1*(K % MaxEl));
}

valuetype Value(HashMap M, keytype k) {
    int i = 0;
    bool found = false;
    while (i < MaxEl && !found) {
        if (M.Elements[i].Key == k) {
            found = true;
        } else {
            i++;
        }
    }

    if (found) {
        return M.Elements[i].Value;
    } else {
        return Undefined;
    }
}

bool isKeyIn(HashMap M, keytype k) {
    int i = 0;
    bool found = false;
    while (i < MaxEl && !found) {
        if (M.Elements[i].Key == k) {
            found = true;
        } else {
            i++;
        }
    }
    return found;
}

void Insert(HashMap *M, keytype k, valuetype v) {
    int i = 0;
    bool found = false;
    int idxHash = Hash(k);
    while (i < MaxEl && !found) {
        if (M->Elements[i].Key == k) {
            found = true;
        } else {
            i++;
        }
    }

    if (!found) {
        while (M->Elements[idxHash].Key != Undefined) {
            idxHash = (idxHash + 1) % MaxEl;
        }

        M->Elements[idxHash].Key = k;
        M->Elements[idxHash].Value = v;
    }
}

void twoSum(int* arr, int target, HashMap* M, int n, int* idx1, int* idx2) {
    for (int i = 0; i < n; i++) {
        int diff = target - arr[i];
        if (isKeyIn(*M, diff)) {
            // printf("%d\n", Value(*M, diff));
            *idx1 = Value(*M, diff);
            *idx2 = i;
            // printf("%d\n", i);
            return;
        }
        else {
            Insert(M, arr[i], i);
        }
    }
}

int main() {
    HashMap M;
    CreateEmpty(&M);

    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int target;
    scanf("%d", &target);

    int idx1, idx2;
    twoSum(arr, target, &M, n, &idx1, &idx2);
    printf("%d\n", idx1);
    printf("%d\n", idx2);
    return 0;
}