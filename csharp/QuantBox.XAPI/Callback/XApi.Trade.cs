using QuantBox.XAPI.Interface;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;


namespace QuantBox.XAPI.Callback
{
    public partial class XApi : IXTrade
    {
        public DelegateOnRtnOrder OnRtnOrder
        {
            get { return OnRtnOrder_; }
            set { OnRtnOrder_ = value; }
        }
        public DelegateOnRtnTrade OnRtnTrade
        {
            get { return OnRtnTrade_; }
            set { OnRtnTrade_ = value; }
        }
        public DelegateOnRtnQuote OnRtnQuote
        {
            get { return OnRtnQuote_; }
            set { OnRtnQuote_ = value; }
        }

        private DelegateOnRtnOrder OnRtnOrder_;
        private DelegateOnRtnTrade OnRtnTrade_;
        private DelegateOnRtnQuote OnRtnQuote_;

        public void SendOrder(ref OrderField[] orders,out string[] OrderRefs)
        {
            int OrderField_size = Marshal.SizeOf(typeof(OrderField));
            int OrderIDType_size = Marshal.SizeOf(typeof(OrderIDType));
            
            IntPtr OrderField_Ptr = Marshal.AllocHGlobal(OrderField_size * orders.Length);
            IntPtr OrderIDType_Ptr = Marshal.AllocHGlobal(OrderIDType_size * orders.Length);

            // 将结构体写成内存块
            for (int i = 0; i < orders.Length;++i)
            {
                Marshal.StructureToPtr(orders[i], new IntPtr(OrderField_Ptr.ToInt64() + i * OrderField_size), false);
            }

            IntPtr ptr = proxy.XRequest((byte)RequestType.ReqOrderInsert, Handle, IntPtr.Zero,
                0, 0,
                OrderField_Ptr, orders.Length, OrderIDType_Ptr, 0, IntPtr.Zero, 0);

            OrderRefs = new string[orders.Length];

            for(int i = 0;i<orders.Length;++i)
            {
                // 这里定义一个ID占64字节
                OrderIDType output = (OrderIDType)Marshal.PtrToStructure(new IntPtr(OrderIDType_Ptr.ToInt64() + i * OrderIDType_size), typeof(OrderIDType));

                OrderRefs[i] = output.ID;
            }

            Marshal.FreeHGlobal(OrderField_Ptr);
            Marshal.FreeHGlobal(OrderIDType_Ptr);
        }

        public void CancelOrder(string[] szId,out string[] errs)
        {
            int OrderIDType_size = Marshal.SizeOf(typeof(OrderIDType));

            IntPtr Input_Ptr = Marshal.AllocHGlobal(OrderIDType_size * szId.Length);
            IntPtr Output_Ptr = Marshal.AllocHGlobal(OrderIDType_size * szId.Length);

            // 将结构体写成内存块
            for (int i = 0; i < szId.Length; ++i)
            {
                OrderIDType _szId = new OrderIDType();
                _szId.ID = szId[i];
                Marshal.StructureToPtr(_szId, new IntPtr(Input_Ptr.ToInt64() + i * OrderIDType_size), false);
            }

            IntPtr ptr = proxy.XRequest((byte)RequestType.ReqOrderAction, Handle, IntPtr.Zero, 0, 0,
                Input_Ptr, szId.Length, Output_Ptr, 0, IntPtr.Zero, 0);

            errs = new string[szId.Length];

            for (int i = 0; i < szId.Length; ++i)
            {
                // 这里定义一个ID占64字节
                OrderIDType output = (OrderIDType)Marshal.PtrToStructure(new IntPtr(Output_Ptr.ToInt64() + i * OrderIDType_size), typeof(OrderIDType));

                errs[i] = output.ID;
            }

            Marshal.FreeHGlobal(Input_Ptr);
            Marshal.FreeHGlobal(Output_Ptr);
        }

        public void SendQuote(ref QuoteField quote,out string AskRef,out string BidRef)
        {
            int QuoteField_size = Marshal.SizeOf(typeof(QuoteField));
            int OrderIDType_size = Marshal.SizeOf(typeof(OrderIDType));

            IntPtr QuoteField_Ptr = Marshal.AllocHGlobal(QuoteField_size);
            IntPtr AskRef_Ptr = Marshal.AllocHGlobal(OrderIDType_size);
            IntPtr BidRef_Ptr = Marshal.AllocHGlobal(OrderIDType_size);

            // 将结构体写成内存块
            for (int i = 0; i < 1; ++i)
            {
                Marshal.StructureToPtr(quote, new IntPtr(QuoteField_Ptr.ToInt64() + i * QuoteField_size), false);
            }

            IntPtr ptr = proxy.XRequest((byte)RequestType.ReqQuoteInsert, Handle, IntPtr.Zero,
                0, 0,
                QuoteField_Ptr, 1, AskRef_Ptr, 0, BidRef_Ptr, 0);

            AskRef = string.Empty;
            BidRef = string.Empty;

            for (int i = 0; i < 1; ++i)
            {
                // 这里定义一个ID占64字节
                OrderIDType output = (OrderIDType)Marshal.PtrToStructure(new IntPtr(AskRef_Ptr.ToInt64() + i * OrderIDType_size), typeof(OrderIDType));
                AskRef = output.ID;
                output = (OrderIDType)Marshal.PtrToStructure(new IntPtr(BidRef_Ptr.ToInt64() + i * OrderIDType_size), typeof(OrderIDType));
                BidRef = output.ID;
            }

            Marshal.FreeHGlobal(QuoteField_Ptr);
            Marshal.FreeHGlobal(AskRef_Ptr);
            Marshal.FreeHGlobal(BidRef_Ptr);
        }

        public void CancelQuote(string szId,out string err)
        {
            IntPtr szIdPtr = Marshal.StringToHGlobalAnsi(szId);
            int OrderIDType_size = Marshal.SizeOf(typeof(OrderIDType));
            IntPtr OrderIDType_Ptr = Marshal.AllocHGlobal(OrderIDType_size);

            IntPtr ptr = proxy.XRequest((byte)RequestType.ReqQuoteAction, Handle, IntPtr.Zero, 0, 0,
                szIdPtr, 0, OrderIDType_Ptr, 0, IntPtr.Zero, 0);

            err = string.Empty;

            for (int i = 0; i < 1; ++i)
            {
                // 这里定义一个ID占64字节
                OrderIDType output = (OrderIDType)Marshal.PtrToStructure(new IntPtr(OrderIDType_Ptr.ToInt64() + i * OrderIDType_size), typeof(OrderIDType));

                err = output.ID;
            }

            Marshal.FreeHGlobal(szIdPtr);
            Marshal.FreeHGlobal(OrderIDType_Ptr);
        }

        private void _OnRtnOrder(IntPtr ptr1, int size1)
        {
            // 求快，不加
            if (OnRtnOrder_ == null)
                return;

            OrderField obj = (OrderField)Marshal.PtrToStructure(ptr1, typeof(OrderField));

            OnRtnOrder_(this, ref obj);
        }

        private void _OnRtnTrade(IntPtr ptr1, int size1)
        {
            // 求快，不加
            if (OnRtnTrade_ == null)
                return;

            TradeField obj = (TradeField)Marshal.PtrToStructure(ptr1, typeof(TradeField));

            OnRtnTrade_(this, ref obj);
        }

        private void _OnRtnQuote(IntPtr ptr1, int size1)
        {
            if (OnRtnQuote_ == null)
                return;

            QuoteField obj = (QuoteField)Marshal.PtrToStructure(ptr1, typeof(QuoteField));

            OnRtnQuote_(this, ref obj);
        }
    }
}
