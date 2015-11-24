using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace QuantBox.XAPI
{
    public enum QueryType : byte
    {
        ReqQryInstrument = 32,
        ReqQryTradingAccount,
        ReqQryInvestorPosition,

        ReqQryOrder,
        ReqQryTrade,
        ReqQryQuote,

        ReqQryInstrumentCommissionRate,
        ReqQryInstrumentMarginRate,
        ReqQrySettlementInfo,
        ReqQryInvestor,

        ReqQryHistoricalTicks,
        ReqQryHistoricalBars,
    }
}
