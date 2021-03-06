﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;


namespace QuantBox.XAPI.Interface
{
    public interface IXApi
    {
        DelegateOnConnectionStatus OnConnectionStatus { get; set; }
        DelegateOnRtnError OnRtnError { get; set; }
        DelegateOnLog OnLog { get; set; }


        void Connect();
        void Disconnect();

        void ReqQuery(QueryType type, ref ReqQueryField query);

        ApiType GetApiType { get;}
        string GetApiName { get;}
        string GetApiVersion { get;}
    }

    public interface IXMarketData
    {
        DelegateOnRtnDepthMarketData OnRtnDepthMarketData{ get; set; }
        void Subscribe(string szInstrument, string szExchange);
        void Unsubscribe(string szInstrument, string szExchange);
    }

    public interface IXInstrument
    {
        DelegateOnRspQryInstrument OnRspQryInstrument { get; set; }
    }

    public interface IXQuery
    {
        DelegateOnRspQryTradingAccount OnRspQryTradingAccount { get; set; }
        DelegateOnRspQryInvestorPosition OnRspQryInvestorPosition { get; set; }
        DelegateOnRspQrySettlementInfo OnRspQrySettlementInfo { get; set; }

        DelegateOnRspQryOrder OnRspQryOrder { get; set; }
        DelegateOnRspQryTrade OnRspQryTrade { get; set; }
        DelegateOnRspQryQuote OnRspQryQuote { get; set; }
    }

    public interface IXTrade
    {
        DelegateOnRtnOrder OnRtnOrder { get; set; }
        DelegateOnRtnTrade OnRtnTrade { get; set; }
        DelegateOnRtnQuote OnRtnQuote { get; set; }


        void SendOrder(ref OrderField[] orders, out string[] OrderRefs);
        void CancelOrder(string[] szId,out string[] errs);
        void SendQuote(ref QuoteField quote,out string AskRef,out string BidRef);
        void CancelQuote(string szId,out string err);
    }

    public interface IXHistoricalData
    {
        DelegateOnRspQryHistoricalTicks OnRspQryHistoricalTicks { get; set; }
        DelegateOnRspQryHistoricalBars OnRspQryHistoricalBars { get; set; }

        //int ReqQryHistoricalTicks(ref HistoricalDataRequestField request);
        //int ReqQryHistoricalBars(ref HistoricalDataRequestField request);
    }
}
