# Sasuke_CodeWar
Cuộc thi lập trình sasuke_codewar trên codelearn.io <br />
Link cuộc thi : https://codelearn.io/fights/detail/2279399

# Thể lệ : 
## 1. Cách nộp bài trên hệ thống

Hệ thống sẽ chấm điểm dựa trên giá trị trả về của hàm cho trước, đầu vào và đầu ra chính là các tham số và giá trị trả về của hàm. Do đó, bạn chỉ cần hoàn thiện hàm cho trước, không cần phải thực hiện nhập xuất dữ liệu. Ví dụ nếu bài tập yêu cầu viết hàm trả về tổng 2 số nguyên thì bạn có thể làm như sau:

### Với ngôn ngữ C++, Java, C#:
```
int add(int a, int b){
    return a + b;
}
```

### Với ngôn ngữ Javascript:
```
function add(a, b){
    return a + b;
}
```

### Với ngôn ngữ Python:
```
def add(a, b):
    return a + b
```

###Với ngôn ngữ Go:
```
func add(a int, b int) int {
    return a + b;
}
```
Thông tin về các trình dịch trên hệ thống

    java: jdk8.0.24
    python2: Python 2.7.16
    python3: Python 3.7.78
    C++: gcc version 8.3.0
    C#: Mono JIT compiler version 6.8.0.96
    Javascript: Node.js v13.8.0
    Go: go1.13.8

## 2. Các thư viện đã được hệ thống import sẵn
Ngôn ngữ lập trình C:

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <math.h>
#include <ctype.h>
```

Ngôn ngữ lập trình C++:

```
#include <iostream>
#include <string>
#include <vector>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <cstdarg>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <sstream>
#include <numeric>
#include <iterator>
#include <utility>
#include <stack>
#include <functional>
#include <deque>
#include <complex>
#include <bitset>
#include <list>
#include <array>
#include <regex>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <typeinfo>
#include <bits/stdc++.h>
```

Ngôn ngữ lập trình C#:

```
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Runtime.Serialization;
using System.Text;
using System.Linq;
using System.Xml.Linq;
using System.Xml;
using System.Data;
using System.Web;
using System.Web.Helpers;
using System.Text.RegularExpressions;
```

Ngôn ngữ lập trình Go:

```
Go:
import (
    "os"
    "fmt"
    "time"
    "io/ioutil"
    "encoding/json"
    "math"
    "strconv"
    "strings"
    "sort"
)
```

Ngôn ngữ lập trình Java:

```
import java.io.*;
import java.util.*;
import java.math.*;
import java.util.regex.*;
import java.util.stream.*;
import java.text.*;
import java.util.function.*;
```

Ngôn ngữ lập trình Python:

```
import decimal
import math
import string
import re
import random
import functools
```

## 3. Hướng dẫn sử dụng kiểu dữ liệu mảng và ma trận đối với ngôn ngữ lập trình C
Các kiểu dữ liệu có tên arr_##name, matrix_##name là các kiểu dữ liệu đã được định nghĩa sẵn và có cấu trúc giống như sau:
```
typedef struct arr_bool {
	int* arr;
	int size;
} arr_bool;

typedef struct matrix_bool {
	arr_bool* arr;
	int size;
} matrix_bool;

typedef struct arr_char{
    char* arr;
    int size;
} arr_char;

typedef struct arr_string {
	char** arr;
	int size;
} arr_string;

typedef struct arr_int {
	int* arr;
	int size;
} arr_int;

typedef struct arr_long {
	long long* arr;
	int size;
} arr_long;

typedef struct arr_double {
	double* arr;
	int size;
} arr_double;

typedef struct matrix_char {
	arr_char* arr;
	int size;
} matrix_char;

typedef struct matrix_string {
	arr_string* arr;
	int size;
} matrix_string;

typedef struct matrix_int {
	arr_int* arr;
	int size;
} matrix_int;

typedef struct matrix_long {
	arr_long* arr;
	int size;
} matrix_long;

typedef struct matrix_double {
	arr_double* arr;
	int size;
} matrix_double;
```

Ví dụ nếu bài tập yêu cầu bạn tính tổng các số trong mảng arr thì bạn có thể làm như sau:
```
int sumOfArray(arr_int arr){
    int sum = 0;
    for(int i = 0; i < arr.size; ++i){
        sum += arr.arr[i];
    }
    return sum;
}
```

Ví dụ khác, nếu bài tập yêu cầu viết hàm trả về mảng các xâu có độ dài lớn hơn 3 trong mảng cho trước thì bạn có thể làm giống như sau:
```
arr_string getArray(arr_string input) {
    int size = 0;
    arr_string result;
    result.arr = (char**)malloc(input.size * sizeof(char*));
    for (int i = 0; i < input.size; i++) {
        if (strlen(input.arr[i]) >= 3) {
            result.arr[size++] = input.arr[i];
        }
    }
    result.size = size;
    return result;
}
```
Lưu ý: hệ thống sẽ chấm điểm dựa trên thuộc tính size và các phần tử có chỉ số từ 0 -> size - 1 trong thuộc tính arr. <br />

Tương tự, nếu bài tập yêu cầu viết hàm trả về ma trận các số từ 1 tới 9 thì bạn có thể làm giống như sau:
```
matrix_int getMatrix() {
    matrix_int matrix;
    matrix.arr = (arr_int*)malloc(3 * sizeof(arr_int));
    for (int i = 0; i < 3; ++i) {
        matrix.arr[i].size = 3;
        matrix.arr[i].arr = (int*)malloc(3 * sizeof(int));
        for (int j = 0; j < 3; ++j) {
            matrix.arr[i].arr[j] = i * 3 + j + 1;
        }
    }
    return matrix;
}
```

## 4. Có bao nhiêu kiểm thử ẩn trong một bài tập?

- Số kiểm thử ẩn sẽ được quy ước theo công thức sau: <br />
(kết quả được làm tròn xuống nếu số kiểm thử là số lẻ)

## 5. Quy tắc chấm điểm ở mỗi bài tập là như thế nào?
- Trường hợp số câu hỏi sai là 1 thì người học sẽ được 1/2 số điểm tối đa của bài tập đó
- Trường hợp số câu hỏi sai là 2 thì người học sẽ được 1/4 số điểm tối đa của bài tập đó
- Trường hợp số câu hỏi sai lớn hơn 2 thì người học sẽ không được điểm nào ở bài tập đó

## 6. Tại sao tôi không có nhìn thấy tab Lịch sử nộp và tab Bình luận?

Bạn không nhìn thấy thông tin này do chưa đăng nhập hệ thống, ở góc bên phải cuối màn hình sẽ hiển nút đăng nhập để bạn thực hiện thao tác đăng nhập hệ thống

## 7. Tại sao tôi không thấy hiển thị có nút nộp bài?
Không hiển thị nút nộp bài có thể bạn đang ở 1 trong những trường hợp sau: <br />
- Chưa thực hiện đăng nhập tài khoản vào hệ thống <br />
- Chưa đăng kí thi vào trong cuộc thi <br />
- Cuộc thi đang mở đã hết thời gian thi <br /> 
- Bài tập bạn đang mở đã sử dụng hết lượt nộp bài ( mỗi bài sẽ có khoảng 10 lượt nộp bài)

## 8. Số đi kèm theo nút "Nộp bài" có ý nghĩa gì? 

Đây là tổng số lươt nộp bài của bài tập đó, số lần được tự trừ đi sau mỗi lần người dùng nộp bài

## 9. Giới hạn ký tự có ý nghĩa gì?

Là giới hạn số kí tự dùng để giải quyết bài toán không tính kí tự khoảng trắng và xuống dòng

## 10. Giới hạn thời gian chạy một testcase là gì?

Mỗi ngôn ngữ sẽ có một giới hạn thời gian chạy khác nhau 

Giới hạn thời gian chạy testcase là thời gian tối đa để đoạn mã nguồn mà người dùng nộp lên hệ thống dùng để xử lý 1 testcase. Trường hợp thời gian chạy thực tế lớn hơn giới hạn thời gian của test case đó thì testcase đó sẽ bị báo Fail

## 11. Tôi muốn xem lại bài mình đã nộp thì như thế nào?

Bạn mở phần "Lịch sử nộp" của mình để có thể xem lại toàn bộ những lượt nộp bài của mình và chọn từng lượt nộp sẽ hiển thị lại đoạn mã nguồn bạn đã ghi nhận
