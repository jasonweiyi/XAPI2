# XAPI2设计文档

## 设计中考虑的问题 ##

####1. 在`ApiStruct.h`中的结构体的命名####

在[`ApiStruct.h`](https://github.com/QuantBox/XAPI2/blob/master/include/ApiStruct.h)中很多结构体的名称以Field结尾，比如`PositionField`。但是在C++中，结构体中的元素才叫做field，结构体名称不叫Field。
建议修改：把结构体的名称中的Field后缀去掉，比如`PositionField`更名为`Position`。这样从C++的概念上才正确，其次代码因为结构体的名称变短会更易读。
