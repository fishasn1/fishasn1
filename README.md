# fishasn1
fishasn1 (fish•asn1) is an open source ASN.1 compiler written in C with minimal third party libraries dependences. The goal is to make an accurate, secure and easy-to-use ASN.1 compiler from scratch.

## How to test
#### Requirements
1. This project uses `meson` to build and test, so please install the latest version of `meson` on your system before you can run test.
2. C compiler that supports C99 standards (GCC, Clang etc)

#### Run Test
1. Configure meson the first time, run this command (NOTE: Only run this command once)
```
meson setup build
```

2. Run these commands to run test
```
cd build
meson test
```

## Donate
Making an ASN.1 compiler takes a lot of time and affort, and this project is in its initial stage, If you would like to see a new ASN.1 compiler develop, please consider [donate](https://www.patreon.com/tommyjeff) to support the development.

## License
fishasn1 source code are made available under the terms of the GNU Affero General Public License ([GNU AGPL v3.0](https://www.gnu.org/licenses/agpl-3.0.html)).
