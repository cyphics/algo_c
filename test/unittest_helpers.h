#ifndef UNITTEST_HELPERS_H
#define UNITTEST_HELPERS_H

#define test_equal_str(str1, str2)  CU_ASSERT(strcmp(str1, str2) == 0);
#define test_equal_data(data1, data2, size) CU_ASSERT(memcmp(data1, data2, size) == 0);

#endif
