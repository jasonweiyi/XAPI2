using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace QuantBox.XAPI
{
    public enum ResponeType : byte
    {
        OnConnectionStatus = 64,
        OnRtnError,
        OnLog,

        OnRtnDepthMarketData,
        OnRspQryInstrument,
        OnRspQryTradingAccount,
        OnRspQryInvestorPosition,
        OnRspQrySettlementInfo,
        OnRtnOrder,
        OnRtnTrade,

        OnRtnQuote,
        OnRtnQuoteRequest,

        OnRspQryHistoricalTicks,
        OnRspQryHistoricalBars,
        OnRspQryInvestor,

        OnFilterSubscribe,
    }
}
