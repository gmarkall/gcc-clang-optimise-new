GCC vs. Clang optimising away new / delete
==========================================

Original reference: https://www.linkedin.com/feed/update/urn:li:activity:6538352164987858944

Current hypothesis:It appears that GCC will preserve calls to new under
optimisation, allowing the override of raw operator new and delete. Clang
appears to remove the calls, even though this changes the behaviour of the
program.

No judgment is made about the correctness of either approach as yet :-)


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
