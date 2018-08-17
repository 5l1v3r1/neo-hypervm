<p align="center">
  <img src="http://res.cloudinary.com/vidsy/image/upload/v1503160820/CoZ_Icon_DARKBLUE_200x178px_oq0gxm.png" width="125px">
</p>

<h1 align="center">neo-hypervm</h1>

<p align="center">      
  <a href="https://travis-ci.org/CityOfZion/neo-hypervm">
    <img src="https://api.travis-ci.org/CityOfZion/neo-hypervm.svg?branch=master">
  </a>
  <a href="https://github.com/CityOfZion/neo-hypervm/blob/master/LICENSE.md">
    <img src="https://img.shields.io/badge/license-MIT-blue.svg">
  </a>
</p>

<p align="center">
    Virtual Machine for the <a href="https://neo.org">NEO</a> blockchain written in <b>C++</b>
</p>

# Overview

**neo-hypervm** aims to be a virtual machine in C++ 100% compatible with the NEO standard.

# Projects

* NeoVM - C++ Native Virtual Machine
* NeoVM.Interop - Interoperability for C# calls
* NeoVM.Interop.Tests - Unit Tests

# Installation

### Visual studio (Windows Users)
For debugging the native source make sure to append the following line in `**/Properties/launchSettings.json` 

```
"nativeDebugging": true
```
Copy binaries or create a symbolic link, also you can set `NEO_HYPERVM_PATH`environment variable with the path of the native library

```
cd C:\neo-hypervm\tests\NeoVM.Interop.Tests\bin\Debug\netcoreapp2.0
mkdir Windows
cd Windows
mkdir x86
mkdir x64

cd x86
cmd /c mklink NeoVM.dll C:\neo-hypervm\src\NeoVM\Win32\Debug\NeoVM.dll
cd ../x64
cmd /c mklink NeoVM.dll C:\neo-hypervm\src\NeoVM\x64\Debug\NeoVM.dll
```

### Benchmarks

You could get the sources [here](https://github.com/CityOfZion/neo-hypervm/tree/development/tests/Neo.HyperVM.Benchmarks/Benchmarks)

``` ini

BenchmarkDotNet=v0.11.0, OS=Windows 10.0.17134.228 (1803/April2018Update/Redstone4)
Intel Core i7-6700HQ CPU 2.60GHz (Skylake), 1 CPU, 8 logical and 4 physical cores
Frequency=2531248 Hz, Resolution=395.0620 ns, Timer=TSC
.NET Core SDK=2.1.400
  [Host]     : .NET Core 2.1.2 (CoreCLR 4.6.26628.05, CoreFX 4.6.26629.01), 64bit RyuJIT
  Job-CAVTBJ : .NET Core 2.1.2 (CoreCLR 4.6.26628.05, CoreFX 4.6.26629.01), 64bit RyuJIT

InvocationCount=1000  IterationCount=10  LaunchCount=3  
UnrollFactor=1  WarmupCount=2  

```

|            Method |   Test |      Mean |     Error |    StdDev |       Min |       Max |    Median | Rank |
|------------------ |------- |----------:|----------:|----------:|----------:|----------:|----------:|-----:|
|           HyperVM | NOP*1K |  17.66 us | 1.187 us | 3.501 us |  12.27 us |  27.68 us |  17.57 us |    1 |
|             NeoVM | NOP*1K |  80.59 us | 1.530 us | 1.761 us |  77.33 us |  83.66 us |  80.52 us |    2 |
| ApplicationEngine | NOP*1K | 163.17 us | 2.280 us | 1.904 us | 159.16 us | 167.62 us | 162.97 us |    3 |
| | | | | | | | | |
|           HyperVM | (PUSH1+DROP)*1K |  89.62 us | 1.791 us |  3.699 us |  82.67 us |  99.01 us |  89.50 us |    1 |
|             NeoVM | (PUSH1+DROP)*1K | 229.47 us | 4.925 us | 14.521 us | 200.12 us | 267.15 us | 228.49 us |    2 |
| ApplicationEngine | (PUSH1+DROP)*1K | 454.61 us | 9.058 us | 10.431 us | 436.31 us | 473.51 us | 456.10 us |    3 |

*NeoVM and ApplicationEngine come form from NEO 3.0 binaries*

### Other
There is a `Makefile` in the root of the project. To build the `VM` source:

```
make
```

For cross compiling x86 from x64

`apt-get install g++-multilib`

# Contributing

Feel free to contribute to this project after reading the
[contributing guidelines](https://github.com/CityOfZion/neo-go/blob/master/CONTRIBUTING.md).

Before starting to work on a certain topic, create an new issue first,
describing the feauture/topic you are going to implement and remember to use [development](https://github.com/CityOfZion/neo-hypervm/tree/development) branch.

# License

- Open-source [MIT](https://github.com/CityOfZion/neo-hypervm/blob/master/LICENCE.md)
