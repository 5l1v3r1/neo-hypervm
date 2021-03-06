﻿using System;
using System.Numerics;

namespace NeoSharp.VM.Interop.Tests.Extra
{
    /// <summary>
    /// Contains two BigInteger values
    /// </summary>
    public struct BigIntegerPair : IEquatable<BigIntegerPair>
    {
        public readonly BigInteger A, B;

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="a">A</param>
        /// <param name="b">B</param>
        public BigIntegerPair(BigInteger a, BigInteger b)
        {
            A = a;
            B = b;
        }

        /// <summary>
        /// Check Equals
        /// </summary>
        /// <param name="other">Other value</param>
        /// <returns>Return true if equals</returns>
        public bool Equals(BigIntegerPair other)
        {
            return other.A == A && other.B == B;
        }

        public override int GetHashCode()
        {
            return 0;
        }

        /// <summary>
        /// Create new inverted pair
        /// </summary>
        public BigIntegerPair Invert()
        {
            return new BigIntegerPair(B, A);
        }
    }
}