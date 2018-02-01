# Compile your code

gcc -g -std=c99 loop_overflow.c

# Run code

./a.out

## Quick Cmd

gcc -g -std=c99 loop_overflow.c && ./a.out
gcc -g -std=c99 ifelse.c && ./a.out
gcc -g -std=c99 IO.c && ./a.out

gcc -g -std=c99 lab1.c && ./a.out

# VS Code integrate

Install the code runner extension, and add the following to your user setting.

However, if your program need to input info, it will stuck when executing.

```json
"code-runner.executorMap": {
  "c": "gcc -g -std=c99 && ./a.out",  
}
```

## Key Map
