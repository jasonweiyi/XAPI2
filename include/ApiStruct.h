#ifndef _API_STRUCT_H_
#define _API_STRUCT_H_

#include "ApiDataType.h"
#include "ApiEnum.h"

#pragma pack(push,1)

//////////////////////////////////////////////////////////////////////////
///字段分为两大类
/// 1.由API直接提供有效值
/// 2.计算出来的值，字段正好预留了此字段，可以直接填充，这样使用者就不需要定义自己的字段了

///查询持仓
struct ReqQryPositionField
{
	/////合约名称
	//InstrumentNameType	InstrumentName;
	/////唯一符号
	//SymbolType			Symbol;
	///合约代码
	InstrumentIDType	InstrumentID;
	///交易所代码
	ExchangeIDType		ExchangeID;
	///客户号，多账号支持使用
	IDChar32Type		ClientID;
	///账号，证券中用于股东代码
	IDChar32Type		AccountID;

}

///持仓
struct PositionField
{
	///持仓方向
	PositionSide	Side;
	///总持仓
	QtyType			Position;
	///今持仓
	QtyType			TdPosition;
	///昨持仓
	QtyType			YdPosition;
	///投保
	HedgeFlagType	HedgeFlag;
	///持仓成本，可用来计算持仓均价
	MoneyType		PositionCost;
	///交易日
	DateIntType		TradingDay;


	///合约名称
	InstrumentNameType	InstrumentName;
	///唯一符号
	SymbolType			Symbol;
	///合约代码
	InstrumentIDType	InstrumentID;
	///交易所代码
	ExchangeIDType		ExchangeID;
	///客户号，多账号支持使用
	IDChar32Type		ClientID;
	///账号，证券中用于股东代码
	IDChar32Type		AccountID;
};

///做市商双向报价
struct QuoteField
{
	QtyType			AskQty;
	PriceType		AskPrice;
	OpenCloseType	AskOpenClose;
	HedgeFlagType	AskHedgeFlag;

	QtyType			BidQty;
	PriceType		BidPrice;
	OpenCloseType	BidOpenClose;
	HedgeFlagType	BidHedgeFlag;

	OrderStatus		Status;
	ExecType		ExecType;

	

	///合约名称
	InstrumentNameType	InstrumentName;
	///唯一符号
	SymbolType			Symbol;
	///合约代码
	InstrumentIDType	InstrumentID;
	///交易所代码
	ExchangeIDType		ExchangeID;
	///客户号，多账号支持使用
	IDChar32Type		ClientID;
	///账号，证券中用于股东代码
	IDChar32Type		AccountID;

	///询价编号
	OrderIDType		QuoteReqID;

	OrderIDType		LocalID;
	OrderIDType		ID;
	OrderIDType		AskID;
	OrderIDType		BidID;
	OrderIDType		AskOrderID;
	OrderIDType		BidOrderID;

	///XAPI中错误代码，转成统一的值后，应用程序可以直接用它进行判断
	Int32Type		XErrorID;
	///原始错误代码
	Int32Type		RawErrorID;
	Char256Type		Text;
};


///查询委托
struct ReqQryOrderField
{
	/////合约名称
	//InstrumentNameType	InstrumentName;
	/////唯一符号
	//SymbolType			Symbol;
	///合约代码
	InstrumentIDType	InstrumentID;
	///交易所代码
	ExchangeIDType		ExchangeID;
	///客户号，多账号支持使用
	IDChar32Type		ClientID;
	///账号，证券中用于股东代码
	IDChar32Type		AccountID;

	///交易所生成的ID，此字段可供比较报单先后。不同交易所可能出现相同OrderID
	OrderIDType			OrderID;
	OrderIDType			RefID;

	///开始时间
	TimeIntType			TimeStart;
	///结束时间
	TimeIntType			TimeEnd;
}


///委托，委托回报都是同一结构体
struct OrderField
{
	///订单方向
	OrderSide		Side;
	///数量
	QtyType			Qty;
	///价格
	PriceType		Price;
	///开平
	OpenCloseType	OpenClose;
	///投机套保
	HedgeFlagType	HedgeFlag;
	///日期
	DateIntType		Date;
	///时间
	TimeIntType		Time;

	///唯一符号
	SymbolType			Symbol;
	///合约代码
	InstrumentIDType	InstrumentID;
	///交易所代码
	ExchangeIDType		ExchangeID;
	///合约名称，本来没有必要加的，但证券代码并不利于识别
	InstrumentNameType	InstrumentName;
	///客户号，多账号支持使用
	IDChar32Type		ClientID;
	///账号，证券中用于股东代码
	IDChar32Type		AccountID;

	///系统ID，其实是柜台ID，唯一
	OrderIDType			ID;

	//////////////////////////////////////////////////////////////////////////

	///交易所生成的ID，此字段可供比较报单先后。不同交易所可能出现相同OrderID
	OrderIDType			OrderID;
	///本地ID,只在委托时定位使用，收到回报后将使用ID
	OrderIDType			LocalID;

	///订单类型
	OrderType		Type;
	///止损价
	PriceType		StopPx;
	///有效时间类型
	TimeInForce		TimeInForce;
	///订单状态
	OrderStatus		Status;
	///执行类型
	ExecType		ExecType;
	///剩余数量
	QtyType			LeavesQty;
	///成交数量
	QtyType			CumQty;
	///成交均价
	PriceType		AvgPx;


	///XAPI中错误代码，转成统一的值后，应用程序可以直接用它进行判断
	Int32Type		XErrorID;
	///原始错误代码
	Int32Type		RawErrorID;
	///信息
	Char256Type		Text;

	///预留数字
	Int32Type		ReserveInt32;
	///预留字符串
	Char64Type		ReserveChar64;
};


///查询成交
struct ReqQryTradeField
{
	/////合约名称，本来没有必要加的，但证券代码并不利于识别
	//InstrumentNameType	InstrumentName;
	/////唯一符号
	//SymbolType			Symbol;
	///合约代码
	InstrumentIDType	InstrumentID;
	///交易所代码
	ExchangeIDType		ExchangeID;
	///客户号，多账号支持使用
	IDChar32Type		ClientID;
	///账号，证券中用于股东代码
	IDChar32Type		AccountID;

	///交易所生成的ID
	OrderIDType			TradeID;
	OrderIDType			RefID;

	///开始时间
	TimeIntType			TimeStart;
	///结束时间
	TimeIntType			TimeEnd;
}

///成交回报
struct TradeField
{
	///订单方向
	OrderSide		Side;
	///数量
	QtyType			Qty;
	///价格
	PriceType		Price;
	///开平
	OpenCloseType	OpenClose;
	///投机套保
	HedgeFlagType	HedgeFlag;
	///日期
	DateIntType		Date;
	///时间
	TimeIntType		Time;

	///合约名称
	InstrumentNameType	InstrumentName;
	///唯一符号
	SymbolType			Symbol;
	///合约代码
	InstrumentIDType	InstrumentID;
	///交易所代码
	ExchangeIDType		ExchangeID;
	///客户号，多账号支持使用
	IDChar32Type		ClientID;
	///账号，证券中用于股东代码
	IDChar32Type		AccountID;
	
	///所对应的Order的ID
	OrderIDType		ID;

	//////////////////////////////////////////////////////////////////////////

	///交易所产生的成交ID，可用于判断自成交
	TradeIDType		TradeID;
	///手续费
	MoneyType		Commission;

	///预留数字
	Int32Type		ReserveInt32;
	///预留字符串
	Char64Type		ReserveChar64;
};

///服务器信息
struct ServerInfoField
{
	///是否UDP
	BooleanType			IsUsingUdp;
	///是否多播
	BooleanType			IsMulticast;
	///订阅ID
	Int32Type			TopicId;
	///端口号
	Int32Type			Port;

	ResumeType			MarketDataTopicResumeType;
	ResumeType			PrivateTopicResumeType;
	ResumeType			PublicTopicResumeType;
	ResumeType			UserTopicResumeType;

	///经纪商ID
	BrokerIDType		BrokerID;
	///产品信息
	ProductInfoType		UserProductInfo;
	///授权码
	AuthCodeType		AuthCode;
	///地址信息
	AddressType			Address;
	///配置文件路径
	Char256Type			ConfigPath;
	///扩展信息
	Char128Type			ExtInfoChar128;
};


// 用户信息
struct UserInfoField
{
	///用户代码
	IDChar32Type	UserID;
	///密码
	PasswordType	Password;
	///扩展信息，通达信中用来做通讯密码
	Char64Type		ExtInfoChar64;
	///扩展信息，32位的数字
	Int32Type		ExtInfoInt32;
};


// 错误信息
struct ErrorField
{
	///XAPI中错误代码，转成统一的值后，应用程序可以直接用它进行判断
	Int32Type		XErrorID;
	///原始错误代码
	Int32Type		RawErrorID;
	// 消息来源
	Char64Type	Source;
	// 错误信息
	Char256Type	ErrorMsg;
};


/// 登录回报
/// 通过size1>0来判断是否有内容
/// 不管成功还是失败都可以输出，这个结构体中大部分内容是给人看的
struct RspUserLoginField
{
	///交易日
	DateIntType		TradingDay;
	///时间
	TimeIntType		LoginTime;
	///会话ID
	SessionIDType	SessionID;
	///XAPI中错误代码，转成统一的值后，应用程序可以直接用它进行判断
	Int32Type		XErrorID;
	///原始错误代码
	Int32Type		RawErrorID;
	///信息
	Char256Type		Text;
	///用户账号
	IDChar32Type	UserID;
	///股东账号
	IDChar32Type	Account;
	///投资者名称
	PartyNameType	InvestorName;
};


///深度行情N档
struct DepthMarketDataNField
{
	///占用总字节大小
	SizeType			Size;
	///交易日，用于给数据接收器划分到同一文件使用，基本没啥别的用处
	DateIntType			TradingDay;
	///日历日，实际日期
	DateIntType			ActionDay;
	///时间
	TimeIntType			UpdateTime;
	///毫秒
	TimeIntType			UpdateMillisec;

	///唯一符号
	SymbolType			Symbol;
	///合约代码
	InstrumentIDType	InstrumentID;
	///交易所代码
	ExchangeType		Exchange;

	///最新价
	PriceType			LastPrice;
	///数量
	LargeVolumeType		Volume;
	///成交金额
	MoneyType			Turnover;
	///持仓量
	LargeVolumeType		OpenInterest;
	///当日均价
	PriceType			AveragePrice;


	///今开盘
	PriceType			OpenPrice;
	///最高价
	PriceType			HighestPrice;
	///最低价
	PriceType			LowestPrice;
	///今收盘
	PriceType			ClosePrice;
	///本次结算价
	PriceType			SettlementPrice;

	///涨停板价
	PriceType			UpperLimitPrice;
	///跌停板价
	PriceType			LowerLimitPrice;
	///昨收盘
	PriceType			PreClosePrice;
	///上次结算价
	PriceType			PreSettlementPrice;
	///昨持仓量
	LargeVolumeType		PreOpenInterest;
	///交易阶段类型
	TradingPhaseType	TradingPhase;

	///买档个数
	SizeType			BidCount;
};

///深度行情中的某一档
struct DepthField
{
	///价格
	PriceType		Price;
	///量
	VolumeType		Size;
	///笔数
	VolumeType		Count;
};

///合约
struct InstrumentField
{
	///合约类型
	InstrumentType		Type;
	///合约数量乘数
	VolumeMultipleType	VolumeMultiple;
	///最小变动价位
	PriceType			PriceTick;
	///到期日
	DateIntType			ExpireDate;
	///执行价
	PriceType			StrikePrice;
	///期权类型
	PutCall				OptionsType;
	///合约名称
	InstrumentNameType	InstrumentName;
	///唯一符号
	SymbolType			Symbol;
	///合约代码
	InstrumentIDType	InstrumentID;
	///交易所代码
	ExchangeIDType		ExchangeID;
	///客户号，多账号支持使用
	IDChar32Type		ClientID;
	///账号，证券中用于股东代码
	IDChar32Type		Account;
	///合约在交易所的代码，个股期权交易代码会变化
	InstrumentIDType	ExchangeInstID;

	///产品代码
	InstrumentIDType	ProductID;

	///基础商品代码
	InstrumentIDType	UnderlyingInstrID;
	///合约生命周期状态
	InstLifePhaseType	InstLifePhase;
};

///账号资金
struct AccountField
{
	///客户号，多账号支持使用
	IDChar32Type		ClientID;
	///账号，证券中用于股东代码
	IDChar32Type		Account;
	///币种
	CurrencyCodeType	CurrencyCode;
	///上次结算准备金
	MoneyType			PreBalance;
	///当前保证金总额
	MoneyType			CurrMargin;
	///平仓盈亏
	MoneyType			CloseProfit;
	///持仓盈亏
	MoneyType			PositionProfit;
	///期货结算准备金
	MoneyType			Balance;
	///可用资金
	MoneyType			Available;

	///入金金额
	MoneyType			Deposit;
	///出金金额
	MoneyType			Withdraw;

	///冻结的过户费
	MoneyType			FrozenTransferFee;
	///冻结的印花税
	MoneyType			FrozenStampTax;
	///冻结的手续费
	MoneyType			FrozenCommission;
	///冻结的资金
	MoneyType			FrozenCash;

	///过户费
	MoneyType			TransferFee;
	///印花税
	MoneyType			StampTax;
	///手续费
	MoneyType			Commission;
	///资金差额
	MoneyType			CashIn;
};


///发给做市商的询价请求
struct QuoteRequestField
{
	///交易日
	DateIntType			TradingDay;
	///询价时间
	TimeIntType			QuoteTime;
	///唯一符号
	SymbolType			Symbol;
	///合约代码
	InstrumentIDType	InstrumentID;
	///交易所代码
	ExchangeIDType		ExchangeID;
	///询价编号
	OrderIDType			QuoteID;
};

///结算信息
struct SettlementInfoField
{
	///大小
	SizeType	Size;
	///交易日
	DateIntType	TradingDay;
	///消息正文，以下是消息正文
};

///投资者
struct InvestorField
{
	///用户代码
	IDChar32Type			InvestorID;

	BrokerIDType			BrokerID;

	///证件类型
	IdCardType				IdentifiedCardType;
	///证件号码
	IdentifiedCardNoType	IdentifiedCardNo;
	///投资者名称
	PartyNameType			InvestorName;
};











//////////////////////////////////////////////////////////////////////////
struct ConfigInfoField
{
	bool DirectOutput;
};

///Tick行情
struct TickField
{
	///交易所时间
	DateIntType			Date;
	TimeIntType			Time;
	TimeIntType			Millisecond;

	PriceType	LastPrice;
	///数量
	LargeVolumeType	Volume;
	///持仓量
	LargeVolumeType	OpenInterest;
	PriceType	BidPrice1;
	PriceType	AskPrice1;
	VolumeType	BidSize1;
	VolumeType	AskSize1;
};


///Bar行情
struct BarField
{
	///交易所时间
	DateIntType			Date;
	TimeIntType			Time;

	///开
	PriceType	Open;
	///高
	PriceType	High;
	///低
	PriceType	Low;
	///收
	PriceType	Close;
	///数量
	LargeVolumeType	Volume;
	///持仓量
	LargeVolumeType	OpenInterest;
	///成交金额
	MoneyType	Turnover;
};


///历史数据请求，这个需要后期再改，目前肯定无法使用
struct HistoricalDataRequestField
{
	int Date1;
	int Date2;
	int Time1;
	int Time2;

	DataObjetType DataType;
	BarType BarType;
	long BarSize;

	int RequestId;
	int CurrentDate;
	int lRequest;

	///唯一符号
	SymbolType			Symbol;
	///合约代码
	InstrumentIDType	InstrumentID;
	///交易所代码
	ExchangeIDType	ExchangeID;
};

#pragma pack(pop)//恢复对齐状态

#endif
