GCC vs. Clang optimising away new / delete
==========================================

Original reference: https://www.linkedin.com/feed/update/urn:li:activity:6538352164987858944

GCC will preserve calls to `new` under optimisation, allowing the override of
raw operator `new` and `delete`. Clang appears to remove the calls, even though
this changes the behaviour of the program.

The calls to new (even if they would have had side effects) can be elided in
C++14, because of the changes in N3664:
http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3664.html.

There is a bug in the GCC Bugzilla:
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=88118


Building / running
------------------

Compile with:

```
make
```

Execution output:

```
$ ./gcc-test
allocating 1 bytes
deallocating at 0x1b9ae70
allocating 1 bytes
deallocating at 0x1b9ae70

$ ./clang-test
<no output>
```
