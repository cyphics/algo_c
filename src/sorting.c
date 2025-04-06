
/*void foo(int i) {*/
/*    printf("%d", i);*/
/*}*/
/**/
/*void test_IndexOfSorted(void) {*/
/*    int foo[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};*/
/*    int size = sizeof(foo) / sizeof(foo[0]);*/
/*    CU_ASSERT(IndexOfSorted(foo, 69, size) == 3);*/
/*    CU_ASSERT(IndexOfSorted(foo, 1336, size) == -1);*/
/*    CU_ASSERT(IndexOfSorted(foo, 69420, size) == 10);*/
/*    CU_ASSERT(IndexOfSorted(foo, 69421, size) == -1);*/
/*    CU_ASSERT(IndexOfSorted(foo, 1, size) == 0);*/
/*    CU_ASSERT(IndexOfSorted(foo, 0, size) == -1);*/
/*}*/
/**/
/*void test_sorting(void) {*/
/*    /*int array[] = {1, 2, 4, 5, 7};
/*    /*CU_ASSERT(Sorting.BinarySearch(5, array, 5));
/*}*/
/**/
/*void test_IndexOf(void) {*/
/*    char target1 = 'c';*/
/*    char target2 = 'z';*/
/*    char array[] = {'a', 'b', 'c', 'd', 'e'};*/
/*    int index1 =*/
/*            IndexOf(&target1, &array, sizeof(array), sizeof(target1));*/
/*    int index2 =*/
/*            IndexOf(&target2, &array, sizeof(array), sizeof(target2));*/
/*    CU_ASSERT(index1 == 2);*/
/*    CU_ASSERT(index2 == -1);*/
/**/
/*    double double1 = 0.1;*/
/*    double double2 = 0.2;*/
/*    double array2[] = {0.2, 3.98, 38924.9, 0.0};*/
/**/
/*    index1 = IndexOf(&double1, &array2, sizeof(array2), sizeof(double1));*/
/*    index2 = IndexOf(&double2, &array2, sizeof(array2), sizeof(double2));*/
/*    CU_ASSERT(index1 == -1);*/
/*    CU_ASSERT(index2 == 0);*/
/*}*/
/**/
/*void test_BubbleSort(void) {*/
/*    int arr[] = {10, 9, 3, 7, 4, 69, 420, 42, 41};*/
/*    int sorted[] = {3, 4, 7, 9, 10, 41, 42, 69, 420};*/
/**/
/*    int size = sizeof(arr) / sizeof(arr[0]);*/
/*    BubbleSort(arr, size);*/
/**/
/*    CU_ASSERT(CompareArrays(arr, sorted, sizeof(arr)));*/
/*}*/
