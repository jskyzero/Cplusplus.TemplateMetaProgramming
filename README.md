# Cplusplus.TemplateMetaProgramming.Effective
`jskyzero` `2019/01/13`


## Overview

This project aims to compare the template metaprogramming's effectiveness with origin methods in cplusplus, in fact this could do in a more fair way, but anyhow, this is only a example.

+ compile time class generation
  + programming at compile time, see the factorial example.
+ compile time code optimization
  + optimization at compule time, see the vector example.
+ static polymorphism
  + do not need virtual look-up table cost.

## Result & Analysis

use `make compile` to run all programs and see the usage.

```bash
# "factorial"
time ././bin/factorial.out
0.48user 0.01system 0:00.50elapsed 99%CPU (0avgtext+0avgdata 1456maxresident)k
0inputs+0outputs (0major+415minor)pagefaults 0swaps
# "factorial with template meta programming"
time ././bin/factorial.tmp.out
0.03user 0.00system 0:00.02elapsed 106%CPU (0avgtext+0avgdata 1452maxresident)k
0inputs+0outputs (0major+413minor)pagefaults 0swaps
# "vector"
time ././bin/vector.out
4.59user 0.01system 0:04.59elapsed 100%CPU (0avgtext+0avgdata 1464maxresident)k
0inputs+0outputs (0major+417minor)pagefaults 0swaps
# "vector with template meta programming"
time ././bin/vector.tmp.out
4.54user 0.00system 0:04.57elapsed 99%CPU (0avgtext+0avgdata 1460maxresident)k
0inputs+0outputs (0major+416minor)pagefaults 0swaps
# "polymorphic"
time ././bin/polymorphic.out
0.25user 0.01system 0:00.26elapsed 101%CPU (0avgtext+0avgdata 1452maxresident)k
0inputs+0outputs (0major+415minor)pagefaults 0swaps
# "polymorphic with template meta programming"
time ././bin/polymorphic.tmp.out
0.18user 0.00system 0:00.19elapsed 94%CPU (0avgtext+0avgdata 1452maxresident)k
0inputs+0outputs (0major+414minor)pagefaults 0swaps
# make all compare finished
```

so we could see, the template metaprogramming could save time in runtime, for the verter example, the oprimization may not be clearly, this could be oprimization makes no difference when for loop does't need much time.

## Reference

+ [Compile_time_function_execution](https://en.wikipedia.org/wiki/Compile_time_function_execution)
+ [Template_metaprogramming](https://en.wikipedia.org/wiki/Template_metaprogramming)
