GCC vs. Clang optimising away new / delete
==========================================

Original reference: https://www.linkedin.com/feed/update/urn:li:activity:6538352164987858944

GCC will preserve calls to global `new` under optimisation, allowing the
override of raw operator `new` and `delete`. Clang removes the calls, even
though this changes the behaviour of the program. Both are correct, but GCC is
missing an optimisation opportunity.

Both GCC and Clang preserve calls to class-specific `new` and `delete`.
Preserving these calls is required for correctness.

The calls to global `new` (even if they would have had side effects) can be
elided in C++14, because of the changes in N3664. The calls to class-specific
`new` and `delete` are excluded from the changes in N3664:
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3664.html.

There is a bug in the GCC Bugzilla for the missed removal of global `new` and
`delete`:
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=88118


Building / running
------------------

Compile with:

```
make
```

Execution output demonstrating that GCC does not remove the calls to global new
and delete, but Clang does:

```
$ ./gcc-test
allocating 1 bytes
deallocating at 0x1b9ae70
allocating 1 bytes
deallocating at 0x1b9ae70

$ ./clang-test
<no output>
```

Execution output demonstrating that neither removes calls to class-specific new
and delete:

```
$ ./gcc-test2
New  A
allocating 4 bytes
Delete A
deallocating at 0x847e70

$ ./clang-test2
New  A
allocating 4 bytes
Delete A
deallocating at 0x1122e70
```
