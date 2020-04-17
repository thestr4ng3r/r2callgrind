
# r2callgrind

Core plugin for radare2 to profile individual command calls.

## Usage

run radare2 like this:

```
valgrind --tool=callgrind --instr-atstart=no radare2 <r2 args>
```

Then, profile a single command like this (in this case `aaa`):

```
?C aaa
```

This will generate a file that contains only the profiling data of this command.

