﻿using NeoVM.Interop.Enums;
using NeoVM.Interop.Interfaces;
using System;
using System.Linq;

namespace NeoVM.Interop.Types.StackItems
{
    public class ByteArrayStackItem : IStackItem<byte[]>, IEquatable<ByteArrayStackItem>
    {
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="engine">Engine</param>
        /// <param name="data">Data</param>
        internal ByteArrayStackItem(ExecutionEngine engine, byte[] data) : base(engine, data, EStackItemType.ByteArray)
        {
            CreateNativeItem();
        }
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="engine">Engine</param>
        /// <param name="handle">Handle</param>
        /// <param name="value">Raw value</param>
        internal ByteArrayStackItem(ExecutionEngine engine, IntPtr handle, byte[] value) : base(engine, value, EStackItemType.ByteArray, handle) { }

        public bool Equals(ByteArrayStackItem other)
        {
            return other != null && other.Value.SequenceEqual(Value);
        }

        public override bool Equals(IStackItem other)
        {
            if (other is ByteArrayStackItem b)
                return b.Value.SequenceEqual(Value);

            return false;
        }

        protected override byte[] GetNativeByteArray()
        {
            return Value;
        }
    }
}