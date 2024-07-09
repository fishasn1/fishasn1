# fishasn1
fishasn1 (fish•asn1) is an open source ASN.1 compiler written in C with minimal third party libraries dependences. The goal is to make an accurate and easy-to-use ASN.1 compiler from scratch.

## How to test
#### Requirements
1. This project uses `meson` to build and test, so please install the latest version of `meson` on your system before you can run test.
2. C compiler that supports C99 standards (GCC, Clang etc)

#### Run Test
0. Configure meson the first time, run this command (NOTE: Only run this command once)
```
meson setup build
```

1. Run these commands to run test
```
cd build
meson test
```
