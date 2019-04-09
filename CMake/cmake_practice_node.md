# Cmake Practice Node

## 常用命令
`PROJECT` 指令的语法是:   
```cmake
PROJECT(projectname [CXX] [C] [Java])
```
可以用这个指令定义工程名称,并可指定工程支持的语言,支持的语言列表是可以忽略的,默认情况表示支持所有语言. cmake 系统预定义了 `PROJECT_BINARY_DIR` 和 `PROJECT_SOURCE_DIR` 变量.    

`SET` 指令可以用来显式的定义变量, 指令的语法是:    
```cmake
SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])
```

`MESSAGE` 指令用于向终端输出用户定义的信息, 语法是:    
```cmake
MESSAGE([SEND_ERROR | STATUS | FATAL_ERROR] "message to display"
...)
```
- `SEND_ERROR` : 产生错误,生成过程被跳过    
- `SATUS` : 输出前缀为 -- 的信息    
- `FATAL_ERROR` : 立即终止所有 cmake 过程    

```cmake
ADD_EXECUTABLE(executable_file_name ${SRC_LIST})
```
定义了这个工程会生成一个文件名为 `executable_file_name` 的可执行文件,相关的源文件是 `SRC_LIST` 中定义的源文件列表.    

在本例我们使用了`${}`来引用变量,这是 cmake 的变量应用方式,但是,有一些例外,比如在 `IF` 控制语句,变量是直接使用变量名引用,而不需要`${}`。如果使用了`${}`去应用变量,其实 `IF` 会去判断名为`${}`所代表的值的变量,那当然是不存在的了.    

## 基本语法

1. 变量使用`${}`方式取值,但是在 `IF` 控制语句中是直接使用变量名

2. 指令(参数 1 参数 2...) 

    参数使用括弧括起,参数之间使用空格或分号分开。    
    以上面的 `ADD_EXECUTABLE` 指令为例,如果存在另外一个 func.c 源文件,就要写成:   
    ```cmake 
    ADD_EXECUTABLE(hello main.c func.c)
    ```
    或者    
    ```cmake
    ADD_EXECUTABLE(hello main.c; func.c)
    ```

3. 指令是大小写无关的,参数和变量是大小写相关的。但, 推荐全部使用大写指令。    

    上面的 `MESSAGE` 指令我们已经用到了这条规则:    
    ```cmake
    MESSAGE(STATUS “This is BINARY dir” ${HELLO_BINARY_DIR})
    ```
    也可以写成:
    ```cmake
    MESSAGE(STATUS “This is BINARY dir ${HELLO_BINARY_DIR}”)
    ```
    这里需要特别解释的是作为工程名的 `HELLO` 和生成的可执行文件 `hello` 是没有任何关系的。    

    hello 定义了可执行文件的文件名,你完全可以写成:    
    ```cmake
    ADD_EXECUTABLE(t1 main.c)
    ```
    编译后会生成一个 t1 可执行文件。
