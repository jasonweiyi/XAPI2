# XAPI2设计文档

## 设计中需要解决的问题

####1. 在`ApiStruct.h`中的结构体的命名

在[`ApiStruct.h`](https://github.com/QuantBox/XAPI2/blob/master/include/ApiStruct.h)中很多结构体的名称以Field结尾，比如`PositionField`。但是在C++中，结构体中的元素才叫做field，结构体名称不叫Field。

建议修改：把结构体的名称中的Field后缀去掉，比如`PositionField`更名为`Position`。这样从C++的概念上才正确，其次代码因为结构体的名称变短会更易读。

####2. [CXApi类](https://github.com/QuantBox/XAPI2/blob/master/include/XApiCpp.h)中的回调函数中的int size1参数
在这些回调函数中，有个参数`int size1`，似乎和业务不相关。

解决方案：（来自伍侃）回调函数的参数风格按照CTP回调函数的风格来修改：在回调函数中，参数为先是数据相关的，然后是一个错误，然后是一个`isLast`。

####3. 枚举类型`ExchangeType`
在[`ApiEnum.h`](https://github.com/QuantBox/XAPI2/blob/master/include/ApiEnum.h)中定义了`ExchangeType`枚举类型。但是在[CXApiCpp.h](https://github.com/QuantBox/XAPI2/blob/master/include/XApiCpp.h)中，有些地方使用的是`ExchangeType`，比如回调函数`OnFilterSubscribe`。但是有些地方使用的是以字符串指定的交易所，比如函数`Subscribe`，`Unsubscribe`，`ReqQryInstrument`和`ReqQryInvestorPosition`。从减少混淆的角度出发，应该统一使用`ExchangeType`来引用交易所。

建议修改：所有需要交易所的地方都使用ExchangeType。

####4. 结构体DepthMarketDataNField的名称
在[`ApiStruct.h`](https://github.com/QuantBox/XAPI2/blob/master/include/ApiStruct.h)中定义了结构体`DepthMarketDataNField`。在XAPI2中并没有找到`DepthMarketDataField`，是否可以把其中的N去掉，并且去掉Field后缀（见问题1）。

建议修改：把`DepthMarketNDataField`重命名为`DepthMarketData`。

####5. 是否需要增加一个OnRspQryOrder的回调函数
现在有一个OnRtnOrder，是否需要增加一个OnRspQryOrder？
问题：OnRspQryOrder是响应哪个request的回调函数？OnRspQryOrder在什么情况下会被调用？
同样，是否要增加一个OnRspQryTrade的回调函数？

####6. 对于股票的只有查询，没有主动回报的功能的API，可能查询委托功能会交给用户
这是什么意思？

####7.撤单部分的修改
需要吴侃指明为什么要修改，现在的问题是什么，解决方案是什么。

####8. OrderField.ID在什么范围内能保证ID的唯一性
需要吴侃进一步说明。


